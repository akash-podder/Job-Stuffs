#!/bin/bash

# -------------------------------------------
# | Script Created By: Adib Akhtab Faruquee |
# | Script Created at: 04-05-2025 09:00 AM  |
# -------------------------------------------

# Function to check and modify sshd_config
update_sshd_config() {
    SSHD_CONFIG="/etc/ssh/sshd_config"
    BACKUP_FILE="/etc/ssh/sshd_config.bak.$(date +%F_%T)"

    # Backup current sshd_config
    cp "$SSHD_CONFIG" "$BACKUP_FILE"

    # Define required values
    REQUIRED_VALUES=(
        "PermitRootLogin without-password"
        "PasswordAuthentication no"
        "AuthorizedKeysFile /etc/ssh/%u/authorized_keys"
    )

    # Update or comment conflicting lines
    for VALUE in "${REQUIRED_VALUES[@]}"; do
        KEY=$(echo "$VALUE" | awk '{print $1}')
        if grep -qE "^$KEY" "$SSHD_CONFIG"; then
            sed -i "s/^$KEY.*/#$&/" "$SSHD_CONFIG" # Comment out conflicting lines
        fi
        echo "$VALUE" >> "$SSHD_CONFIG"
    done

    # Check and update AllowUsers line
    if grep -q "^AllowUsers" "$SSHD_CONFIG"; then
        if ! grep -q "\b$user_variable\b" "$SSHD_CONFIG"; then
            # Add username to the existing AllowUsers line if not already present
            sed -i "/^AllowUsers/ s/$/ $user_variable/" "$SSHD_CONFIG"
        fi
    else
        # Add AllowUsers line if it doesn't exist
        echo "AllowUsers $user_variable" >> "$SSHD_CONFIG"
    fi
}

# Main script
read -p "Enter the username to create: " user_variable
read -p "Enter the public key: " public_key

# Command-1: Create user
adduser "$user_variable"

# Command-2: Set password for user
passwd "$user_variable"

# Command-3 to Command-5: Setup .ssh directory
mkdir -p /home/"$user_variable"/.ssh
chown -R "$user_variable":"$user_variable" /home/"$user_variable"
chmod 700 /home/"$user_variable"/.ssh

# Command-6: Add public key
echo "$public_key" > /home/"$user_variable"/.ssh/authorized_keys
chmod 640 /home/"$user_variable"/.ssh/authorized_keys

# Command-8 to Command-12: Additional setup for SSH
mkdir -p /etc/ssh/"$user_variable"
cp /home/"$user_variable"/.ssh/authorized_keys /etc/ssh/"$user_variable"
chmod 755 /etc/ssh/"$user_variable"
chmod 644 /etc/ssh/"$user_variable"/authorized_keys
chown -R "$user_variable":"$user_variable" /etc/ssh/"$user_variable"

# Command-13: Update sshd_config
update_sshd_config

# Command-14: Reload SSH service
service sshd reload

echo "User $user_variable has been created and configured with SSH access."