#pragma once

//#include "Arduino.h"
//#include "FastLED.h"
//#define LED_PIN     7
//#define WIDTH 16
//#define HEIGHT 32
//#define NUM_LEDS    16 * 32
//
//CRGB leds[NUM_LEDS];
//
//const uint8_t PROGMEM
//gamma8[] = {
//0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
//0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1,
//1,  1,  1,  1,  1,  1,  1,  1,  1,  2,  2,  2,  2,  2,  2,  2,
//2,  3,  3,  3,  3,  3,  3,  3,  4,  4,  4,  4,  4,  5,  5,  5,
//5,  6,  6,  6,  6,  7,  7,  7,  7,  8,  8,  8,  9,  9,  9, 10,
//10, 10, 11, 11, 11, 12, 12, 13, 13, 13, 14, 14, 15, 15, 16, 16,
//17, 17, 18, 18, 19, 19, 20, 20, 21, 21, 22, 22, 23, 24, 24, 25,
//25, 26, 27, 27, 28, 29, 29, 30, 31, 32, 32, 33, 34, 35, 35, 36,
//37, 38, 39, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 50,
//51, 52, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 66, 67, 68,
//69, 70, 72, 73, 74, 75, 77, 78, 79, 81, 82, 83, 85, 86, 87, 89,
//90, 92, 93, 95, 96, 98, 99,101,102,104,105,107,109,110,112,114,
//115,117,119,120,122,124,126,127,129,131,133,135,137,138,140,142,
//144,146,148,150,152,154,156,158,160,162,164,167,169,171,173,175,
//177,180,182,184,186,189,191,193,196,198,200,203,205,208,210,213,
//215,218,220,223,225,228,231,233,236,239,241,244,247,249,252,255 };
//
//const uint8_t PROGMEM
//colors[] = {
//0xbc, 0xcc, 0xdc, 0x52, 0x79, 0x9e, 0x01, 0x2b, // ff = 15 * 16 + 15
//0x65, 0x0d, 0x41, 0x75, 0x88, 0xa0, 0xbe, 0xb5,
//0xc5, 0xd6, 0x9a, 0xb0, 0xc7, 0xa6, 0xbc, 0xd0,
//0x98, 0xaf, 0xc5, 0x29, 0x52, 0x84, 0x01, 0x24,
//0x5d, 0x02, 0x2c, 0x67, 0x6b, 0x89, 0xad, 0xd0,
//0xdd, 0xe6, 0x3a, 0x65, 0x94, 0x59, 0x7e, 0xa9,
//0x01, 0x21, 0x5c, 0x00, 0x1d, 0x59, 0x00, 0x1f,
//0x5a, 0x01, 0x25, 0x63, 0x01, 0x25, 0x5f, 0x00,
//0x29, 0x67, 0x05, 0x31, 0x6d, 0x5b, 0x7e, 0xab,
//0x00, 0x29, 0x66, 0x9b, 0xae, 0xc4, 0x02, 0x2b,
//0x67, 0x01, 0x22, 0x60, 0x01, 0x27, 0x65, 0x01,
//0x2b, 0x6b, 0xbe, 0xce, 0xde, 0xd2, 0xdd, 0xe7,
//0xcf, 0xdc, 0xe5, 0xd2, 0xdf, 0xe6, 0xcb, 0xd6,
//0xe2, 0x3e, 0x67, 0x99, 0x10, 0x40, 0x7c, 0x18,
//0x4e, 0x84, 0x9c, 0xb3, 0xcc, 0xaa, 0xbc, 0xcf,
//0xb4, 0xc6, 0xd4, 0xb4, 0xc4, 0xd2, 0xe3, 0xe9,
//0xed, 0xdb, 0xe5, 0xea, 0xdb, 0xe5, 0xee, 0x78,
//0x95, 0xb6, 0x00, 0x3c, 0x7c, 0x8e, 0xa9, 0xca,
//0xb2, 0xc5, 0xd1, 0xc5, 0xd1, 0xdd, 0x92, 0xa9,
//0xbf, 0xa3, 0xb6, 0xca, 0xcd, 0xda, 0xe3, 0xe7,
//0xeb, 0xef, 0xe6, 0xec, 0xef, 0x58, 0x82, 0xaa,
//0xb4, 0xc4, 0xd4, 0x97, 0xae, 0xc7, 0xaf, 0xbf,
//0xcf, 0xb6, 0xc7, 0xd5, 0xc7, 0xd5, 0xdf, 0xb2,
//0xc2, 0xd0, 0xe2, 0xe7, 0xee, 0xde, 0xe8, 0xec,
//0x87, 0xa5, 0xc6, 0xa8, 0xbc, 0xd4, 0x79, 0x9b,
//0xbb, 0x64, 0x87, 0xad, 0x66, 0x89, 0xab, 0x73,
//0x95, 0xb3, 0x88, 0xa5, 0xbd, 0xb7, 0xc9, 0xd3,
//0x00, 0x22, 0x62, 0x00, 0x27, 0x65, 0x03, 0x36,
//0x75, 0x07, 0x42, 0x7d, 0x37, 0x65, 0x99, 0x66,
//0x8e, 0xb1, 0x75, 0x9a, 0xba, 0xad, 0xc0, 0xd1,
//0x00, 0x23, 0x63, 0x00, 0x26, 0x67, 0x00, 0x27,
//0x68, 0x01, 0x2b, 0x6c, 0x04, 0x37, 0x76, 0x00,
//0x32, 0x72, 0x08, 0x41, 0x7d, 0x00, 0x35, 0x77,
//0x02, 0x25, 0x67, 0x00, 0x2f, 0x6c, 0x87, 0xa6,
//0xc4, 0x7f, 0x9c, 0xbf, 0x0a, 0x43, 0x7f, 0xc6,
//0xd3, 0xdc, 0xec, 0xf0, 0xf2, 0xdf, 0xe7, 0xec,
//0x00, 0x29, 0x69, 0x28, 0x59, 0x8d, 0x93, 0xa8,
//0xbe, 0xc3, 0xce, 0xd8, 0xb7, 0xc4, 0xd0, 0x80,
//0x9b, 0xaf, 0xaa, 0xbb, 0xc9, 0xe1, 0xe6, 0xea,
//0x3e, 0x65, 0x90, 0x63, 0x87, 0xa6, 0xbc, 0xca,
//0xd5, 0xbc, 0xca, 0xd4, 0xce, 0xda, 0xe3, 0xbb,
//0xc9, 0xd3, 0xc3, 0xd0, 0xdb, 0xb9, 0xc7, 0xd1,
//0x03, 0x35, 0x73, 0x01, 0x38, 0x73, 0x01, 0x36,
//0x77, 0x54, 0x7c, 0xa7, 0xb2, 0xc1, 0xcf, 0xb8,
//0xc8, 0xd3, 0xbd, 0xca, 0xd5, 0xcd, 0xdb, 0xe3,
//0x01, 0x2f, 0x72, 0x01, 0x37, 0x77, 0x0a, 0x48,
//0x84, 0x0b, 0x48, 0x84, 0x29, 0x5c, 0x92, 0x73,
//0x95, 0xb8, 0x05, 0x45, 0x82, 0x01, 0x41, 0x7f,
//0x01, 0x34, 0x75, 0x02, 0x34, 0x76, 0x01, 0x37,
//0x79, 0x1c, 0x55, 0x8d, 0x83, 0x9f, 0xb7, 0xa9,
//0xc0, 0xd1, 0x13, 0x57, 0x92, 0x02, 0x43, 0x85,
//0x02, 0x3c, 0x7c, 0x01, 0x3a, 0x7b, 0x03, 0x43,
//0x81, 0x5a, 0x87, 0xaf, 0x54, 0x80, 0xab, 0x0d,
//0x53, 0x8d, 0x06, 0x4e, 0x8d, 0x02, 0x45, 0x89,
//0x4c, 0x7b, 0xa7, 0x02, 0x3f, 0x80, 0x01, 0x3e,
//0x7f, 0x01, 0x42, 0x84, 0x03, 0x49, 0x89, 0x03,
//0x4d, 0x8c, 0x02, 0x47, 0x8a, 0x02, 0x4c, 0x8d,
//0x01, 0x41, 0x81, 0x02, 0x41, 0x84, 0x03, 0x44,
//0x84, 0x01, 0x45, 0x86, 0x01, 0x46, 0x89, 0x02,
//0x4b, 0x8c, 0x02, 0x4c, 0x8d, 0x02, 0x52, 0x93,
//0x01, 0x45, 0x86, 0x00, 0x44, 0x85, 0x05, 0x4e,
//0x8b, 0x38, 0x70, 0xa3, 0x0e, 0x56, 0x92, 0x19,
//0x62, 0x93, 0x01, 0x58, 0x98, 0x8a, 0xaf, 0xce,
//0x01, 0x46, 0x86, 0x03, 0x49, 0x89, 0x02, 0x4d,
//0x8e, 0x02, 0x52, 0x91, 0x05, 0x55, 0x95, 0xaf,
//0xbe, 0xcc, 0xc2, 0xcf, 0xd8, 0xc1, 0xce, 0xd5,
//0x39, 0x6f, 0x9a, 0x02, 0x4e, 0x8e, 0x02, 0x51,
//0x8f, 0x61, 0x89, 0xac, 0x59, 0x7c, 0x9c, 0x46,
//0x72, 0x9a, 0x79, 0x9c, 0xba, 0xc0, 0xcd, 0xd5,
//0x41, 0x75, 0x9f, 0x97, 0xaa, 0xb7, 0xb5, 0xc4,
//0xcd, 0xa6, 0xb3, 0xc3, 0xc1, 0xcb, 0xd4, 0xb6,
//0xc7, 0xd2, 0x7d, 0x9d, 0xb2, 0x7d, 0xa0, 0xb3,
//0x7a, 0x9a, 0xb4, 0x29, 0x68, 0x99, 0x33, 0x6a,
//0x94, 0x3e, 0x6d, 0x93, 0x55, 0x7a, 0x9e, 0x96,
//0xb0, 0xbe, 0xa4, 0xb8, 0xc2, 0xbd, 0xcb, 0xd4,
//0x0f, 0x5b, 0x91, 0x1a, 0x5e, 0x8f, 0x06, 0x59,
//0x91, 0x08, 0x5d, 0x93, 0x12, 0x63, 0x9a, 0x1a,
//0x6a, 0x9f, 0x25, 0x70, 0xa5, 0x37, 0x7a, 0xaa,
//0x10, 0x5f, 0x93, 0x0d, 0x5f, 0x92, 0x11, 0x62,
//0x96, 0x14, 0x64, 0x9a, 0x1b, 0x68, 0x9c, 0x20,
//0x6d, 0xa1, 0x24, 0x72, 0xa3, 0x25, 0x73, 0xa4,
//0x1e, 0x66, 0x98, 0x21, 0x69, 0x9a, 0x20, 0x6b,
//0x9c, 0x24, 0x70, 0x9f, 0x2b, 0x73, 0xa1, 0x7d,
//0xa6, 0xbe, 0x2d, 0x76, 0xa4, 0x31, 0x77, 0xa6,
//0x89, 0x9f, 0xae, 0x89, 0x9e, 0xae, 0x58, 0x8b,
//0xa8, 0x33, 0x78, 0xa2, 0xa6, 0xb7, 0xc0, 0xc3,
//0xce, 0xd1, 0xb6, 0xc5, 0xca, 0x77, 0x9d, 0xb3,
//0x6e, 0x8c, 0x9e, 0x44, 0x6c, 0x85, 0x8e, 0xa4,
//0xaf, 0x64, 0x89, 0xa1, 0x82, 0x9d, 0xae, 0xac,
//0xbb, 0xc4, 0x82, 0xa2, 0xb5, 0x86, 0xa1, 0xaf,
//0x64, 0x8a, 0x9f, 0x7b, 0x96, 0xa5, 0x52, 0x80,
//0x99, 0x72, 0x90, 0xa2, 0x71, 0x8f, 0xa3, 0x50,
//0x78, 0x97, 0x7a, 0x9a, 0xae, 0x9d, 0xb5, 0xc0,
//0x44, 0x6b, 0x86, 0x5e, 0x7f, 0x92, 0x6a, 0x88,
//0x96, 0x62, 0x86, 0x97, 0x5f, 0x83, 0x94, 0x62,
//0x85, 0x99, 0x76, 0x97, 0xa6, 0x77, 0x9b, 0xaa
//};
