//
//  Profile.hpp
//  Teledoc
//
//  Created by Russ on 2/25/21.
//  Copyright © 2021 Russ-org. All rights reserved.
//

#ifndef Profile_hpp
#define Profile_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>

#include "Resource.hpp"

struct Age : Date {
    
};

using namespace std;

class Patient_Profile {
    
public:
    
    Patient_Profile();
    Patient_Profile(istream in);
    
    void Change_basic_profile(string new_first, string new_last, string new_gender, Age new_age, string
                              new_language, string new_occupation, string new_healthcare, string new_emial);
    void Change_basic_profile(istream in);
    
    void Change_address_profile();
    void Change_address_profile(string new_address_1, string new_address_2, string new_city,
                               string new_conutry, string new_region, int new_zip, string new_phone);
    void Change_address_profile(istream in);
    
    stringstream& print_profile(stringstream& ss);
    
private:

    string firstname; // basic profile
    string lastname;
    string gender;
    Age age;
    string language;
    string occupation;
    string healthcare_insurance;
    string email;
    
    string address_1; // address_profile;
    string address_2;
    string city;
    string country;
    string region;
    int zipcode;
    string phone_number;
    
    string username; // 以后加上密码保护
    string passward;
    
};


#endif
