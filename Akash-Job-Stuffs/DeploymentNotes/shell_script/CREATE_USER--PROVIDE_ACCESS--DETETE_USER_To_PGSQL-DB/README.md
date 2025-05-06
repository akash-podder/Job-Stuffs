# 🔥 PostgreSQL User Access Management Script

[![Shell](https://img.shields.io/badge/Shell-Bash-brightgreen?logo=gnu-bash&logoColor=white)](https://www.gnu.org/software/bash/)
[![Status](https://img.shields.io/badge/status-stable-success.svg)](https://github.com/adibakhtab007/shell_script)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](./LICENSE)
[![Last Commit](https://img.shields.io/github/last-commit/adibakhtab007/shell_script.svg)](https://github.com/adibakhtab007/shell_script/commits/main)

This Bash script provides an interactive CLI tool to **manage PostgreSQL users** and their **SELECT-level access** to databases, schemas, and tables. It is designed for database administrators and DevOps engineers who need a streamlined way to create new users or assign access to existing users on PostgreSQL servers.

---

## 📜 Script Details

- **Script Name:** `PGSQL-DB-CREATE_NEW_USER_ACCESS_AT_DB-OR-PROVIDE_EXISTING_USER_ACCESS_AT_DB.sh`
- **Author:** _Adib Akhtab Faruquee_
- **Created On:** _04-05-2025 at 09:00 AM_
- **Supported Environments:** Unix-based systems with PostgreSQL
- **Required Access:** The script runs with `sudo` privileges under the `postgres` user.

---

## 🎯 Features

✅ **List Existing Users**  
✅ **Create a New Superuser**  
✅ **Create a New Normal User**  
✅ **Grant SELECT Access to All Tables in a Schema**  
✅ **Grant SELECT Access to a Specific Table**  
✅ **Support for Existing User Access Provisioning**

---

## 📦 Script Structure & Workflow

Upon running the script, you will be guided through a **step-by-step prompt-based workflow**:

### 🛠️ Option 1: Create a New User
- **(A)** Create a Superuser
- **(B)** Create a Normal User
  - **(i)** Access to all tables in a selected schema
  - **(ii)** Access to a specific table

### 🛡️ Option 2: Provide Access to an Existing User
- **(i)** SELECT access to all tables in a schema
- **(ii)** SELECT access to a specific table

---

## 🔐 Access Control Logic

### 🔸 Superuser Creation
Grants full access using:
```sql
CREATE USER <username> WITH ENCRYPTED PASSWORD '<password>';
ALTER USER <username> WITH SUPERUSER;
```

### 🔹 Normal User (All Tables)
Grants:
- Database connection
- Schema usage
- SELECT on all tables and sequences

### 🔹 Normal User (Specific Table)
Grants:
- Database connection
- Schema usage
- SELECT on a specific table

---

## 🧠 Example Use Cases

1. **DevOps automation for onboarding developers**
2. **DBA task delegation with limited access**
3. **Production access provisioning with read-only rights**

---

## ▶️ How to Run

```bash
chmod +x PGSQL-DB-CREATE_NEW_USER_ACCESS_AT_DB-OR-PROVIDE_EXISTING_USER_ACCESS_AT_DB.sh
./PGSQL-DB-CREATE_NEW_USER_ACCESS_AT_DB-OR-PROVIDE_EXISTING_USER_ACCESS_AT_DB.sh
```

> You must have `sudo` privileges and PostgreSQL installed with access to the `postgres` system user.

---

## 📤 Example Outputs

See [`PGSQL-DB-User-Actions-Example-Outputs.md`](./PGSQL-DB-User-Actions-Example-Outputs.md) for a detailed log of sample script executions.

The file demonstrates:
- Creating superuser and normal users
- Granting access to all or specific tables
- Assigning access for existing users

---

# 🔥 PostgreSQL User Deletion & Access Revocation Script

This script allows administrators to **delete PostgreSQL users entirely from all databases** or **revoke access from a single database** while ensuring ownership reassignment and data safety.

---

## 📜 Script Details

- **Script Name:** _`PGSQL-DB-DELETE_USER_OR_REVOKE_DB_ACCESS.sh`_
- **Author:** _Adib Akhtab Faruquee_
- **Created On:** _04-05-2025 at 09:00 AM_
- **Supported Environments:** Unix-based systems with PostgreSQL
- **Required Access:** The script runs with `sudo` privileges under the `postgres` user.

---

## 🎯 Features

✅ List existing users  
✅ Reassign and drop user-owned objects  
✅ Delete user from all databases  
✅ Revoke user access from a specific database  
✅ Interactive CLI-based user input

---

## 📦 Script Structure & Workflow

When executed, this script provides the following options:

### Option 1: Delete User from All Databases
- Lists existing PostgreSQL users.
- Iterates over all non-template databases.
- Reassigns and drops all objects owned by the user.
- Deletes the user role from the PostgreSQL cluster.

### Option 2: Revoke User Access from a Specific Database
- Lists all users and databases.
- Reassigns and drops user-owned objects from the selected database.
- Does **not** delete the user globally.

---

## 🧠 Example Use Cases

- Cleanly remove deprecated or inactive users across all DBs.
- Ensure ownership reassignment before deletion to prevent orphaned objects.
- Revoke access without dropping the global user role.

---

## ▶️ How to Run

```bash
chmod +x PGSQL-DB-DELETE_USER_OR_REVOKE_DB_ACCESS.sh
./PGSQL-DB-DELETE_USER_OR_REVOKE_DB_ACCESS.sh
```

> You must have `sudo` privileges and PostgreSQL installed with access to the `postgres` system user.

---

## 📤 Example Outputs

```
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
```

---

## 📄 License

Both scripts are distributed under the MIT License. See `LICENSE` for details.

---

## 📁 Directory Structure

```
.
├── PGSQL-DB-CREATE_NEW_USER_ACCESS_AT_DB-OR-PROVIDE_EXISTING_USER_ACCESS_AT_DB.sh
├── PGSQL-DB-DELETE_USER_OR_REVOKE_DB_ACCESS.sh
├── PGSQL-DB-User-Actions-Example-Outputs.md
└── README.md
```

---

## 🤝 Contributions

Pull requests, issues, and suggestions are welcome for both scripts. Please open an issue to discuss improvements or bugs before submitting a PR.

---

## 📧 Contact

_**Adib Akhtab Faruquee**_  
_Senior System Engineer_  
_Systems Network & Security Team, Engineering_  
Reach out via GitHub for questions or collaboration opportunities.