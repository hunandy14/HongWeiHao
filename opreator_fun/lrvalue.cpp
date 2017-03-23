/*****************************************************************
Name : 
Date : 2017/03/20
By   : CharlotteHonG
Final: 2017/03/20
*****************************************************************/
#include <iostream>
using namespace std;

void fun(int & i){
    cout << "l only" << endl;
}
void fun(int const && i){
    cout << "r only" << endl;
}

void fun2(int const & i){
    // 如果有其他限定左右直的函式則他們優先
    cout << "l or r" << endl;
}

int val(){
    return 0;
}
/*==============================================================*/
int main(int argc, char const *argv[]){
    int i(0);
    // fun1
    fun(i);
    fun(move(i));
    fun(val());
    // fun2
    fun2(i);
    fun2(move(i));
    fun2(val());

    return 0;
}
/*==============================================================*/