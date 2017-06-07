/*****************************************************************
Name : 讀取特定格式文件
Date : 2017/06/06
By   : CharlotteHonG
Final: 2017/06/06
*****************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;
constexpr char file_name[] = "Data.txt";

auto ReadFile(string file_name) {
    vector<string> v;
    fstream fs(file_name, ios::in);
    for(string str; fs >> str;) {
        v.emplace_back(str);
    } fs.seekg(0, fs.beg);
    fs.close();
    return v;
}
auto Data_Slice(vector<string>& v) {
    vector<vector<string>> data;
    size_t item_len = 0, idx = 0, line_len=0;
    size_t end_mode = 0; // 0.補0;  1.補英文
    // 補數字
    auto Append_Num = [&]() {
        if(!isalpha(v[idx + 1][0])) // 下一個是數字就接著補上
            data[line_len-1][data[line_len-1].size()-1] += v[++idx];
        --item_len;
    };
    // 開始處理
    for(; idx < v.size()-2; ++idx) {
        // 是頭長度時
        if(item_len == 0){
            ++line_len;
            item_len = stoi(v[idx]);
            data.emplace_back(vector<string> {v[idx]});
        }
        // 非頭長度是英文遞減
        else if(isalpha(v[idx][0])) {
            data[line_len-1].emplace_back(v[idx]);
            if(item_len == 1) { // 最後一個檢查
                if(isalpha(v[idx + 2][0])) { // 最後一組缺數字
                    --item_len;
                    end_mode = 1;
                    continue;
                }
            }
            Append_Num(); // 補數字
            end_mode = 0;
        }
    }
    // 結尾處理
    if(item_len==1 && end_mode ==0) {
        // 補一組
        data[line_len-1].emplace_back(v[idx]);
        Append_Num();
    } else {
        if(end_mode==0) {
            data.emplace_back(vector<string> {v[idx]}); // 補 0
        } else {
            data[line_len-1].emplace_back(v[++idx]); // 補英文
        }
    }
    return data;
}
int main(int argc, char const *argv[]) {
    auto list = ReadFile(file_name);
    auto data = Data_Slice(list);
    // 查看二維陣列
    for(auto&& j : data) {
        for(auto&& i : j) {
            cout << i << ", ";
        } cout << endl;
    }
}
