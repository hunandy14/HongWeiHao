/**********************************************************
Name : 
Date : 2016/08/20
By   : CharlotteHonG
Final: 2016/08/20
**********************************************************/
#include <iostream>
using namespace std;
/*=======================================================*/
//接收不同型態的資料
void pri_int(void* data){
	int temp=(int)*(unsigned char*)data;
	cout << "temp=" << temp << endl;
}
int main(int argc, char const *argv[]){
	// 創建兩個不同型態的指標
	int num = 99;
	int* p1 = &num;
	unsigned char str='5';
	unsigned char* p2 = &str;
	// 5的無號整數
	cout << "(int)str=" << (int)*p2 << endl;
	// 印出整數
	pri_int(p1);
	pri_int(p2);
	return 0;
}
/*=======================================================*/