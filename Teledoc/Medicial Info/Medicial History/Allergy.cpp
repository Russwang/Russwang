//
//  Allergy.cpp
//  Teledoc
//
//  Created by Russ on 2/25/21.
//  Copyright © 2021 Russ-org. All rights reserved.
//


#include <iostream>

#include "Allergy.hpp"
#include "Resource.hpp"

using namespace std;

void Allergy::read(istream in) {
    in >> name >> reaction;
    
    string curstatus;
    in >> curstatus;
    status = judge(curstatus);
        
}
