/*****************************************************************
Name :
Date : 2017/05/28
By   : CharlotteHonG
Final: 2017/05/28
*****************************************************************/
#ifndef NUM_HPP
#define NUM_HPP


using namespace std;
template<class T>
class Num {
public:
    Num(T num): num(num) {}
public:
    Num<T> operator+=(const Num& rhs);

    template<class T2>
    friend ostream& operator<<(ostream& os, const Num<T2>& rhs);
    template<class T2>
    friend istream& operator>>(istream& is, Num<T2>& rhs);
    
    template<class T2>
    friend bool operator!=(const Num<T2>& lhs, const Num<T2>& rhs);
    template<class T2>
    friend bool operator==(const Num<T2>& lhs, const Num<T2>& rhs);

    explicit operator T&();
private:
    T num;
};
#include "Num.cpp"

#endif // NUM_HPP
