//
//  Medicial History.hpp
//  Teledoc
//
//  Created by Russ on 2/25/21.
//  Copyright © 2021 Russ-org. All rights reserved.
//


#ifndef Medicial_Histroy_hpp
#define Medicial_Histroy_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <utility>

#include "Allergy.hpp"
#include "Resource.hpp"

using namespace std;

// medical histroy includes height, weight, medications, allergies,
// lifestyle : smoke, alcohol, travals
// Last visit to doctor->date
// health problems: asthma, kidney problems, ...

struct Personal_data {
    double height;
    double weight;
    vector<string> medications;
    Allergy personal_allergies;
};


struct Lifestyle {
    bool smoke;
    bool alcohol;
    bool travel_within_two_month;
    string traval_destination;
};

unordered_map<string, bool> Health_problems {
    {"asthma",false},
    {"kidney_problems",false},
    {"high_blood_pressure",false},
    {"diabetes",false},
    {"heart_problemes",false},
    {"headaches_migraints",false},
    {"urinary_tract_infections",false},
    {"depression",false},
    {"seizures",false},
    {"stroke",false},
    {"thyroid_disease",false},
    {"arrhythmias",false},
    {"anxiety",false},
    {"panic_attacks",false},
    {"copd",false},
    {"eczema",false},
    {"psoriasis",false},
    {"cancer",false},
    {"other_problems",false}
};

struct Health_Problems {
};

class Medical_history {
    
public:
    
    Medical_history();
    Medical_history(istream in);
    
    void get_personal_data();
    void get_lifestyle();
    
    Medical_history* change_personal_data(Personal_data new_data);
    
    
    
private:
    
    Personal_data data_;
    Lifestyle lifestyle_;
    Date Last_visit;
    vector<Date> visits;
    Health_Problems health_problems;
    Health_Problems Family_history;
    
};


#endif /* Medicial_Histroy_hpp */

