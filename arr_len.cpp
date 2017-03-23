/**********************************************************
Name : 副程式取得陣列長度
Date : 2016/05/31
By   : CharlotteHonG
Final: 2016/06/19
**********************************************************/
#include <iostream>

template<size_t N>
void arr_len(int (&arr)[N]);

template<size_t N, size_t N2>
void arr_len(int (&arr)[N][N2]);
/*=======================================================*/
int main(int argc, char const *argv[]){
    
    int a[] = {1,2,3,4};
    arr_len(a);
    std::cout << std::endl;
    
    int b[][2] = {{1, 2}, {3, 4}, {5, 6}};
    arr_len(b);
    std::cout << std::endl;
    
    return 0;
}
/*=======================================================*/
template<size_t N>
void arr_len(int (&arr)[N]) {
    std::cout << "sizeof = " << sizeof(arr) << " / ";        
    std::cout << sizeof(arr[0]) << std::endl;
    std::cout << "len = arr[" << N << "]" << std::endl;
}

template<size_t N, size_t N2>
void arr_len(int (&arr)[N][N2]) {
    std::cout << "sizeof = " << sizeof(arr) << " / ";
    std::cout << sizeof(arr[0][0]) << std::endl;
    std::cout << "len = arr[" << N << "][";
    std::cout << N2 << "]" << std::endl;
}
/*=======================================================*/