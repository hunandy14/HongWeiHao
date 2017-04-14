#### 不定引數要怎麼區分
List a(len);
List b{len};

#### ::怎麼取值的
```cpp
tuple_size<decltype(make_tuple(args...))>::value
```



#### <>怎麼取值的

```cpp
get<0>
```



#### 他們為什麼不一樣

```cpp
tuple<int, const char*, double> t{1, "Foo", 3.14};
```

```cpp
tuple<int, const char*, double> t={1, "Foo", 3.14};
```


#### decltype

```cpp
auto fun() -> decltype(auto){}

decltype(auto) fun(){}

template<class T, class T2>
auto fun(T a,  T2 b) -> decltype(a+b){
    return a+b;
}
```


#### std::out_of_range 練習
at(i)：STL 系列最常出來鬧場的人，拿陣列裡面的第 i 個人，很貼心地幫你做 bound checking，讓你在如果你手殘或是你手賤或是你就是賤存取到超出範圍的項目，就會丟個 std::out_of_range 例外出來而不會被 OS 殺掉，當然前提是你要抓住這個例外…不然你就是看到 SIGABRT 了。










