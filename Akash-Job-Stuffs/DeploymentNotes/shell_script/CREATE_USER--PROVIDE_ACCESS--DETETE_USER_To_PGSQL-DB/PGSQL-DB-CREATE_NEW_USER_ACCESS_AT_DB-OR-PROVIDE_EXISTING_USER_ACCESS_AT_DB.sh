#!/bin/bash

# -------------------------------------------
# | Script Created By: Adib Akhtab Faruquee |
# | Script Created at: 04-05-2025 09:00 AM  |
# -------------------------------------------

# Function to list existing users
list_existing_users() {
    echo "EXISTING USERS LIST..."
    echo ""
    USER_LIST=$(sudo -u postgres -i psql -t -c "SELECT '[' || string_agg(usename, ', ') || ']' FROM pg_user;")
    echo "EXISTING USERS: $USER_LIST"
    echo ""
}

# Function to create a superuser
create_superuser() {
    echo ""
    echo "AS YOU HAVE CHOSEN TO CREATE A SUPERUSER, PLEASE PROVIDE THE BELOW INFO."
    read -p "USERNAME: " username
    read -p "PASSWORD: " password

    echo "Creating superuser $username..."
    sudo -u postgres -i psql -c "CREATE USER $username WITH ENCRYPTED PASSWORD '$password';"
    sudo -u postgres -i psql -c "ALTER USER $username WITH SUPERUSER;"
    echo ""
    echo "$username USER CREATED WITH SUPERUSER ACCESS."
    echo ""
}

# Function to create a normal user with access to all tables
option_1_choose_B_choose_i() {
    echo ""
    echo "AS YOU HAVE CHOSEN TO CREATE A NORMAL USER, PLEASE PROVIDE THE BELOW INFO."
    read -p "UserName: " username
    read -p "Password: " password
    echo ""

    DB_LIST=$(sudo -u postgres -i psql -t -c "SELECT '[' || string_agg(datname, ', ') || ']' FROM pg_database WHERE datistemplate = false;")
    echo "DATABASE LIST: $DB_LIST"
    echo ""
    read -p "DataBase: " database
    echo ""

    SCHEMA_LIST=$(sudo -u postgres -i psql -d "$database" -t -c "SELECT '[' || string_agg(schema_name, ', ') || ']' FROM information_schema.schemata WHERE schema_name NOT LIKE 'pg_%' AND schema_name != 'information_schema';")
    echo "SCHEMA LIST: $SCHEMA_LIST"
    echo ""
    read -p "Schema: " schema

    echo "Creating normal user $username with access to all tables in $database..."
    sudo -u postgres -i psql -d "$database" -c "CREATE USER $username WITH ENCRYPTED PASSWORD '$password';"
    sudo -u postgres -i psql -d "$database" -c "GRANT CONNECT ON DATABASE $database TO $username;"
    sudo -u postgres -i psql -d "$database" -c "GRANT USAGE ON SCHEMA $schema TO $username;"
    sudo -u postgres -i psql -d "$database" -c "GRANT SELECT ON ALL TABLES IN SCHEMA $schema TO $username;"
    sudo -u postgres -i psql -d "$database" -c "GRANT SELECT ON ALL SEQUENCES IN SCHEMA $schema TO $username;"
    echo ""
    echo "$username USER CREATED WITH SELECT ACCESS."
    echo ""
}

# Function to create a normal user with access to a single table
option_1_choose_B_choose_ii() {
    echo ""
    echo "AS YOU HAVE CHOSEN TO CREATE A NORMAL USER, PLEASE PROVIDE THE BELOW INFO."
    read -p "UserName: " username
    read -p "Password: " password
    echo ""

    # Fetch and display database list
    DB_LIST=$(sudo -u postgres -i psql -t -c "SELECT '[' || string_agg(datname, ', ') || ']' FROM pg_database WHERE datistemplate = false;")
    echo "DATABASE LIST: $DB_LIST"
    echo ""
    read -p "DataBase: " database
    echo ""

    # Fetch and display schema list for the selected database
    SCHEMA_LIST=$(sudo -u postgres -i psql -d "$database" -t -c "SELECT '[' || string_agg(schema_name, ', ') || ']' FROM information_schema.schemata WHERE schema_name NOT LIKE 'pg_%' AND schema_name != 'information_schema';")
    echo "SCHEMA LIST: $SCHEMA_LIST"
    echo ""
    read -p "Schema: " schema
    echo ""

    # Fetch and display table list for the selected schema
    TABLE_LIST=$(sudo -u postgres -i psql -d "$database" -t -c "SELECT '[' || string_agg(table_name, ', ') || ']' FROM information_schema.tables WHERE table_schema = '$schema';")
    echo "TABLE LIST: $TABLE_LIST"
    echo ""
    read -p "Table: " table
    echo ""

    # SQL command to create normal user with access to a single table
    echo "Creating normal user $username with access to table $table in $database..."
    sudo -u postgres -i psql -d "$database" -c "CREATE USER $username WITH ENCRYPTED PASSWORD '$password';"
    sudo -u postgres -i psql -d "$database" -c "GRANT CONNECT ON DATABASE $database TO $username;"
    sudo -u postgres -i psql -d "$database" -c "GRANT USAGE ON SCHEMA $schema TO $username;"
    sudo -u postgres -i psql -d "$database" -c "GRANT SELECT ON TABLE $schema.$table TO $username;"
    echo ""
    echo "$username USER CREATED WITH SELECT ACCESS ON $schema.$table."
    echo ""
}

# Function to provide access to an existing user for all tables
option_2_choose_i() {
    echo ""
    echo "AS YOU HAVE CHOSEN TO PROVIDE ACCESS TO AN EXISTING USER, PLEASE PROVIDE THE BELOW INFO."
    list_existing_users
    read -p "UserName: " username
    echo ""

    DB_LIST=$(sudo -u postgres -i psql -t -c "SELECT '[' || string_agg(datname, ', ') || ']' FROM pg_database WHERE datistemplate = false;")
    echo "DATABASE LIST: $DB_LIST"
    echo ""
    read -p "DataBase: " database
    echo ""

    SCHEMA_LIST=$(sudo -u postgres -i psql -d "$database" -t -c "SELECT '[' || string_agg(schema_name, ', ') || ']' FROM information_schema.schemata WHERE schema_name NOT LIKE 'pg_%' AND schema_name != 'information_schema';")
    echo "SCHEMA LIST: $SCHEMA_LIST"
    echo ""
    read -p "Schema: " schema

    echo "Providing access to user $username for all tables in $database..."
    sudo -u postgres -i psql -d "$database" -c "GRANT CONNECT ON DATABASE $database TO $username;"
    sudo -u postgres -i psql -d "$database" -c "GRANT USAGE ON SCHEMA $schema TO $username;"
    sudo -u postgres -i psql -d "$database" -c "GRANT SELECT ON ALL TABLES IN SCHEMA $schema TO $username;"
    sudo -u postgres -i psql -d "$database" -c "GRANT SELECT ON ALL SEQUENCES IN SCHEMA $schema TO $username;"
    echo ""
    echo "$username NOW HAS ACCESS TO ALL TABLES IN $schema."
    echo ""
}

# Function to provide access to an existing user for single table
option_2_choose_ii() {
    echo ""
    echo "AS YOU HAVE CHOSEN TO PROVIDE ACCESS TO AN EXISTING USER, PLEASE PROVIDE THE BELOW INFO."
    list_existing_users
    read -p "UserName: " username

    echo ""
    # Fetch and display database list
    DB_LIST=$(sudo -u postgres -i psql -t -c "SELECT '[' || string_agg(datname, ', ') || ']' FROM pg_database WHERE datistemplate = false;")
    echo "DATABASE LIST: $DB_LIST"
    echo ""
    read -p "DataBase: " database
    echo ""

    # Fetch and display schema list for the selected database
    SCHEMA_LIST=$(sudo -u postgres -i psql -d "$database" -t -c "SELECT '[' || string_agg(schema_name, ', ') || ']' FROM information_schema.schemata WHERE schema_name NOT LIKE 'pg_%' AND schema_name != 'information_schema';")
    echo "SCHEMA LIST: $SCHEMA_LIST"
    echo ""
    read -p "Schema: " schema
    echo ""

    # Fetch and display table list for the selected schema
    TABLE_LIST=$(sudo -u postgres -i psql -d "$database" -t -c "SELECT '[' || string_agg(table_name, ', ') || ']' FROM information_schema.tables WHERE table_schema = '$schema';")
    echo "TABLE LIST: $TABLE_LIST"
    echo ""
    read -p "Table: " table
    echo ""

    # SQL command to create normal user with access to a single table
    echo "Creating normal user $username with access to table $table in $database..."
    sudo -u postgres -i psql -d "$database" -c "GRANT CONNECT ON DATABASE $database TO $username;"
    sudo -u postgres -i psql -d "$database" -c "GRANT USAGE ON SCHEMA $schema TO $username;"
    sudo -u postgres -i psql -d "$database" -c "GRANT SELECT ON TABLE $schema.$table TO $username;"
    echo ""
    echo "$username NOW HAS ACCESS TO ALL TABLES ON $schema.$table."
    echo ""
}

# Main function
main() {
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
    echo "(1). CREATE A NEW USER IN THE MASTER DATABASE."
    echo "(2). PROVIDE ACCESS TO AN EXISTING USER."
    read -p "Choose an option: " choice

    case $choice in
        1)
            echo ""
            echo "AS YOU HAVE CHOSEN TO CREATE A NEW USER, WHAT TYPE OF USER DO YOU WANT TO CREATE?"
            echo "(A). SUPERUSER"
            echo "(B). NORMAL USER"
            read -p "Choose an option (A/B): " user_type
            case $user_type in
                A|a) create_superuser ;;
                B|b)
                    echo ""
                    echo "AS YOU HAVE CHOSEN TO CREATE A NORMAL USER, WHAT TYPE OF ACCESS DO YOU WANT TO PROVIDE?"
                    echo "(i). PROVIDE ACCESS TO ALL TABLES"
                    echo "(ii). PROVIDE ACCESS TO A SINGLE TABLE"
                    read -p "Choose an option (i/ii): " access_type
                    case $access_type in
                        i|I) option_1_choose_B_choose_i ;;
                        ii|II) option_1_choose_B_choose_ii ;;
                        *) echo "Invalid option. Exiting." ;;
                    esac
                    ;;
                *) echo "Invalid option. Exiting." ;;
            esac
            ;;
        2)
            echo ""
            echo "AS YOU HAVE CHOSEN TO PROVIDE ACCESS TO AN EXISTING USER, WHAT TYPE OF ACCESS DO YOU WANT TO PROVIDE?"
            echo "(i). PROVIDE ACCESS TO ALL TABLES"
            echo "(ii). PROVIDE ACCESS TO A SINGLE TABLE"
            read -p "Choose an option (i/ii): " access_type
            case $access_type in
                i|I) option_2_choose_i ;;
                ii|II) option_2_choose_ii ;;
                *) echo "Invalid option. Exiting." ;;
            esac
            ;;
        *) echo "Invalid option. Exiting." ;;
    esac
}

# Execute the main function
main