#include <FastLED.h>
#include "Arduino.h"
//#include "Fire.h"
#include "Constants.h"

int clamp(int val) {
    return clamp(val, 0, 255);
}

int clamp(int val, int min, int max) {
    if (val < min) {
        val = min;
    }
    if (val > max) {
        val = max;
    }
    return val;
}

long HSBtoRGB(float _hue, float _sat, float _brightness) {
    float red = 0.0;
    float green = 0.0;
    float blue = 0.0;

    if (_sat == 0.0) {
        red = _brightness;
        green = _brightness;
        blue = _brightness;
    } else {
        if (_hue == 360.0) {
            _hue = 0;
        }

        int slice = _hue / 60.0;
        float hue_frac = (_hue / 60.0) - slice;

        float aa = _brightness * (1.0 - _sat);
        float bb = _brightness * (1.0 - _sat * hue_frac);
        float cc = _brightness * (1.0 - _sat * (1.0 - hue_frac));

        switch (slice) {
            case 0:
                red = _brightness;
                green = cc;
                blue = aa;
                break;
            case 1:
                red = bb;
                green = _brightness;
                blue = aa;
                break;
            case 2:
                red = aa;
                green = _brightness;
                blue = cc;
                break;
            case 3:
                red = aa;
                green = bb;
                blue = _brightness;
                break;
            case 4:
                red = cc;
                green = aa;
                blue = _brightness;
                break;
            case 5:
                red = _brightness;
                green = aa;
                blue = bb;
                break;
            default:
                red = 0.0;
                green = 0.0;
                blue = 0.0;
                break;
        }
    }

    long ired = red * 255.0;
    long igreen = green * 255.0;
    long iblue = blue * 255.0;

    return long((ired << 16) | (igreen << 8) | (iblue));
}

void setup() {
    Serial.begin(9600);
    FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS); //.setCorrection(0x9010FF); // 30 works for green
    FastLED.setBrightness(100);
}

int xOffset = 0;
int yOffset = 0;

void setPixel(int x, int y, int red, int green, int blue) {
    red = clamp(red);
    green = clamp(green);
    blue = clamp(blue);
    x = (x + xOffset) % WIDTH;
    y = (y + yOffset) % HEIGHT;
    if (y % 2 == 0) {
        // reverse every other row
        x = (WIDTH - 1) - x;
    }
    leds[(x + y * WIDTH)] = CRGB(pgm_read_byte(&gamma8[red]), pgm_read_byte(&gamma8[green]),
                                 pgm_read_byte(&gamma8[blue]));
}

void displayImage(bool scroll) {
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            int idx = (x + y * WIDTH) * 3;
            int red = pgm_read_byte(&colors[idx]);
            int blue = pgm_read_byte(&colors[idx + 1]);
            int green = pgm_read_byte(&colors[idx + 2]);
            setPixel(x, y, red, green, blue);
        }
    }
    FastLED.delay(400);
    if(scroll) {
        xOffset++;
    }
}

void displayFullscreenRainbowCycle(int colors, float saturation, float brightness, int d) {
    for (int i = 0; i < colors; i++) {
        float hue = (i / float(colors)) * 360; // Number between 0 and 360
        long color = HSBtoRGB(hue, saturation, brightness);

        // Get the red, blue and green parts from generated color
        int red = color >> 16 & 255;
        int green = color >> 8 & 255;
        int blue = color & 255;
        Serial.print(red);
        Serial.print(" ");
        Serial.print(green);
        Serial.print(" ");
        Serial.println(blue);
        for (int x = 0; x < WIDTH; x++) {
            for (int y = 0; y < HEIGHT; y++) {
                setPixel(x, y, red, green, blue);
            }
        }
        FastLED.delay(d);

    }
}

void displayMovingRainbow(int colors, int speed, bool axis, float saturation, float brightness, int d) {

}



void loop() {
    random16_add_entropy(random());
    // fastest update is about 30 ms
    // displayFullscreenRainbowCycle(32, 1, 1, 50); // good values for a fast loop
//    Fire2012();
    FastLED.show();
    delay(1000/30);
}