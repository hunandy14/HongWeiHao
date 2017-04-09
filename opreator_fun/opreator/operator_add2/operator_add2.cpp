/*****************************************************************
Name : operator 移動運算子的實現
Date : 2017/03/25
By   : CharlotteHonG
Final: 2017/04/07
*****************************************************************/
#include <iostream>
#include <iomanip>
#include <numeric>
#include <vector>
#include <initializer_list>
#include <algorithm>
using namespace std;

template <typename T>
class List{
public:
    // 建構子
    template<class ...U>
    List(U ...args): len(sizeof...(args)), 
        list(new T[len]{args...}) {}
    // 複製建構子
    List(List const & rhs): len(rhs.len), list(new T[rhs.len]){
        cout << "  Copy-ctor" << endl;
        std::copy_n(rhs.list, len, this->list);
    }
    // 移動建構子
    List(List && rhs): len(0), list(nullptr){
        cout << "  Move-ctor" << endl;
        (*this) = std::move(rhs);
    }
    // 解構子
    ~List(){
        if(this->list != nullptr)
            delete [] this->list;
    }
    List & operator+=(List const & rhs){
        for(unsigned i = 0; i < len; ++i)
            this->list[i] += rhs.list[i];
        return (*this);
    }
public:
    List & pri(string name=""){
        if(name != "")
            cout << name << endl;
        for(unsigned i = 0; i < this->len; ++i) {
            cout << setw(3) << (*this).list[i];
        } cout << endl;
        return (*this);
    }
public:
    // 複製函式
    List & operator=(List const & rhs){
        cout << "  Copy" << endl;
        // 相同則離開
        if(this == &rhs)
            return (*this);
        // 清除本地資源
        this->~List();
        // 重建資源
        this->list = new T[len];
        this->len = rhs.len;
        // 深度拷貝
        std::copy_n(rhs.list, len, this->list); 
        return (*this);
    }
    // 移動函式
    List & operator=(List && rhs){
        cout << "  Move-op" << endl;
        // 相同則離開
        if(this == &rhs)
            return (*this);
        // 清除本地資源
        this->~List();
        // 淺度拷貝
        this->len = rhs.len;
        this->list = rhs.list;
        // 清空來源地址
        rhs.list = nullptr;
        rhs.len = 0;
        return (*this);
    }
public:
    size_t len;
    T* list;
};
// 一般運算子
template<typename T>
List<T> operator+(List<T> const & lhs, List<T> const & rhs){
    return List<T>(lhs) += rhs;
}
// 移動運算子
template<typename T>
List<T> operator+(List<T> && lhs, List<T> const & rhs){
    cout << "  Move-lhs" << endl;
    return List<T>(std::move(lhs+=rhs));
}
template<typename T>
List<T> operator+(List<T> const & lhs, List<T> && rhs){
    cout << "  Move-rhs" << endl;
    return List<T>(std::move(rhs+=lhs));
}
//================================================================
int main(int argc, char const *argv[]){
    List<int> a{3, 2, 1};
    List<int> b{1, 2, 3};
    cout << "a=" << a.list << endl;
    cout << "b=" << b.list << endl;

    cout << "move op" << endl;
    // List<int> c = (move(a) +(b));
    List<int> c = a + a + a;
    cout << "d=" << c.list << endl;
    c.pri();

    return 0;
}
//=================================================================