//
//  Boolean.cpp
//  Teledoc
//
//  Created by Russ on 2/25/21.
//  Copyright © 2021 Russ-org. All rights reserved.
//

#include "Boolean.hpp"

#include <string>

using namespace std;

bool judge(string entry) {
    if (entry == "No" || entry == "NO" || entry == "no") {
        return false;
    } else {
        return true;
    }
}
