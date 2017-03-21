/*****************************************************************
Name : 
Date : 2016/11/23
By   : CharlotteHonG
Final: 2016/12/05
*****************************************************************/
#include <iostream>
#include <vector>
using namespace std;
using unt = unsigned int;

// 遊戲
class Game{
public:
    // 初始化答案
    Game(string setans):
        ans{setans}, count(2), times(0){}
    // 驗證答案
    bool veri(string str);
    // 印出結果
    void pri();
    // A與B的數值
    const unt & operator[](size_t i) const{
        return count[i];
    }
private:
    string ans;
    vector<unt> count;
    unt times;
};
/*=======================================================*/
int main(int argc, char const *argv[]){
    Game game("0123");
    cout << game.veri("3112") << endl;
    cout << game[0] << "A" << game[1] << "B" << endl;
    cout << game.veri("0123") << endl;
    cout << game[0] << "A" << game[1] << "B" << endl;
    cout << "--------------------------------" << endl;
    Game game2("3210");
    cout << game2.veri("3210") << endl;
    cout << game2[0] << "A" << game2[1] << "B" << endl;
    return 0;
}
/*=======================================================*/
// 驗證答案
bool Game::veri(string str){
    if (str.size() != this->ans.size()){
        cout << "Input Size Error."
        << "Size is " << this->ans.size() << endl;
        return 0;
    }
    // 初始化計數器(計數A與B)
    for(auto&& i : count)
        i=0;
    // 尚未驗證的答案
    vector<int> idx;
    // 找A並記錄剩下的位置
    for (unsigned i = 0; i < this->ans.size(); ++i){
        if (this->ans[i] == str[i]){
            ++count[0];
        }// 記下剩下的位置
        else{
            idx.push_back(i);
        }
    }
    // 答案正確
    if (idx.size()==0){
        return 1;
    }
    // 找B有幾個
    vector<int> ans_idx=idx; //(答案的索引 / 輸入的索引)
    for(auto&& j : ans_idx) {
        for (int i = idx.size()-1; i >= 0; --i){
            // 不比對已標記的位置
            if (idx[i]==-1)
                --i;
            // 答案與輸入比對
            if (this->ans[j] == str[idx[i]]){
                ++count[1];
                //標記已經找過的
                idx[i]=-1;
                break;
            }
        }
    }
    // 記錄驗證次數
    ++times;
    return 0;
}
// 印出結果
void Game::pri(){
    cout << count[0] << "A" << count[1] << "B" <<
        "[" << times << "]" << endl;
}
