#include "Arduino.h"
#include "Wire.h"
#include "SPI.h"
#include "Adafruit_SSD1306.h"
#include "Adafruit_GFX.h"


// Pin Definitions
#define OLED128X32_PIN_RST	2

// Global variables and defines

// object initialization
#define SSD1306_LCDHEIGHT 32
Adafruit_SSD1306 oLed128x32(OLED128X32_PIN_RST);

// Setup the essentials for your circuit to work. It runs first every time your circuit is powered with electricity.
void setup()
{
  // Setup Serial which is useful for debugging
  // Use the Serial Monitor to view printed messages
  Serial.begin(9600);
  while (!Serial) ; // wait for serial port to connect. Needed for native USB
  Serial.println("Start highway sign");

  oLed128x32.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x32)
  oLed128x32.clearDisplay(); // Clear the buffer.
  oLed128x32.display();
}

// Main logic of your circuit. It defines the interaction between the components you selected. After setup, it runs over and over again, in an eternal loop.
void loop()
{
    oLed128x32.clearDisplay();
    oLed128x32.setTextColor(WHITE);
    
    /* Draw speed limitation */
    // Draw circle
    oLed128x32.drawCircle(16, 16, 15, WHITE);
    // Write 90 in the circle
    oLed128x32.setTextSize(1);
    oLed128x32.setCursor(8, 12);
    oLed128x32.println("110");

    /* Write message */
    oLed128x32.setTextSize(1);
    
    oLed128x32.setCursor(40, 0);
    oLed128x32.println("    ALERTE    ");

    oLed128x32.setCursor(40, 8);
    oLed128x32.println("POLLUTION AIR");

    oLed128x32.setCursor(40, 16);
    oLed128x32.println(" MOINS 20KM/H ");

    oLed128x32.setCursor(40, 24);
    oLed128x32.println(" OBLIGATOIRE  ");
    
    oLed128x32.display();
    delay(1000);
}
