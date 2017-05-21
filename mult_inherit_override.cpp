/*****************************************************************
Name : �h���~�Ӯɨ禡�W�٤@�˫�򭫸������禡
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
// �S��k�����ӧO�� draw()
// class A: public A1, public A2 {
// public:
//     void draw(){cout << "A=" << endl;}
// };
//----------------------------------------------------------------
// ��o (���ժ����w��o�禡)
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
// �����ӧO�� draw()
class A: public AuxA1, public AuxA2 {
public:
    virtual void A2draw(){cout << "A2draw" << endl;}
    virtual void A1draw(){cout << "A1draw" << endl;}
};
//----------------------------------------------------------------
int main() {
    A a;
    // A1 �O �����O���w�]�欰�AA1 draw �O�l���O������
    dynamic_cast<A1*>(&a) -> draw();
    dynamic_cast<A2*>(&a) -> draw();
    return 0;
}
//----------------------------------------------------------------
