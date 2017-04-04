/*****************************************************************
Name : 
Date : 2017/03/22
By   : CharlotteHonG
Final: 2017/03/22

loveflames
*****************************************************************/
#include <iostream>
#include <vector>
#include <tuple>
#include <initializer_list>
using namespace std;

template <typename T>
class Arr {
public:
    // 方法0
    // Arr(initializer_list<T> n): len(n.size()), arr(new T[len]) {
    //     for(unsigned i = 0; i < n.size(); ++i) {
    //         auto it = n.begin() ;
    //         arr[i] = *(it+i);
    //     }    
    // }

    // 方法1
    template<class   ...U>
    Arr(U ...args): len(tuple_size<decltype(make_tuple(args...))>::value), 
    arr(new T[tuple_size<decltype(make_tuple(args...))>::value]
        {args...})
    {}

    // 方法2
    // template<class ...U>
    // Arr(U ...args): len(sizeof...(args)), 
    // arr(new T[sizeof...(args)]{args...}){}

    Arr(Arr const & rhs){
        cout << "123" << endl;
    }


    size_t len;
    T* arr;
    void pri(){
        cout << "pri=" << endl;
        for(unsigned i = 0; i < len; ++i){
            cout << arr[i] << ", ";
        } cout << endl;
    }
};

int main(int argc, char const *argv[]){
    Arr<int> a(1, 2, 3);
    // Arr<int> b=a;
    a.pri();
    return 0;
}