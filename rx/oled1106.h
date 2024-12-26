#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>


  /* Uncomment the initialize the I2C address , uncomment only one, If you get a totally blank screen try the other*/
#define i2c_Address 0x3c  //initialize with the I2C addr 0x3C Typically eBay OLED's
  //#define i2c_Address 0x3d //initialize with the I2C addr 0x3D Typically Adafruit OLED's

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels
#define OLED_RESET -1     //   QT-PY / XIAO
  Adafruit_SH1106G display = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define LOGO16_GLCD_HEIGHT 16
#define LOGO16_GLCD_WIDTH 16


void oled_init() {

  // Serial.begin(9600);




  delay(250);                        // wait for the OLED to power up
  display.begin(i2c_Address, true);  // Address 0x3C default
                                     //display.setContrast (0); // dim display

  display.display();
  delay(2000);

  // Clear the buffer.
  display.clearDisplay();


  // // invert the display
  // display.invertDisplay(true);
  // delay(1000);
  // display.invertDisplay(false);
  // delay(1000);
  // display.clearDisplay();

  // // draw a bitmap icon and 'animate' movement
  // testdrawbitmap(logo16_glcd_bmp, LOGO16_GLCD_HEIGHT, LOGO16_GLCD_WIDTH);
}

void displayText(uint8_t x,uint8_t y,String text,uint8_t size=1){
    // text display tests
  display.setTextSize(1);
  display.setTextColor(SH110X_WHITE);
  display.setCursor(x,y);
  display.print(text);
  display.display(); // actually display all of the above
}
void displayPrint(String text,uint8_t size=1){
    // text display tests
  display.setTextSize(1);
  display.setTextColor(SH110X_WHITE);
  // display.setCursor(x,y);
  display.print(text);
  display.display(); // actually display all of the above
}
void displayPrintln(uint8_t x,uint8_t y,String text,uint8_t size=1){
    // text display tests
  display.setTextSize(1);
  display.setTextColor(SH110X_WHITE);
  display.setCursor(x,y);
  display.println(text);
  display.display(); // actually display all of the above
}