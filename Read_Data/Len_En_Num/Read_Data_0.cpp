/*****************************************************************
Name :
Date : 2017/05/07
By   : CharlotteHonG
Final: 2017/05/07
*****************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;
constexpr char file_name[] = "text2.txt";
int main(int argc, char const *argv[]) {
    fstream fs(file_name, ios::in);
    vector<string> v;
    for(string str; fs >> str;) {
        v.emplace_back(str);
    } fs.seekg(0, fs.beg);

    size_t item_len = 0, idx = 0, line_len=0;
    vector<vector<string>> data;
    for(; idx < v.size()-2; ++idx) {
        if(item_len == 0) {  // �O�Y���׮�
            item_len = stoi(v[idx]);
            ++line_len;
            cout << endl << "[" << item_len << "] ";
            data.emplace_back(vector<string>{v[idx]});
        }
        else if(isalpha(v[idx][0])){ // �D�Y���׬O�^�廼��
            cout << v[idx];
            data[line_len-1].emplace_back(v[idx]);
            if(item_len == 1) {  // �̫�@���ˬd�U�U�ӬO�_���Ʀr
                if(isalpha(v[idx + 2][0])) { // �̫�@�կʼƦr
                    cout << ", ";
                    --item_len;
                    continue;
                }
            }
            // �U�@�ӬO�Ʀr�N����
            if(!isalpha(v[idx + 1][0])) {
                ++idx;
                cout << v[idx];
                data[line_len-1][data[line_len-1].size()-1] += v[idx];
            }
            cout << ", ";
            --item_len;
        }
    }
    // �ɵ���
    if(isalpha(v[idx][0])) {  // �O�^�廼��
        cout << v[idx];
        data[line_len-1].emplace_back(v[idx]);
        // �U�@�ӬO�Ʀr�N����
        if(!isalpha(v[idx + 1][0])) {
            ++idx;
            cout << v[idx];
            data[line_len-1][data[line_len-1].size()-1] += v[idx];
        }
        cout << ", ";
        --item_len;
    }
    cout << endl << "===========================================" << endl;
    for(unsigned i = 0; i < data.size(); ++i) {
        for(unsigned j = 0; j < data[i].size(); ++j) {
            cout << data[i][j] << ", ";
        }
        cout << endl;
    }



    // string str, str_p();
    // fs >> str_p;
    // size_t len=0;
    // for(unsigned i=0; i<tal_len; ++i) {
    //     fs >> str;
    //     // ���y�Y����
    //     if(len==0 and isalpha(str[0])) {
    //         len=stoi(str_p);
    //         cout << endl << "[" << len << "]";
    //     } else { // ���L
    //         cout << str_p << "";
    //     }
    //     // �J���Y���׬�0
    //     if(!isalpha(str[0]) and stoi(str) == 0) {
    //         cout << endl << "[" << len << "]";
    //     }
    //     // �O�^�廼��
    //     if(isalpha(str_p[0])) {
    //         cout << "";
    //         --len;
    //         // �s��^��
    //         if(isalpha(str[0])) {
    //             cout << ". ";
    //         }
    //     }else{
    //         cout << ", ";
    //     }
    //     str_p=str;
    // } cout << endl;

}