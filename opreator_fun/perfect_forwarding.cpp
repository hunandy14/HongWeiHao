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
// && �ѨM�F const �P non-constt �����D
// forward �ѨM�F�ޤJ���k�Ȧ��F�W�r�ܦ����Ȫ����D
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