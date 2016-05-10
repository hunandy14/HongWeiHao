#include <stdio.h>
#include <stdlib.h>
#include "fun.c"
/*===========================================*/
int main(int argc, char const *argv[]){
    int arr1[] = {0,1,2,3,4,5,0,0,0,0};
    int arr2[]  =  {0,1,2,3,4,5,6,7,8,9};
    int len = sizeof(arr1) / sizeof(arr1[0]);
    /*--------*******--------*/
    /* 翻轉 */
    int *arr1_r=arr_rever(arr1, len);
    /* 印出 */
    arr_print(arr1_r,len);
    /* 複製新陣列 */
    int *temp = arr_creat(len);
    arr_copy(arr1_r, temp, len);
    /* 回傳乘積和 */
    int total=arr_rtotal(arr1,arr2,len);
    printf("total=%d\n", total);
    /*--------*******--------*/
    free(arr1_r);
    free(temp);
    return 0;
}
/*===========================================*/