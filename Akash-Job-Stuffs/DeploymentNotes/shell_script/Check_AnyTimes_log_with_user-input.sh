#!/bin/bash

# -------------------------------------------
# | Script Created By: Adib Akhtab Faruquee |
# | Script Created at: 04-05-2025 09:00 AM  |
# -------------------------------------------

# Prompt for log output path with a demo
echo "Enter full path to save the filtered output log (e.g., /home/adib/FILE.log):"
read -p "OUTPUT_LOG_PATH: " OUTPUT_LOG_PATH

# Prompt for date/time ranges with examples
echo "Enter FROM date (e.g., 14/Apr/2025):"
read -p "FROM_DATE: " FROM_DATE

echo "Enter FROM time (e.g., 18:30:00):"
read -p "FROM_TIME: " FROM_TIME

echo "Enter TO date (e.g., 14/Apr/2025):"
read -p "TO_DATE: " TO_DATE

echo "Enter TO time (e.g., 19:30:00):"
read -p "TO_TIME: " TO_TIME

# Combine into full timestamps
FROM_TS="${FROM_DATE}:${FROM_TIME}"
TO_TS="${TO_DATE}:${TO_TIME}"

# Fixed path to log file (you can later prompt for this too if needed)
NAS_LOG_PATH='/path/FILE.gz'

# Process log
zcat "$NAS_LOG_PATH" | awk -v from="$FROM_TS" -v to="$TO_TS" '
  match($0, /"time_local": ?"([^"]+)"/, m) {
    if (m[1] >= from && m[1] <= to)
      print
  }
' > "$OUTPUT_LOG_PATH"

echo "✅ Log entries from $FROM_TS to $TO_TS saved to: $OUTPUT_LOG_PATH"
