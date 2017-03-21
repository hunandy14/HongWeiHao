/*****************************************************************
Name : 
Date : 2016/11/03
By   : CharlotteHonG
Final: 2016/11/03

利用旗標存取達到重載[][]效果，不過有很多缺陷
- 讀取兩次[]，第二次會算成[][]
- [][]或[]不能夠賦值，因為他返回自己的參考
- 地址被重載 直接使用會回傳紀錄中元素 ，addressof() 取得真實地址
*****************************************************************/
#include <iostream>
#include <iomanip>
#include <numeric>
#include <vector>
#include <string>
#include <memory>
using namespace std;
typedef unsigned char uch;
typedef unsigned int unt;

class raw{
public:
    // 建構
    raw(int y, int x): y(y),x(x), img(x*y){
        iota(img.begin(), img.end(), 1);
    }
    // 印出
    void info(string name="Title"){
        cout << name << endl;
        // 印出元素
        for (unsigned j = 0; j < this->y; ++j){
            for (unsigned i = 0; i < this->x; ++i){
                cout << setw(3);
                cout << (int)img[(j*this->x)+i] << "";
            } cout << endl;
        } cout << endl;
    }
    // 二維讀取
    uch & at2d(int y, int x){
        int pos = (y*this->y)+x;
        return this->img[pos];
    }
    const uch & at2d(int y, int x) const{
        int pos = (y*this->y)+x;
        return this->img[pos];
    }
    // 重載
    operator uch&(){
        return this->img[this->idx];
    }
    raw & operator[](const size_t __n){
        if(this->flag==0) {
            // cout << "***1" << endl;
            this->flag = 1;
            this->idx = __n;
        }else{
            // cout << "***2" << endl;
            this->flag = 0;
            this->idx = (this->y*this->idx)+__n;
        }
        return (*this);
    }
private:
    unt y, x;
    vector<uch> img;
    int flag = 0;
    size_t idx = 0;
};
/*=======================================================*/
int main(int argc, char const *argv[]){
    raw a(3, 3);
    a.info("a");

    cout << "a[1][1] = " << (int)a[1][1] << endl;
    cout << "a[1]    = " << (int)a[1] << endl;

    return 0;
}
/*=======================================================*/