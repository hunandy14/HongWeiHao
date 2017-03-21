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
    // 建構
    Test(){
        cout << "this=" << this << endl;
        cout << "i=" << &i << endl;
        cout << "j=" << &j << endl;
        cout << endl;
    }
public:
    // 重載
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
    // 呼叫 operator T&()
    cout << "a=" << a << endl;

    // 呼叫 T* operator&()
    cout << "a=" << &a << endl;

    // 在已經被重載的情況下取得真實地址
    cout << "real add=" << addressof(a) << endl;
    return 0;
}
/*=======================================================*/