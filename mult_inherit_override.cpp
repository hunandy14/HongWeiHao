/*****************************************************************
Name : 多重繼承時函式名稱一樣怎麼重載虛擬函式
Date : 2017/05/21
By   : CharlotteHonG
Final: 2017/05/22
*****************************************************************/
#include <iostream>
using namespace std;

// Base class
class A1 {
public:
    virtual void draw(){cout << "A1" << endl;}
};
class A2{
public:
    virtual void draw(){cout << "A2" << endl;}
};
//----------------------------------------------------------------
// 沒辦法重載個別的 draw()
// class A: public A1, public A2 {
// public:
//     void draw(){cout << "A=" << endl;}
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
    virtual void A2draw(){cout << "A2draw" << endl;}
    virtual void A1draw(){cout << "A1draw" << endl;}
};
//----------------------------------------------------------------
int main() {
    A a;
    // A1 是 父類別的預設行為，A1 draw 是子類別的重載
    dynamic_cast<A1*>(&a) -> draw();
    dynamic_cast<A2*>(&a) -> draw();
    return 0;
}
//----------------------------------------------------------------
