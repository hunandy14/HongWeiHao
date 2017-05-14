/*****************************************************************
Name : 
Date : 2017/05/04
By   : CharlotteHonG
Final: 2017/05/05
*****************************************************************/
#include <iostream>
using namespace std;
// Tw class定義
class Name;
class Tw{
public:
    virtual ~Tw(){}
    virtual string name()=0;
    static Tw* makeTw(Name const & name);
};

// Name class定義
class Name{
public:
    Name(string const & n);
    operator string&(){
        return n;
    }
    friend ostream& operator<<(ostream& out, Name const & n);
private:
    string n;
};
//================================================================
int main(int argc, char const *argv[]){
    Tw* p;
    Name chg = string("chg");
    p = Tw::makeTw(chg);
    cout << p->name() << endl;
    return 0;
}
//================================================================

// Tw class定義
class RealTw: public Tw{
public:
    RealTw(Name const & name): n(name){}
    string name(){return n;}
private:
    Name n;
};

// makeTw 函式定義
Tw* Tw::makeTw(Name const & name){
    return new RealTw(name);
}

// Name 函式定義
Name::Name(string const & n): n(n){}
ostream& operator<<(ostream& out, Name const & n){
    out << n.n;
    return out;
}