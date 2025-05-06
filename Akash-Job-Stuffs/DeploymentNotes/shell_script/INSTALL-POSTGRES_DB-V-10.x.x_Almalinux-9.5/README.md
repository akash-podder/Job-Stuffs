# 🐘 PostgreSQL 10.x + PostGIS 2.5.5 Installer for AlmaLinux 9.5

[![Shell](https://img.shields.io/badge/Shell-Bash-brightgreen?logo=gnu-bash&logoColor=white)](https://www.gnu.org/software/bash/)
[![Status](https://img.shields.io/badge/status-stable-success.svg)](https://github.com/adibakhtab007/shell_script)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](./LICENSE)
[![Last Commit](https://img.shields.io/github/last-commit/adibakhtab007/shell_script.svg)](https://github.com/adibakhtab007/shell_script/commits/main)
[![Platform](https://img.shields.io/badge/Platform-AlmaLinux%209.5-blue)](https://almalinux.org/)

---

## 🧾 Overview

This automated shell script installs:

- **PostgreSQL 10.20** from source  
- **PostGIS 2.5.5**, including all required dependencies  
- **GDAL 3.0.4**, **PROJ 6.3.2**, and essential geo-libraries  

The script is tailored for **AlmaLinux 9.5** and sets up a functional spatial database environment suitable for GIS applications.

---

## ⚙️ What It Does

✅ Updates system packages  
✅ Installs all dependencies required for building PostGIS stack  
✅ Downloads and compiles PostgreSQL, PROJ, GDAL, and PostGIS  
✅ Configures a clean PostgreSQL environment  
✅ Verifies the installation and PostGIS extension  

---

## 📁 Files Included

- `Install_PGSQL-10.xx_and_PosGIS-2.5.5-Almalinux-9.5.sh` — Main installation script
- `LICENSE` — MIT License
- `README.md` — You're reading it!

---

## 🧑‍💻 Author

**Adib Akhtab Faruquee**  
_Senior System Engineer_  
_Systems Network & Security Team, Engineering_  
📅 Created: 04-05-2025

---

## 🛠️ Usage

> ⚠️ **Run as root or with sudo privileges**.

```bash
chmod +x Install_PGSQL-10.xx_and_PosGIS-2.5.5-Almalinux-9.5.sh
sudo ./Install_PGSQL-10.xx_and_PosGIS-2.5.5-Almalinux-9.5.sh
```

Logs are written to:

```
/var/log/install_postgis.log
```

---

## 🧱 Directory Structure Used

```
/usr/local/src/                  ← Working directory
/usr/local/pgsql                 ← PostgreSQL installed here
/var/lib/pgsql/10/data           ← PostgreSQL data directory
/usr/local/lib                   ← Dynamic library path for PostGIS & GDAL
```

---

## 📦 Installed Versions
| Component  | Version |
| ---------- | ------- |
| PostgreSQL | 10.20   |
| PostGIS    | 2.5.5   |
| GDAL       | 3.0.4   |
| PROJ       | 6.3.2   |

---

## 🛡️ Safety Features
- Uses set -e, set -u, and pipefail to fail-fast on errors
- Full log output to /var/log/install_postgis.log
- Line-specific failure tracing with trap on ERR

---

## 🔍 Sample Output

```
[SUCCESS] Installation started at ...
[INFO] Running: yum update -y
[SUCCESS] Completed: yum update -y
[INFO] Running: su - postgres -c '/usr/local/pgsql/bin/pg_ctl ...'
```

---

## 📝 License
This project is licensed under the MIT License. See the LICENSE file for full details.

---

## 🤝 Contributions
Contributions, improvements, and testing on other RHEL-based distros are welcome!
Please submit a pull request or open an issue to get started.

---

## 🚨 Disclaimer
This script assumes a clean AlmaLinux 9.5 environment. Avoid using it on servers with existing PostgreSQL/PostGIS installations to prevent conflicts or overwrites.

---

##  📂 Repository Structure
```bash
shell_script
├── INSTALL-POSTGRES_DB-V-10.x.x_Almalinux-9.5/
	├── Install_PGSQL-10.xx_and_PosGIS-2.5.5-Almalinux-9.5.sh   # Main script
	├── LICENSE                                                 # MIT License
	└── README.md                                               # Documentation
```