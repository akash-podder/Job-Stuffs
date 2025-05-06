#!/bin/bash

# -------------------------------------------
# | Script Created By: Adib Akhtab Faruquee |
# | Script Created at: 04-05-2025 09:00 AM  |
# -------------------------------------------

clear
echo "################################################################################################"
echo "#                                                                                              #"
echo "#                       ____    _   _   _ _____ ___ ___  _   _    _   _                        #"
echo "#                      / ___|  / \ | | | |_   _|_ _/ _ \| \ | |  | | | |                       #"
echo "#                     | |     / _ \| | | | | |  | | | | |  \| |  | | | |                       #"
echo "#                     | |___ / ___ \ |_| | | |  | | |_| | |\  |  |_| |_|                       #"
echo "#                      \____/_/   \_\___/  |_| |___\___/|_| \_|  (_) (_)                       #"
echo "#                                                                                              #"
echo "#                                                                                              #"
echo "#                    YOU ARE ABOUT TO EXECUTE A COMMAND INTO THE DATABASE!                     #"
echo "#   YOUR IP: $(hostname -I | awk '{$1=$1};1'), LOGIN TIME: $(who -u | awk '{print $3, $4}') AND USERNAME: $(whoami) HAVE BEEN NOTED AND   #"
echo "#                              SENT TO THE SERVER ADMINISTRATOR!                               #"
echo "################################################################################################"
echo ""
echo "NOW, CHOOSE FROM THE OPTIONS BELOW WHAT YOU WANT TO DO:"
echo "(1). DELETE A USER FROM ALL DATABASES"
echo "(2). DELETE A USER FROM A SINGLE DATABASE"
read -p "ENTER YOUR CHOICE (1 or 2): " choice

# Fetch and display the user list
user_list=$(sudo -u postgres -i psql -t -c "SELECT '[' || string_agg(usename, ', ') || ']' FROM pg_user;")

if [[ "$choice" == "1" ]]; then
    echo ""
    echo "AS YOU HAVE CHOSEN TO DELETE A USER FROM ALL DATABASES, PLEASE PROVIDE YOUR DELETED DB USER NAME."
    echo "USERNAME LIST: $user_list"
    echo ""
    read -p "USERNAME: " username

    # Fetch all databases
    databases=$(sudo -u postgres -i psql -d postgres -t -c "SELECT datname FROM pg_database WHERE datistemplate = false;" | awk '{$1=$1};1')

    for db in $databases; do
        echo ""
        echo "Executing deletion in database: $db"
        sudo -u postgres -i psql -d "$db" -c "REASSIGN OWNED BY $username TO postgres;"
        sudo -u postgres -i psql -d "$db" -c "DROP OWNED BY $username;"
    done

    # Drop user globally
    sudo -u postgres -i psql -d postgres -c "DROP USER $username;"
    echo ""
    echo "User '$username' has been droped from databases."
    echo ""

elif [[ "$choice" == "2" ]]; then
    echo ""
    echo "AS YOU HAVE CHOSEN TO DELETE A USER FROM A SINGLE DATABASE, PLEASE PROVIDE YOUR DELETED DB USER NAME."
    echo "USERNAME LIST: $user_list"
    echo ""
    read -p "USERNAME: " username

    # Fetch and display databases
    databases_list=$(sudo -u postgres -i psql -t -c "SELECT '[' || string_agg(datname, ', ') || ']' FROM pg_database WHERE datistemplate = false;")
    echo ""
    echo "DATABASE LIST: $databases_list"
    echo ""
    read -p "SELECT THE DATABASE FROM THE LIST: " db_choice

    # Run commands on the chosen database
    echo ""
    echo "Executing deletion in database: $db_choice"
    sudo -u postgres -i psql -d "$db_choice" -c "REASSIGN OWNED BY $username TO postgres;"
    sudo -u postgres -i psql -d "$db_choice" -c "DROP OWNED BY $username;"
    echo ""
    echo "User '$username' access has been removed from database '$db_choice'."
    echo ""

else
    echo "Invalid choice! Exiting..."
fi