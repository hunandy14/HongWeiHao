/*****************************************************************
Name :
Date : 2017/04/24
By   : 
Final: 2017/04/24
*****************************************************************/
#include <iostream>
#include <vector>
#include <initializer_list>
using namespace std;

class Adji{
public:
    // 初始化
    Adji(initializer_list<vector<int>> mat):
        graph(mat), vert(mat.size()),
        dist(vert), parent(vert), sptSet(vert)
    {}
    // 印出路徑(遞歸查路徑)
    void printPath(int i){
        if (parent[i] == -1)
            return;
        printPath(parent[i]);
        printf("%d ", i);
        // 儲存路徑
        path.push_back(i);
    }
    // 印出路徑
    void printSolution(int src, int end){
        printf("Vertex\t  Distance\tPath\n");
        printf("%d->%d \t\t%d\t%d ", src, end, dist[end], src);
        printPath(end);// 遞迴一直印出
        cout << endl;
    }
    // 返回最小距離的點
    int minDistance(){
        int min = INT_MAX, min_index;
        for (int i = 0; i < vert; i++){
            // 跳過已知最短的 , 並找最短的
            if (sptSet[i] == false && dist[i] <= min){
                min = dist[i];
                min_index = i;
            }
        }
        return min_index;
    }
    // dijk演算法
    auto&& dijkstra(int src, int end){
        // 初始化資料
        for(int i = 0; i < vert ; ++i) {
            dist[i] = INT_MAX;
            parent[i] = -1;
            sptSet[i] = false;
            path.resize(0);
        }
        // 放入起點
        path.push_back(src);
        dist[src] = 0;
        // 依序找點
        for (int j = 0; j < vert-1; j++){
            // 下一個最短距離是哪個點
            int u = minDistance();
            sptSet[u] = true;// 找過的標記
            for (int v = 0; v < vert; v++){
                if (sptSet[v]==0 &&   // 還沒確認最短
                    graph[u][v]!=0 && // 下個點是有效距離
                    dist[u]+graph[u][v] < dist[v]) // 當前路徑比較優
                {
                    parent[v] = u; // 更新路徑
                    dist[v] = dist[u] + graph[u][v]; // 更新距離
                }
            }
        }
        // 印出路徑
        printSolution(src, end);
        return path;
    }
    // 比較是否在路徑內
    int compare(vector<int>& rhs){
        unsigned flag=0;
        for(unsigned j=0; j<path.size()-rhs.size()+1; ++j){
            for (unsigned i=0; i < rhs.size(); ++i){
                if( rhs[i] == path[i+j] ){
                    flag++;
                }
            }
            if(flag==rhs.size()){
                return 1;
            }
            flag=0;
        }
        return 0;
    }
public:
    vector<vector<int>> graph; // 鄰接矩陣
    int vert;
    vector<int> dist;   // 頂點的最短距離
    vector<int> parent; // 頂點的最短路徑，來自哪個點
    vector<bool> sptSet;// 頂點的最短路徑，已被找到
    vector<int> path;
};
//================================================================
int main(int argc, char const *argv[]){
    Adji a{
        {0, 10, 0, 0, 0, 0, 0, 10},
        {10, 0, 10, 0, 0, 0, 0, 10},
        {0, 10, 0, 10, 0, 0, 100, 0},
        {0, 0, 10, 0, 10, 10, 0, 0},
        {0, 0, 0, 10, 0, 10, 0, 0},
        {0, 0, 0, 10, 10, 0, 10, 0},
        {0, 0, 100, 0, 0, 10, 0, 10},
        {10, 10, 0, 0, 0, 0, 10, 0},
    };
    // 最短路徑(輸入)
    auto path1 = a.dijkstra(1, 6);
    auto path2 = a.dijkstra(2, 4);
    // 印出
    for(unsigned i = 0; i < path1.size(); ++i) {
        cout << path1[i] << ", ";
    } cout << endl;
    for(unsigned i = 0; i < path1.size(); ++i) {
        cout << path2[i] << ", ";
    } cout << endl;

    // 是否在已找出的最短路徑內
    vector<int> v{2, 3};
    cout << "a.compare(v)=" << a.compare(v) << endl;

    return 0;
}
//================================================================
