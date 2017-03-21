/*****************************************************************
Name : 
Date : 2016/11/19
By   : CharlotteHonG
Final: 2016/11/19
*****************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "SingleLink.h"
// 初始化亂數種子
int rand_int(int low, int up){
    return (int)((rand() / (RAND_MAX+1.0)) * (up - low) + low);
}
// 取亂數(不包含up)
void rand_init(){
    srand((unsigned)time(NULL));rand();
}
// 動態整數
int* dint(int data){
    int* num = (int*)malloc(sizeof(int));
    *num = data;
    return num;
}
//----------------------------------------------------------------
// 創建節點
Node* create(int* data){
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = data;
    n->next = NULL;
    return n;
}
// 印出節點
void pri(Node* n){
    printf("%d, ", *(int*)n->data);
}
// 查找長度
size_t len(Node* n){
    size_t lenth = 0;
    while( n->next != NULL && lenth<=999){
        n=n->next;
        lenth++;
    }
    return lenth;
}
// 存取
Node* at(Node* n, size_t idx){
    n=n->next;
    for(unsigned i = 0; i < idx; ++i) {
        if (n->next==NULL)
            return n;
        n=n->next;
    }
    return n;
}
// 插入
void insert_data(Node* n, size_t idx, int* data){
    // 旗標(插入點的前一個)
    Node* flag=NULL;
    if (idx == 0)
        flag = n;
    else
        flag = at(n, --idx);

    Node* temp = flag->next;
    flag->next = create(data);
    flag->next->next=temp;
}
// 刪除
void del(Node* n, size_t idx){
    if (len(n)==0)
        return;
    // 旗標(被刪除者的前一個)
    Node* flag=NULL;
    // 長度為1時
    if (len(n)==1)
        idx=0;
    // 設置旗標
    if (idx == 0)
        flag = n;
    else
        flag = at(n, --idx);

    Node* targ = flag->next;
    // 如果是最後一個
    if (targ == NULL)
        flag = at(n, len(n)-1-1);
    flag->next = flag->next->next;
    free(targ);
}
//----------------------------------------------------------------
// 找結尾
Node* tail(Node* n){
    size_t lenth = 0;
    while( n->next != NULL && lenth<=999){
        n=n->next;
        lenth++;
    }
    return n;
}
// 從尾端加入
void append(Node* n, int* data){
    tail(n)->next = create(data);
}
// 印出全部
void pri_all(Node* n){
    for (int i = 0; i < len(n); ++i){
        pri(at(n, i));
    } 
    printf("[len = %I64u]\n", len(n));
}
// 刪除全部
void del_all(Node* n){
    size_t node_len=len(n);
    for (unsigned i = 0; i < node_len; ++i){
        del(n, 0);
    }
}