//
//  Database.hpp
//  Teledoc
//
//  Created by Russ on 2/27/21.
//  Copyright © 2021 Russ-org. All rights reserved.
//

#ifndef Database_hpp
#define Database_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <sqlite3.h>
#include <sstream>

// 增加一个删除指定数据的function
// 如何删除多个数据

using namespace std;

void createDB();
void createTable();
void deleteData();
stringstream& insertData(stringstream& ss);
void updateData(string category, string name, string updatecategory, string updateinfo);
void selectData();
static int callback(void *NotUsed, int argc, char** argv, char **azColName);

#endif /* Database_hpp */
