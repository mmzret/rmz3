#ifndef __INCLUDE_CONSTANTS_RGB_H__
#define __INCLUDE_CONSTANTS_RGB_H__

// 本当は include/gba/defines.h に書くべきだが、今のところ .s で include する hファイルは include/constants/ 以下に置くことにしているので、ここに書く

#define RGB(r5, g5, b5) ((r5) | ((g5) << 5) | ((b5) << 10))
#define RGBg(r5, g5, b5) (RGB(r5, g5, b5) | (1 << 15))  // GBAのPLTTのbit15は普段は無視されるが、ブレンド時のみbit15を緑のLSBとした RGB565 で扱う, でも視覚的に違いを感じるものではないので、不要だと思う

#define RGB_BLACK RGB(0, 0, 0)
#define RGB_WHITE RGB(31, 31, 31)
#define RGBg_WHITE RGBg(31, 31, 31)

#endif  // __INCLUDE_CONSTANTS_RGB_H__
