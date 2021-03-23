#ifndef __COLOR_H__
#define __COLOR_H__

#include <stdint.h>

// RGB565 Color from RGB888
#define RGB565(r, g, b)         (((r & 0xF8) << 8) | ((g & 0xFC) << 3) | ((b & 0xF8) >> 3))

// RGB565 Color
#define C16_BLACK    0x0000
#define C16_BLUE     0x001F
#define C16_RED      0xF800
#define C16_GREEN    0x07E0
#define C16_CYAN     0x07FF
#define C16_MAGENTA  0xF81F
#define C16_YELLOW   0xFFE0
#define C16_WHITE    0xFFFF


typedef struct{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
}color_rgba_s;

typedef struct{
    uint8_t r;
    uint8_t g;
    uint8_t b;
}color_rgb888_s;

typedef color_rgb888_s color_rgb_s;

typedef struct
{
	uint16_t r:5;
	uint16_t g:6;
	uint16_t b:5;
}color_rgb565_s;

typedef union
{
	color_rgb565_s rgb;
	uint16_t word;
} color_rgb565_u;

#ifdef __cplusplus
extern "C" {
#endif

uint16_t    color_24_to_16_s(color_rgb_s color);
uint16_t    color_24_to_16(uint8_t r,uint8_t g,uint8_t b);
color_rgb_s color_rgba_to_rgb_ss(color_rgb_s background,color_rgba_s color);
color_rgb_s color_16_to_24_su(color_rgb565_u color);
color_rgb_s color_16_to_24_s(uint16_t color);

#ifdef __cplusplus
}
#endif

#endif
