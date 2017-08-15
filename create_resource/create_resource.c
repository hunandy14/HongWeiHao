/*****************************************************************
Name : 
Date : 2017/08/15
By   : CharlotteHonG
Final: 2017/08/15

圖形資源檔 .rc 內容
ID ICON "icon.ico"
編譯圖形資源檔ˋ
windres -i res.rc -o res.o
編譯程式碼
gcc -Wall -O2 -mwindows icon.o sou.c -o sou_release
*****************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void getFileName(char* buf, const char* fullName);
void getBaseName(char* buf, const char* fullName);
void creatResource(const char* fullName);
//================================================================
int main(int argc, char const *argv[]){
    if(argc>1) {
        for(int i = 1; i < argc; ++i) {
            char* CMDName = (char*) malloc(strlen(argv[i]));
            creatResource(argv[i]);
            free(CMDName);
        }
    }
    else if(argc==1) {
        creatResource("CHG.ico");
    }
    // system("pause");
    return 0;
}
//================================================================
void getFileName(char* buf, const char* fullName){
    int idx;
    for(idx=strlen(fullName)-1; idx >=0; --idx)
        if(fullName[idx]=='/' || fullName[idx]=='\\') {break;}
    strcpy(buf, (fullName+idx+1));
    buf[strlen(fullName)-idx-1]='\0';
}
void getBaseName(char* buf, const char* fullName){
    getFileName(buf, fullName);
    int idx;
    for(idx=strlen(buf)-1; idx >=0; --idx)
        if(buf[idx]=='.') {break;}
    buf[idx]='\0';
}
void creatResource(const char* fullName){
    char* res_cmd = (char*) malloc(strlen(fullName) + 21 + 1);
    strcpy(res_cmd, "echo ID ICON ");
    strcat(res_cmd, fullName);
    strcat(res_cmd, " >res.rc");
    system(res_cmd);
    free(res_cmd);
    
    char* iconName = (char*) malloc(strlen(fullName) + 1);
    getBaseName(iconName, fullName);
    res_cmd = (char*) malloc(strlen(iconName) + 28 + 1);
    strcpy(res_cmd, "windres -i res.rc -o ");
    strcat(res_cmd, iconName);
    strcat(res_cmd, "_icon.o");

    system(res_cmd);
    system("del res.rc");

    free(iconName);
    free(res_cmd);
}