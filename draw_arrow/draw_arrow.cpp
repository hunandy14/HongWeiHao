/*****************************************************************
Name : 畫箭頭
Date : 2017/11/09
By   : CharlotteHonG
Final: 2017/11/09
*****************************************************************/
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

#define M_PI 3.14159265358979323846
// 檔案結構
#pragma pack(2)
struct BmpFileHeader{
    uint16_t bfTybe=0x4d42;
    uint32_t bfSize;
    uint16_t bfReserved1=0;
    uint16_t bfReserved2=0;
    uint32_t bfOffBits=54;
};
struct BmpInfoHeader{
    uint32_t biSize=40;
    uint32_t biWidth;
    uint32_t biHeight;
    uint16_t biPlanes=1; // 1=defeaul, 0=custom
    uint16_t biBitCount;
    uint32_t biCompression=0;
    uint32_t biSizeImage;
    uint32_t biXPelsPerMeter=0; // 72dpi=2835, 96dpi=3780
    uint32_t biYPelsPerMeter=0; // 120dpi=4724, 300dpi=11811
    uint32_t biClrUsed=0;
    uint32_t biClrImportant=0;
};
#pragma pack()
// 快速atan運算
static inline float fastAtan2f(float dy, float dx){
    static const float atan2_p1 = 0.9997878412794807f*(float)(180/M_PI);
    static const float atan2_p3 = -0.3258083974640975f*(float)(180/M_PI);
    static const float atan2_p5 = 0.1555786518463281f*(float)(180/M_PI);
    static const float atan2_p7 = -0.04432655554792128f*(float)(180/M_PI);
    static const float atan2_DBL_EPSILON = 2.2204460492503131e-016;

    float ax = std::abs(dx), ay = std::abs(dy);
    float a, c, c2;
    if (ax >= ay) {
        c = ay/(ax + static_cast<float>(atan2_DBL_EPSILON));
        c2 = c*c;
        a = (((atan2_p7*c2 + atan2_p5)*c2 + atan2_p3)*c2 + atan2_p1)*c;
    } else {
        c = ax/(ay + static_cast<float>(atan2_DBL_EPSILON));
        c2 = c*c;
        a = 90.f - (((atan2_p7*c2 + atan2_p5)*c2 + atan2_p3)*c2 + atan2_p1)*c;
    }
    if (dx < 0)
        a = 180.f - a;
    if (dy < 0)
        a = 360.f - a;
    return a;
}
// 圖像結構
class ImgRaw{
public:
    using uch = unsigned char;
    ImgRaw(size_t width, size_t height):
        raw_img(width*height*3), 
        width(width), height(height){}
    void bmp(string name){
        // 檔案資訊
        BmpFileHeader file_h;
        file_h.bfSize = file_h.bfOffBits + width*height * 3;
        // 圖片資訊
        BmpInfoHeader info_h;
        info_h.biWidth = width;
        info_h.biHeight = height;
        info_h.biBitCount = 24;
        info_h.biSizeImage = width*height * 3;
        // 寫入檔頭
        ofstream bmp(name, ios::binary);
        bmp.exceptions(ifstream::failbit|ifstream::badbit);
        bmp.write((char*)&file_h, sizeof(file_h));
        bmp.write((char*)&info_h, sizeof(info_h));
        // 寫入圖片資訊
        size_t alig = ((width*3)*3) % 4;
        cout << "ali=" << alig << endl;
        for(int j = height-1; j >= 0; --j) {
            for(unsigned i = 0; i < width; ++i) {
                bmp.write((char*)&raw_img[(j*width+i)*3 + 2], sizeof(uch));
                bmp.write((char*)&raw_img[(j*width+i)*3 + 1], sizeof(uch));
                bmp.write((char*)&raw_img[(j*width+i)*3 + 0], sizeof(uch));
            }
            // 對齊4byte
            for(unsigned i = 0; i < alig; ++i) {
                uch c = 0;
                bmp.write((char*)&c, sizeof(uch));
            }
        }
    }
public:
    vector<uch> raw_img;
    uint32_t width;
    uint32_t height;
};
// 畫線RGB
class Draw{
public:
    static void drawLineRGB_p(ImgRaw& img, int y, int x, int y2, int x2) {
        // 兩點之間的距離差
        float dx = x2-x;
        float dy = y2-y;
        // 以Y軸為主
        float sita=fastAtan2f(dy, dx);
        if ((sita>45 and sita<135) or (sita>225 and sita<315)) {
            float slopeY = dx/dy; // 斜率
            for (int i = 0; i < abs(dy); i++) {
                int iFix = dy>0? i:-i;
                int currPos = iFix*slopeY + x;

                int distX = currPos;
                int distY = y+iFix;

                if (distX<0 or distX>=(int)img.width or 
                    distY<0 or distY>=(int)img.height)
                {
                    return;
                }
                size_t posi = distY*img.width + distX;
                img.raw_img[posi*3 + 0] = 255;
                img.raw_img[posi*3 + 1] = 0;
                img.raw_img[posi*3 + 2] = 0;
            }
        } 
        // 以X軸為主
        else {
            float slopeX = dy/dx; // 斜率
            for (int i = 0; i < abs(dx); i++) {
                int iFix = dx>0? i:-i;
                int currPos = iFix*slopeX + y;

                int distX = x+iFix;
                int distY = currPos;

                if (distX<0 or distX>=(int)img.width or 
                    distY<0 or distY>=(int)img.height)
                {
                    return;
                }
                size_t posi = distY*img.width + distX;
                img.raw_img[posi*3 + 0] = 255;
                img.raw_img[posi*3 + 1] = 0;
                img.raw_img[posi*3 + 2] = 0;
            }
        }
    }
    static void drawLineRGB_s(ImgRaw& img, int y, int x, float line_len, float sg) {
        // 檢查
        if (line_len <= 0) { return; }
        // 算頭尾
        int x2 = x + line_len*cos(sg * M_PI/180);
        int y2 = y + line_len*sin(sg * M_PI/180);
        // 畫線
        drawLineRGB_p(img, y, x, y2, x2);
    }
    static void draw_arrowRGB(ImgRaw& img, int y, int x, float line_len, float sg) {
        // 檢查
        if (line_len <= 0) { return; }
        // 算頭尾
        int x2 = x + line_len*cos(sg * M_PI/180);
        int y2 = y + line_len*sin(sg * M_PI/180);
        // 畫線
        drawLineRGB_p(img, y, x, y2, x2);
        // 畫頭
        drawLineRGB_s(img, y2, x2, 10, sg-150);
        drawLineRGB_s(img, y2, x2, 10, sg+150);
    }
};

//================================================================
int main(int argc, char const *argv[]){
    ImgRaw img(400, 400);
    for (size_t i = 0; i < 36; i++) {
        Draw::draw_arrowRGB(img, 200, 200, 100.f*sqrt(2), i*10);
    }
    img.bmp("lineRGB.bmp");
    return 0;
}
//================================================================
