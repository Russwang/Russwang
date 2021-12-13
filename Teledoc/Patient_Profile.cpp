//
//  Profile.cpp
//  Teledoc
//
//  Created by Russ on 2/25/21.
//  Copyright © 2021 Russ-org. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

#include "Resource.hpp"
#include "Patient_Profile.hpp"

using namespace std;


Patient_Profile::Patient_Profile() {
    cout << "Let's start by finding your benifits: " << endl;
    cout << "Please enter your first and last name: ";
    cin >> firstname >> lastname;
    cout << "Please enter your gender: Male/Female ";
    cin >> gender;
    cout << "Please enter your birthday: MM DD YY";
    cin >> age.month >> age.date >> age.year;
    cout << "Please enter your language: ";
    cin >> language;
    cout << "Please enter your occupation: ";
    cin >> occupation;
    cout << "Please enter the health insurance you currently using(No if doesn't have any): ";
    cin >> healthcare_insurance;
    cout << "Please enter your email address: ";
    cin >> email;
    Change_address_profile();
    cout << endl;
    cout << "Please set your UserName/Passward next" << endl;
    cout << "Please create your Username: ";
    cin >> username;
    while (true) {
        string confirm;
        cout << "Please create your Passward: ";
        cin >> passward;
        cout << "Please confirm you Passward: ";
        cin >> confirm;
        if (confirm == passward) return;
        else cout << "Two passwards don't match. Please try again." << endl;
    }
    
    return;
}

Patient_Profile::Patient_Profile(istream in) {
    
    in >> firstname >> lastname >> gender >> age.month >> age.date >> age.year >> language >> occupation
    >> healthcare_insurance >> email;
    
}

void Patient_Profile::Change_basic_profile(string new_first, string new_last, string new_gender, Age new_age,
                                   string new_language, string new_occupation,
                                   string new_healthcare, string new_emial) {
    firstname = new_first;
    lastname = new_last;
    gender = new_gender;
    age.month = new_age.month;
    age.date = new_age.date;
    age.year = new_age.year;
    language = new_language;
    occupation = new_occupation;
    healthcare_insurance = new_healthcare;
    email = new_emial;
}

void Patient_Profile::Change_basic_profile(istream in) {
    in >> firstname >> lastname >> gender >> age.month >> age.date >> age.year >> language >> occupation
    >> healthcare_insurance >> email;
}

void Patient_Profile::Change_address_profile() {
    
    cout << endl;
    
    cout << "Nearly done... Please provide your address and phone" << endl << endl;
    cout << "Please enter your address 1: ";
    getline(cin, address_1);// getline();
    cout << "Please enter your address 2: ";
    getline(cin, address_2);
    cout << "Please enter the city country region you currently live in: ";
    cin >> city >> country >> region;
    cout << "Please enter the zipcode: ";
    cin >> zipcode;
    cout << "Please enter your cell phone number: ";
    cin >> phone_number;
    return;
}
    

void Patient_Profile::Change_address_profile(string new_address_1, string new_address_2, string new_city,
                           string new_conutry, string new_region, int new_zip, string new_phone) {
    
    address_1 = new_address_1;
    address_2 = new_address_2;
    city = new_city;
    country = new_conutry;
    region = new_region;
    zipcode = new_zip;
    phone_number = new_phone;
    
}

void Patient_Profile::Change_address_profile(istream in) {
    in >> address_1 >> address_2 >> city >> country >> region >> zipcode >> phone_number;
}

stringstream& Patient_Profile::print_profile(stringstream& ss) {
    
    cout << endl;
    cout << "Processing ... " << endl << endl;
    
    cout << "Basic Info: " << endl;
    cout << "First Name: " << firstname << endl;
    cout << "Last Name: " << lastname << endl;
    cout << "Gender: " << gender << endl;
    cout << "Age: " << age.month << "/" << age.date << "/" << age.year << endl;
    cout << "Language: " << language << endl;
    cout << "Occupation: " << occupation << endl;
    cout << "Health insurance: " << healthcare_insurance << endl;
    cout << "Email address: " << email << endl;
    cout << "Address and Phone Number Info: " << endl;
    cout << "Address: " << address_1 << " " << address_2 << endl;
    cout << "City: " << city << endl;
    cout << "Country: " << country << endl;
    cout << "Region: " << region << endl;
    cout << "Zipcode: " << zipcode << endl;
    cout << "Phone Number: " << phone_number << endl;
    
    string birthday = to_string(age.month) + "/" + to_string(age.date) + "/" + to_string(age.year);
    ss.str(firstname + " " + lastname + " " + gender + " " + birthday + " " + language + " " + occupation + " " + healthcare_insurance + " " + email + " " + address_1 + " " + address_2 + " " + city + " " + country + " " + region + " " + to_string(zipcode) + " " + phone_number + " " + username + " " + passward);
    
    return ss;
}
