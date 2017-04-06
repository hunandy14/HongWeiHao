/*****************************************************************
Name : 
Date : 2017/04/04
By   : CharlotteHonG
Final: 2017/04/04
*****************************************************************/
#include <iostream>
using namespace std;

int add(int a, int b){
    return a+b;
}
int sub(int a, int b){
    return a-b;
}

// 為宣告建立別名
// typedef int (*p)(int, int);
// using p = int (*)(int, int);

// 搭配 decltype
// typedef decltype(add) *p;
using p = decltype(add);


// 使用 p 宣告
int fun(int a, int b, auto fun_point){
    return (*fun_point)(a, b);
}
// 直接使用
int fun2(int a, int b, decltype(add) fun){
    return (*fun)(a, b);
}
//================================================================
int main(int argc, char const *argv[]){
    cout << fun(2, 3, &add) << endl;
    cout << fun(2, 3, &sub) << endl;

    // 主程式取別名
    auto p=add;
    cout << fun2(2, 3, p) << endl;

    return 0;
}
//================================================================