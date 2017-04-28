/*****************************************************************
Name :
Date : 2017/04/21
By   : CharlotteHonG
Final: 2017/04/21

�ѦҡG
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
        // ��0��-1�אּ�̤j��
        for(auto&& j : adja)
            for(auto&& i : j)
                i<=0? i=INT_MAX: i;
    }
    // �L�X�w�䪺�Z��
    void pri_dist(){
        cout << "dist = ";
        for(auto&& i : dist) {
            cout << i << ", ";
        } cout << endl;
    }
    // �L�X�w�䪺�Z��
    void pri_s(){
        cout << "dist = ";
        for(auto&& i : s) {
            cout << i << ", ";
        } cout << endl;
    }
    // �L�X�w�䪺���|
    void pri_path(){
        cout << "path = ";
        for(auto&& i : path) {
            cout << (i+1) << ", ";
        } cout << endl;
    }
    // ��̤p��
    int get_min(vector<int> arr, vector<bool> s){
        // �ư����n��
        for(unsigned i = 0; i < adja_len; ++i) {
            if(s[i]==1) arr[i]=INT_MAX;
            if(arr[i]==0) arr[i]=INT_MAX;
        }
        std::partial_sort (arr.begin(), arr.begin(), arr.end());
        return arr[0];
    }
    // �j�����|
    int search_path(int num){
        if(num==-1)
            return -1;
        s[num]=1;
        // ��s�Z��
        int flag=0;
        // pri_s(); 
        for(unsigned i = 0; i < adja_len; ++i) {
            // ���L �S���|(�L���Z��) and �w�g�T�w�̵u
            if(adja[num][i]!=INT_MAX and s[i]==0) {
                // cout << "adja[num][i]=" << adja[num][i] << endl;
                // pri_path();
                // pri_dist();
                // �S�o������ɭ�(�Ĥ@��)
                if(dist[i]==0) {
                    // cout << "num=" << num << endl;
                    // cout << "=" << dist[num];
                    // cout << "+" << adja[num][i] << "||";
                    dist[i] += dist[num];   // �H�ۤv���_�I���[�ۤv
                    dist[i] += adja[num][i];// �[�W�j���쪺�ؼ�
                    
                    // cout << "dist[i]=" << dist[i] << endl;
                    // cout << "i=" << i << endl;
                }
                // ���o����A��̵u���I
                else if(dist[i] > dist[num]+adja[num][i]) {
                    dist[i] = dist[num]+adja[num][i];
                    // pri_path();
                    // cout << "i=" << i << endl;
                    // cout << "dist[i]=" << dist[i] << endl;
                    // cout << "num=" << num << endl;
                    // cout << "path[times]=" << path[times] << endl;
                    // �諸�I��W�����I�@�ˡA�����W�������|
                    if(path[times] == (size_t)num and flag==0) {
                        // cout << "***" << endl;
                        ++flag;
                        path[times-1] = path[times];
                        --times;
                    }
                }
            }
        }
        // ��̤p��
        int min = get_min(dist, s);
        // �U�@�ӷj�����|���I
        for(unsigned i=0; i < adja_len; ++i) {
            if(s[i]==0) {// �u�j�٨S�T�{�̵u�Z����
                if(dist[i] == min){ // ���@�ӬO����쪺�̤p��
                    if(path[times] == adja_len-1){ // ���ؼи��|�F
                        path.resize(times+1);
                        return -1;
                    } else {
                        // pri_path();
                        path[++times]=i; // �������|
                    }
                    return i;
                }
            }
        }
        return -1;
    }
    // ��̵u���|�t��k
    void dijkstra(size_t a){
        star_p=a-1;
        path[0]=star_p;
        // �U���j���I
        int next=star_p;
        // �j��
        for(size_t i = 0; i < adja_len-1; ++i){
            // cout << "   next=" << next << endl;
            next = search_path(next);
        }
        // �ɺ|
        for(size_t i = adja_len-1; i > 0 ; --i){
            if(s[i]==0) {
                search_path(i);
            }
        }
    }
private:
    size_t adja_len;  // ���I�ƶq
    vector<vector<int>> adja; //�F���x�}
    vector<int> dist; // �C���I���̤p�Z��
    vector<bool> s;   // ��1�A�T�{�̤p�Z��
    vector<size_t> path; //���|
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
    // // ���L��T
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
    // ���L��T
    b.pri_dist();
    b.pri_path();
    return 0;
}
//================================================================
