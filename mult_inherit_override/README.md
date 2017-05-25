多重繼承時函式名稱一樣怎麼重載虛擬函式
===


### 函式名稱的衝突
繼承重要的用途之一就是  
> 利用父類別的指針型別來建立子類別

```cpp
Fa* p = new SonA;
p->fun();
```

如此一來父類別可以提供預設的行為，子類別也可以視需求更改行為或增加資料成員。
宣告都用父類別用途意旨fun()可以接收所有子類，這讓程式設計得到很大彈性。

但是在多重繼承的時候如果兩個不同的父類別名稱一樣會造成"曖昧"衝突，並且子類別沒辦法重新指定函式行為。

```cpp
// Base class
class A1 {
public:
    virtual void draw(){cout << "A1" << endl;}
};
class A2{
public:
    virtual void draw(){cout << "A2" << endl;}
};
```

現在同時繼承他們

```cpp
class A: public A1, public A2 {
public:
    void draw(){cout << "A draw" << endl;}
};
```

你的 `draw()` 到底是重寫 `A1::draw()` 還是 `A2::draw()`？
> 沒有方法區別



</br></br></br>

### 新增中介轉發類別
我們可以繞個彎使用一對class重新導向函式名稱

```cpp
class AuxA1: public A1{
public:
    virtual void A1draw() = 0;
    virtual inline void draw(){A1draw();}
};
class AuxA2: public A2{
public:
    virtual void A2draw() = 0;
    virtual inline void draw(){A2draw();}
};
```

現在，你繼承 AuxA1 重寫新的 A1draw() 就等於重載 A1 的 draw()

```cpp
// 重載個別的 draw()
class A: public AuxA1, public AuxA2 {
public:
    void A1draw(){cout << "Override A1 draw" << endl;}
    void A2draw(){cout << "Override A2 draw" << endl;}
};
```

你可以放心的使用他們

```cpp
A1* a1 = new A;
A2* a2 = new A;
a1 -> draw();
a2 -> draw();
```



</br></br></br>

### 虛擬函式的彈性
另外重申一下虛擬繼承的好處，像這樣的 funtion

```cpp

class B{};
class D1: public B{};
class D2: public B{};

void fun(B* p){
    p->fun();
}
```

你可以根據輸入的指針不一樣選擇不一樣的行為

```cpp
B* b1 = nullptr

b1 = new D1;
fun(b1); // 呼叫 D1 fun
b1 = new D2;
fun(b2); // 呼叫 D2 fun
```



</br></br></br>

### 範例代碼

```cpp
/*****************************************************************
Name : 多重繼承時函式名稱一樣怎麼重載虛擬函式
Date : 2017/05/21
By   : CharlotteHonG
Final: 2017/05/26
*****************************************************************/
#include <iostream>
using namespace std;

// Base class
class A1 {
public:
    virtual void draw(){cout << "Base A1 draw" << endl;}
};
class A2{
public:
    virtual void draw(){cout << "Base A2 draw" << endl;}
};
//----------------------------------------------------------------
// 沒辦法重載個別的 draw()
// class A: public A1, public A2 {
// public:
//     void draw(){cout << "A draw" << endl;}
// };
//----------------------------------------------------------------
// 轉發 (明白的指定轉發函式)
class AuxA1: public A1{
public:
    virtual void A1draw() = 0;
    virtual inline void draw(){A1draw();}
};
class AuxA2: public A2{
public:
    virtual void A2draw() = 0;
    virtual inline void draw(){A2draw();}
};
// 重載個別的 draw()
class A: public AuxA1, public AuxA2 {
public:
    void A1draw(){cout << "Override A1 draw" << endl;}
    void A2draw(){cout << "Override A2 draw" << endl;}
};
//----------------------------------------------------------------
int main() {
    // 繼承的使用方式
    A1* a1 = new A;
    A2* a2 = new A;
    a1 -> draw();
    a2 -> draw();
    // 這樣仍然會因為曖昧不能使用
    // A a;
    // a.draw();
    return 0;
}
//----------------------------------------------------------------


```















