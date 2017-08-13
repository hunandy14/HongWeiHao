/*****************************************************************
Name : 
Date : 2017/08/13
By   : CharlotteHonG
Final: 2017/08/13

給定一個整數如何知道
1. 二進位總共有幾個ˊ1
2. 第3位是0還是1
*****************************************************************/
#include <iostream>
#include <cmath >
using namespace std;

void exp_pos_range_error(){
    printf("%s\n", "Error! range only 0~31.");
    exit(1);
}
// 印出二進位
void bit_print(uint32_t n){  
    int c=1;
    for(uint64_t i = pow(2, 31); i; i>>=1, ++c){
        printf(i&n?"1":"0");
        if(c==4) {c=0, printf(" ");}
    } printf("\n");
}
// 查找第 pos 位元是不是 1
void bit_test(uint32_t n, size_t pos){
    if(pos>31) {exp_pos_range_error();}
    uint64_t temp = 1;
    for(size_t i = 0; i < pos; ++i)
        temp <<= 1;
    printf(temp&n ?"Yes":"No");
    printf(" pos %llu is one.", pos);
    printf("\n");
}
// 統計有多少位元是 1
void bit_count(uint32_t n){
    int c=0;
    for(uint64_t i = pow(2, 31); i; i>>=1){
        if(i&n) {++c;}
    } printf("has %d ones\n", c);
}

// 設置位元為 1
void bit_set(uint32_t* n, size_t pos){
    if(pos>31) {exp_pos_range_error();}
    uint64_t temp = 1;
    for(size_t i = 0; i < pos; ++i)
        temp <<= 1;
    *n |= temp;
}
// 設置位元為 0
void bit_reset(uint32_t* n, size_t pos){
    if(pos>31) {exp_pos_range_error();}
    uint64_t temp = -2;
    for(size_t i = 0; i < pos; ++i)
        temp <<= 1;
    *n &= temp;
}
//================================================================
int main(int argc, char const *argv[]){
    uint32_t num=0x80000000;
    // 印出二進位
    bit_print(num);
    // 查找第 31 位元是不是 1
    bit_test(num, 31);
    // 統計有多少 1
    bit_count(num);

    // 設置第 31 位元為 0
    bit_reset(&num, 31);
    bit_print(num);
    // 設置第 31 位元為 1
    bit_set(&num, 31);
    bit_print(num);
    return 0;
}
//================================================================
