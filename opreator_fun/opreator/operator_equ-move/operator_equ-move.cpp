/*****************************************************************
Name : operator 移動語意的實現
Date : 2017/03/06
By   : CharlotteHonG
Final: 2017/03/25
*****************************************************************/
#include <iostream>
#include <iomanip>
#include <numeric>
#include <vector>
#include <initializer_list>
using namespace std;

template <typename T>
class List{
public:
    // 建構子
    List(initializer_list<T> n):
        len(n.size()), list(new T[len])
    {
        std::copy(n.begin(), n.begin() + n.size(), this->list);
    }
    // 複製建構子
    List(List const & rhs): len(rhs.len), list(new T[rhs.len]){
        std::copy(rhs.list, rhs.list + len, this->list);
    }
    List(List && rhs): len(rhs.len), list(new T[rhs.len]){
        (*this) = std::move(rhs);
    }
    // 解構子
    ~List(){
        if(this->list != nullptr) {
            delete [] this->list;
        }
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
    // 重載賦值符號
    List & operator=(List const & rhs){
        cout << "copy" << endl;
        // 相同則離開
        if(this != &rhs){
            // 清除原始資源
            this->~List();
            // 重建資源
            this->list = new T[len];
            this->len = rhs.len;
            // 深度拷貝
            std::copy(rhs.list, rhs.list + len, this->list); 
        }
        return (*this);
    }
    List & operator=(List && rhs){
        cout << "Move" << endl;
        // 相同則離開
        if(this != &rhs){
            // 清除原始資源
            this->~List();
            // 淺度拷貝
            this->len = rhs.len;
            this->list = rhs.list;
            // 清空來源地址
            rhs.list = nullptr;
            rhs.len = 0;
        }
        return (*this);
    }
public:
    size_t len;
    T* list;
};
/*==============================================================*/
int main(int argc, char const *argv[]){
    List<int> a{3, 2, 1};
    List<int> b{1, 2, 3};
    a.pri();

    a = move(b);
    a.pri();

    List<int> c = std::move(a);
    c.pri();
    return 0;
}
/*==============================================================*/