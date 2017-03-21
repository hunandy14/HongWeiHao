/*****************************************************************
Name : 
Date : 2016/12/25
By   : CharlotteHonG
Final: 2016/12/25
*****************************************************************/
#include <iostream>
#include <iomanip>
#include <vector>
#include <initializer_list>

using namespace std;

namespace gau {
    // 正向消去
    void Gau_Elim::forward(size_t n){
        // 依階層消去
        for(unsigned i = 0; i < n; ++i) {
            this->sub(n, i);
            this->info();
        }
        this->nlz(n);
    }
    // 反向帶入
    void Gau_Elim::reverse(size_t n){
        size_t len = this->matrix.size();
        for(unsigned i = n+1; i < len; ++i) {
            this->sub(n, i);
            this->info();
        }
        this->nlz(n);
    }
    // 印出
    void Gau_Elim::info(){
        for(auto&& j : matrix) {
            for(auto&& i : j) {
                cout << setw(priw) << i;
            }cout << endl;
        }cout << endl;
    }

    
    // 正規化(最高次方化簡為1)
    void Gau_Elim::nlz(size_t n){
        // 輸入錯誤
        if (n>=this->matrix.size())
            return;
        // 最高次方
        size_t idx = this->high(n);
        // 已經為最簡離開
        if (this->matrix[n][idx]==1)
            return;
        // 化簡
        this->zoom(n, 1, matrix[n][idx]);
        this->info();
        return;
    }
    // 相減 a-b (b適應a)
    void Gau_Elim::sub(size_t a, size_t b, int idx=-1){
        // 輸入錯誤
        size_t len = this->matrix.size();
        if (a>=len or b>=len)
            return;
        // 找b最高次方
        if (idx < 0 or idx >= (int)this->matrix[0].size())
            idx = this->high(b);
        // 最高次方相差的比率
        double ratio = matrix[a][idx] / matrix[b][idx];
        // 通分後相減
        for (unsigned i = 0; i < matrix[0].size(); ++i)
            this->matrix[a][i] -= this->matrix[b][i]*ratio;
    }
    // 找最高次方
    size_t Gau_Elim::high(size_t n){
        for (unsigned i = 0; i < this->matrix[0].size(); ++i)
            if (matrix[n][i] != 0)
                return i;
        // 回傳長度表示錯誤
        return this->matrix[0].size();
    }
    // 調整倍率
    void Gau_Elim::zoom(size_t n, double in=1, double out=1){
        for (unsigned i = 0; i < this->matrix[n].size(); ++i){
            if (this->matrix[n][i]==0)
                ++i;
            this->matrix[n][i] *= (in/out);
        }
    }
} // gau