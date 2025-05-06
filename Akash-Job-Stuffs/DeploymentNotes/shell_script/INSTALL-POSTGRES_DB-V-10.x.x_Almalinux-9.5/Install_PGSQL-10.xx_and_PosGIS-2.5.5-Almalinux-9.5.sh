#!/bin/bash

# -------------------------------------------
# | Script Created By: Adib Akhtab Faruquee |
# | Script Created at: 04-05-2025 09:00 AM  |
# -------------------------------------------

set -e  # Exit immediately if a command exits with a non-zero status
set -o pipefail  # Catch pipeline errors
set -u  # Treat unset variables as an error

log_file="/var/log/install_postgis.log"
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
execute_command "yum update -y"

# Install dependencies
execute_command "sudo dnf install -y gcc gcc-c++ make cmake readline-devel zlib-devel bzip2 bzip2-devel geos-devel postgresql-devel libxml2-devel sqlite sqlite-devel libtiff-devel libcurl-devel expat-devel"

# Navigate to source directory
execute_command "cd /usr/local/src/"

# Download required source files
execute_command "wget -q --show-progress https://ftp.postgresql.org/pub/source/v10.20/postgresql-10.20.tar.bz2"
execute_command "wget -q --show-progress http://download.osgeo.org/proj/proj-datumgrid-1.8.zip"
execute_command "wget -q --show-progress http://download.osgeo.org/proj/proj-6.3.2.tar.gz"
execute_command "wget -q --show-progress https://download.osgeo.org/postgis/source/postgis-2.5.5.tar.gz"
execute_command "wget -q --show-progress https://github.com/OSGeo/gdal/releases/download/v3.0.4/gdal-3.0.4.tar.gz"

# Extract downloaded files
execute_command "tar -xvjf postgresql-10.20.tar.bz2"
execute_command "unzip proj-datumgrid-1.8.zip"
execute_command "tar -xvzf proj-6.3.2.tar.gz"
execute_command "tar -xvzf postgis-2.5.5.tar.gz"
execute_command "tar -xvzf gdal-3.0.4.tar.gz"

# Compile and install PostgreSQL
execute_command "cd postgresql-10.20 && ./configure --prefix=/usr/local/pgsql"
execute_command "make -j$(nproc)"
execute_command "make install"

# Setup PostgreSQL user and data directory
execute_command "mkdir -p /var/lib/pgsql/10/data"
execute_command "useradd postgres || true"
execute_command "chown -R postgres:postgres /var/lib/pgsql"

# Initialize and start PostgreSQL as postgres user
execute_command "su - postgres -c '/usr/local/pgsql/bin/initdb -D /var/lib/pgsql/10/data'"
execute_command "su - postgres -c '/usr/local/pgsql/bin/pg_ctl -D /var/lib/pgsql/10/data start'"
execute_command "su - postgres -c '/usr/local/pgsql/bin/pg_ctl -D /var/lib/pgsql/10/data status'"

# Compile and install PROJ
execute_command "cd /usr/local/src/proj-6.3.2 && ./configure --prefix=/usr/local"
execute_command "make -j$(nproc)"
execute_command "make install"

# Compile and install GDAL
execute_command "cd /usr/local/src/gdal-3.0.4/ && ./configure --with-proj=/usr/local"

# Modify source file to include missing header
execute_command "sed -i '41i #include <limits>\n' /usr/local/src/gdal-3.0.4/ogr/ogrsf_frmts/cad/libopencad/dwg/r2000.cpp"

execute_command "make -j$(nproc)"
execute_command "make install"

# Compile and install PostGIS
execute_command "cd /usr/local/src/postgis-2.5.5/ && ./configure --with-pgconfig=/usr/local/pgsql/bin/pg_config --with-projdir=/usr/local --with-gdalconfig=/usr/local/bin/gdal-config"
execute_command "make -j$(nproc)"
execute_command "make install"
execute_command "echo "/usr/local/lib" > /etc/ld.so.conf.d/postgis.conf"
execute_command "ldconfig"
execute_command "ldconfig -p | grep libproj"

# Install PostGIS-2.5.5
execute_command "su - postgres -c \"/usr/local/pgsql/bin/psql -c 'CREATE EXTENSION postgis;'\""
execute_command "su - postgres -c \"/usr/local/pgsql/bin/psql -c 'SELECT postgis_version();'\""

echo "[SUCCESS] Installation completed successfully at $(date)"