/*****************************************************************
Name : 重載下標符號
Date : 2017/02/20
By   : CharlotteHonG
Final: 2017/02/20
*****************************************************************/
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Arr{
public:
    // 建構子
    Arr(int len): arr(len){
        iota(arr.begin(),arr.end(),1);
    }
    // 重載下標符號
    int & operator[](size_t idx){
        cout << "**Non_";
        return const_cast<int&>(static_cast<const Arr&>(*this)[idx]);
    }
    const int & operator[](size_t idx) const{
        cout << "**Const**" << endl;
        return arr[idx];
    }
private:
    vector<int> arr;
};

int main(int argc, char const *argv[]){
    // **Const**
    const Arr ca(5);
    cout << ca[0] << endl;
    // **Non-Const**
    Arr a(5);
    cout << a[0] << endl;
    return 0;
}