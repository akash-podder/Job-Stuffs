#!/bin/bash

# -------------------------------------------
# | Script Created By: Adib Akhtab Faruquee |
# | Script Created at: 04-05-2025 09:00 AM  |
# -------------------------------------------

# Display a warning message
clear
echo "##################################################################################################"
echo "#                                                                                                #"
echo "#                       ____    _   _   _ _____ ___ ___  _   _    _   _                          #"
echo "#                      / ___|  / \ | | | |_   _|_ _/ _ \| \ | |  | | | |                         #"
echo "#                     | |     / _ \| | | | | |  | | | | |  \| |  | | | |                         #"
echo "#                     | |___ / ___ \ |_| | | |  | | |_| | |\  |  |_| |_|                         #"
echo "#                      \____/_/   \_\___/  |_| |___\___/|_| \_|  (_) (_)                         #"
echo "#                                                                                                #"
echo "#             YOU ARE ABOUT TO EXECUTE AN LVM-INCREASING COMMAND INTO THE SYSTEM!                #"
echo "#   YOUR IP: $(hostname -I | awk '{print $1}'), LOGIN TIME: $(who -u | awk '{print $3" "$4}' | head -n 1) AND USERNAME: $(whoami) HAVE BEEN NOTED AND   #"
echo "#                              SENT TO THE SERVER ADMINISTRATOR!                                 #"
echo "##################################################################################################"
echo ""

# Show current disk layout
echo "Checking current disk layout..."
lsblk
echo ""

echo "Checking for package updates..."
if ! yum check-update &>/dev/null; then
    echo "System is already up-to-date."
else
    yum update -y
fi
echo ""

echo "Checking required packages..."
for pkg in cloud-utils-growpart gdisk; do
    if ! rpm -q $pkg &>/dev/null; then
        echo "Installing $pkg..."
        yum -y install $pkg
    else
        echo "$pkg is already installed."
    fi
done
echo ""

# Show current partition info
echo "Current partition layout:"
lsblk | grep 'vda'
echo ""

# Expand partition
echo "Expanding partition /dev/vda3..."
sudo growpart /dev/vda 3
echo ""

# Show updated partition info
echo "Updated partition layout:"
lsblk | grep 'vda'
echo ""

# Display available Logical Volumes and Volume Groups
echo "Fetching available Logical Volumes..."
lvs --noheadings -o lv_name,vg_name | awk '{print NR". LV: "$1", VG: "$2}'
echo ""

# Store available LVs and VGs
mapfile -t LV_LIST < <(lvs --noheadings -o lv_name,vg_name --separator="," | sed 's/^ *//')

while true; do
    # Ask if user wants to modify LV
    read -p "Do you want to modify an LV size? (YES/NO): " choice
    if [[ "$choice" != "YES" ]]; then
        break
    fi

    # Show available LVs again
    echo ""
    echo "Available Logical Volumes:"
    for i in "${!LV_LIST[@]}"; do
        echo "$((i+1)). LV: ${LV_LIST[$i]//,/ in VG: }"
    done
    echo ""

    # Ask user which LV to modify
    read -p "Enter the number of the LV you want to modify: " lv_choice

    # Validate input
    if ! [[ "$lv_choice" =~ ^[0-9]+$ ]] || (( lv_choice < 1 || lv_choice > ${#LV_LIST[@]} )); then
        echo "Invalid choice. Please enter a valid number."
        continue
    fi

    # Get LV and VG names
    LV_NAME=$(echo "${LV_LIST[$((lv_choice-1))]}" | cut -d, -f1)
    VG_NAME=$(echo "${LV_LIST[$((lv_choice-1))]}" | cut -d, -f2)
    LV_PATH="/dev/$VG_NAME/$LV_NAME"

    echo "Selected LV: $LV_PATH"

    # Ask for size increase or use all free space
    read -p "Enter size increase for $LV_NAME (e.g., +20G) or type 'MAX' to use all remaining free space: " size

    # Check if user wants to use all remaining free space
    if [[ "$size" == "MAX" ]]; then
        echo "Using all remaining free space for $LV_PATH..."
        sudo lvextend -l +100%FREE "$LV_PATH"
    else
        echo "Extending $LV_PATH by $size..."
        sudo lvextend -L "$size" "$LV_PATH"
    fi
    echo ""

    # Resize filesystem based on type
    FS_TYPE=$(blkid -o value -s TYPE "$LV_PATH")

    case "$FS_TYPE" in
        xfs)
            echo "Resizing XFS filesystem on $LV_PATH..."
            sudo xfs_growfs "$LV_PATH"
            ;;
        ext4)
            echo "Resizing EXT4 filesystem on $LV_PATH..."
            sudo resize2fs "$LV_PATH"
            ;;
        swap)
            echo "Modifying SWAP size..."
            sudo swapoff -v "$LV_PATH"
            sudo mkswap "$LV_PATH"
            sudo swapon -v "$LV_PATH"
            ;;
        *)
            echo "Unknown filesystem type: $FS_TYPE. Manual resizing may be required."
            ;;
    esac
    echo ""

    # Show updated LV info
    echo "Updated partition layout:"
    lsblk | grep "$VG_NAME"
    echo ""

    # Ask if user wants to modify another LV
    read -p "Do you want to modify another LV? (YES/NO): " modify_more
    if [[ "$modify_more" != "YES" ]]; then
        break
    fi
done

# Display final disk usage
echo "Final disk usage summary:"
lsblk
echo ""