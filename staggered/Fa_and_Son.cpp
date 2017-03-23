/*****************************************************************
Name : 類別的互相交錯實作
Date : 2016/12/09
By   : CharlotteHonG
Final: 2017/03/23
*****************************************************************/
#include <iostream>
using namespace std;

struct Fa{
    Fa(string name):name(name){}

    struct Son{
        Son(string name, Fa* fa):name(name), fa(*fa){}
        void fa_name(){
            cout << "My fa = " << this->fa.name << endl;
        }
        string name;
        Fa& fa;
    };

    Son cre_son(string name){
        Son temp(name, this);
        this->son = &temp;
        return temp;
    }

    void son_name(){
        cout << "My son = " << (*son).name << endl;
    }

    string name;
    Son* son;
};

using Son=Fa::Son;
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