#!/bin/bash

# -------------------------------------------
# | Script Created By: Adib Akhtab Faruquee |
# | Script Created at: 04-05-2025 09:00 AM  |
# -------------------------------------------

# --------------------------
# | Configuration Section  |
# --------------------------

SMTP_SERVER="smtp.gmail.com"
EMAIL_FROM="adib@gmail.com"

EMAIL_TO="adibakhtab@gmail.com adibakhtab007@gmail.com"
EMAIL_SUBJECT="⚠️ URGENT: PROJECT_NAME Application Unresponsive"

ALERT_FILE="/path_1/path_2/PROJECT_NAME_API-Health-Check-Email.log"

# Clear the log file before writing new results
> "$ALERT_FILE"

# Function to check APIs and generate alerts
check_apis() {
    local group_name="$1"
    shift  # Remove the first argument so only the API list remains

    all_ok=true  # Flag to track if all APIs return 2xx codes

    for line in "$@"; do
        server=$(echo "$line" | cut -d':' -f1)
        port=$(echo "$line" | cut -d':' -f2)
        api=$(echo "$line" | cut -d':' -f3 | cut -d'=' -f1)
        path=$(echo "$line" | cut -d'=' -f2)

        if [[ -z "$server" || -z "$port" || -z "$api" || -z "$path" ]]; then
            echo "Error: Invalid API entry -> $line"
            continue
        fi

        url="http://$server:$port/$path"
        response_code=$(curl -o /dev/null -s -w "%{http_code}" "$url")

        if [[ -z "$response_code" ]]; then
            response_code="ERROR"
        fi

        if [[ "$response_code" -ge 300 && "$response_code" -lt 600 ]]; then
            echo "CRITICAL! HTTP-Code: $response_code   |   Application: $url"
            echo "CRITICAL!!!   HTTP-Code: $response_code   |   Application: http://$server:$port/$api" >> "$ALERT_FILE"
            all_ok=false
        fi
    done

    if ! $all_ok; then
        send_email_alert
        exit 2
    else
        echo "OK - All APIs are returning 2xx responses."
    fi
}

# Function to check application statuses and generate alerts
check_application_status() {
    declare -A APPS=(
        ["application-name_1"]="http://xx.xx.xx.xx:yyyy/app_1/"
        ["application-name_2"]="http://xx.xx.xx.xx:yyyy/app_2/"
        ["application-name_3"]="http://xx.xx.xx.xx:yyyy/app_3/"
        ["application-name_4"]="http://xx.xx.xx.xx:yyyy/app_4/"
    )

    EXPECTED_TEXT="Whitelabel Error Page"
    ANY_DOWN=0

    echo "Checking application statuses..."

    # Loop through each application
    for APP in "${!APPS[@]}"; do
        URL="${APPS[$APP]}"
        RESPONSE=$(curl -s -H "Accept: text/html" "$URL")

        if echo "$RESPONSE" | grep -q "$EXPECTED_TEXT"; then
            echo "[UP] $APP is running normally."
        else
            echo "CRITICAL! $APP is NOT returning the expected response!"
            echo "CRITICAL!!!  |  [DOWN] $APP" >> "$ALERT_FILE"
            ANY_DOWN=1
        fi
    done

    if [[ $ANY_DOWN -eq 1 ]]; then
        send_email_alert
        exit 2
    #else
        #echo "✅ All applications are UP!"
    fi
}

# Function to send email alerts
send_email_alert() {
    if [[ -s "$ALERT_FILE" ]]; then
        {
            echo "Assalamualaikum Wa Rahmatullah Dear Team,"
            echo ""
            echo "ALERT! The following applications from PROJECT_NAME are currently unresponsive:"
            echo ""
            cat "$ALERT_FILE"
            echo ""
            echo "Please investigate immediately to restore service availability."
            echo ""
            echo "Best Regards,"
            echo "Adib Akhtab Faruquee"
            echo "Senior System Engineer"
            echo "Systems Network & Security Team, Engineering"
            echo ""
            echo "This is an auto-generated email. Please do not reply."
        } | mailx -s "$EMAIL_SUBJECT" -S smtp="$SMTP_SERVER" -r "$EMAIL_FROM" "$EMAIL_TO"
        echo "Alert email sent for unresponsive applications."
    else
        echo "No critical issues detected. No alert sent."
    fi
}

# Check applications
check_application_status

# Check APIs
check_apis "Group 1" \
    "xx.xx.xx.xx:yyyy:APPLICATION_NAME-10=app_10/api" \
    "xx.xx.xx.xx:yyyy:APPLICATION_NAME-11=app_11/api" \
    "xx.xx.xx.xx:yyyy:APPLICATION_NAME-12=app_12/api/"
