/*****************************************************************
Name : 多重繼承時函式名稱一樣怎麼重載虛擬函式
Date : 2017/05/21
By   : CharlotteHonG
Final: 2017/05/26
*****************************************************************/
#include <iostream>
using namespace std;

// Base class
class A1 {
public:
    virtual void draw(){cout << "Base A1 draw" << endl;}
};
class A2{
public:
    virtual void draw(){cout << "Base A2 draw" << endl;}
};
//----------------------------------------------------------------
// 沒辦法重載個別的 draw()
// class A: public A1, public A2 {
// public:
//     void draw(){cout << "A draw" << endl;}
// };
//----------------------------------------------------------------
// 轉發 (明白的指定轉發函式)
class AuxA1: public A1{
public:
    virtual void A1draw() = 0;
    virtual inline void draw(){A1draw();}
};
class AuxA2: public A2{
public:
    virtual void A2draw() = 0;
    virtual inline void draw(){A2draw();}
};
// 重載個別的 draw()
class A: public AuxA1, public AuxA2 {
public:
    void A1draw(){cout << "Override A1 draw" << endl;}
    void A2draw(){cout << "Override A2 draw" << endl;}
};
//----------------------------------------------------------------
int main() {
    // 繼承的使用方式
    A1* a1 = new A;
    A2* a2 = new A;
    a1 -> draw();
    a2 -> draw();
    // 這樣仍然會因為曖昧不能使用
    // A a;
    // a.draw(); //error: request for member 'draw' is ambiguous
    return 0;
}
//----------------------------------------------------------------
