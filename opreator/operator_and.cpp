/*****************************************************************
Name : 
Date : 2017/03/20
By   : CharlotteHonG
Final: 2017/03/20
*****************************************************************/
#include <iostream>
#include <memory>

using namespace std;

template<typename T>
class Test{
public:
    // �غc
    Test(){
        cout << "this=" << this << endl;
        cout << "i=" << &i << endl;
        cout << "j=" << &j << endl;
        cout << endl;
    }
public:
    // ����
    operator T&(){
        cout << "operator T&() : ";
        return j;
    }
    T* operator&(){
        cout << "T& operator&() : ";
        return &j;
    }
private:
    //init since c++11
    T i=1;
    T j=2;
};
/*=======================================================*/
int main(int argc, char const *argv[]){
    Test<int> a;
    // �I�s operator T&()
    cout << "a=" << a << endl;

    // �I�s T* operator&()
    cout << "a=" << &a << endl;

    // �b�w�g�Q���������p�U���o�u��a�}
    cout << "real add=" << addressof(a) << endl;
    return 0;
}
/*=======================================================*/