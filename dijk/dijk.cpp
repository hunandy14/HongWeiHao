/*****************************************************************
Name :
Date : 2017/04/21
By   : CharlotteHonG
Final: 2017/04/21

參考：
1. http://www.wutianqi.com/?p=1890
2. https://goo.gl/oV8aD8
*****************************************************************/
#include <iostream>
#include <vector>
#include <initializer_list>
#include <algorithm>
using namespace std;

class Dijk{
public:
    Dijk(initializer_list<vector<int>> i): adja_len(i.size()),
        adja(i), dist(adja_len), s(adja_len), path(adja_len-1)
    {
        // 把0或-1改為最大值
        for(auto&& j : adja)
            for(auto&& i : j)
                i<=0? i=INT_MAX: i;
    }
    // 印出已找的距離
    void pri_dist(){
        cout << "dist = ";
        for(auto&& i : dist) {
            cout << i << ", ";
        } cout << endl;
    }
    // 印出已找的距離
    void pri_s(){
        cout << "dist = ";
        for(auto&& i : s) {
            cout << i << ", ";
        } cout << endl;
    }
    // 印出已找的路徑
    void pri_path(){
        cout << "path = ";
        for(auto&& i : path) {
            cout << (i+1) << ", ";
        } cout << endl;
    }
    // 找最小值
    int get_min(vector<int> arr, vector<bool> s){
        // 排除不要的
        for(unsigned i = 0; i < adja_len; ++i) {
            if(s[i]==1) arr[i]=INT_MAX;
            if(arr[i]==0) arr[i]=INT_MAX;
        }
        std::partial_sort (arr.begin(), arr.begin(), arr.end());
        return arr[0];
    }
    // 搜索路徑
    int search_path(int num){
        if(num==-1)
            return -1;
        s[num]=1;
        // 更新距離
        int flag=0;
        // pri_s(); 
        for(unsigned i = 0; i < adja_len; ++i) {
            // 跳過 沒路徑(無限距離) and 已經確定最短
            if(adja[num][i]!=INT_MAX and s[i]==0) {
                // cout << "adja[num][i]=" << adja[num][i] << endl;
                // pri_path();
                // pri_dist();
                // 沒得比較的時候(第一次)
                if(dist[i]==0) {
                    // cout << "num=" << num << endl;
                    // cout << "=" << dist[num];
                    // cout << "+" << adja[num][i] << "||";
                    dist[i] += dist[num];   // 以自己為起點先加自己
                    dist[i] += adja[num][i];// 加上搜索到的目標
                    
                    // cout << "dist[i]=" << dist[i] << endl;
                    // cout << "i=" << i << endl;
                }
                // 有得比較，選最短的點
                else if(dist[i] > dist[num]+adja[num][i]) {
                    dist[i] = dist[num]+adja[num][i];
                    // pri_path();
                    // cout << "i=" << i << endl;
                    // cout << "dist[i]=" << dist[i] << endl;
                    // cout << "num=" << num << endl;
                    // cout << "path[times]=" << path[times] << endl;
                    // 選的點跟上次的點一樣，消除上次的路徑
                    if(path[times] == (size_t)num and flag==0) {
                        // cout << "***" << endl;
                        ++flag;
                        path[times-1] = path[times];
                        --times;
                    }
                }
            }
        }
        // 找最小值
        int min = get_min(dist, s);
        // 下一個搜索路徑的點
        for(unsigned i=0; i < adja_len; ++i) {
            if(s[i]==0) {// 只搜還沒確認最短距離的
                if(dist[i] == min){ // 哪一個是剛剛找到的最小值
                    if(path[times] == adja_len-1){ // 找到目標路徑了
                        path.resize(times+1);
                        return -1;
                    } else {
                        // pri_path();
                        path[++times]=i; // 紀錄路徑
                    }
                    return i;
                }
            }
        }
        return -1;
    }
    // 找最短路徑演算法
    void dijkstra(size_t a){
        star_p=a-1;
        path[0]=star_p;
        // 下次搜索點
        int next=star_p;
        // 搜索
        for(size_t i = 0; i < adja_len-1; ++i){
            // cout << "   next=" << next << endl;
            next = search_path(next);
        }
        // 補漏
        for(size_t i = adja_len-1; i > 0 ; --i){
            if(s[i]==0) {
                search_path(i);
            }
        }
    }
private:
    size_t adja_len;  // 頂點數量
    vector<vector<int>> adja; //鄰接矩陣
    vector<int> dist; // 每個點的最小距離
    vector<bool> s;   // 為1，確認最小距離
    vector<size_t> path; //路徑
    size_t times = 0;
    size_t star_p;
    size_t end_p;
};
//================================================================
int main(int argc, char const *argv[]){
    // Dijk a{
    //     { 0, 10, -1, 30, 100},
    //     {-1,  0, 50, -1,  -1},
    //     {-1, -1,  0, -1,  10},
    //     {-1, -1, 20,  0,  60},
    //     {-1, -1, -1, -1,   0}
    // }; a.dijkstra();
    // // 打印資訊
    // a.pri_dist();
    // a.pri_path();

    Dijk b{
        {0, 7, 9, -1, -1, 14},
        {7, 0, 10, 15, -1, -1},
        {9, 10, 0, 11, -1, 2},
        {-1, 15, 11, 0, 6, -1},
        {-1, -1, -1, 6, 0, 9},
        {14, -1, 2, -1, 9, 0}
    }; b.dijkstra(1);
    // 打印資訊
    b.pri_dist();
    b.pri_path();
    return 0;
}
//================================================================
