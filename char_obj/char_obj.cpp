/*****************************************************************
Name :
Date : 2017/04/27
By   : CharlotteHonG
Final: 2017/04/27
*****************************************************************/
#include <iostream>
#include <cstring>
using namespace std;
/*
      #####     ##
     ##   ##    ##
     ##       ######   ## ###
      #####     ##     ###
          ##    ##     ##
     ##   ##    ##     ##
      #####      ###   ##

*/
class Str{
public:
    Str(char const* str="");
    Str(Str const& rhs);
    ~Str();
public:
    Str& insert(size_t pos, Str const& str,
        size_t subpos, size_t sublen);
    Str& insert(size_t pos, Str const& str);
    Str& insert(size_t pos, const char* str, size_t n);
    Str& insert(size_t pos, const char* str);
public:
    Str& operator=(Str const& rhs);
    Str& operator+=(Str const& rhs);
    Str& operator+=(char const* rhs);
    Str& operator+=(char rhs);
    char& operator[](size_t idx);
    const char& operator[](size_t idx) const;
    friend Str operator+(Str const& lhs, Str const& rhs);
    friend ostream& operator<<(ostream& s, const Str& rhs);
    friend istream& operator>>(istream& is, Str& rhs);
    friend bool operator!=(const Str& lhs, const Str& rhs);
    friend bool operator==(const Str& lhs, const Str& rhs);
public:
    const size_t size() const;
    Str& resize(size_t len);
    char const* c_str();
private:
    char* s;
};
/*
                         ##

     ### ##    ######  ####     ## ###
     ## # ##  ##   ##    ##     ###  ##
     ## # ##  ##   ##    ##     ##   ##
     ## # ##  ##  ###    ##     ##   ##
     ##   ##   ### ##  ######   ##   ##

*/
int main(int argc, char const *argv[]){
    Str a="Hello World!";
    Str b=a;
    Str c;
    c = a+b; // c is "Hello World!Hello World!"

    // print c and modify c
    for(unsigned i = 0; i < c.size(); ++i){
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

    const Str& d=c;
    for(unsigned i = 0; i < d.size(); ++i){
        cout << d[i];
    } cout << endl;

    Str a1="123456";
    Str b1="ABCDE";
    a1.insert(1, b1, 2, 2);
    a1.insert(1, b1);
    a1.insert(1, b1.c_str(), 6);
    cout << "a1 =" << a1 << endl;
    return 0;
}
/*
       ####     ##
      ##  ##    ##
     ##       ######    #####   ## ###
     ##         ##     ##   ##  ###
     ##         ##     ##   ##  ##
      ##  ##    ##     ##   ##  ##
       ####      ###    #####   ##

*/
Str::Str(char const* str): s(new char[strlen(str)+1]){
    strcpy(s, str);
}
Str::Str(Str const& rhs): s(new char[strlen(rhs.s)+1]){
    strcpy(s, rhs.s);
}
Str::~Str(){
    delete [] s;
}
/*
       ##                                           ##
                                                    ##
     ####     ## ###    #####    #####   ## ###   ######
       ##     ###  ##  ##       ##   ##  ###        ##
       ##     ##   ##   ####    #######  ##         ##
       ##     ##   ##      ##   ##       ##         ##
     ######   ##   ##  #####     #####   ##          ###

*/
Str& Str::insert(size_t pos, Str const& str,
    size_t subpos, size_t sublen)
{
    // 檢查越界
    if(pos > strlen(s) or subpos > strlen(str.s)) {
        cout << "out_of_range" << endl;
        return (*this);
    }
    // 檢查 sublen 長度是否異常
    if(sublen > strlen(str.s+subpos))
        sublen = strlen(str.s+subpos);
    // 插入後的長度
    size_t newlen = strlen(s);
    newlen += strlen(str.s+subpos);
    // 插入
    char const* temp = s;
    s = new char[newlen+1];
    strncpy(s, temp, pos);
    strncpy(s+pos, str.s+subpos, sublen);
    strcpy(s+pos+sublen, temp+pos);
    delete [] temp;
    return (*this);
}
Str& Str::insert(size_t pos, Str const& str){
    this->insert(pos, str, 0, str.size());
    return (*this);
}
Str& Str::insert(size_t pos, const char* str, size_t n){
    // 檢查越界
    if(pos > strlen(s)) {
        cout << "out_of_range" << endl;
        return (*this);
    }
    // 檢查 n 長度是否異常
    if(n > strlen(str))
        n = strlen(str);
    // 插入後的長度
    size_t newlen = strlen(s);
    newlen += n;
    // 插入
    char const* temp = s;
    s = new char[newlen+1];
    strncpy(s, temp, pos);
    strncpy(s+pos, str, n);
    strcpy(s+pos+n, temp+pos);
    delete [] temp;
    return (*this);
}
Str& Str::insert(size_t pos, const char* str){
    insert(pos, str, strlen(str));
    return (*this);
}
/*
                                                    ##
                                                    ##
      #####   ######    #####   ## ###    ######  ######    #####   ## ###
     ##   ##  ##   ##  ##   ##  ###      ##   ##    ##     ##   ##  ###
     ##   ##  ##   ##  #######  ##       ##   ##    ##     ##   ##  ##
     ##   ##  ##   ##  ##       ##       ##  ###    ##     ##   ##  ##
      #####   ######    #####   ##        ### ##     ###    #####   ##
              ##
*/
Str& Str::operator=(Str const& rhs){
    // 來源是否相同
    if(this == &rhs)
        return (*this);
    this->~Str();
    s = new char[strlen(rhs.s)+1];
    strcpy(s, rhs.s);
    return (*this);
}
Str& Str::operator+=(Str const& rhs){
    char* temp = s;
    size_t len = strlen(rhs.s)+strlen(temp);
    s = new char[len+1];
    strcpy(s, temp);
    // 來源是否相同
    this==&rhs?
        strcat(s, temp):
        strcat(s, (rhs.s));
    // 刪除緩存
    delete [] temp;
    return (*this);
}
Str& Str::operator+=(char const* rhs){
    char* temp = s;
    size_t len = strlen(rhs)+strlen(temp);
    s = new char[len+1];
    strcpy(s, temp);
    strcat(s, rhs);
    // 刪除緩存
    delete [] temp;
    return (*this);
}
Str& Str::operator+=(char rhs){
    char* temp = s;
    size_t len = strlen(temp)+1;
    s = new char[len+1];
    strcpy(s, temp);
    s[len-1] = rhs;
    s[len] = 0;
    // 刪除緩存
    delete [] temp;
    return (*this);
}
char& Str::operator[](size_t idx){
    return const_cast<char&>(static_cast<const Str&>(*this)[idx]);
}
const char& Str::operator[](size_t idx) const{
    return s[idx];
}

Str operator+(Str const& lhs, Str const& rhs){
    return Str(lhs) += rhs;
}
ostream& operator<<(ostream& s, const Str& rhs){
    s << rhs.s;
    return s;
}
istream& operator>>(istream& is, Str& rhs){
    is >> rhs.s;
    return is;
}
bool operator!=(const Str& lhs, const Str& rhs){return !(lhs == rhs);}
bool operator==(const Str& lhs, const Str& rhs){
    return strcmp(lhs.s, rhs.s) == 0;
}
/*
                ##     ##
                ##     ##
      #####   ######   ######    #####   ## ###
     ##   ##    ##     ##   ##  ##   ##  ###
     ##   ##    ##     ##   ##  #######  ##
     ##   ##    ##     ##   ##  ##       ##
      #####      ###   ##   ##   #####   ##

*/
const size_t Str::size() const{
    return strlen(s);
}
Str& Str::resize(size_t len){
    char* temp = s;
    s = new char[len+1];
    if(len > strlen(temp))
        len = strlen(temp);
    strncpy(s, temp, len);
    s[len] = 0;
    return (*this);
}
char const* Str::c_str(){
    return const_cast<char const*>(s);
}