/*****************************************************************
Name : 
Date : 2017/11/10
By   : CharlotteHonG
Final: 2017/11/11
*****************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
typedef unsigned char uch;

// 檔案結構
#pragma pack(2)
struct BmpFileHeader{
    uint16_t bfTybe;
    uint32_t bfSize;
    uint16_t bfReserved1;
    uint16_t bfReserved2;
    uint32_t bfOffBits;
};
struct BmpInfoHeader{
    uint32_t biSize;
    uint32_t biWidth;
    uint32_t biHeight;
    uint16_t biPlanes; // 1=defeaul, 0=custom
    uint16_t biBitCount;
    uint32_t biCompression;
    uint32_t biSizeImage;
    uint32_t biXPelsPerMeter; // 72dpi=2835, 96dpi=3780
    uint32_t biYPelsPerMeter; // 120dpi=4724, 300dpi=11811
    uint32_t biClrUsed;
    uint32_t biClrImportant;
};
#pragma pack()


void bmpWrite(const char* name, const uch* raw_img, uint32_t width, uint32_t height){
    // 檔案資訊
    struct BmpFileHeader file_h = {
        .bfTybe=0x4d42,
        .bfReserved1=0,
        .bfReserved2=0,
        .bfOffBits=54,
    };
    file_h.bfSize = file_h.bfOffBits + width*height * 3;
    // 圖片資訊
    struct BmpInfoHeader info_h = {
        .biSize=40,
        .biPlanes=1,
        .biCompression=0,
        .biXPelsPerMeter=0,
        .biYPelsPerMeter=0,
        .biClrUsed=0,
        .biClrImportant=0,
    };
    info_h.biWidth = width;
    info_h.biHeight = height;
    info_h.biBitCount = 24;
    info_h.biSizeImage = width*height * 3;
    // 寫入檔頭
    FILE *pFile = fopen(name,"wb+");
    if(!pFile) {
        perror("Error opening file.");
        return;
    }
    fwrite((char*)&file_h, sizeof(char), sizeof(file_h), pFile);
    fwrite((char*)&info_h, sizeof(char), sizeof(info_h), pFile);
    // 寫入圖片資訊
    size_t alig = ((width*3)*3) % 4;
    for(int j = height-1; j >= 0; --j) {
        for(unsigned i = 0; i < width; ++i) {
            fwrite((char*)&raw_img[(j*width+i)*3 + 2], sizeof(char), sizeof(uch), pFile);
            fwrite((char*)&raw_img[(j*width+i)*3 + 1], sizeof(char), sizeof(uch), pFile);
            fwrite((char*)&raw_img[(j*width+i)*3 + 0], sizeof(char), sizeof(uch), pFile);
        }
        // 對齊4byte
        for(size_t i = 0; i < alig; ++i) {
            uch c = 0;
            fwrite((char*)&c, sizeof(char), sizeof(uch), pFile);
        }
    }
    fclose(pFile);
}
void bmpRead(const char* name, uch** raw_img, uint32_t* width, uint32_t* height){
    // 檔案資訊
    struct BmpFileHeader file_h;
    // 圖片資訊
    struct BmpInfoHeader info_h;
    // 讀取檔頭
    FILE *pFile = fopen(name,"rb+");
    if(!pFile) {
        perror("Error opening file.");
        return;
    }
    fread((char*)&file_h, sizeof(char), sizeof(file_h), pFile);
    fread((char*)&info_h, sizeof(char), sizeof(info_h), pFile);
    // 讀取長寬
    *width = info_h.biWidth;
    *height = info_h.biHeight;
    *raw_img = (uch*)calloc((info_h.biWidth)*(info_h.biHeight)*3, sizeof(uch));
    // 讀取讀片資訊轉RAW檔資訊
	size_t alig = ((*width*3)*3) % 4;
    for(int j = *height-1; j >= 0; --j) {
        for(unsigned i = 0; i < *width; ++i) {
            fread((char*)&(*raw_img)[(j*(*width)+i)*3 + 2], sizeof(char), sizeof(uch), pFile);
            fread((char*)&(*raw_img)[(j*(*width)+i)*3 + 1], sizeof(char), sizeof(uch), pFile);
            fread((char*)&(*raw_img)[(j*(*width)+i)*3 + 0], sizeof(char), sizeof(uch), pFile);
        }
		fseek (pFile , alig , SEEK_CUR);
    }
    fclose(pFile);
}
/*==============================================================*/
int main(int argc, char const *argv[]){
    uint32_t width, height;
    uch* img=NULL;
    bmpRead("kanna.bmp", &img, &width, &height);
	bmpWrite("BMP.bmp", img, width, height);
    return 0;
}
/*==============================================================*/