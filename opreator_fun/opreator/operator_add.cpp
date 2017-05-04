/*****************************************************************
Name : 重載 operator+ 與 += 函式
Date : 2017/02/22
By   : CharlotteHonG
Final: 2017/03/05
*****************************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Arr{
public:
    Arr(size_t len=3, int value=1): num(len) {
        // cout << "Constructor" << endl;
        for(auto&& i : num)
            i=value;
    }
    ~Arr(){
        // cout << "Destructor" << endl;
    }
    void pri(){
        for(auto&& i : num) {
            cout << i << ", ";
        }cout << endl;
    }
public:
    Arr & operator+=(Arr const &rhs){
        for(unsigned i = 0; i < num.size(); ++i)
            this->num[i] += rhs.num[i];
        return *this;
    }
    Arr & operator+=(int value){
        for(unsigned i = 0; i < num.size(); ++i)
            this->num[i] += value;
        return *this;
    }
private:
    vector<int> num;
};

Arr const operator+(Arr const &lhs, Arr const &rhs){
    cout << "lhs+rhs : ";
    return Arr(lhs) += rhs;
}
Arr const operator+(int value, Arr const &rhs){
    cout << "rhs+    : ";
    return Arr(rhs) += value;
}
Arr const operator+(Arr const &lhs, int value){
    cout << "lhs+    : ";
    return Arr(lhs) += value;
}
/*==============================================================*/
int main(int argc, char const *argv[]){
    Arr p;
    p=p+p;
    p.pri();
    p=1+p;
    p.pri();
    p=p+1;
    p.pri();
    return 0;
}
/*==============================================================*/