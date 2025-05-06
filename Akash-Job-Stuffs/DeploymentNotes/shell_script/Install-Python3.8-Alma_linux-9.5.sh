#!/bin/bash

# -------------------------------------------
# | Script Created By: Adib Akhtab Faruquee |
# | Script Created at: 04-05-2025 09:00 AM  |
# -------------------------------------------

set -e  # Exit immediately if a command exits with a non-zero status
set -o pipefail  # Catch pipeline errors
set -u  # Treat unset variables as an error

log_file="/var/log/install_python38.log"
exec > >(tee -a "$log_file") 2>&1

echo "[SUCCESS] Installation started at $(date)"

handle_error() {
    echo "[ERROR] Command failed at line $1: $2"
    exit 1
}
trap 'handle_error $LINENO "$BASH_COMMAND"' ERR

execute_command() {
    echo "[INFO] Running: $1"
    eval "$1" && echo "[SUCCESS] Completed: $1" || handle_error $LINENO "$1"
}

# Update system
execute_command 'dnf groupinstall -y "Development Tools"'

# Install dependencies
execute_command "dnf install -y gcc gcc-c++ make zlib-devel bzip2 bzip2-devel readline-devel sqlite sqlite-devel openssl-devel tk-devel libffi-devel xz-devel"

# Navigate to source directory
cd /usr/local/src/ || exit 1

# Download required source files
execute_command "curl -O https://www.python.org/ftp/python/3.8.20/Python-3.8.20.tgz"

# Extract downloaded files
execute_command "tar xzf Python-3.8.20.tgz"

# Compile and install Python-3.8.20
cd Python-3.8.20 || exit 1
execute_command "./configure --enable-optimizations"
execute_command "make -j$(nproc)"
execute_command "make altinstall"

# Set Python 3.8 as default
execute_command "alternatives --install /usr/bin/python3 python3 /usr/local/bin/python3.8 1"
execute_command "echo 1 | alternatives --config python3"  # Auto-select Python 3.8

# Verify python3 installation
execute_command "python3 --version"

# Install pip
execute_command "/usr/local/bin/python3.8 -m ensurepip"
execute_command "/usr/local/bin/python3.8 -m pip install --upgrade pip"

# Ensure /usr/local/bin is in PATH
execute_command "echo 'export PATH=\"/usr/local/bin:\$PATH\"' >> ~/.bashrc"
execute_command "echo 'export PATH=\"/usr/local/bin:\$PATH\"' >> ~/.profile"

# Apply changes immediately for the script
export PATH="/usr/local/bin:$PATH"

# Verify pip3 works
execute_command "pip3 --version"

echo "[SUCCESS] Installation completed successfully at $(date)"