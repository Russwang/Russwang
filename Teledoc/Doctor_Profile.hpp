//
//  Doctor_Profile.hpp
//  Teledoc
//
//  Created by Russ on 2/28/21.
//  Copyright © 2021 Russ-org. All rights reserved.
//

#ifndef Doctor_Profile_hpp
#define Doctor_Profile_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Doctor_Profile {
    
public:
    
    Doctor_Profile();
    stringstream& print_Doctor_Profile(stringstream& ss);
    
    
private:
    
    string name; // basic profile
    vector<string> specialty;
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
    
};




#endif /* Doctor_Profile_hpp */
