/*****************************************************************
Name : 
Date : 2017/05/10
By   : CharlotteHonG
Final: 2017/05/10
*****************************************************************/
#include <iostream>
#include <vector>
#include <initializer_list>
using namespace std;

class Arr{
public:
    Arr(initializer_list<int> list): num(list) {}
    friend ostream & operator<< (ostream & str, Arr const & rhs);
public:
    Arr & operator++(){
        for(auto&& i : num) ++i;
        return (*this);
    }
    Arr operator++(int){
        Arr temp(*this);
        this->operator++();
        return temp;
    }
private:
    vector<int> num;
};

ostream & operator<< (ostream & str, const Arr & rhs){
    size_t idx = 0;
    for(idx = 0; idx < rhs.num.size()-1; ++idx) {
        str << rhs.num[idx] << ", ";
    } str << rhs.num[idx];
    return str;
}  
/*==============================================================*/
int main(int argc, char const *argv[]){
    Arr p{1, 1, 1};
    cout << "++p = " << ++p << endl;
    cout << "p = " << p++ << endl;
    cout << "p = " << p << endl;
    return 0;
}
/*==============================================================*/
