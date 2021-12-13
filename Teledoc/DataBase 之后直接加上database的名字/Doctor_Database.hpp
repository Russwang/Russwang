//
//  Dcotor_Databse.hpp
//  Teledoc
//
//  Created by Russ on 3/4/21.
//  Copyright © 2021 Russ-org. All rights reserved.
//

#ifndef Dcotor_Database_hpp
#define Dcotor_Database_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <sqlite3.h>
#include <sstream>

// 增加一个删除指定数据的function

using namespace std;

void createDoctorDB();
void createDoctorTable();
void deleteDoctorData();
stringstream& insertDoctorData(stringstream& ss);
void updateDoctorData(string category, string name, string updatecategory, string updateinfo);
void selectDoctorData();
static int callback(void *NotUsed, int argc, char** argv, char **azColName);



#endif /* Dcotor_Databse_hpp */
