#pragma once
#include <inttypes.h>
typedef unsigned char uch;

// suport cpp build
#ifdef  __cplusplus
extern  "C" {
#endif 


void bmpWrite(const char* name, const uch* raw_img,
	uint32_t width, uint32_t height, uint16_t bits);
void bmpRead(const char* name, uch** raw_img,
	uint32_t* width, uint32_t* height, uint16_t* bits);
void testBMP();

// suport cpp build
#ifdef  __cplusplus
}
#endif 

struct ImgData {
	uint32_t width;
	uint32_t height;
	uint16_t bits;
	size_t size;
	uch* data;

	// only cpp build
	#ifdef  __cplusplus
	ImgData(std::string name) {
		bmpRead(name.c_str(), &data, &width, &height, &bits);
		this->size = width*height * bits/8.f;
	}
	#endif
};