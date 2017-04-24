/*****************************************************************
Name :
Date : 2017/04/22
By   : CharlotteHonG
Final: 2017/04/22
*****************************************************************/
#include <iostream>
using namespace std;

#define V 8
int path_arr[V], c=1; // 路徑陣列
//----------------------------------------------------------------
// 印出路徑(遞歸查路徑)
void printPath(int parent[], int j){
    if (parent[j] == -1)
        return;
    printPath(parent, parent[j]);
    printf("%d ", j);
    // 儲存路徑
    path_arr[c++]=j;
}
// 印出路徑
void printSolution(int dist[], int n,
    int parent[], int src, int end)
{
    printf("Vertex\t  Distance\tPath\n");
    printf("%d->%d \t\t%d\t%d ", src, end, dist[end], src);
    printPath(parent, end);// 遞迴一直印出
}
//----------------------------------------------------------------
// 返回最小距離的點
int minDistance(int dist[], bool sptSet[]){
    int min = INT_MAX, min_index;
    for (int i = 0; i < V; i++)
        // 跳過已知最短的 , 並找最短的
        if (sptSet[i] == false && dist[i] <= min){
            min = dist[i];
            min_index = i;
        }
    return min_index;
}
// dijk演算法
void dijkstra(int graph[V][V], int src, int end){
    int dist[V];   // 頂點的最短距離
    bool sptSet[V];// 頂點的最短路徑，已被找到
    int parent[V]; // 頂點的最短路徑，來自哪個點
    // 初始化
    for (int i = 0; i < V; i++){
        parent[i] = -1;
        dist[i] = INT_MAX;
        sptSet[i] = false;
        path_arr[i] = -1;
    }
    path_arr[0] = src; // 放入起點
    dist[src] = 0;
    // 依序找點
    for (int j = 0; j < V-1; j++){
        // 下一個最短距離是哪個點
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;// 找過的標記
        for (int v = 0; v < V; v++)
            if (sptSet[v]==0 &&   // 還沒確認最短
                graph[u][v]!=0 && // 下個點是有效距離
                dist[u]+graph[u][v] < dist[v]) // 當前路徑比較優
            {
                parent[v] = u; // 更新路徑
                dist[v] = dist[u] + graph[u][v]; // 更新距離
            }
    }
    // 印出路徑
    printSolution(dist, V, parent, src, end);
}
//----------------------------------------------------------------
int main() {
    // 鄰接矩陣
    int graph[V][V] = {
        {0, 10, 0, 0, 0, 0, 0, 10},
        {10, 0, 10, 0, 0, 0, 0, 10},
        {0, 10, 0, 10, 0, 0, 100, 0},
        {0, 0, 10, 0, 10, 10, 0, 0},
        {0, 0, 0, 10, 0, 10, 0, 0},
        {0, 0, 0, 10, 10, 0, 10, 0},
        {0, 0, 100, 0, 0, 10, 0, 10},
        {10, 10, 0, 0, 0, 0, 10, 0},
    };
    // 找最短路徑
    dijkstra(graph, 2, 4);
    printf("\n\n");
    // 印出路徑
    for (int i = 0; i < V-1 ; ++i){
        if(path_arr[i] != -1)
            printf("%d, ", path_arr[i]);
    } printf("\n");
    return 0;
}
