#!/bin/bash

# -------------------------------------------
# | Script Created By: Adib Akhtab Faruquee |
# | Script Created at: 04-05-2025 09:00 AM  |
# -------------------------------------------

#----------------------------------------------------------------------|
# | 🔹  Key Features:                                                  |
#----------------------------------------------------------------------|
# | ✅ Monitors Tomcat Heap Memory Usage (G1 Eden Space + G1 Old Gen). |
# | ✅ Automatically cleans old logs beyond the retention period.      |
# | ✅ Detects sudden memory spikes/drops and alerts administrators.   |
# | ✅ Sends formatted email alerts in case of memory leak detection.  |
# | ✅ Uses XML parsing (xmllint) and mathematical calculations (bc).  |
#----------------------------------------------------------------------|

# --------------------------
# | Configuration Section  |
# --------------------------

# Input parameters
PORT="8080"
USER="adib"
PASSWORD="Y0u#R@Pa$sw0rd"
RETENTION_DAYS=2

LOG_FILE="/path/tomcat-$PORT-leak_heap_memory_email-alert-$(date +%Y-%m-%d).log"
RETENTION_DAYS_LOG_FILE="/path/Tomcat-Heap-Memory"

# Fetch Tomcat status
STATUS=$(curl -s -u "$USER:$PASSWORD" "http://localhost:$PORT/manager/status/all?XML=true")

if [[ -z "$STATUS" ]]; then
  echo "$(date) | ERROR - Unable to fetch Tomcat memory data" >> "$LOG_FILE"
  exit 1
fi

# Find and remove backup files older than 6 days
echo "Cleaning up log files older than $RETENTION_DAYS days..."
find "$RETENTION_DAYS_LOG_FILE" -type f -name "tomcat-$PORT-leak_heap_memory_email-alert-*.log" -mtime +$RETENTION_DAYS -exec rm -f {} \; || {
    echo "Failed to remove old log files";
    exit 1;
}

# Function to convert bytes to MB
convert_bytes() {
  echo "scale=2; $1/1024/1024" | bc
}

# Extract memory data
Eden_Total=$(convert_bytes "$(echo "$STATUS" | xmllint --xpath "string(//status/jvm/memorypool[@name='G1 Eden Space']/@usageCommitted)" - 2>/dev/null)")
Eden_Used=$(convert_bytes "$(echo "$STATUS" | xmllint --xpath "string(//status/jvm/memorypool[@name='G1 Eden Space']/@usageUsed)" - 2>/dev/null)")

OldGen_Total=$(convert_bytes "$(echo "$STATUS" | xmllint --xpath "string(//status/jvm/memorypool[@name='G1 Old Gen']/@usageCommitted)" - 2>/dev/null)")
OldGen_Used=$(convert_bytes "$(echo "$STATUS" | xmllint --xpath "string(//status/jvm/memorypool[@name='G1 Old Gen']/@usageUsed)" - 2>/dev/null)")
OldGen_Max=$(convert_bytes "$(echo "$STATUS" | xmllint --xpath "string(//status/jvm/memorypool[@name='G1 Old Gen']/@usageMax)" - 2>/dev/null)")

# Fallback if OldGen_Max is unlimited (-1)
if [[ "$OldGen_Max" == "-1.00" ]]; then
  OldGen_Max=$OldGen_Total
fi

# Calculate combined usage
Combined_Used=$(echo "$Eden_Used + $OldGen_Used" | bc)
Usage_Percent=$(echo "scale=2; ($Combined_Used / $OldGen_Max) * 100" | bc)

# Log memory usage
echo "$(date) | Used: $Combined_Used MB | Usage: $Usage_Percent%" >> "$LOG_FILE"

# SMTP Configuration
SMTP_SERVER="smtp.gmail.com"
EMAIL_TO="adibakhtab@gmail.com adibakhtab007@gmail.com"
EMAIL_SUBJECT="⚠️ URGENT: Tomcat-$PORT MEMORY LEAK ALERT"

# =================================
# DYNAMIC ALERT CHECK (MEMORY LEAK)
# =================================
if [[ $(wc -l < "$LOG_FILE") -ge 3 ]]; then
  Last_Three_Entries=$(tail -n 3 "$LOG_FILE" | awk '{print $6}')
  Max_Usage=$(echo "$Last_Three_Entries" | sort -nr | head -1)
  Min_Usage=$(echo "$Last_Three_Entries" | sort -n | head -1)

  Usage_Diff=$(echo "$Max_Usage - $Min_Usage" | bc)

  if (( $(echo "$Usage_Diff >= 30" | bc -l) )); then
    echo "$(date) | ⚠️ MEMORY LEAK ALERT: Sudden memory spike and drop detected!" >> "$LOG_FILE"

    # Prepare email body correctly using `cat <<EOF`
    email_body=$(cat <<EOF
Assalamualaikum Wa Rahmatullah Dear Team,

Tomcat-$PORT on HOST-surepay-app is facing **MEMORY LEAK ALERT**. Please take the necessary steps to prevent it before it creates service disruptions.

$(tail -n 10 "$LOG_FILE")

Please plan accordingly to ensure continued service availability.

Best Regards,

Adib Akhtab Faruquee
Senior System Engineer
Systems Network & Security Team, Engineering

This is an auto-generated e-mail and please do not reply to this.
EOF
)
    # Send email using mailx
    echo "$email_body" | mail -s "$EMAIL_SUBJECT" "$EMAIL_TO"
  fi
fi
