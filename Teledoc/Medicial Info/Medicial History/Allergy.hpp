//
//  Allergy.hpp
//  Teledoc
//
//  Created by Russ on 2/25/21.
//  Copyright © 2021 Russ-org. All rights reserved.
//


#ifndef Allergy_hpp
#define Allergy_hpp

#include <stdio.h>
#include <string>

#include "Resource.hpp"

using namespace std;

class Allergy {
public:
    
    Allergy();
    
    void read(istream in);
    
private:
    string name;
    string reaction;
    bool status; // still allergic ? 
};

#endif /* Allergy_hpp */
