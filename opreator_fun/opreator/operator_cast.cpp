 /*****************************************************************
Name : Operator �����ഫ������
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
public: //�غc�l
    // ##��J�|�Q�����ഫ
    Opcast(int i): num(i) {}
    // �ѨM��k 1
    // explicit Opcast(int i): num(i) {}
    // �ѨM��k 2
    // Opcast(OpcastSize i): num(i) {}
public: // �૬�禡
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
    // ��J�������ഫ
    cout << a << endl;
    // ��X�������ഫ
    fun(10);
    return 0;
}
/*==============================================================*/