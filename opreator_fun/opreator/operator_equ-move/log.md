## 2017/03/26
移動語意，發現一個很神奇的問題

先說第一個問題，移動函式必須清空來源地址否則會造成有兩個指針指向同一個地址
這聽起來好像沒什麼時候，而實際上當程式結束時個別會執行個別的解構子
問題就在這裡，這裡會重複解構同一個地址，造成程序崩潰

```cpp
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
```


然後重點是這種崩潰居然能夠藉由一種莫名其妙的方式避免
這是會出問題的代碼

```cpp
    ~List(){
        if(this->list != nullptr) {
            delete [] this->list;
        }
    }
```

只要加上 `*this->list;` WTF 居然就不會因為重複解構而崩潰了

```cpp
    ~List(){
    	*this->list;
        if(this->list != nullptr) {
            delete [] this->list;
        }
    }
```

重點是神奇的點在於，一旦執行過一次不會當機的，再把 `*this->list;` 就不會當機了
他居然能夠被繼承，透過執行過一次有加那行代碼可以避免之後的編譯不會當機，即便已經刪除那行代碼。
如果已經不會當機，要重現當機就必須開新檔案，如果新檔案也不會當機就在開一個。

完整的程式

```cpp
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
        auto l = n.begin();
        for(unsigned i = 0; i < len; ++i) {
            list[i] = *(l+i);
        }
    }
    // 解構子
    ~List(){
        // *this->list;
        if(this->list != nullptr) {
            delete [] this->list;
            this->list = nullptr;
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
            // 清空來源
            // rhs.list = nullptr;
            // rhs.len = 0;
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

    a=move(b);


    return 0;
}
/*==============================================================*/
```



