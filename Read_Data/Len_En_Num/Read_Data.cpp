/*****************************************************************
Name : �xȡ�ض���ʽ�ļ�
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
    size_t end_mode = 0; // 0.�a0;  1.�aӢ��
    // �a����
    auto Append_Num = [&]() {
        if(!isalpha(v[idx + 1][0])) // ��һ���ǔ��־ͽ����a��
            data[line_len-1][data[line_len-1].size()-1] += v[++idx];
        --item_len;
    };
    // �_ʼ̎��
    for(; idx < v.size()-2; ++idx) {
        // ���^�L�ȕr
        if(item_len == 0){
            ++line_len;
            item_len = stoi(v[idx]);
            data.emplace_back(vector<string> {v[idx]});
        }
        // ���^�L����Ӣ���f�p
        else if(isalpha(v[idx][0])) {
            data[line_len-1].emplace_back(v[idx]);
            if(item_len == 1) { // ����һ���z��
                if(isalpha(v[idx + 2][0])) { // ����һ�Mȱ����
                    --item_len;
                    end_mode = 1;
                    continue;
                }
            }
            Append_Num(); // �a����
            end_mode = 0;
        }
    }
    // �Yβ̎��
    if(item_len==1 && end_mode ==0) {
        // �aһ�M
        data[line_len-1].emplace_back(v[idx]);
        Append_Num();
    } else {
        if(end_mode==0) {
            data.emplace_back(vector<string> {v[idx]}); // �a 0
        } else {
            data[line_len-1].emplace_back(v[++idx]); // �aӢ��
        }
    }
    return data;
}
int main(int argc, char const *argv[]) {
    auto list = ReadFile(file_name);
    auto data = Data_Slice(list);
    // �鿴���S���
    for(auto&& j : data) {
        for(auto&& i : j) {
            cout << i << ", ";
        } cout << endl;
    }
}
