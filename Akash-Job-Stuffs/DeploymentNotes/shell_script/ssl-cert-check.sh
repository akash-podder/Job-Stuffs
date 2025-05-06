#!/bin/bash

# -------------------------------------------
# | Script Created By: Adib Akhtab Faruquee |
# | Script Created at: 04-05-2025 09:00 AM  |
# -------------------------------------------

#-------------------------------------------------------------------------|
# | 🔹 Summary of What This Script Does                                   |
#-------------------------------------------------------------------------|
# | 1. Stores SSL certificate paths for different services.               |
# | 2. Stores email recipients who will receive alerts.                   |
# | 3. Stores a list of servers where these SSL certificates are deployed.|
# | 4. Defines a function (check_ssl_expiry) to:                          |
# |                                                                       |
# |   - Extract SSL expiry date.                                          |
# |   - Calculate remaining days.                                         |
# |   - Send an alert if expiry is within 15 days.                        |
# |                                                                       |
# | 5. Checks all defined certificates and sends an email if needed.      |
#-------------------------------------------------------------------------|

# --------------------------
# | Configuration Section  |
# --------------------------

# SSL Certificate Paths
SSL_PATHS=(
    "/path_1/path_2/project_ssl_1.pem"
    "/path_1/path_2/project_ssl_2.crt"
    "/path_1/path_2/project_ssl_3.crt"
)

# Domains Corresponding to SSL Certificates
DOMAINS=(
    "*.project_ssl_1.cloud"
    "*.project_ssl_2.com"
    "*.project_ssl_3.net"
)

# Server List
SERVERS=(
    "xx.xx.xx.xx | HOST-NAME-xx"
    "yy.yy.yy.yy | HOST-NAME-yy"
    "zz.zz.zz.zz | HOST-NAME-zz"
)

# Email Configuration
EMAIL_TO="adibakhtab@gmail.com adibakhtab007@gmail.com"
LOG_FILE="/path/ssl_expiry_check.log"

# Function to check SSL expiry
check_ssl_expiry() {
    local cert_path="$1"
    local domain="$2"

    expiry_date=$(openssl x509 -in "$cert_path" -noout -enddate | cut -d= -f2)
    expiry_timestamp=$(date -d "$expiry_date" +%s)
    current_timestamp=$(date +%s)
    days_left=$(( (expiry_timestamp - current_timestamp) / 86400 ))
    formatted_expiry_date=$(date -d "$expiry_date" +"%Y-%m-%d %H:%M:%S")

    echo "----------------------------------------" | tee -a "$LOG_FILE"
    echo "Domain: $domain" | tee -a "$LOG_FILE"
    echo "Expiry Date: $formatted_expiry_date" | tee -a "$LOG_FILE"
    echo "Days Remaining: $days_left" | tee -a "$LOG_FILE"
    echo "----------------------------------------" | tee -a "$LOG_FILE"

    if [ "$days_left" -le 14 ] && [ "$days_left" -gt 4 ]; then
        subject="SSL Cert. Expiry Warning: Renew Before It's Too Late!"
        body="Assalamualaikum Wa Rahmatullah Dear Team,\n\n 🔔 Reminder: SSL certificate for $domain is expiring soon!\n\nExpiration Date: $formatted_expiry_date\nDays Remaining: $days_left\n\nPlan renewal to avoid service disruption.\n\nAffected Servers:\n  - VM-HOST-IP: xx.xx.xx.xx |  VM-HOST-NAME: HOST-NAME-xx\n  - VM-HOST-IP: yy.yy.yy.yy |  VM-HOST-NAME: HOST-NAME-yy\n  - VM-HOST-IP: zz.zz.zz.zz |  VM-HOST-NAME: HOST-NAME-zz\n\nPlease plan accordingly to avoid any service disruption.\n\nBest Regards,\n\nAdib Akhtab Faruquee\nSenior System Engineer\nSystems Network & Security Team, Engineering\n\nThis is an auto-generated e-mail and please do not reply to this."
        echo -e "$body" | mail -s "$subject" "$EMAIL_TO"
    elif [ "$days_left" -le 4 ] && [ "$days_left" -gt 0 ]; then
        subject="URGENT: PSL SSL Cert. Expiry Alert – Action Required"
        body="Assalamualaikum Wa Rahmatullah Dear Team,\n\n 🚨 URGENT: SSL certificate for $domain is expiring in $days_left days!\n\nExpiration Date: $formatted_expiry_date\n\nImmediate Action Required:\n- Renew and deploy the SSL certificate immediately to prevent service disruption.\n\nAffected Servers:\n  - VM-HOST-IP: xx.xx.xx.xx |  VM-HOST-NAME: HOST-NAME-xx\n  - VM-HOST-IP: yy.yy.yy.yy |  VM-HOST-NAME: HOST-NAME-yy\n  - VM-HOST-IP: zz.zz.zz.zz |  VM-HOST-NAME: HOST-NAME-zz\n\nPlease plan accordingly to avoid any service disruption.\n\nBest Regards,\n\nAdib Akhtab Faruquee\nSenior System Engineer\nSystems Network & Security Team, Engineering\n\nThis is an auto-generated e-mail and please do not reply to this."
        echo -e "$body" | mail -s "$subject" "$EMAIL_TO"
    elif [ "$days_left" -le 0 ]; then
        subject="PSL SSL Cert.s Expired [ !! LIVE SERVICE DOWN !! ]"
        body="Assalamualaikum Wa Rahmatullah Dear Team,\n\n 🚨 CRITICAL: SSL certificate for $domain has EXPIRED!\n\nExpiration Date: $formatted_expiry_date\n\nThis issue is causing a LIVE SERVICE OUTAGE. Renew and apply the updated SSL certificate IMMEDIATELY!\n\nAffected Servers:\n  - VM-HOST-IP: xx.xx.xx.xx |  VM-HOST-NAME: HOST-NAME-xx\n  - VM-HOST-IP: yy.yy.yy.yy |  VM-HOST-NAME: HOST-NAME-yy\n  - VM-HOST-IP: zz.zz.zz.zz |  VM-HOST-NAME: HOST-NAME-zz\n\nPlease plan accordingly to avoid any service disruption.\n\nBest Regards,\n\nAdib Akhtab Faruquee\nSenior System Engineer\nSystems Network & Security Team, Engineering\n\nThis is an auto-generated e-mail and please do not reply to this."
        echo -e "$body" | mail -s "$subject" "$EMAIL_TO"
    fi
}

# Main Execution
> "$LOG_FILE"
echo "========================================"
echo "| SSL Certificate Expiry Checker       |"
echo "========================================"

for i in "${!SSL_PATHS[@]}"; do
    check_ssl_expiry "${SSL_PATHS[$i]}" "${DOMAINS[$i]}"
done

echo "SSL Certificate Expiry Check Completed!"