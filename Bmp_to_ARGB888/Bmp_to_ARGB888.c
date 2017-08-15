/*****************************************************************
Name : 
Date : 2017/08/13
By   : CharlotteHonG
Final: 2017/08/13
*****************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

const char* BMPFileName = "iori1_400x240.bmp";

void BMP_to_ARGB888(const char* name);
void getFileName(char* buf, const char* fullName);
/*==============================================================*/
int main(int argc, char const *argv[]){
    if(argc>1) {
        for(unsigned i = 1; i < argc; ++i) {
            char* BMPCMDName = (char*) malloc(strlen(argv[i]));
            getFileName(BMPCMDName, argv[i]);
            printf("%s\n", BMPCMDName);
            BMP_to_ARGB888(BMPCMDName);
            free(BMPCMDName);
        }
    }
    if(argc==1) {
        BMP_to_ARGB888(BMPFileName);
    }
    return 0;
}
/*==============================================================*/
void getFileName(char* buf, const char* fullName){
    int idx;
    for(idx=strlen(fullName)-1; idx >=0; --idx)
        if(fullName[idx]=='/' || fullName[idx]=='\\') {break;}
    strcpy(buf, (fullName+idx+1));
    buf[strlen(fullName)-idx-1]='\0';
}
void BMP_to_ARGB888(const char* name){
    // 資料結構
    enum RGB_t{
        R,
        G,
        B
    };
    #pragma pack(2)
    typedef struct BmpFileHeader{
        unsigned short bfTybe;
        unsigned int   bfSize;
        unsigned short bfReserved1;
        unsigned short bfReserved2;
        unsigned int   bfOffBits;
    } BmpFileHeader;
    typedef struct BmpInfoHeader{
        unsigned int   biSize;
        unsigned int   biWidth;
        unsigned int   biHeight;
        unsigned short biPlanes;
        unsigned short biBitCount;
        unsigned int   biCompression;
        unsigned int   biSizeImage;
        unsigned int   biXPelsPerMeter;
        unsigned int   biYPelsPerMeter;
        unsigned int   biClrUsed;
        unsigned int   biClrImportant;
    } BmpInfoHeader;
    #pragma pack()


    // 變數
    BmpFileHeader BMP_FH;
    BmpInfoHeader BMP_IH;
    FILE* pBmpFile;
    size_t width;
    size_t height;
    unsigned char* raw_img;


    // 實作
    pBmpFile = fopen(name, "rb");
    if(!pBmpFile) {printf("File Error.\n"), exit(1);}
    // 讀檔頭
    fread(&BMP_FH, sizeof(BMP_FH), 1, pBmpFile);
    fread(&BMP_IH, sizeof(BMP_IH), 1, pBmpFile);
    width = BMP_IH.biWidth;
    height = BMP_IH.biHeight;
    // 讀 Raw 檔案
    raw_img =  (unsigned char*) malloc (width*height*3);
    for(int j = height-1; j >= 0; --j) {
        for(unsigned i = 0; i < width; ++i) {
            fread(raw_img+(j*width*3 + i*3) + B, 1, 1, pBmpFile);
            fread(raw_img+(j*width*3 + i*3) + G, 1, 1, pBmpFile);
            fread(raw_img+(j*width*3 + i*3) + R, 1, 1, pBmpFile);
        }
    } fclose(pBmpFile);


    // 輸出名稱
    char* binName = (char*) malloc (strlen(name)-3 +1 +1);
    strncpy(binName, name, strlen(name)-3);
    binName[strlen(name)-3] = 'h';
    binName[strlen(name)-3 +1] = '\0';
    // 基本名稱
    char* base_name = (char*) malloc (strlen(name)-4 +1);
    char* base_name_upper = (char*) malloc (strlen(name)-4 +1);
    strncpy(base_name, name, strlen(name)-4);
    int idx = strlen(base_name);
    for(int c=0; (idx >= 0); --idx) {
        if(!isdigit(base_name[idx])) {++c;}
        if(c>2) {break;}
    } base_name[idx] = '\0';
    for(int i=0; i<strlen(base_name); ++i)
        base_name_upper[i] = toupper(base_name[i]);
    // 開檔
    pBmpFile = fopen(binName, "wb+");
    if(!pBmpFile) {printf("File Error.\n"), exit(1);}
    free(binName);
    // 開頭
    fprintf(pBmpFile, "/* \n  This image file uses library by CharlotteHonG \n");
    fprintf(pBmpFile, "  Site: https://charlottehong.blogspot.tw/2017/08/stm32f469i-gui-stm.html \n*/\n\n");

    
    fprintf(pBmpFile, "#ifndef __%s_%I64dX%I64d_H\n", base_name_upper, width, height);
    fprintf(pBmpFile, "#define __%s_%I64dX%I64d_H\n", base_name_upper, width, height);
    fprintf(pBmpFile, "\n");
    fprintf(pBmpFile, "#ifdef __cplusplus\n");
    fprintf(pBmpFile, "extern \"C\" {\n");
    fprintf(pBmpFile, "#endif\n");
    fprintf(pBmpFile, "const uint32_t %s_%I64dx%I64d", base_name, width, height);
    fprintf(pBmpFile, "[%I64d] =\n", width*height);
    fprintf(pBmpFile, "{\n");
    // 資料
    for(unsigned i = 0; i < height*width; ++i) {
        fprintf(pBmpFile, "    0xff");
        fprintf(pBmpFile, "%02x", raw_img[i*3 + R]);
        fprintf(pBmpFile, "%02x", raw_img[i*3 + G]);
        fprintf(pBmpFile, "%02x", raw_img[i*3 + B]);
        if(i!=width*height-1){
            fprintf(pBmpFile, ", \n");
        } else {
            fprintf(pBmpFile, "\n};\n");
        }
    } free(raw_img);
    // 結尾
    fprintf(pBmpFile, "\n");
    fprintf(pBmpFile, "\n");
    fprintf(pBmpFile, "#ifdef __cplusplus\n");
    fprintf(pBmpFile, "}\n");
    fprintf(pBmpFile, "#endif\n");
    fprintf(pBmpFile, "\n");
    fprintf(pBmpFile, "#endif /* __%s_%I64dX%I64d_H */\n\n", base_name_upper, width, height);


    fprintf(pBmpFile, "/* \n  This image file uses library by CharlotteHonG \n");
    fprintf(pBmpFile, "  Site: https://charlottehong.blogspot.tw/2017/08/stm32f469i-gui-stm.html \n*/\n\n");
}