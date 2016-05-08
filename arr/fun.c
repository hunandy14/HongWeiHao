#include "fun.h"
/*===========================================*/
int* arr_rever(int* arr, int len){
	int* arr_rever;
	arr_rever = (int*)malloc(sizeof(int)*len);
	for (int i = 0; i < len; ++i){
		arr_rever[i]=arr[(len-1)-i];
		// printf("%d\n", arr_rever[i]);
	}
	return arr_rever;
}

void arr_print(int* arr, int len){
	for (int i = 0; i < len-1; ++i){
		printf("%d,", arr[i]);
	}printf("%d\n", arr[len-1]);
}

int* arr_creat(int len){
	int* arr_new;
	arr_new = (int*)malloc(sizeof(int)*len);
	for (int i = 0; i < len; ++i){
		arr_new[i]=0;
	}
	return arr_new;
}

void arr_rmove(int* arr, int len){
	// arr[len]=arr[len-1];
	for (int i = len; i > 0; --i){
		arr[i]=arr[i-1];
	}arr[0]=0;
}

void arr_copy(int* arr1, int* arr2, int len){
	for (int i = 0; i < len; ++i){
		arr2[i]=arr1[i];
	}
}
/*===========================================*/