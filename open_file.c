/*****************************************************************
Name :
Date : 2017/04/11
By   : CharlotteHonG
Final: 2017/04/11
*****************************************************************/
#include <stdlib.h>
#include <stdio.h>
#define file "file.txt"

size_t filelen(char const * name){
    // 開檔
    FILE* fPtr = fopen(name, "r");
    if(!fPtr)
        return 0;
    // 取得檔案長度
    size_t len=0;
    for (; fgetc(fPtr) != EOF; ++len);
    fclose(fPtr);
    return len;
}
char* getfile(char const * name){
    // 開檔
    FILE* fPtr = fopen(name, "r");
    if(!fPtr)
        return NULL;
    // 取得長度創建動態陣列
    size_t len=filelen(name);
    char* fileSTR = malloc(sizeof(char)*len + 1);
    // 讀出檔案字串
    for (size_t i=0; (fileSTR[i]=fgetc(fPtr)) != EOF; ++i);
    fileSTR[len] = '\0';
    fclose(fPtr);
    return fileSTR;
}
//================================================================
int main(int argc, char const *argv[]){
    char* str=getfile(file);
    printf("%s", str);
    return 0;
}
//================================================================
