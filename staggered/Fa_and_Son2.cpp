/*****************************************************************
Name : 類別的互相交錯實作
Date : 2016/12/09
By   : CharlotteHonG
Final: 2017/03/23
*****************************************************************/
#include <iostream>
using namespace std;
// 主類別的宣告
struct Fa{
    Fa(string name):name(name){}

    struct Son;
    Son cre_son(string name);
    void son_name();

    string name;
    Son* son;
}; using Son=Fa::Son;
// 內類別的定義
struct Fa::Son{
    Son(string name, Fa* fa):name(name), fa(*fa){}
    void fa_name();
    string name;
    Fa& fa;
};
// 內類別的函式定義
void Son::fa_name(){
    cout << "My fa = " << this->fa.name << endl;
}
// 主類別的函式定義
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
    // Fa 裡面有 Son ， Son 又可以存取 Fa
    Job.fa_name();
    John.son_name();
    return 0;
}
/*=======================================================*/