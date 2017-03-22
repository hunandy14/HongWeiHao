/*****************************************************************
Name : 
Date : 2017/03/22
By   : CharlotteHonG
Final: 2017/03/22
*****************************************************************/
#include <iostream>
using namespace std;

class A {
public:
    A(){}
    void virtual fun(){
        cout << "this is A" << endl;
    }
};

class B: public A{
public:
    B(){}
    void fun(){
        cout << "this is B" << endl;
    }
    int i=1;
};


/*==============================================================*/
int main(int argc, char const *argv[]){
    // 用父類別來操作所有指標
    A *a, *b;
    a = new A;
    b = new B;

    // 自動選擇正確的類型
    (*a).fun();
    (*b).fun();

    // 無法存取
    // cout << "(*b).i=" << (*b).i << endl; // Error
    
    // 安全向下轉型
    cout << "(*b).i=" << (*dynamic_cast<B*>(b)).i << endl;

    // 非法的向下轉型
    // cout << "(*a).i=" << (*dynamic_cast<B*>(a)).i << endl;

    return 0;
}
/*==============================================================*/