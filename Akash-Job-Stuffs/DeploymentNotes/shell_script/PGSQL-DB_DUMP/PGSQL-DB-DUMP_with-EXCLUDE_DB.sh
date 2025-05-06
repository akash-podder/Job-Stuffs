#!/bin/bash

# -------------------------------------------
# | Script Created By: Adib Akhtab Faruquee |
# | Script Created at: 04-05-2025 09:00 AM  |
# -------------------------------------------

# Configuration
RETENTION_DAYS=6
PSQL_PATH="psql"
PG_USER="postgres"
PG_DUMP_PATH="pg_dump"
BACKUP_DIR="/path/DB_Postgres/Postgres-DB-Dump"
EXCLUDE_DATABASES=("postgres" "test_adib_sys_2" "test_adib_sys" "test_test")

LOG_FILE="$BACKUP_DIR/backup_log.txt"
PROCESS_START_TIME=$(date +'%d-%m-%Y %H:%M:%S %p')

# Get current date
CURRENT_DATE=$(date +'%Y-%m-%d')

# Ensure required commands exist
for cmd in $PSQL_PATH $PG_DUMP_PATH gzip; do
    if ! command -v $cmd &> /dev/null; then
        echo "[ERROR] Required command '$cmd' is missing! Exiting..." | tee -a "$LOG_FILE"
        exit 1
    fi
done

# Ensure backup directory exists
if [ ! -d "$BACKUP_DIR" ]; then
    echo "[INFO] Backup directory not found. Creating: $BACKUP_DIR" | tee -a "$LOG_FILE"
    mkdir -p "$BACKUP_DIR" || { echo "[ERROR] Failed to create backup directory! Exiting..." | tee -a "$LOG_FILE"; exit 1; }
fi

# Clear the log file before writing new results
> "$LOG_FILE"

echo "[INFO] BACKUP PROCESS STARTED AT $PROCESS_START_TIME" | tee -a "$LOG_FILE"
echo "" | tee -a "$LOG_FILE"

# Remove backups older than retention period
find "$BACKUP_DIR" -type f -name "*.sql.gz" -mtime +$RETENTION_DAYS -exec rm -f {} \;

# Retrieve list of databases excluding template databases
databases=$(sudo -u $PG_USER $PSQL_PATH -d postgres -t -c "SELECT datname FROM pg_database WHERE datistemplate = false;")
if [ -z "$databases" ]; then
    echo "[ERROR] No databases found! Exiting..." | tee -a "$LOG_FILE"
    exit 1
fi

# Loop through each database and back it up
for db in $databases; do
    db=$(echo $db | tr -d ' ')  # Trim whitespace

    # Check if database is in the exclude list
    if [[ " ${EXCLUDE_DATABASES[@]} " =~ " ${db} " ]]; then
        echo "[INFO] Skipping database: $db" | tee -a "$LOG_FILE"
        continue
    fi

    if [ -n "$db" ]; then
        echo "[INFO] Backing up database: $db" | tee -a "$LOG_FILE"
        start_time=$(date +'%Y-%m-%d %H:%M:%S')
        echo "[INFO] $db DUMP STARTED AT: $start_time" >> "$LOG_FILE"

        # Perform database dump
        if sudo -u $PG_USER $PG_DUMP_PATH -d "$db" -F c -f "$BACKUP_DIR/${db}_${CURRENT_DATE}.sql"; then
            gzip "$BACKUP_DIR/${db}_${CURRENT_DATE}.sql"
            end_time=$(date +'%Y-%m-%d %H:%M:%S')
            echo "[INFO] $db DUMP COMPLETED AT: $end_time" >> "$LOG_FILE"
        else
            echo "[ERROR] FAILED TO DUMP DATABASE: $db" | tee -a "$LOG_FILE"
        fi
    fi
done

echo "" | tee -a "$LOG_FILE"

PROCESS_END_TIME=$(date +'%d-%m-%Y %H:%M:%S %p')
echo "[INFO] BACKUP PROCESS COMPLETED AT $PROCESS_END_TIME" | tee -a "$LOG_FILE"