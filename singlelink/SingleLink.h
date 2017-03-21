/*****************************************************************
Name : 
Date : 2016/11/20
By   : CharlotteHonG
Final: 2016/11/20
*****************************************************************/
#ifndef SINGLELINK_H
#define SINGLELINK_H value
//----------------------------------------------------------------
// 結構
typedef struct Node Node;
struct Node {
    void* data;
    Node* next;
};
//----------------------------------------------------------------
// 初始化亂數種子
int rand_int(int low, int up);
// 取亂數(不包含up)
void rand_init();
// 動態整數
int* dint(int data);
//----------------------------------------------------------------
// 創建節點
Node* create(int* data);
// 印出節點
void pri(Node* n);
// 查找長度
size_t len(Node* n);
// 存取
Node* at(Node* n, size_t idx);
// 插入
void insert_data(Node* n, size_t idx, int* data);
// 刪除
void del(Node* n, size_t idx);
//----------------------------------------------------------------
// 找結尾
Node* tail(Node* n);
// 從尾端加入
void append(Node* n, int* data);
// 印出全部
void pri_all(Node* n);
// 刪除全部
void del_all(Node* n);
//----------------------------------------------------------------
// GCC單檔編譯，視情況自行註解
#include "singlelink.c"
//----------------------------------------------------------------
#endif