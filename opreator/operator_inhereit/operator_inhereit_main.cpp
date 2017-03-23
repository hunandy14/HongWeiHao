/*****************************************************************
Name : 無損繼承 operator
Date : 2017/03/17
By   : CharlotteHonG
Final: 2017/03/17
*****************************************************************/
#include <iostream>
#include "operator_inhereit.hpp"
using namespace std;
/*==============================================================*/
int main(int argc, char const *argv[]){
    Arr<int> a{0, 1, 2};
    Arr<int> b{0, 1, 2};
    b=b+a;
    b.pri("b+a");

    // 繼承運算符號
    Arr_int c{1, 1, 1};
    Arr_int c1{1, 1, 1};
    c.i=7;
    c1.i=8;
    c = c1+c1;
    cout << c.i << " || ";
    c.pri("c1+c1");

    // 繼承的 += 操作符號不會操作子類別成員
    c += c1;
    cout << c.i << " || ";
    c.pri("c+=c1");

    // 複製建構子
    Arr_int c2(c1);
    cout << c2.i << " || ";
    c2.pri("c2");
    Arr_int c3(c+c); // c+c 返還的是父類別
    cout << c3.i << " || ";
    c3.pri("c3");

    // 繼承運算符號2
    Arr_uch d{'0', '0', '0'};
    Arr<unsigned char> ch{'0', '0', '0'};
    d = d+d;
    d.pri("d+d");

    return 0;
}
/*==============================================================*/
