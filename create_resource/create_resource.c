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
    system("pause");
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
void getPath(char* buf, const char* fullName){
    int idx;
    for(idx=strlen(fullName)-1; idx >=0; --idx)
        if(fullName[idx]=='/' || fullName[idx]=='\\') {break;}
    strcpy(buf, fullName);
    buf[idx]='\0';  
}
void creatResource(const char* fullName){
    char* img_Path = (char*) malloc(strlen(fullName) + 1);
    getPath(img_Path, fullName);
    // 創建 rc 檔案
    char* res_cmd = (char*) malloc(strlen(fullName) + 21 + 1);
    strcpy(res_cmd, "echo ID ICON ");
    strcat(res_cmd, fullName);
    strcat(res_cmd, " >res.rc");
    system(res_cmd);
    free(res_cmd);
    // 創建資源檔
    char* icon_BaseName = (char*) malloc(strlen(fullName) + 1);
    getBaseName(icon_BaseName, fullName);
    res_cmd = (char*) malloc(strlen(icon_BaseName) + 28 + 1);
    strcpy(res_cmd, "windres -i res.rc -o ");
    strcat(res_cmd, icon_BaseName);
    strcat(res_cmd, "_icon.o");

    system(res_cmd);
    system("del res.rc");

    free(icon_BaseName);
    free(res_cmd);
}