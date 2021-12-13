//
//  Doctor_Profile.cpp
//  Teledoc
//
//  Created by Russ on 2/28/21.
//  Copyright © 2021 Russ-org. All rights reserved.
//

#include "Doctor_Profile.hpp"

Doctor_Profile::Doctor_Profile() {
    
    cout << "Let's start by buliding your porfile: " << endl;
    cout << "Please enter your name: ";
    cin >> name;
    
    int count;
    cout << "How many specialty do you have? ";
    cin >> count;
    
    if (count > 0) {
        cout << "Please enter here: ";
        while (count > 0) {
            string temp;
            cin >> temp;
            specialty.push_back(temp);
            count--;
        }
    } else {
        specialty.push_back("None");
    }
    
    cout << "Please enter the language you prefer? ";
    cin >> language;
    cout << "Please enter your email: ";
    cin >> email;
    cout << "Please enter your address: ";
    cin >> address;
    cout << "Please enter the city country region you currently in: ";
    cin >> city >> country >> region;
    cout << "Please enter zipcode: ";
    cin >> zipcode;
    cout << "Please enter your phone number: ";
    cin >> phone_number;
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

    
}

stringstream& Doctor_Profile::print_Doctor_Profile(stringstream& ss) {
    
    string specialties;
    
    if (specialty[0] != "None") {
        for (auto spe:specialty) {
            specialties += spe + ",";
        }
        specialties.pop_back();
    } else {
        specialties = "None";
    }
    
    
    ss.str(name + " " + specialties + " " + language + " " + email + " " + address + " " + city + " " + country + " " + region + " " + zipcode + " " + phone_number + " " + username + " " + passward);

    cout << endl << "Basic Info: " << endl;
    cout << "Name: " << name << endl;
    cout << "Specialties: " << specialties << endl;
    cout << "Language: " << language << endl;
    cout << "Email address: " << email << endl;
    cout << "Address and Phone Number Info: " << endl;
    cout << "Address: " << address << endl;
    cout << "City: " << city << endl;
    cout << "Country: " << country << endl;
    cout << "Region: " << region << endl;
    cout << "Zipcode: " << zipcode << endl;
    cout << "Phone Number: " << phone_number << endl;

    return ss;
}

