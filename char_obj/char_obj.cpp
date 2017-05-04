/*****************************************************************
Name : 
Date : 2017/04/27
By   : CharlotteHonG
Final: 2017/04/27
*****************************************************************/
#include <iostream>
#include <cstring>
using namespace std;

class Str{
public:
    Str(char const* str=""): s(new char[strlen(str)+1]{}){
        strcpy(s, str);
    }
    Str(Str const & rhs): s(new char[strlen(rhs.s)+1]{}){
        strcpy(s, rhs.s);
    }
    ~Str(){
        delete [] s;
    }
public:
    Str& operator=(Str const & rhs){
        // 來源是否相同
        if(this == &rhs)
            return (*this);
        this->~Str();
        s = new char[strlen(rhs.s)+1]{};
        strcpy(s, rhs.s);
        return (*this);
    }
    Str& operator+=(Str const & rhs){
        char* temp = s;
        size_t len = strlen(rhs.s)+strlen(temp);
        s = new char[len+1]{};
        strcat(s, temp);
        // 來源是否相同
        this==&rhs? strcat(s, temp): strcat(s, (rhs.s));
        // 刪除緩存
        delete [] temp;
        return (*this);
    }
    Str& operator+=(char const* rhs){
        char* temp = s;
        size_t len = strlen(rhs)+strlen(temp);
        s = new char[len+1]{};
        strcat(s, temp);
        strcat(s, rhs);
        // 刪除緩存
        delete [] temp;
        return (*this);
    }
    Str& operator+=(char rhs){
        char* temp = s;
        size_t len = strlen(temp)+1;
        s = new char[len+1]{};
        strcat(s, temp);
        s[len-1] = rhs;
        // 刪除緩存
        delete [] temp;
        return (*this);
    }
    char & operator[](size_t idx){
        return const_cast<char&>(static_cast<const Str&>(*this)[idx]);
    }
    const char & operator[](size_t idx) const{
        return s[idx];
    }
    friend const Str operator+(Str const & lhs, Str const & rhs);
    friend ostream& operator<< (ostream& s, const Str & rhs);
public:
    size_t size(){
        return strlen(s);
    }
    Str & resize(size_t len){
        char* temp = s;
        s = new char[len+1]{};
        size_t len2 = std::min(len, strlen(temp));
        strncat(s, temp, len2);
        return (*this);
    }

    void pri(){
        cout << "pri s = " << s << endl;
    }
private:
    char* s;
};

const Str operator+(Str const & lhs, Str const & rhs){
    return Str(lhs) += rhs;
}
ostream& operator<< (ostream& s, const Str & rhs){
    s << rhs.s;
    return s;
}
//================================================================
int main(int argc, char const *argv[]){
    Str a="Hello World!";
    Str b=a;
    Str c;
    c = a+b; // c is "Hello World!Hello World!"

    // print c and modify c
    for (unsigned i = 0; i < c.size(); ++i){
        cout << c[i];
        c[i] = (i+65);
    } c += "YZ\n\0";
    cout << endl;
    cout << c << endl;

    c.resize(3);
    cout << c << endl;
    c.resize(4);
    c += 'D';
    cout << c << endl;
    c += c;
    cout << c << endl;
    return 0;
}
//================================================================
