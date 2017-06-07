/*****************************************************************
Name :
Date : 2017/05/28
By   : CharlotteHonG
Final: 2017/05/28
*****************************************************************/
#include <iostream>
#include "Num.hpp"
using namespace std;


//================================================================
int main(int argc, char const *argv[]) {
    // Num<double> a(1.1), b(2.2);
    // a += b;
    // cout << "a=" << a << endl;
    // cout << "b=" << b << endl;

    // Num<double> c = a+b;
    // cout << "c=" << c << endl;

    // if(c == Num<double>(5.5))
    //     cout << " 相 等 " << endl;
    // if(c != Num<double>(4.5))
    //     cout << " 不 相 等 " << endl;

    // // double dou = c; // Error
    // double dou = (double)c;
    // cout << "dou=" << dou << endl;

    Num<int> a(10), b(5);
    b = a+a;
    cout << "b=" << b << endl;

    return 0;
}
//================================================================
