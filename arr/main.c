#include <stdio.h>
#include <stdlib.h>
#include "fun.c"
/*===========================================*/
/*===========================================*/
int main(int argc, char const *argv[]){
	int arr[] = {1, 2, 3, 4, 5};
	int len = sizeof(arr) / sizeof(arr[0]);
    /*--------API ����--------*/
    
    /* ½�� */
    int *arr2=arr_rever(arr, len);
    // free(arr2); //�O�o�⦹����̫�[return 0;�e]
    
    /* �C�L */
    arr_print(arr2,len);

    /* �k�� */
    int *temp=arr_creat(len+1);// �y�@�Ӥj��1���Ȧs
    arr_copy(arr, temp, len);// �ƻs�ƭȶi�h
    arr_rmove(temp, len);// �V�k���ʤ@��
    arr_print(temp, len+1);
    /*--------*******--------*/
	return 0;
}
/*===========================================*/