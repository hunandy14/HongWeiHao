/*
By:Charlotte.Hong
Date:2016/05/08
Final:2016/05/10
*/
#include <stdio.h>
#include <stdlib.h>
#include "fun.c"
/*===========================================*/
int main(int argc, char const *argv[]){
    int arr1[] = {1,2,3,4,5};
    int arr2[] = {1,2,3,4,5,6,7,8,9,10};
    int len1=5, len2 = 10;
    /*--------*******--------*/
    /* 翻轉 */
    int *arr1_r = arr_creat(len2);
    int *temp = arr_rever(arr1, len1);
    arr_copy(temp, arr1_r, len1);
    free(temp);
    /* 印出 */
    // arr_print(arr1_r,len2);
    /* 回傳乘積和 */
    int total=arr_rtotal(arr1_r, arr2, len2);
    printf("total = %d\n", total);
    /*--------*******--------*/
    free(arr1_r);
    return 0;
}
/*===========================================*/