## 為什麼要刪除operator=
> Caesar08: 是的。不過再額外提供operator=給assign value比較好

作者本身有提到在這部分沒有補上，自己補上比較好，比較大的問題是
如果不移除就沒問題了，只是會出一個小小語意問題

> 如果不加 Middle& operator=(const Middle &)=delete
那 test[idx]=test[idx];的語意會跟一般使用者所想的不一樣
test[idx]=test[idx]是呼叫的是 Middle 的 copy assignment operator
不是 int=int


