#include "BrainPad.h"
#include "BrainPadDisplay.h"
#include <string>

BrainPad brain;

uint8_t vram[1024];
uint8_t* font = new uint8_t[95 * 5] {
    0x00, 0x00, 0x00, 0x00, 0x00, /* Space	0x20 */
    0x00, 0x00, 0x4f, 0x00, 0x00, /* ! */
    0x00, 0x07, 0x00, 0x07, 0x00, /* " */
    0x14, 0x7f, 0x14, 0x7f, 0x14, /* # */
    0x24, 0x2a, 0x7f, 0x2a, 0x12, /* $ */
    0x23, 0x13, 0x08, 0x64, 0x62, /* % */
    0x36, 0x49, 0x55, 0x22, 0x20, /* & */
    0x00, 0x05, 0x03, 0x00, 0x00, /* ' */
    0x00, 0x1c, 0x22, 0x41, 0x00, /* ( */
    0x00, 0x41, 0x22, 0x1c, 0x00, /* ) */
    0x14, 0x08, 0x3e, 0x08, 0x14, /* // */
    0x08, 0x08, 0x3e, 0x08, 0x08, /* + */
    0x50, 0x30, 0x00, 0x00, 0x00, /* , */
    0x08, 0x08, 0x08, 0x08, 0x08, /* - */
    0x00, 0x60, 0x60, 0x00, 0x00, /* . */
    0x20, 0x10, 0x08, 0x04, 0x02, /* / */
    0x3e, 0x51, 0x49, 0x45, 0x3e, /* 0		0x30 */
    0x00, 0x42, 0x7f, 0x40, 0x00, /* 1 */
    0x42, 0x61, 0x51, 0x49, 0x46, /* 2 */
    0x21, 0x41, 0x45, 0x4b, 0x31, /* 3 */
    0x18, 0x14, 0x12, 0x7f, 0x10, /* 4 */
    0x27, 0x45, 0x45, 0x45, 0x39, /* 5 */
    0x3c, 0x4a, 0x49, 0x49, 0x30, /* 6 */
    0x01, 0x71, 0x09, 0x05, 0x03, /* 7 */
    0x36, 0x49, 0x49, 0x49, 0x36, /* 8 */
    0x06, 0x49, 0x49, 0x29, 0x1e, /* 9 */
    0x00, 0x36, 0x36, 0x00, 0x00, /* : */
    0x00, 0x56, 0x36, 0x00, 0x00, /* ; */
    0x08, 0x14, 0x22, 0x41, 0x00, /* < */
    0x14, 0x14, 0x14, 0x14, 0x14, /* = */
    0x00, 0x41, 0x22, 0x14, 0x08, /* > */
    0x02, 0x01, 0x51, 0x09, 0x06, /* ? */
    0x3e, 0x41, 0x5d, 0x55, 0x1e, /* @		0x40 */
    0x7e, 0x11, 0x11, 0x11, 0x7e, /* A */
    0x7f, 0x49, 0x49, 0x49, 0x36, /* B */
    0x3e, 0x41, 0x41, 0x41, 0x22, /* C */
    0x7f, 0x41, 0x41, 0x22, 0x1c, /* D */
    0x7f, 0x49, 0x49, 0x49, 0x41, /* E */
    0x7f, 0x09, 0x09, 0x09, 0x01, /* F */
    0x3e, 0x41, 0x49, 0x49, 0x7a, /* G */
    0x7f, 0x08, 0x08, 0x08, 0x7f, /* H */
    0x00, 0x41, 0x7f, 0x41, 0x00, /* I */
    0x20, 0x40, 0x41, 0x3f, 0x01, /* J */
    0x7f, 0x08, 0x14, 0x22, 0x41, /* K */
    0x7f, 0x40, 0x40, 0x40, 0x40, /* L */
    0x7f, 0x02, 0x0c, 0x02, 0x7f, /* M */
    0x7f, 0x04, 0x08, 0x10, 0x7f, /* N */
    0x3e, 0x41, 0x41, 0x41, 0x3e, /* O */
    0x7f, 0x09, 0x09, 0x09, 0x06, /* P		0x50 */
    0x3e, 0x41, 0x51, 0x21, 0x5e, /* Q */
    0x7f, 0x09, 0x19, 0x29, 0x46, /* R */
    0x26, 0x49, 0x49, 0x49, 0x32, /* S */
    0x01, 0x01, 0x7f, 0x01, 0x01, /* T */
    0x3f, 0x40, 0x40, 0x40, 0x3f, /* U */
    0x1f, 0x20, 0x40, 0x20, 0x1f, /* V */
    0x3f, 0x40, 0x38, 0x40, 0x3f, /* W */
    0x63, 0x14, 0x08, 0x14, 0x63, /* X */
    0x07, 0x08, 0x70, 0x08, 0x07, /* Y */
    0x61, 0x51, 0x49, 0x45, 0x43, /* Z */
    0x00, 0x7f, 0x41, 0x41, 0x00, /* [ */
    0x02, 0x04, 0x08, 0x10, 0x20, /* \ */
    0x00, 0x41, 0x41, 0x7f, 0x00, /* ] */
    0x04, 0x02, 0x01, 0x02, 0x04, /* ^ */
    0x40, 0x40, 0x40, 0x40, 0x40, /* _ */
    0x00, 0x00, 0x03, 0x05, 0x00, /* `		0x60 */
    0x20, 0x54, 0x54, 0x54, 0x78, /* a */
    0x7F, 0x44, 0x44, 0x44, 0x38, /* b */
    0x38, 0x44, 0x44, 0x44, 0x44, /* c */
    0x38, 0x44, 0x44, 0x44, 0x7f, /* d */
    0x38, 0x54, 0x54, 0x54, 0x18, /* e */
    0x04, 0x04, 0x7e, 0x05, 0x05, /* f */
    0x08, 0x54, 0x54, 0x54, 0x3c, /* g */
    0x7f, 0x08, 0x04, 0x04, 0x78, /* h */
    0x00, 0x44, 0x7d, 0x40, 0x00, /* i */
    0x20, 0x40, 0x44, 0x3d, 0x00, /* j */
    0x7f, 0x10, 0x28, 0x44, 0x00, /* k */
    0x00, 0x41, 0x7f, 0x40, 0x00, /* l */
    0x7c, 0x04, 0x7c, 0x04, 0x78, /* m */
    0x7c, 0x08, 0x04, 0x04, 0x78, /* n */
    0x38, 0x44, 0x44, 0x44, 0x38, /* o */
    0x7c, 0x14, 0x14, 0x14, 0x08, /* p		0x70 */
    0x08, 0x14, 0x14, 0x14, 0x7c, /* q */
    0x7c, 0x08, 0x04, 0x04, 0x00, /* r */
    0x48, 0x54, 0x54, 0x54, 0x24, /* s */
    0x04, 0x04, 0x3f, 0x44, 0x44, /* t */
    0x3c, 0x40, 0x40, 0x20, 0x7c, /* u */
    0x1c, 0x20, 0x40, 0x20, 0x1c, /* v */
    0x3c, 0x40, 0x30, 0x40, 0x3c, /* w */
    0x44, 0x28, 0x10, 0x28, 0x44, /* x */
    0x0c, 0x50, 0x50, 0x50, 0x3c, /* y */
    0x44, 0x64, 0x54, 0x4c, 0x44, /* z */
    0x08, 0x36, 0x41, 0x41, 0x00, /* { */
    0x00, 0x00, 0x77, 0x00, 0x00, /* | */
    0x00, 0x41, 0x41, 0x36, 0x08, /* } */
    0x08, 0x08, 0x2a, 0x1c, 0x08  /* ~ */
};

void DrawPoint(int x, int y, bool set) {
    if (x >= 0 && x < 128 && y >= 0 && y < 64) {
        int offset = y * 16 + x / 8;
        int mask = 0x80 >> (x & 7);

        if (set)
            vram[offset] |= mask;
        else
            vram[offset] &= ~mask;
    }
}

void DrawText(int x, int y, char letter) {
    int index = 5 * (letter - 32);

    for (int h = 0; h < 5; h++)
        for (int v = 0; v < 8; v++)
            DrawPoint(x + h, y + v, (font[index + h] & (1 << v)) != 0);

    // clear the space between characters
    for (int i = 0; i < 8; i++)
        DrawPoint(x + 5, y + i, 0);
}

void DrawString(int x, int y, std::string text) {
    for (size_t i = 0; i < text.length(); i++) {
        if (text[i] >= 32) {
            DrawText(x, y, text[i]);

            x += 6;
        }
    }
}

void TestButtons() {
    if (brain.buttonUp.isPressed())
        DrawString(1, 40, "UP   ");

    if (brain.buttonLeft.isPressed())
        DrawString(1, 40, "LEFT ");

    if (brain.buttonRight.isPressed())
        DrawString(1, 40, "RIGHT");

    if (brain.buttonDown.isPressed())
        DrawString(1, 40, "DOWN ");

}

void TestBuzzer() {
    // Turn the buzzer on at 1800hz for 300ms

    int frequency = 1800;

    brain.io.buzzer.setAnalogValue(512); //per https://github.com/Microsoft/pxt-brainpad/blob/master/libs/music/music.cpp#L48
    brain.io.buzzer.setAnalogPeriodUs(1000000 / frequency);

    brain.sleep(300);

    brain.io.buzzer.setAnalogValue(0);
}

void TestLightBulb() {
    // Slowley turn the LED on

    for (int i = 0; i < 10; i++) {
        brain.io.ledBlue.setAnalogValue(i * 100);
        brain.sleep(200);
    }

    brain.io.ledBlue.setAnalogValue(0);
}

void TestLightSensor() {
    // Show the light level on the screen
    // see: https://github.com/Microsoft/pxt-common-packages/blob/master/libs/lightsensor/lightsensor.cpp#L48

    int light = brain.io.lightPin.getAnalogValue() / 4; // returned values are 16K max, change to 1K max.

    std::string l = "L:" + std::to_string(light) + "  ";

    DrawString(1, 20, l);
}

void TestTemperatureSensor() {
    // Show temp in celsius

    int temper = ((brain.io.temperaturePin.getAnalogValue() * 3.3) - 450) / 19.5;

    std::string t = "T:" + std::to_string(temp) + "  ";

    DrawString(1, 1, t);
}

void TestServo() {
    // Requires servo motor on servo pins #1

    brain.io.servoOne.setServoValue(180);
    brain.sleep(200);

    brain.io.servoOne.setServoValue(90);
    brain.sleep(200);

    brain.io.servoOne.setServoValue(0);
    brain.sleep(200);
}

int main() {
    brain.init();

    TestServo();
    TestBuzzer();
    TestLightBulb();

    while (true) {
        TestButtons();
        TestTemperatureSensor();
        TestLightSensor();

        brain.lcd.writeScreenBuffer(vram);
    }

    return 0;
}
