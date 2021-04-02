#ifndef __COLOR_H__
#define __COLOR_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

// Fast RGB Convert
#define RGB565(r,g,b)   (((r & 0xF8) << 8) | ((g & 0xFC) << 3) | ((b & 0xF8) >> 3))
#define RGB888(r,g,b)   (((r & 0xFF) <<16) | ((g & 0xFF) << 8) | ((b & 0xFF) << 0))

// RGB888 Not Set
#define COLOR_NOT_SET   {0,0,0}

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
	uint16_t b:5;
	uint16_t g:6;
	uint16_t r:5;
}color_rgb565_s;

typedef union
{
	color_rgb565_s rgb;
	uint16_t word;
} color_rgb565_u;

color_rgb_s color_s(uint8_t r,uint8_t g,uint8_t b);
color_rgb_s color_rgba_to_rgb_ss(color_rgb_s background,color_rgba_s color);
color_rgb_s color_16_to_24_su(color_rgb565_u color);
color_rgb_s color_16_to_24_s(uint16_t color);
uint16_t    color_24_to_16_s(color_rgb_s color);
uint16_t    color_24_to_16(uint8_t r,uint8_t g,uint8_t b);

#ifdef __cplusplus
}
#endif

#define WHITE   color_s(0xff,0xff,0xff)
#define SILVER  color_s(0xc0,0xc0,0xc0)
#define GRAY    color_s(0x80,0x80,0x80)
#define BLACK   color_s(0x00,0x00,0x00)
#define RED     color_s(0xff,0x00,0x00)
#define MAROON  color_s(0x80,0x00,0x00)
#define YELLOW  color_s(0xff,0xff,0x00)
#define OLIVE   color_s(0x80,0x80,0x00)
#define LIME    color_s(0x00,0xff,0x00)
#define GREEN   color_s(0x00,0x80,0x00)
#define AQUA    color_s(0x00,0xff,0xff)
#define TEAL    color_s(0x00,0x80,0x80)
#define BLUE    color_s(0x00,0x00,0xff)
#define NAVY    color_s(0x00,0x00,0x80)
#define FUCHSIA color_s(0xff,0x00,0xff)
#define PURPLE  color_s(0x80,0x00,0x80)

#endif
