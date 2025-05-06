# 🐚 shell_script Collection

[![MIT License](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE)
![Bash](https://img.shields.io/badge/shell-bash-1f425f.svg)
![Contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg)

A growing collection of reliable, production-grade shell scripts to automate server tasks, health checks, database installations, and more. Each module is well-documented, simple to use, and designed with extensibility in mind.

---

## 📂 Repository Structure

| Script | Description | Key Tools | License |
|--------|-------------|-----------|---------|
| [API Health Check](./API-HEALTH-CHECK_SHELL-SCRIPT) | Monitor an API endpoint and send email alerts on failure | `curl`, `mailx` | MIT |
| [PostgreSQL Installer](./INSTALL-POSTGRES_DB-V-10.x.x_Almalinux-9.5) | Install PostgreSQL 10.x and PostGIS 2.5.5 on AlmaLinux 9.5 | `yum`, `wget`, `tar` | MIT |
| [PGSQL DB Dump Tool](./PGSQL-DB_DUMP) | Dump all PostgreSQL databases while excluding specific ones | `pg_dump`, `grep` | MIT |
| [LVM CONFIGURATION](./CONFIGURE-LVM-DISK_SETTINGS) | Safely and automatically expand Logical Volumes (LVs) on AlmaLinux 9.5 | `yum`, `growpart`, `xfs_growfs`, `lsblk` | MIT |
| [PGSQL USER ACCESS MANAGEMENT](./CREATE_USER--PROVIDE_ACCESS--DETETE_USER_To_PGSQL-DB) | Manage PostgreSQL users and their SELECT-level access to databases, schemas, and tables | `psql`, `database`, `schema`, `table`, `SELECT`, `DROP`, `REASSIGN OWNED` | MIT |
| [MYSQL DB Dump Tool](./MYSQL-DB-DUMP) | Dump all MySql databases while excluding specific ones | `mysqldump`, `grep` | MIT |

---

## 🚀 Getting Started

### 🧰 Prerequisites

- Linux environment (tested on AlmaLinux 9.5 and Ubuntu)
- `bash`, `cron`, `mailx`, `postgresql`, and utilities specific to each script

### 📥 Clone the Repo

```bash
git clone https://github.com/your-username/shell_script.git
cd shell_script
```

### ▶️ Run a Script

```bash
cd API-HEALTH-CHECK_SHELL-SCRIPT
chmod +x API-Health-Check_with_Email-Alert.sh
./API-Health-Check_with_Email-Alert.sh
```

🔍 Be sure to update configuration variables inside each script before executing.

---

## 📘 API Health Check

#### 💡 Monitoring Application's health using API 

Monitors the response from a specified API and sends an email if it's down or returns an unexpected status code.

<details> <summary>🔧 Example Output</summary>

```bash
[✓] Checking API endpoint: https://example.com/health
[✓] Status Code: 200 OK
[✓] Everything is healthy.
```
```bash
[✗] Status Code: 500 Internal Server Error
[!] Sending alert email to admin@example.com...
```

</details>

---

## 🛠 PostgreSQL 10.x Installer (AlmaLinux 9.5)

#### 💡 Installs PostgreSQL 10.x with PostGIS support and configures it on AlmaLinux.

<details> <summary>📋 Steps Performed</summary>

```bash
 1. Install dependencies (gcc, make, libxml2, etc.)   
 2. Download and extract PostgreSQL  
 3. Compile and install PostGIS 2.5.5  
 4. Setup postgres user and environment variables  
 5. Configure pg_hba.conf and postgresql.conf  
```

</details>

---

## 🛠 PGSQL USER ACCESS MANAGEMENT

#### 💡 Manage PostgreSQL users and their access

<details> <summary>📋 Steps Performed</summary>

🟢 Create Superuser
```bash
AS YOU HAVE CHOSEN TO CREATE A SUPERUSER, PLEASE PROVIDE THE BELOW INFO.
USERNAME: admin_adib
PASSWORD: ********

Creating superuser admin_adib...
CREATE ROLE
ALTER ROLE

admin_adib USER CREATED WITH SUPERUSER ACCESS. 
```

🟢 Delete user
~~~
NOW, CHOOSE FROM THE OPTIONS BELOW WHAT YOU WANT TO DO:
(1). DELETE A USER FROM ALL DATABASES
(2). DELETE A USER FROM A SINGLE DATABASE
ENTER YOUR CHOICE (1 or 2): 1

USERNAME LIST: [admin_adib, readonly_rahim, user_mina]

USERNAME: readonly_rahim

Executing deletion in database: app_db
REASSIGN OWNED
DROP OWNED

Executing deletion in database: analytics
REASSIGN OWNED
DROP OWNED

DROP ROLE

User 'readonly_rahim' has been droped from databases.
~~~

</details>

---

## 🛠 Expand-LVM (AlmaLinux 9.5)

#### 💡 Interactive Bash script to safely and automatically expand Logical Volumes (LVs) on AlmaLinux 9.5 systems.

<details> <summary>📋 Steps Performed</summary>

```bash
Do you want to modify an LV size? (YES/NO): YES
Available Logical Volumes:
1. LV: home in VG: centos
2. LV: data in VG: centos

Enter the number of the LV you want to modify: 2
Enter size increase for data (e.g., +20G) or type 'MAX': MAX
Using all remaining free space for /dev/centos/data...
Resizing XFS filesystem on /dev/centos/data...
```

</details>

---

## 💾 PGSQL DB Dump with Exclusions

#### 💡 Dumps all PostgreSQL databases except the ones listed in an exclusion file or variable.

<details> <summary>📦 Sample Dump Output</summary>

```bash
[✓] Skipping database: template1
[✓] Skipping database: test_db
[✓] Dumping database: production_db
[✓] Dump completed: production_db_2025-05-04.sql
```

</details>

---

## 💾 MYSQL DB Dump with Exclusions

#### 💡 Dumps all MySql databases except the ones listed in an exclusion file or variable.

<details> <summary>📦 Sample Dump Output</summary>

```bash
[✓] Skipping database: performance_schema
[✓] Skipping database: mysql
[✓] Dumping database: production_db
[✓] Dump completed: production_db-250506_0040.sql.gz
```

</details>

---

## 🤝 Contribution Guide

We welcome new scripts, improvements, and documentation fixes!

 1. Fork this repo  
 2. Add your script in a new folder with a README.md and LICENSE  
 3. Ensure consistent formatting and executable permissions  
 4. Open a pull request 🚀  

---

## 📜 License

This project is licensed under the MIT License. See individual folders for their respective LICENSE files.

---

## 🧑‍💻 Author

**Adib Akhtab Faruquee**  
_Senior System Engineer_  
_Systems Network & Security Team, Engineering_  
📅 Created: May 2025  
📧 Email: adibakhtab@gmail.com  
🌐 Visit: https://bold.pro/my/adib-akhtab-faruquee-250402002920