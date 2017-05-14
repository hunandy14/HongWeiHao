/*****************************************************************
Name :
Date : 2017/05/14
By   : 
Final: 2017/05/14

https://www.ptt.cc/bbs/C_and_CPP/M.1363233380.A.9EA.html
*****************************************************************/
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
    auto PlanA = []()-> bool { return false; };
    auto PlanB = []()-> bool { return false; };
    auto PlanC = []()-> bool {
        cout << "PlanC" << endl;
        return true;
    };
    auto Error = []()-> bool {
        cout << "Error" << endl;
        return false;
    };
    // 方法1
    cout << "=========================" << endl;
    bool isSuccess = false;
    isSuccess = isSuccess || PlanA(); //先做 A 計畫
    isSuccess = isSuccess || PlanB(); //如果 A 計畫失敗，才做 B 計畫
    isSuccess = isSuccess || PlanC(); //連 B 計畫也失敗，才做 C 計畫
    isSuccess = isSuccess || Error(); //上面都失敗，就顯示錯誤
    // 方法2
    cout << "=========================" << endl;
    function<bool()> steps[] = {
        PlanA,
        PlanB,
        PlanC,
        Error,
        []() { return false; }
    };
    auto failed_at = std::begin(steps);
    while(!(*failed_at++)());
    cout << "failed at: " << std::distance(
             std::begin(steps), failed_at) << endl;
    cout << "=========================" << endl;
    // 方法3 (模擬 goto?)
    while(1) {
        if(PlanA()) {break;}
        if(PlanB()) {break;}
        if(PlanC()) {break;}
        break;
    }
}
//================================================================
