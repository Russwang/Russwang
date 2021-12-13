//
//  Dcotor_Databse.cpp
//  Teledoc
//
//  Created by Russ on 3/4/21.
//  Copyright © 2021 Russ-org. All rights reserved.
//

#include "Doctor_Database.hpp"

void createDoctorDB() {
    
    sqlite3 *DB;
    int exit = 0;
    string database = "Doctor Database 1.0";
    exit = sqlite3_open(database.c_str(), &DB);
    
    if (exit != SQLITE_OK) {
        cerr << "Create Doctor Database Error" << endl;
        return;
    } else {
        cout << "Create Doctor Database Successfully" << endl;
    }
    
    sqlite3_close(DB);

}

void createDoctorTable() {
    
    sqlite3 *DB;
    string database = "Doctor Database 1.0";
    
    string sql = "CREATE TABLE IF NOT EXISTS DOC_PROFILE("
    "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
    "NAME           TEXT    NOT NULL, "
    "SPECIALTY      TEXT    NOT NULL, "
    "LANGUAGE       TEXT    NOT NULL, "
    "EMAIL          TEXT    NOT NULL, "
    "ADDRESS        TEXT    NOT NULL, "
    "CITY           TEXT    NOT NULL, "
    "COUNTRY        TEXT    NOT NULL, "
    "REGION         TEXT    NOT NULL, "
    "ZIPCODE        TEXT    NOT NULL, "
    "PHONE_NUMBER   TEXT    NOT NULL, "
    "USERNAME   TEXT    NOT NULL, "
    "PASSWARD   TEXT    NOT NULL);";
    
    try {
        int exit = 0;
        exit = sqlite3_open(database.c_str(), &DB);
        
        char* Errermsg;
        exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &Errermsg);
        
        if (exit != SQLITE_OK) {
            cout << "Create Doctor Table Error" << endl;
            return;
        } else {
            cout << "Create Doctor Table Successfully" << endl;
        }
        sqlite3_close(DB);
    } catch (const exception & e) {
        cerr << e.what();
    }

}
void deleteDoctorData() {
    sqlite3 *DB;
    string database = "Doctor Database 1.0";
    
    sqlite3_open(database.c_str(), &DB);
    
    string sql = "DELETE FROM DOC_PROFILE";
    
    sqlite3_exec(DB, sql.c_str(), callback, NULL, NULL);

}

stringstream& insertDoctorData(stringstream& ss) {
    
    sqlite3 *DB;
    char *Errermsg;
    string sql;
    string database = "Doctor Database 1.0";

    string name; // basic profile
    string specialty;
    string language;
    string email;
    
    string address; // address_profile;
    string city;
    string country;
    string region;
    string zipcode;
    string phone_number;
    
    string username; // 以后加上密码保护
    string passward;
    
    ss >> name >> specialty >> language >> email >> address >> city >> country >> region >> zipcode >> phone_number >> username >> passward;
    
    int exit = sqlite3_open(database.c_str(), &DB);
    
    sql = "INSERT INTO DOC_PROFILE (NAME, SPECIALTY, LANGUAGE, EMAIL, ADDRESS, CITY, COUNTRY, REGION, ZIPCODE, PHONE_NUMBER, USERNAME, PASSWARD) VALUES ('" + name + "', '" + specialty + "', '" + language + "', '" + email + "', '" + address + "', '" + city + "', '" + country + "', '" + region + "', '" + zipcode + "', '" + phone_number + "', '" + username + "', '" + passward + "');";
    
    cout << endl << sql << endl;
    
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &Errermsg);
    
    if (exit != SQLITE_OK) {
        cerr << "Error Insert!" << endl;
        cout << Errermsg << endl;
        sqlite3_free(Errermsg);
    } else {
        cout << "New Patient Record Created Successfully" << endl;
    }
    
    return ss;

}

void updateDoctorData(string category, string name, string updatecategory, string updateinfo) {
    
    sqlite3 *DB;
    char *Errermsg;
    string database = "Doctor Database 1.0";
    
    int exit = sqlite3_open(database.c_str(), &DB);
    
    string sql;
    
    sql = "UPDATE DOC_PROFILE SET " + updatecategory + " = '" + updateinfo + "' WHERE " + category + " = '" + name + "'";
    
    cout << sql;
    
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &Errermsg);
    
    if (exit != SQLITE_OK) {
        cerr << "Error update!" << endl;
        sqlite3_free(Errermsg);
    } else {
        cout << "Doctor Record Updated Successfully" << endl;
    }

    
}
void selectDoctorData() {
    sqlite3 *DB;
    string database = "Doctor Database 1.0";
    
    sqlite3_open(database.c_str(), &DB);
    
    string sql = "SELECT * FROM DOC_PROFILE;";
    
    sqlite3_exec(DB, sql.c_str(), callback, NULL, NULL);

}

// retrieve contents of datebase used by selectData();
// *argc: holds the number of results, azColName: hold each column returned in array
// argv: holds each value in the array

static int callback(void *NotUsed, int argc, char** argv, char **azColName) {
    
    for (int i = 0; i < argc; i++) {
        // column name and value
        cout << azColName[i] << ": " << argv[i] << endl;
    }
    
    cout << endl;
    
    return 0;
}
