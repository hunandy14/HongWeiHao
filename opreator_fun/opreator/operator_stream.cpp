/*****************************************************************
Name : 
Date : 2017/04/25
By   : CharlotteHonG
Final: 2017/04/25
*****************************************************************/
#include <iostream>
using namespace std;

class Rati{
public:
    Rati(int a, int b): n(a), d(b){}
    friend ostream & operator<<(ostream & str, Rati const & rhs);
    friend istream & operator>>(istream & str, Rati & rhs);
private:
    int n, d;
};
ostream & operator<<(ostream & os, const Rati & rhs){
    os << rhs.n << "/" << rhs.d;
    return os;
}
istream & operator>>(istream & is, Rati & rhs){
    is >> rhs.n >> rhs.d;
    return is;
}  
//================================================================
int main(int argc, char const *argv[]){
    Rati a(0, 0);
    cin >> a;
    cout << a << endl;
    return 0;
}
//================================================================
