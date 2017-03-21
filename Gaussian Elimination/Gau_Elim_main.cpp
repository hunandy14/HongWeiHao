/****************************************************************
Name : 
Date : 2016/12/24
By   : CharlotteHonG
Final: 2016/12/25

高斯消去
1. 正規化＝依照階層讓頭變1，記下正規化倍數n (返回n)
2. 正向消去＝扣除第一行的n倍
3. 反向帶入＝扣除接下下所有的階層（這個階層要乘以頭街頭以便能消除）
*****************************************************************/
#include <iostream>
#include "Gau_Elim.hpp"
#include "Gau_Elim.cpp"// gcc 單檔編譯
using namespace std;
using namespace gau;
/*==============================================================*/
int main(int argc, char const *argv[]){
    Gau_Elim a{
        {2, 3, -1, -2}, 
        {1, -1, 1, 8}, 
        {3, -2, -9, 9}
    };
    // 正向消去
    cout << "forward" << endl;
    for(unsigned i = 0; i < 3; ++i) 
        a.forward(i);
    // 反向帶入
    cout << "reverse" << endl;
    for(unsigned i = 3; i > 0; --i) {
        a.reverse(i-1);
    }
    return 0;
}
/*==============================================================*/