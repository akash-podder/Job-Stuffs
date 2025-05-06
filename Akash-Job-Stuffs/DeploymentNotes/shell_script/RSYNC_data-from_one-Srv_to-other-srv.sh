#!/bin/bash

# -------------------------------------------
# | Script Created By: Adib Akhtab Faruquee |
# | Script Created at: 04-05-2025 09:00 AM  |
# -------------------------------------------

# Base path definition
BASE_PATH="/path_1/path_2"

# Define an array of folder paths and their corresponding RSYNC sources
declare -A FOLDERS_AND_SOURCES=(
    ["DIR_NAME"]="/etc /var/spool/cron /var/log /storage/script"
)

# Log file definition
LOG_FILE="/path/FILE.log"
exec > >(tee -a "$LOG_FILE") 2>&1

# Function to check and create a folder
check_and_create_folder() {
    local folder_path="$1"
    if [ -d "$folder_path" ]; then
        echo "[$(date '+%Y-%m-%d %H:%M:%S')] INFO: The folder '$folder_path' already exists."
    else
        mkdir -p "$folder_path"
        if [ $? -eq 0 ]; then
            echo "[$(date '+%Y-%m-%d %H:%M:%S')] INFO: The folder '$folder_path' has been created."
        else
            echo "[$(date '+%Y-%m-%d %H:%M:%S')] ERROR: Failed to create the folder '$folder_path'. Please check permissions."
        fi
    fi
}

# Function to execute RSYNC
execute_rsync() {
    local source="$1"
    local destination="$2"
    echo "[$(date '+%Y-%m-%d %H:%M:%S')] INFO: Starting RSYNC from '$source' to '$destination/'."
    rsync -av --progress $source "$destination/"
    if [ $? -eq 0 ]; then
        echo "[$(date '+%Y-%m-%d %H:%M:%S')] INFO: RSYNC completed successfully from '$source' to '$destination/'."
    else
        echo "[$(date '+%Y-%m-%d %H:%M:%S')] ERROR: RSYNC failed from '$source' to '$destination/'. Please check paths or permissions."
    fi
}

# Main execution loop
for folder in "${!FOLDERS_AND_SOURCES[@]}"; do
    FOLDER_PATH="$BASE_PATH/$folder"
    SOURCE_PATH="${FOLDERS_AND_SOURCES[$folder]}"
    check_and_create_folder "$FOLDER_PATH"
    execute_rsync "$SOURCE_PATH" "$FOLDER_PATH"
done