/*****************************************************************
Name : Handle Class
Date : 2017/05/04
By   : CharlotteHonG
Final: 2017/05/04
*****************************************************************/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Tw class�w�q
class Name;
class Tw{
public:
    Tw(string name);
private:
    Name* n;
    // vector<Name> n;
};

//================================================================
int main(int argc, char const *argv[]){
    Tw a("chg");
    return 0;
}
//================================================================

// Name class�w�q
class Name{
public:
    Name(string n);
    friend ostream& operator<<(ostream& out, Name const & n);
private:
    string n;
};
// Tw�غc�l
Tw::Tw(string name){
    n = new Name(name);   // point
    // n.push_back(name); // vector
    cout << "n=" << n[0] << endl;
}
// Name �禡�w�q
Name::Name(string n): n(n){}
ostream& operator<<(ostream& out, Name const & n){
    out << n.n;
    return out;
}


