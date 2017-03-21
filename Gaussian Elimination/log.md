## 20161225

這裡的i因為是無號整數，所以扣到0在扣一次就溢位了

```cpp
    for(unsigned i = 2; i >= 0; --i) {
        cout << "i=" << i << endl;
    }
```