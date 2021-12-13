//
//  Database.cpp
//  Teledoc
//
//  Created by Russ on 2/27/21.
//  Copyright © 2021 Russ-org. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <iostream>
#include <sqlite3.h>


#include "Patient_Database.hpp"

using namespace std;

void createDB() {
    sqlite3 *DB;
    int exit = 0;
    string database = "Patient DataBase 1.0";
    
    exit = sqlite3_open(database.c_str(), &DB);
    
    if (exit != SQLITE_OK) {
        cerr << "Create Error" << endl;
        return;
    } else {
        cout << "Create Database Successfully" << endl;
    }

    
    sqlite3_close(DB);
    
}

void createTable() {
    
    sqlite3 *DB;
    string database = "Patient DataBase 1.0";
    
    string sql = "CREATE TABLE IF NOT EXISTS PROFILE("
    "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
    "FIRST_NAME     TEXT    NOT NULL, "
    "LAST_NAME      TEXT    NOT NULL, "
    "GENDER         TEXT    NOT NULL, "
    "AGE            TEXT    NOT NULL, "
    "LANGUAGE       TEXT    NOT NULL, "
    "OCCUPATION     TEXT    NOT NULL, "
    "HEALTHCARE     TEXT    NOT NULL, "
    "EMAIL          TEXT    NOT NULL, "
    "ADDRESS_1      TEXT    NOT NULL, "
    "ADDRESS_2      TEXT    NOT NULL, "
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
            cout << "Create Table Error" << endl;
            return;
        } else {
            cout << "Create Table Successfully" << endl;
        }
        sqlite3_close(DB);
    } catch (const exception & e) {
        cerr << e.what();
    }
    
}

void deleteData() {
    
    sqlite3 *DB;
    string database = "Patient DataBase 1.0";
    
    sqlite3_open(database.c_str(), &DB);
    
    string sql = "DELETE FROM PROFILE";
    
    sqlite3_exec(DB, sql.c_str(), callback, NULL, NULL);
    
}

stringstream& insertData(stringstream& ss) {
    
    sqlite3 *DB;
    char *Errermsg;
    string sql;
    string database = "Patient DataBase 1.0";
    
    string firstname; // basic profile
    string lastname;
    string gender;
    string age; //Age age;
    string language;
    string occupation;
    string healthcare_insurance;
    string email;
    string address_1; // address_profile;
    string address_2;
    string city;
    string country;
    string region;
    string zipcode;
    string phone_number;
    string username; // 以后加上密码保护
    string passward;
    
    ss >> firstname >> lastname  >> gender >> age >> language >> occupation >> healthcare_insurance >> email >> address_1 >> address_2 >> city >> country >> region >> zipcode >> phone_number >>  username >> passward;
    
    int exit = sqlite3_open(database.c_str(), &DB);
    
    sql = "INSERT INTO PROFILE (FIRST_NAME, LAST_NAME, GENDER, AGE, LANGUAGE, OCCUPATION, HEALTHCARE, EMAIL, ADDRESS_1, ADDRESS_2, CITY, COUNTRY, REGION, ZIPCODE, PHONE_NUMBER, USERNAME, PASSWARD) VALUES ('" + firstname + "', '" + lastname + "', '" + gender + "', '" + age + "', '" + language + "', '" + occupation + "', '" + healthcare_insurance + "', '" + email + "', '" + address_1 + "', '" + address_2 + "', '" + city + "', '" + country + "', '" + region + "', '" + zipcode + "', '" + phone_number + "', '" + username + "', '" + passward + "');";
        
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

void updateData(string category, string name, string updatecategory, string updateinfo) {
    sqlite3 *DB;
    char *Errermsg;
    string database = "Patient DataBase 1.0";
    
    int exit = sqlite3_open(database.c_str(), &DB);
    
    string sql;
    
    sql = "UPDATE PROFILE SET " + updatecategory + " = '" + updateinfo + "' WHERE " + category + " = '" + name + "'";
    
    cout << sql;
    
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &Errermsg);
    
    if (exit != SQLITE_OK) {
        cerr << "Error update!" << endl;
        sqlite3_free(Errermsg);
    } else {
        cout << "Patient Record Updated Successfully" << endl;
    }
    
}

void selectData() {
    
    sqlite3 *DB;
    string database = "Patient DataBase 1.0";
    
    sqlite3_open(database.c_str(), &DB);
    
    string sql = "SELECT * FROM PROFILE;";
    
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
