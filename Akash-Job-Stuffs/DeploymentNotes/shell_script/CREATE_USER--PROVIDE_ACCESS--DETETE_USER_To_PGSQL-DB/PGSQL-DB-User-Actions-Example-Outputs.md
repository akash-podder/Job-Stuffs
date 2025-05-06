# 📤 Example Outputs

This document shows sample outputs for each major action performed by the `PGSQL-DB-CREATE_NEW_USER_ACCESS_AT_DB-OR-PROVIDE_EXISTING_USER_ACCESS_AT_DB.sh` script.

---

## 🟢 Create Superuser

```
AS YOU HAVE CHOSEN TO CREATE A SUPERUSER, PLEASE PROVIDE THE BELOW INFO.
USERNAME: admin_adib
PASSWORD: ********

Creating superuser admin_adib...
CREATE ROLE
ALTER ROLE

admin_adib USER CREATED WITH SUPERUSER ACCESS.
```

---

## 🟢 Create Normal User with Access to All Tables

```
AS YOU HAVE CHOSEN TO CREATE A NORMAL USER, PLEASE PROVIDE THE BELOW INFO.
UserName: readonly_rahim
Password: ********

DATABASE LIST: [app_db, test_db, analytics]
DataBase: app_db

SCHEMA LIST: [public]
Schema: public

Creating normal user readonly_rahim with access to all tables in app_db...
CREATE ROLE
GRANT
GRANT
GRANT
GRANT

readonly_rahim USER CREATED WITH SELECT ACCESS.
```

---

## 🟢 Create Normal User with Access to Single Table

```
AS YOU HAVE CHOSEN TO CREATE A NORMAL USER, PLEASE PROVIDE THE BELOW INFO.
UserName: user_mina
Password: ********

DATABASE LIST: [app_db, test_db, analytics]
DataBase: analytics

SCHEMA LIST: [reporting]
Schema: reporting

TABLE LIST: [sales_summary, customer_data, revenue]
Table: sales_summary

Creating normal user user_mina with access to table sales_summary in analytics...
CREATE ROLE
GRANT
GRANT
GRANT

user_mina USER CREATED WITH SELECT ACCESS ON reporting.sales_summary.
```

---

## 🟢 Grant Access to Existing User for All Tables

```
AS YOU HAVE CHOSEN TO PROVIDE ACCESS TO AN EXISTING USER, PLEASE PROVIDE THE BELOW INFO.
EXISTING USERS LIST...

EXISTING USERS: [admin_adib, readonly_rahim, user_mina]

UserName: readonly_rahim

DATABASE LIST: [app_db, test_db, analytics]
DataBase: analytics

SCHEMA LIST: [reporting]
Schema: reporting

Providing access to user readonly_rahim for all tables in analytics...
GRANT
GRANT
GRANT
GRANT

readonly_rahim NOW HAS ACCESS TO ALL TABLES IN reporting.
```

---

## 🟢 Grant Access to Existing User for Single Table

```
AS YOU HAVE CHOSEN TO PROVIDE ACCESS TO AN EXISTING USER, PLEASE PROVIDE THE BELOW INFO.
EXISTING USERS LIST...

EXISTING USERS: [admin_adib, readonly_rahim, user_mina]

UserName: user_mina

DATABASE LIST: [app_db, test_db, analytics]
DataBase: analytics

SCHEMA LIST: [reporting]
Schema: reporting

TABLE LIST: [sales_summary, customer_data, revenue]
Table: customer_data

Creating normal user user_mina with access to table customer_data in analytics...
GRANT
GRANT
GRANT

user_mina NOW HAS ACCESS TO ALL TABLES ON reporting.customer_data.
```