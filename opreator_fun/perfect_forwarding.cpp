/*****************************************************************
Name : 
Date : 2017/04/07
By   : CharlotteHonG
Final: 2017/04/07
*****************************************************************/
#include <iostream>
using namespace std;

void fun(int & i){
    cout << "fun L" << endl;
}
void fun(int const & i){
    cout << "fun L const" << endl;
}
void fun(int && i){
    cout << "fun R" << endl;
}
void fun(int const && i){
    cout << "fun R const" << endl;
}

template<class T>
void tran(T && t){
    // fun(t);
    fun(forward<T>(t));
}
// && 解決了 const 與 non-constt 的問題
// forward 解決了引入的右值有了名字變成左值的問題
/*==============================================================*/
int main(int argc, char const *argv[]){
    int a=0;
    int const b=0;
    // fun(a);
    // fun(b);
    // fun(move(a));
    // fun(move(b));

    tran(a);
    tran(b);
    tran(move(a));
    tran(move(b));
    return 0;
}
/*==============================================================*/