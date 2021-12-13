//
//  Basic_Profile.h
//  Teledoc
//
//  Created by Russ on 2/26/21.
//  Copyright © 2021 Russ-org. All rights reserved.
//

#ifndef Basic_Profile_h
#define Basic_Profile_h

#include <string>

using namespace std;

struct Date {
    int month;
    int date;
    int year;
};

struct Basic_profile {
    string name; // basic profile
    string gender;
    Date age;
    string language;
    string occupation;
    string healthcare_insurance;
    string email;
};

bool judge(string entry);



#endif /* Basic_Profile_h */

