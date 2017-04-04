# 2017/03/31
## template 的 argv

## tuple 是用來集合各種不同型態變數的


## 原來 {} 與 () 是有區分的

```cpp
T v();
T v{};
T v={};
```

第二個是C++才有的新特性


### initializer_list
只有重載initializer_list
的話在這種情況下

```cpp
List<int> a{3, 2, 1};
List<int> a={3, 2, 1};
```

他們是相等的

```cpp
List<int> a(3, 2, 1);
```

這個則會找不到變數，因為他會去找有三個變數的建構函式


### template argv
這種情況下居然三個都相等

```cpp
Arr<int> a(1, 2, 3);
Arr<int> a{1, 2, 3};
Arr<int> a={1, 2, 3};
```

看過文章說，為了方便使用者讓 {} 與 () 相等
https://www.devbean.net/2012/11/biggest-changes-in-c11/
不知道有沒有相關


### tuple
以上都好以理解，令人崩潰的是

```cpp
tuple<int, const char*, double> t{1, "Foo", 3.14};
```

```cpp
tuple<int, const char*, double> t={1, "Foo", 3.14};
```

特麼這兩個為什麼不相等，改第二個就出事了




