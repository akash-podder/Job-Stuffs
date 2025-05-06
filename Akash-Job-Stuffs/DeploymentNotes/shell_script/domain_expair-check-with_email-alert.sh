#!/bin/bash

# -------------------------------------------
# | Script Created By: Adib Akhtab Faruquee |
# | Script Created at: 04-05-2025 09:00 AM  |
# -------------------------------------------

#-------------------------------------------------------------------------------------|
# | 🔹 Summary of What This Script Does                                               |
#-------------------------------------------------------------------------------------|
# | 1. Reads a list of domain names from an input file (`domain-check-list.txt`).     |
# | 2. Defines email settings (SMTP server, recipients, subjects) for sending alerts. |
# | 3. Clears old alert files before processing new data.                             |
# | 4. For each domain, the script:                                                   |
# |                                                                                   |
# |   - Extracts the domain extension to determine the type of WHOIS lookup.          |
# |   - Uses standard or custom WHOIS servers based on the domain extension.          |
# |   - Retrieves the domain's expiry date via a WHOIS query.                         |
# |   - Converts the expiry date to UNIX epoch time for easy comparison.              |
# |   - Calculates the number of days remaining until the domain expires.             |
# |                                                                                   |
# | 5. Domains expiring within 7 days are logged in `domain_expiry_7days.txt`.        |
# | 6. Domains expiring within 4 days are logged in `domain_expiry_4days.txt`.        |
# | 7. Expired domains are logged in `domain_expiry_expired.txt`.                     |
# | 8. If any alert files have data, the script formats and sends an email alert.     |
# | 9. The email contains domain expiry details and a signature for each case.        |
# | 10. After sending, the script prints a status message indicating completion.      |
#-------------------------------------------------------------------------------------|

# --------------------------
# | Configuration Section  |
# --------------------------

INPUT_FILE="/path_1/path_2/domain-check-list.txt"
ALERT_FILE_7D="/path_1/path_2/domain_expiry_7days.txt"
ALERT_FILE_4D="/path_1/path_2/domain_expiry_4days.txt"
ALERT_FILE_EXPIRED="/path_1/path_2/domain_expiry_expired.txt"

TMP_FILE_7D="/tmp/domain_7d.tmp"
TMP_FILE_4D="/tmp/domain_4d.tmp"
TMP_FILE_EXPIRED="/tmp/domain_expired.tmp"

SMTP_SERVER="smtp.gmail.com"
EMAIL_FROM="adib@gmail.com"
EMAIL_TO="adibakhtab@gmail.com adibakhtab007@gmail.com"

EMAIL_SUBJECT_7D="Domain Expiry Warning: Renew Before It's Too Late!"
EMAIL_SUBJECT_4D="URGENT: PSL Domain Expiry Alert – Action Required"
EMAIL_SUBJECT_EXPIRED="PSL Domains Canceling in 30 Days – Take Action Now!"

STANDARD_EXTENSIONS="sg net biz cc co com info bz"
declare -A CUSTOM_WHOIS_SERVERS=(
    ["business"]="whois.nic.business"
    ["app"]="whois.nic.app"
    ["cloud"]="whois.nic.cloud"
    ["store"]="whois.nic.store"
    ["digital"]="whois.nic.digital"
    ["shop"]="whois.nic.shop"
    ["ltd"]="whois.nic.ltd"
    ["xyz"]="whois.nic.xyz"
    ["ai"]="whois.nic.ai"
    ["pe"]="whois.nic.pe"
)

# Clear previous alert and temp files
> "$ALERT_FILE_7D" > "$ALERT_FILE_4D" > "$ALERT_FILE_EXPIRED"
> "$TMP_FILE_7D" > "$TMP_FILE_4D" > "$TMP_FILE_EXPIRED"

TODAY=$(date +%Y-%m-%d)
TODAY_EPOCH=$(date -d "$TODAY" +%s)

# --------------------------
# | Domain Expiry Checker  |
# --------------------------

while IFS= read -r domain; do
    extension="${domain##*.}"
    expiry_date=""

    if [[ " $STANDARD_EXTENSIONS " =~ " $extension " ]]; then
        expiry_date=$(whois "$domain" | grep -i "Expiry Date" | awk -F': ' '{print $2}' | cut -d'T' -f1)
    elif [[ -n "${CUSTOM_WHOIS_SERVERS[$extension]}" ]]; then
        WHOIS_SERVER=${CUSTOM_WHOIS_SERVERS[$extension]}
        expiry_date=$(whois -h "$WHOIS_SERVER" "$domain" | grep -i "Expiry Date" | awk -F': ' '{print $2}' | cut -d'T' -f1)
    fi

    if [[ -n "$expiry_date" ]]; then
        exp_epoch=$(date -d "$expiry_date" +%s 2>/dev/null)
        if [[ -n "$exp_epoch" ]]; then
            days_left=$(( (exp_epoch - TODAY_EPOCH) / 86400 ))

            if [[ "$days_left" -le 7 && "$days_left" -gt 4 ]]; then
                printf "  - %s expires in %d days (Expiry date: %s)\n" "$domain" "$days_left" "$expiry_date" >> "$TMP_FILE_7D"
            elif [[ "$days_left" -le 4 && "$days_left" -ge 0 ]]; then
                printf "  - %s expires in %d days (Expiry date: %s)\n" "$domain" "$days_left" "$expiry_date" >> "$TMP_FILE_4D"
            elif [[ "$days_left" -lt 0 ]]; then
                printf "  - %s already expired on %s\n" "$domain" "$expiry_date" >> "$TMP_FILE_EXPIRED"
            fi
        fi
    fi
done < "$INPUT_FILE"

# --------------------------
# | Email Builder Function |
# --------------------------

build_email_body() {
    local header="$1"
    local tmp_file="$2"
    local output_file="$3"

    if [[ -s "$tmp_file" ]]; then
        {
            printf "Assalamualaikum Wa Rahmatullah Dear Team,\n\n"
            printf "%s\n\n" "$header"
            cat "$tmp_file"
            printf "\nPlease plan accordingly to ensure continued service availability.\n\n"
            printf "Best Regards,\n\nAdib Akhtab Faruquee\nSenior System Engineer\nSystems Network & Security Team, Engineering\n\n"
            printf "This is an auto-generated e-mail. Please do not reply.\n"
        } > "$output_file"
    fi
}

# --------------------------
# | Build Emails for Each  |
# --------------------------

build_email_body \
    "🔔  Reminder: The following domains will expire within the next 7 days. Please take the necessary steps to renew them before they expire to avoid any service disruptions." \
    "$TMP_FILE_7D" "$ALERT_FILE_7D"

build_email_body \
    "⚠️ The following domains will expire in 4 days or less! Immediate renewal is required to avoid downtime." \
    "$TMP_FILE_4D" "$ALERT_FILE_4D"

build_email_body \
    "❌ The following domains have already expired. If they are not renewed within 30 days, they may be permanently lost." \
    "$TMP_FILE_EXPIRED" "$ALERT_FILE_EXPIRED"

# --------------------------
# | Send Emails If Needed  |
# --------------------------

send_email() {
    local subject="$1"
    local file="$2"

    if [[ -s "$file" ]]; then
        mailx -s "$subject" \
            -S smtp="$SMTP_SERVER" \
            -S smtp-auth=login \
            -S smtp-auth-user="$EMAIL_FROM" \
            -S smtp-auth-password="ascdsaswdsxdsax" \
            -r "$EMAIL_FROM" \
            "$EMAIL_TO" < "$file"
        echo "Alert email sent: $subject"
    fi
}

send_email "$EMAIL_SUBJECT_7D" "$ALERT_FILE_7D"
send_email "$EMAIL_SUBJECT_4D" "$ALERT_FILE_4D"
send_email "$EMAIL_SUBJECT_EXPIRED" "$ALERT_FILE_EXPIRED"

echo "✅ Domain expiry check completed. Alerts saved and sent."