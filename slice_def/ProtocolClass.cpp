/*****************************************************************
Name : 
Date : 2017/05/04
By   : CharlotteHonG
Final: 2017/05/04
*****************************************************************/
#include <iostream>
using namespace std;
// Tw class定義
class Name;
class Tw{
public:
    virtual ~Tw(){}
    virtual Name name()=0;
    static Tw* makeTw(string const & name);
};
// Name class定義
class Name{
public:
    Name(string const & n);
    friend ostream& operator<<(ostream& out, Name const & n);
private:
    string n;
};


// Tw class定義
class RealTw: public Tw{
public:
    RealTw(string const & name): n(name){}
    Name name(){return n;}
private:
    Name n;
};
//================================================================
int main(int argc, char const *argv[]){
    Tw* p = Tw::makeTw("chg");
    // cout << p->name() << endl;
    return 0;
}
//================================================================
// makeTw 函式定義
Tw* Tw::makeTw(string const & name){
    return new RealTw(name);
}
// Name 函式定義
Name::Name(string const & n): n(n){}
ostream& operator<<(ostream& out, Name const & n){
    out << n.n;
    return out;
}