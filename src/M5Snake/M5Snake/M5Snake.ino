/******************************************************************************
 * M5Snake                                                                    *
 * -------                                                                    *
 * Snake game for M5Stack-Core with Gameboy Keyboard faces                    *
 * Author: Olivier Staquet                                                    *
 * Last version available on https://github.com/ostaquet/M5Snake              *
 ******************************************************************************
 * MIT License
 *
 * Copyright (c) 2020 Olivier Staquet
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *******************************************************************************/
#include <M5Stack.h>
#include "GameboyInput.h"
#include "Power.h"

void setup() {
  // Initialize M5Stack (LCD = true, SD = false, Serial = true, I2C = true)
  M5.begin(true, false, true, true);

  // Show that we are alive
  M5.Lcd.setBrightness(100);
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setTextSize(2);
  M5.Lcd.println(F("M5Snake by Olivier Staquet"));

  // Disable white noise on speaker 
  // (according to https://community.m5stack.com/topic/61/noise-on-speaker/15)
  dacWrite(25,0);

  // Start the Gameboy faces controller
  GameboyInput.begin();

  // Show battery management
  Power.begin();
  Power.adaptChargeMode();

  M5.Lcd.print(F("Battery level "));
  int8_t batt = Power.getBatteryLevel();
  if(batt >= 0) {
    M5.Lcd.print(batt);
    M5.Lcd.println(F("%"));
  } else {
    M5.Lcd.println(F("unavailable"));
  }
}

void loop() {
  uint8_t key_val = GameboyInput.getActivity();
  if(key_val != GAMEBOY_KEY_NONE) {
    M5.Lcd.printf("0x%02X ",key_val);
    Serial.printf("0x%02X ",key_val);
  }
  delay(5);
}
