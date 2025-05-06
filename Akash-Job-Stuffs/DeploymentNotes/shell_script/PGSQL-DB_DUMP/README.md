# 🗃️ PostgreSQL Daily Backup Script with EXCLUDE Support (Linux)

[![Shell](https://img.shields.io/badge/Shell-Bash-brightgreen?logo=gnu-bash&logoColor=white)](https://www.gnu.org/software/bash/)
[![Status](https://img.shields.io/badge/status-stable-success.svg)](https://github.com/adibakhtab007/shell_script)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](./LICENSE)
[![Last Commit](https://img.shields.io/github/last-commit/adibakhtab007/shell_script.svg)](https://github.com/adibakhtab007/shell_script/commits/main)
[![Cron Job](https://img.shields.io/badge/Schedule-Daily-blue)](https://crontab.guru/#0_2_*_*_*)

---

## 📌 Overview

This is a robust shell script designed to perform **daily database-dump of PostgreSQL databases** on a Linux server while **excluding specific databases**.

It uses `pg_dump` with `gzip` compression and logs each backup process in detail.

---

## ✨ Features

- 🔁 Daily PostgreSQL database backups
- 📤 GZIP compression of `.sql` dump files
- ❌ Exclusion list for skipping specific databases
- 📆 Configurable retention policy (deletes backups older than N days)
- 📋 Logs all actions to a backup log
- 👨‍💻 Runs under the `postgres` user using `sudo -u`

---

## ⚙️ Configuration

Update the script variables to suit your environment:

```
RETENTION_DAYS=6                                         # Number of days to keep old backups
PG_USER="postgres"                                       # PostgreSQL user
BACKUP_DIR="/path/DB_Postgres/Postgres-DB-Dump"          # Where to store backups
EXCLUDE_DATABASES=("postgres" "test_adib_sys_2" ...)     # Databases to skip
```
Ensure PostgreSQL binaries (psql, pg_dump) are in your PATH, or set full paths in PSQL_PATH and PG_DUMP_PATH.

---

## 🧑‍💻 Author

**Adib Akhtab Faruquee**  
_Senior System Engineer_  
_Systems Network & Security Team, Engineering_  
📅 Created: 04-05-2025

---

## 🛠️ Usage

📂 Step 1: Make script executable

```
chmod +x PGSQL-DB-DUMP_with-EXCLUDE_DB.sh
```

▶️ Step 2: Run manually

```
sudo ./PGSQL-DB-DUMP_with-EXCLUDE_DB.sh
```

🕑 Step 3: Automate via Cron (e.g., 2 AM daily)

```
0 2 * * * /path/to/PGSQL-DB-DUMP_with-EXCLUDE_DB.sh >> /var/log/pgsql_backup_cron.log 2>&1
```

---

## 📁 Output

- Dump files saved in: $BACKUP_DIR
- Filename format: database_YYYY-MM-DD.sql.gz
- Logs saved in: $BACKUP_DIR/backup_log.txt

---

## ❌ Example Excluded Databases

```
EXCLUDE_DATABASES=("postgres" "test_adib_sys_2" "template1")
These databases will be skipped during the backup process.
```

---

## 🔍 Sample Log Output

```
[INFO] BACKUP PROCESS STARTED AT 04-05-2025 09:00:00 AM
[INFO] Backing up database: production_db
[INFO] production_db DUMP STARTED AT: 2025-05-04 09:00:01
[INFO] production_db DUMP COMPLETED AT: 2025-05-04 09:00:20
[INFO] Skipping database: postgres
[INFO] BACKUP PROCESS COMPLETED AT 04-05-2025 09:00:25 AM
```

---

## 📦 Requirements

- Linux OS with Bash
- PostgreSQL installed (psql, pg_dump)
- gzip installed
- Permissions to run as or sudo -u postgres

---

## 📝 License

This project is licensed under the MIT License. See the LICENSE file for full details.

---

## 🧼 Cleanup

Old backup files older than RETENTION_DAYS are automatically deleted:

```find "$BACKUP_DIR" -type f -name "*.sql.gz" -mtime +$RETENTION_DAYS -exec rm -f {} \;```

---

## 🤝 Contributions

Feel free to fork the repo, submit improvements, or raise issues. All contributions are welcome!

---

## 🚨 Disclaimer

This script is tested on Linux systems with PostgreSQL running locally. Review and adapt it before deploying in production or on remote DB setups.

---

##  📂 Repository Structure

```bash
shell_script
├── PGSQL-DB_DUMP/
	├── PGSQL-DB-DUMP_with-EXCLUDE_DB.sh   # Main script
	├── LICENSE                            # MIT License
	└── README.md                          # Documentation
```