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