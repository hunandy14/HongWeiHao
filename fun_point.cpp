/*****************************************************************
Name : �禡����
Date : 2017/02/23
By   : CharlotteHonG
Final: 2017/02/23
*****************************************************************/
#include <iostream>
using namespace std;

int add(int & a, int & b){
    return a+b;
}
int sub(int & a, int & b){
    return a-b;
}
/*==============================================================*/
int main(int argc, char const *argv[]){
    int (*ptr[2])(int & a, int & b){add, sub};

    int a=1, b=3;
    cout << "ptr[0](a, b)=" << ptr[0](a, b) << endl;
    cout << "ptr[0](a, b)=" << ptr[1](a, b) << endl;
    return 0;
}
/*==============================================================*/