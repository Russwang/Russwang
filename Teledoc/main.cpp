//
//  main.cpp
//  Teledoc
//
//  Created by Russ on 2/25/21.
//  Copyright © 2021 Russ-org. All rights reserved.
//

#include <iostream>

#include "Patient_Profile.hpp"
#include "Patient_Database.hpp"
#include "Doctor_Profile.hpp"
#include "Doctor_Database.hpp"

// 未来医疗的系统，通过线上监测，自动预约医生，或者线上预约，也可以节省基建成本
// 绑定同城快递系统，早上看病，一天之内拿到药，而且省去在医院排队的时间
// 看一下英国的医疗系统

// 加入新功能 连接百度地图/谷歌地图 来根据距离匹配病人

int main(int argc, const char * argv[]) {
        
    selectData();
    selectDoctorData();
    
    return 0;
}
