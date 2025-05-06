#!/bin/bash

# -------------------------------------------
# | Script Created By: Adib Akhtab Faruquee |
# | Script Created at: 04-05-2025 09:00 AM  |
# -------------------------------------------

DATE=$(date +'%y%m%d_%H%M')
BACKUP_DIR="/path/DB_Mysql/Mysql-DB-Dump"
LOG_FILE="$BACKUP_DIR/mysqldump_log.txt"

MYSQL_USER="adib"
MYSQL_PASS="Y0u#R@Pa$sw0rd"

echo "-- Mysql dump started at $(date) --" > "$LOG_FILE"

# Fetch all database names except system databases
DATABASES=$(mysql -u "$MYSQL_USER" -p"$MYSQL_PASS" -e "SHOW DATABASES;" 2>/dev/null | grep -Ev "Database|information_schema|performance_schema|mysql|sys|adib_test|pitr_new|test_dwh|test_slave")

for DB in $DATABASES; do
    echo "Dumping $DB schema at $(date)" >> "$LOG_FILE"

    # Dump the database
    DUMP_FILE="$BACKUP_DIR/$DB-${DATE}.sql"
    mysqldump -u "$MYSQL_USER" -p"$MYSQL_PASS" --single-transaction "$DB" 2>/dev/null > "$DUMP_FILE"

    # Get file size before compression
    du -sh "$DUMP_FILE" >> "$LOG_FILE"

    # Compress the dump file immediately
    gzip "$DUMP_FILE"

    echo "Compressed: $DUMP_FILE.gz" >> "$LOG_FILE"
done

echo "-- Mysql dump ended at $(date) --" >> "$LOG_FILE"

# Cleanup old backups (older than 6 days)
find "$BACKUP_DIR" -name "*.sql.gz" -mtime +6 -exec rm {} \;