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
    // �}��
    FILE* fPtr = fopen(name, "r");
    if(!fPtr)
        return 0;
    // ���o�ɮת���
    size_t len=0;
    for (; fgetc(fPtr) != EOF; ++len);
    fclose(fPtr);
    return len;
}
char* getfile(char const * name){
    // �}��
    FILE* fPtr = fopen(name, "r");
    if(!fPtr)
        return NULL;
    // ���o���׳ЫذʺA�}�C
    size_t len=filelen(name);
    char* fileSTR = malloc(sizeof(char)*len + 1);
    // Ū�X�ɮצr��
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
