 /*****************************************************************
Name : Operator 隱式轉換的重載
Date : 2017/04/11
By   : CharlotteHonG
Final: 2017/04/11
*****************************************************************/
#include <iostream>
using namespace std;

class Opcast {
public:
    class OpcastSize{
    public:
        OpcastSize(int i): len(i){}
        operator int&(){return len;}
        int len;
    };
public: //建構子
    // ##轉入會被隱式轉換
    Opcast(int i): num(i) {}
    // 解決方法 1
    // explicit Opcast(int i): num(i) {}
    // 解決方法 2
    // Opcast(OpcastSize i): num(i) {}
public: // 轉型函式
    operator double() const{
        cout << "Cast to double. --> ";
        return num+1;
    }
    double to_dou(){
        cout << "Cast to double. --> ";
        return num+1;
    }
private:
    int num;
};


void fun(Opcast a){
    cout << "fun" << endl;
}
/*==============================================================*/
int main(int argc, char const *argv[]){
    Opcast a(1);
    // 轉入的隱式轉換
    cout << a << endl;
    // 轉出的隱式轉換
    fun(10);
    return 0;
}
/*==============================================================*/