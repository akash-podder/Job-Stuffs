# 🔍 Application & API Health Monitoring Script

[![Shell](https://img.shields.io/badge/Shell-Bash-brightgreen?logo=gnu-bash&logoColor=white)](https://www.gnu.org/software/bash/)
[![Status](https://img.shields.io/badge/status-active-success.svg)](https://github.com/adibakhtab007/shell_script)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](./LICENSE)
[![Last Commit](https://img.shields.io/github/last-commit/adibakhtab007/shell_script.svg)](https://github.com/adibakhtab007/shell_script/commits/main)
[![Cron Job](https://img.shields.io/badge/Cron-Every%205%20min-blue)](https://crontab.guru/#*/5_*_*_*_*)

---

## 🧾 Overview

This shell script performs **automated health checks on applications and APIs**, logs any issues, and sends **email alerts** when services become unresponsive. It is useful for maintaining uptime in production environments by catching early signs of failure.

---

## ✨ Features

- ✅ Application availability checks via expected HTML response
- ✅ API endpoint response code checks (`2xx` validation)
- 📧 Email alerts for failures (via `mailx`)
- 📜 Logs errors for audit and debugging
- ⚙️ Easily configurable for your infrastructure

---

## ⚙️ Configuration

Before using, configure the following:

```bash
SMTP_SERVER="smtp.gmail.com"
EMAIL_FROM="adib@gmail.com"
EMAIL_TO="adibakhtab@gmail.com adibakhtab007@gmail.com"
EMAIL_SUBJECT="⚠️ URGENT: PROJECT_NAME Application Unresponsive"
ALERT_FILE="/path_1/path_2/PROJECT_NAME_API-Health-Check-Email.log"
```

Define your monitored applications:

```
declare -A APPS=(
	["application-name_1"]="http://xx.xx.xx.xx:yyyy/app_1/"
	["application-name_2"]="http://xx.xx.xx.xx:yyyy/app_2/"
)
```

And your API list in the script:

```
check_apis "Group 1" \
	"xx.xx.xx.xx:yyyy:APPLICATION_NAME-10=app_10/api"
```

---

##  🖥️ How It Works
1. Application Check
Verifies if application URLs return expected HTML content (e.g. Whitelabel Error Page).

Logs and alerts on mismatch.

2. API Check
Sends requests to API endpoints.

Checks for HTTP status 2xx.

Logs critical failures for anything >= 300.

3. Email Notification
Compiles alerts from a temporary log file.

Sends email using mailx and SMTP server.

---

##  🛠️ Usage
Make the script executable:

```
chmod +x API-Health-Check_with_Email-Alert.sh
./API-Health-Check_with_Email-Alert.sh
```

---

##  📅 Automate with Cron
Example cron entry to run every 5 minutes:

```
*/5 * * * * /path/to/API-Health-Check_with_Email-Alert.sh >> /var/log/health_monitor.log 2>&1
```

---

📧 Sample Email Alert

```
Subject: ⚠️ URGENT: PROJECT_NAME Application Unresponsive

Assalamualaikum Wa Rahmatullah Dear Team,

ALERT! The following applications from PROJECT_NAME are currently unresponsive:

CRITICAL!!!   HTTP-Code: 500   |   Application: http://xx.xx.xx.xx:yyyy/app_10/api
CRITICAL!!!  |  [DOWN] application-name_3

Please investigate immediately to restore service availability.

Best Regards,
Adib Akhtab Faruquee
Senior System Engineer
```

---

## 🧑‍💻 Author

**Adib Akhtab Faruquee**  
_Senior System Engineer_  
_Systems Network & Security Team, Engineering_  
📅 Created: 04-05-2025

---

##  📝 License
Distributed under the MIT License. See LICENSE for more information.

---

##  🤝 Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you’d like to change.

---

##  📂 Repository Structure
```bash
shell_script
├── API-HEALTH-CHECK_SHELL-SCRIPT/
	├── API-Health-Check_with_Email-Alert.sh   # Main script
	├── LICENSE                                # MIT License
	└── README.md                              # Documentation
```