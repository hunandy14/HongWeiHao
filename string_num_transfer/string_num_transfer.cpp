/*****************************************************************
Name : C and C++ 字串轉整數，整數轉字串 綜合整理
Date : 2017/05/26
By   : CharlotteHonG
Final: 2017/05/26
*****************************************************************/
#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
using namespace std;

constexpr unsigned long long num = 3141592653589793238;
constexpr int num2 = 314159265;
const char* str = "3141592653589793238";
const char* str2 = "314159265";

void to_str1(){
    char str[20];
    strcpy(str, to_string(num).c_str());
    cout << "to_str1 = " << str << endl;
}
void to_str2(){
    char str[20];
    itoa(num2, str, 10);
    cout << "to_str2 = " << str << endl;
}
void  to_str3() {
    char str[20];
    sprintf(str,"%d",num2);
    cout << "to_str3 = " << str << endl;
}
void to_num1(){
    unsigned long long num = stoull(str);
    cout << "to_num1 = " << num << endl;
}
void to_num2(){
    stringstream ss(str);
    unsigned long long num;
    ss >> num;
    cout << "to_num2 = " << num << endl;
}
void to_num3(){
    unsigned long long num = strtoull(str, NULL, 10);
    cout << "to_num3 = " << num << endl;
}
void to_num4(){
    long long num = atoll(str);
    cout << "to_num4 = " << num << endl;
}
void to_num5() {
    unsigned int num;
    sscanf(str2,"%d",&num);
    cout << "to_num5 = " << num << endl;
}

int main() {
    to_str1();
    to_str2();
    to_str3();
    to_num1();
    to_num2();
    to_num3();
    to_num4();
    to_num5();
    return 0;
}
