/*****************************************************************
Name : ���O�����ۥ����@
Date : 2016/12/09
By   : CharlotteHonG
Final: 2017/03/23
*****************************************************************/
#include <iostream>
using namespace std;
// �D���O���ŧi
struct Fa{
    Fa(string name):name(name){}

    struct Son;
    Son cre_son(string name);
    void son_name();

    string name;
    Son* son;
}; using Son=Fa::Son;
// �����O���w�q
struct Fa::Son{
    Son(string name, Fa* fa):name(name), fa(*fa){}
    void fa_name();
    string name;
    Fa& fa;
};
// �����O���禡�w�q
void Son::fa_name(){
    cout << "My fa = " << this->fa.name << endl;
}
// �D���O���禡�w�q
Son Fa::cre_son(string name){
    Son temp(name, this);
    this->son = &temp;
    return temp;
}
void Fa::son_name(){
    cout << "My son = " << (*son).name << endl;
}
/*=======================================================*/
int main(int argc, char const *argv[]){
    Fa John("John");
    Son Job = John.cre_son("Job");
    // Fa �̭��� Son �A Son �S�i�H�s�� Fa
    Job.fa_name();
    John.son_name();
    return 0;
}
/*=======================================================*/