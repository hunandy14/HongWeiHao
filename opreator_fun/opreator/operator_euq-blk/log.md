# LOG記錄檔
## 2017/04/05
vector 的 end 居然不是最後一個地址，想說奇怪怎麼怎麼樣都怪怪的

copy() 跟 cpy_n() 存在著奇怪的關係

- copy() 複製 vector
- copy_n() 複製 元素




## 2017/03/21
因為沒有設置類別的空建構子導致 vector 調整大小或初始化時出問題
這坑也太大了，特麼超級難找阿

```cpp
class classA
{
public:
    classA(int i){}
};

vector<classA> v;
v.resize(1);
```

因為沒有空建構子vector初始化不知道要填什麼




> 為什麼過去的我這麼好運QQ



</br></br></br>

## 2017/03/21
我在 Block 的建構子上加上了 const　結果就出問題了，找了好久

```cpp
Block(Raw const & img, size_t pos);
```

運氣真好之前居然沒碰到，只是偶然的不寫 const



</br></br></br>

## 2017/03/21
> 運氣真好之前都沒碰到...可能是一切都照高標準來的幸運吧

### 定義不完全
如果將定義移動至外面會導致定義不完全出現

`field '' has incomplete type ''`

#### 資料成員

```cpp
class Raw {
private:
    class Block;
    Block data;
};

class Raw::Block{

}
```

解決辦法先不要實作利用 `指標` 或 `vector` 規避

```cpp
class Raw {
private:
    class Block;
    vector<Block> data;
    Block* data2;
};

class Raw::Block{

}
```


#### 副函式
定義副函式的時候也會出現這個問題

```cpp
class Raw {
private:
    class Block;
    Block blk(size_t pos){}
};

class Raw::Block{

}
```

解決辦法將定義移出至宣告後先不要讓他實做

```cpp
class Raw {
private:
    class Block;
    Block blk(size_t pos)
};

class Raw::Block{

}

Raw::Block Raw::blk(size_t pos){

}
```













