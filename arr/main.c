#include <stdio.h>
#include <stdlib.h>
#include "fun.c"
/*===========================================*/
/*===========================================*/
int main(int argc, char const *argv[]){
	int arr[] = {1, 2, 3, 4, 5};
	int len = sizeof(arr) / sizeof(arr[0]);
    /*--------API 說明--------*/
    
    /* 翻轉 */
    int *arr2=arr_rever(arr, len);
    // free(arr2); //記得把此行放到最後[return 0;前]
    
    /* 列印 */
    arr_print(arr2,len);

    /* 右移 */
    int *temp=arr_creat(len+1);// 造一個大於1的暫存
    arr_copy(arr, temp, len);// 複製數值進去
    arr_rmove(temp, len);// 向右移動一格
    arr_print(temp, len+1);
    /*--------*******--------*/
	return 0;
}
/*===========================================*/