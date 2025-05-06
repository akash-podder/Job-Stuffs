# MySQL Auto Dump Script

[![Shell](https://img.shields.io/badge/Shell-Bash-brightgreen?logo=gnu-bash&logoColor=white)](https://www.gnu.org/software/bash/)
[![Status](https://img.shields.io/badge/status-stable-success.svg)](https://github.com/adibakhtab007/shell_script)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](./LICENSE)
[![Last Commit](https://img.shields.io/github/last-commit/adibakhtab007/shell_script.svg)](https://github.com/adibakhtab007/shell_script/commits/main)
[![Cron Job](https://img.shields.io/badge/Schedule-Daily-blue)](https://crontab.guru/#0_2_*_*_*)

---

## 📌 Overview

This is a Bash script designed to automatically dump all MySQL databases **one by one** while excluding specified databases. It compresses each dump and retains logs, with automatic cleanup of backups older than 6 days.

---

## 🛠️ Features

- Dumps all MySQL databases **individually**
- Excludes default/system databases and user-defined ones
- Compresses each SQL dump using `gzip`
- Maintains a log of dump operations
- Deletes old dump files older than 6 days

---

## 🚀 Usage

### Prerequisites

- MySQL server access with credentials
- `mysqldump` and `mysql` installed
- Bash shell

### Edit Credentials

Update the following variables in the script:

```bash
MYSQL_USER="your_username"
MYSQL_PASS="your_password"
BACKUP_DIR="/desired/backup/path"
```
Exclude Databases
Customize the grep -Ev pattern in the script to skip specific databases.

```bash
grep -Ev "Database|information_schema|performance_schema|mysql|sys|db1|db2"
```

Run the Script

```bash
bash mysql_dump.sh
```

Add to a cron job for automation:

```bash
0 2 * * * /path/to/mysql_dump.sh
```

---

## 📁 Output

- Individual ```.sql.gz``` files per database
- Dump file names include a timestamp
- Log file: ```mysqldump_log.txt```

---

## 🧹 Cleanup

Automatically removes backup files older than 6 days:

```bash
find "$BACKUP_DIR" -name "*.sql.gz" -mtime +6 -exec rm {} \;
```
---

## 👨‍💻 Author

**Adib Akhtab Faruquee**  
_Senior System Engineer_  
_Systems Network & Security Team, Engineering_  
📅 Created: 04-05-2025

---

## 📄 License

This project is licensed under the MIT License - see the LICENSE file for details.