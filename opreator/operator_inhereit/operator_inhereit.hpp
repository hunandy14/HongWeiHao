/*****************************************************************
Name : 無損繼承 operator
Date : 2017/03/17
By   : CharlotteHonG
Final: 2017/03/17
*****************************************************************/
#include <iostream>
#include <vector>
#include <initializer_list>
using namespace std;

template <typename T>
class Arr {
public:
    Arr(initializer_list<T> i): arr(i){}
    Arr & operator=(Arr<T> const & rhs) = default;
public:
    void pri(string name=""){
        cout << name << " = ";
        for(auto&& i : arr) {
            cout << i << ", ";
        }cout << endl;
    }
public:
    // 重載下標符號
    T & operator[](size_t idx){
        return const_cast<T&>(static_cast<const Arr&>(*this)[idx]);
    }
    const T & operator[](size_t idx) const{
        return arr[idx];
    }
    // 重載+=符號
    template <typename T1> friend
        Arr<T1> operator+(Arr<T1> const &lhs, Arr<T1> const &rhs);
    Arr & operator+=(Arr const& rhs){
        for(unsigned i = 0; i < arr.size(); ++i)
            (*this)[i] += rhs[i];
        return (*this);
    }
    Arr & operator+=(T const &rhs){
        for(unsigned i = 0; i < arr.size(); ++i)
            (*this)[i] += rhs;
        return (*this);
    }
protected:
    vector<T> arr;
};
// 重載+符號(全域函式)
template <typename T1>
Arr<T1> operator+(Arr<T1> const &lhs, Arr<T1> const &rhs){
    return Arr<T1>(lhs) += rhs;
}
//----------------------------------------------------------------
class Arr_int: public Arr<int>{
public:
    Arr_int(initializer_list<int> i): Arr<int>(i), i(-1){}
    Arr_int(Arr<int> const & rhs):Arr<int>(rhs), i(-1){}
    Arr_int & operator=(Arr<int> const & rhs){
        this->Arr<int>::operator=(rhs);
        return (*this);
    }
public:
    int i;
};

using uch = unsigned char;
class Arr_uch: public Arr<uch>{
public:
    // 更換別名
    decltype(arr) & mask = arr;
public:
    Arr_uch(initializer_list<uch> i): Arr<uch>(i){}
    Arr_uch(Arr<uch> const & rhs):Arr<uch>(rhs){}
    Arr_uch & operator=(Arr<uch> const & rhs){
        (*this).Arr<uch>::operator=(rhs);
        return (*this);
    }
};
//----------------------------------------------------------------