#include "Constants.h"
//#include "Arduino.h"
//#include "FastLED.h"
//#include "Fire.h"

// COOLING: How much does the air cool as it rises?
// Less cooling = taller flames.  More cooling = shorter flames.
// Default 55, suggested range 20-100
#define COOLING  55

// SPARKING: What chance (out of 255) is there that a new spark will be lit?
// Higher chance = more roaring fire.  Lower chance = more flickery fire.
// Default 120, suggested range 50-200.
#define SPARKING 120
//void Fire2012()
//{
//// Array of temperature readings at each simulation cell
//    static byte heat[NUM_LEDS];
//
//    // Step 1.  Cool down every cell a little
//    for( int i = 0; i < NUM_LEDS; i++) {
//        heat[i] = qsub8( heat[i],  random8(0, ((COOLING * 10) / NUM_LEDS) + 2));
//    }
//
//    // Step 2.  Heat from each cell drifts 'up' and diffuses a little
//    for( int k= NUM_LEDS - 3; k > 0; k--) {
//        heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
//    }
//
//    // Step 3.  Randomly ignite new 'sparks' of heat near the bottom
//    if( random8() < SPARKING ) {
//        int y = random8(7);
//        heat[y] = qadd8( heat[y], random8(160,255) );
//    }
//
//    // Step 4.  Map from heat cells to LED colors
//    for( int j = 0; j < NUM_LEDS; j++) {
//        leds[j] = HeatColor2( heat[j]);
//    }
//}
//
//

// CRGB 2( uint8_t temperature)
// [to be included in the forthcoming FastLED v2.1]
//
// Approximates a 'black body radiation' spectrum for
// a given 'heat' level.  This is useful for animations of 'fire'.
// Heat is specified as an arbitrary scale from 0 (cool) to 255 (hot).
// This is NOT a chromatically correct 'black body radiation'
// spectrum, but it's surprisingly close, and it's extremely fast and small.
//
// On AVR/Arduino, this typically takes around 70 bytes of program memory,
// versus 768 bytes for a full 256-entry RGB lookup table.

//CRGB HeatColor2( uint8_t temperature)
//{
//    CRGB heatcolor;
//
//    // Scale 'heat' down from 0-255 to 0-191,
//    // which can then be easily divided into three
//    // equal 'thirds' of 64 units each.
//    uint8_t t192 = scale8_video( temperature, 192);
//
//    // calculate a value that ramps up from
//    // zero to 255 in each 'third' of the scale.
//    uint8_t heatramp = t192 & 0x3F; // 0..63
//    heatramp <<= 2; // scale up to 0..252
//
//    // now figure out which third of the spectrum we're in:
//    if( t192 & 0x80) {
//        // we're in the hottest third
//        heatcolor.r = 255; // full red
//        heatcolor.g = 255; // full green
//        heatcolor.b = heatramp; // ramp up blue
//
//    } else if( t192 & 0x40 ) {
//        // we're in the middle third
//        heatcolor.r = 255; // full red
//        heatcolor.g = heatramp; // ramp up green
//        heatcolor.b = 0; // no blue
//
//    } else {
//        // we're in the coolest third
//        heatcolor.r = heatramp; // ramp up red
//        heatcolor.g = 0; // no green
//        heatcolor.b = 0; // no blue
//    }
//
//    return heatcolor;
//}