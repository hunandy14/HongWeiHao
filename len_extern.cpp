/*****************************************************************
Name : 陣列長度的外置(集中定義)
Date : 2017/04/27
By   : CharlotteHonG
Final: 2017/04/27
*****************************************************************/
#include <iostream>
using namespace std;

// const可以直接初始化
class const_init{
public:
    const_init(int len=10):len(len){
        cout << "len=" << len << endl;
    }
private:
    const int len;
};

// C11 支持類內定義
// 委託結構定義
struct Array_size{
    static const int len = 10;
};
class defstru{
public:
    defstru(){
        cout << "len=" << sizeof(arr)/sizeof(arr[0]) << endl;
    }
private:
    int arr[Array_size::len];
};
// 直接定義在類別內也可
class defin{
public:
    defin(){
        cout << "len=" << sizeof(arr)/sizeof(arr[0]) << endl;
    }
private:
    static const int len = 10;
    int arr[Array_size::len];
};


// 不支持類內定義可以拉出來定義
struct Array_size2{
    static const int len;
};
const int Array_size2::len=10;


// 拉出來定義要是再不行還可以用 enmu
class defenmu{
public:
    defenmu(){
        cout << "len=" << sizeof(arr)/sizeof(arr[0]) << endl;
    }
private:
    enum{Array_size=10};
    int arr[Array_size];
};


// 還有一個手段 constexpr
struct Array_size4{
    static constexpr size_t len1(){
        return 10;
    }
} size;
class deffunc{
public:
    deffunc(){
        cout << "len=" << sizeof(arr)/sizeof(arr[0]) << endl;
    }
private:
    int arr[Array_size4::len1()];
    int arr2[size.len1()];
};
//================================================================
int main(int argc, char const *argv[]){
    defstru a;
    defin b;
    defenmu c;
    const_init d;
    deffunc e;
    return 0;
}
//================================================================
