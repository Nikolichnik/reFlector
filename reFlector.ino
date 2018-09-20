/*********************************************************************
This is an example for our Monochrome OLEDs based on SSD1306 drivers

  Pick one up today in the adafruit shop!
  ------> http://www.adafruit.com/category/63_98

This example is for a 128x64 size display using I2C to communicate
3 pins are required to interface (2 I2C and one reset)

Adafruit invests time and resources providing this open source code, 
please support Adafruit and open-source hardware by purchasing 
products from Adafruit!

Written by Limor Fried/Ladyada  for Adafruit Industries.  
BSD license, check license.txt for more information
All text above, and the splash screen must be included in any redistribution
*********************************************************************/

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2


#define LOGO16_GLCD_HEIGHT 16 
#define LOGO16_GLCD_WIDTH  16 
static const unsigned char PROGMEM logo16_glcd_bmp[] =
{ B00000000, B11000000,
  B00000001, B11000000,
  B00000001, B11000000,
  B00000011, B11100000,
  B11110011, B11100000,
  B11111110, B11111000,
  B01111110, B11111111,
  B00110011, B10011111,
  B00011111, B11111100,
  B00001101, B01110000,
  B00011011, B10100000,
  B00111111, B11100000,
  B00111111, B11110000,
  B01111100, B11110000,
  B01110000, B01110000,
  B00000000, B00110000 };

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

const int button1Pin = 11;     // the number of the pushbutton pin
const int button2Pin = 12;     // the number of the pushbutton pin
const int led1Pin =  A0;      // the number of the LED pin
const int led2Pin =  A1;
const int relay1Pin = 2;
const int relay2Pin = 3;

// variables will change:
int button1State = 0;         // variable for reading the pushbutton status
int button2State = 0;

void setup()   {
  // initialize the LED pin as an output:
  pinMode(relay1Pin, OUTPUT);
  pinMode(relay2Pin, OUTPUT);
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);                
  Serial.begin(9600);

  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
  // init done
  
  // Show image buffer on the display hardware.
  // Since the buffer is intialized with an Adafruit splashscreen
  // internally, this will display the splashscreen.
  display.display();
  delay(2000);

  // Clear the buffer.
  display.clearDisplay();

  // draw a single pixel  

  // draw many lines
  testdrawline();
  display.display();
  delay(2000);
  display.clearDisplay();

  

  // draw multiple rectangles  

  // draw mulitple circles  

  // draw a white circle, 10 pixel radius
  

  // draw the first ~12 characters in the font  

  /*
  // draw scrolling text
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(20,25);
  display.clearDisplay();
  display.println("Zdravo, Tatjana");
  display.println("       Socanin!");
  display.display();
  delay(1500);
 
  display.startscrollright(0x00, 0x0F);
  delay(8500);
  display.stopscroll();
  delay(999);
  display.clearDisplay();

  display.setCursor(6,30);  
  display.println("Nalete stvar odozdo");
  //display.println("    pesmu odozdo");
  display.display();
  delay(1);
 
  display.startscrolldiagright(0x00, 0x07);
  delay(8500);
  display.stopscroll();
  delay(999);
  display.clearDisplay();

  display.setCursor(21,30);
  display.println("I setih se...");
  display.display();
  delay(1);  
 
  display.startscrolldiagleft(0x00, 0x07);
  delay(8500);
  display.stopscroll();
  delay(999);
  display.clearDisplay();

  display.setCursor(45,30);
  display.println("koliko");
  display.display();
  delay(900);
  display.clearDisplay();
  delay(300);

  display.setCursor(60,30);
  display.println("mi");
  display.display();
  delay(900);
  display.clearDisplay();
  delay(300);

  display.setCursor(41,30);
  display.println("nedostaju");
  display.display();
  delay(900);
  display.clearDisplay();
  delay(300);

  display.setCursor(31,30);
  display.println("iscekivanja");
  display.display();
  delay(900);
  display.clearDisplay();
  delay(300);

  display.setCursor(45,30);
  display.println("tvojih");
  display.display();
  delay(900);
  display.clearDisplay();
  delay(300);

  display.setTextSize(2);
  display.setCursor(15,25);
  display.println("odgovora!");
  display.display();
  delay(3000);
  display.clearDisplay();
  delay(999);

  display.setTextSize(1);
  display.setCursor(43,30);
  display.println("...i ti.");
  display.display();
  delay(2500);
  display.clearDisplay();
  delay(900);
 */
  
  // text display tests  

  // miniature bitmap display
  
  // invert the display
  
  // draw a bitmap icon and 'animate' movement

  
 }

void loop() {

  

  // draw rectangles
  testdrawrect();
  display.display();
  delay(100);
  display.clearDisplay();
  
}


void testdrawbitmap(const uint8_t *bitmap, uint8_t w, uint8_t h) {
  uint8_t icons[NUMFLAKES][3];
 
  // initialize
  for (uint8_t f=0; f< NUMFLAKES; f++) {
    icons[f][XPOS] = random(display.width());
    icons[f][YPOS] = 0;
    icons[f][DELTAY] = random(5) + 1;
    
    Serial.print("x: ");
    Serial.print(icons[f][XPOS], DEC);
    Serial.print(" y: ");
    Serial.print(icons[f][YPOS], DEC);
    Serial.print(" dy: ");
    Serial.println(icons[f][DELTAY], DEC);
  }

  while (1) {
    // draw each icon
    for (uint8_t f=0; f< NUMFLAKES; f++) {
      display.drawBitmap(icons[f][XPOS], icons[f][YPOS], bitmap, w, h, WHITE);
    }
    display.display();
    delay(200);
    
    // then erase it + move it
    for (uint8_t f=0; f< NUMFLAKES; f++) {
      display.drawBitmap(icons[f][XPOS], icons[f][YPOS], bitmap, w, h, BLACK);
      // move it
      icons[f][YPOS] += icons[f][DELTAY];
      // if its gone, reinit
      if (icons[f][YPOS] > display.height()) {
        icons[f][XPOS] = random(display.width());
        icons[f][YPOS] = 0;
        icons[f][DELTAY] = random(5) + 1;
      }
    }
   }
}


void testdrawchar(void) {
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);

  for (uint8_t i=0; i < 168; i++) {
    if (i == '\n') continue;
    display.write(i);
    if ((i > 0) && (i % 21 == 0))
      display.println();
  }    
  display.display();
  delay(1);
}

void testdrawcircle(void) {
  for (int16_t i=0; i<display.height(); i+=2) {
    display.drawCircle(display.width()/2, display.height()/2, i, WHITE);
    display.display();
    delay(1);
  }
}

void testfillrect(void) {
  uint8_t color = 1;
  for (int16_t i=0; i<display.height()/2; i+=3) {
    // alternate colors
    display.fillRect(i, i, display.width()-i*2, display.height()-i*2, color%2);
    display.display();
    delay(1);
    color++;
  }
}

void testdrawtriangle(void) {
  for (int16_t i=0; i<min(display.width(),display.height())/2; i+=5) {
    display.drawTriangle(display.width()/2, display.height()/2-i,
                     display.width()/2-i, display.height()/2+i,
                     display.width()/2+i, display.height()/2+i, WHITE);
    display.display();
    delay(1);
  }
}

void testfilltriangle(void) {
  uint8_t color = WHITE;
  for (int16_t i=min(display.width(),display.height())/2; i>0; i-=5) {
    display.fillTriangle(display.width()/2, display.height()/2-i,
                     display.width()/2-i, display.height()/2+i,
                     display.width()/2+i, display.height()/2+i, WHITE);
    if (color == WHITE) color = BLACK;
    else color = WHITE;
    display.display();
    delay(1);
  }
}

void testdrawroundrect(void) {
  for (int16_t i=0; i<display.height()/2-2; i+=2) {
    display.drawRoundRect(i, i, display.width()-2*i, display.height()-2*i, display.height()/4, WHITE);
    display.display();
    delay(1);
  }
}

void testfillroundrect(void) {
  uint8_t color = WHITE;
  for (int16_t i=0; i<display.height()/2-2; i+=2) {
    display.fillRoundRect(i, i, display.width()-2*i, display.height()-2*i, display.height()/4, color);
    if (color == WHITE) color = BLACK;
    else color = WHITE;
    display.display();
    delay(1);
  }
}
   
void testdrawrect(void) {
  for (int16_t i=0; i<display.height()/2; i+=2) {
    button1State = digitalRead(button1Pin);
  button2State = digitalRead(button2Pin);
  

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (button1State == HIGH) {
    // turn LED on:
    digitalWrite(relay1Pin, HIGH);
    digitalWrite(led1Pin, HIGH);
  } else {
    // turn LED off:
    digitalWrite(relay1Pin, LOW);
    digitalWrite(led1Pin, LOW);
  }

   if (button2State == HIGH) {
    // turn LED on:
    digitalWrite(relay2Pin, HIGH);
    digitalWrite(led2Pin, HIGH);
  } else {
    // turn LED off:
    digitalWrite(relay2Pin, LOW);
    digitalWrite(led2Pin, LOW);
  }
    display.drawRect(i, i, display.width()-2*i, display.height()-2*i, WHITE);
    display.display();
    delay(1);
  }
}

void testdrawline() {  
  for (int16_t i=0; i<display.width(); i+=4) {
    display.drawLine(0, 0, i, display.height()-1, WHITE);
    display.display();
    delay(1);
  }
  for (int16_t i=0; i<display.height(); i+=4) {
    display.drawLine(0, 0, display.width()-1, i, WHITE);
    display.display();
    delay(1);
  }
  delay(250);
  
  /*display.clearDisplay();
  for (int16_t i=0; i<display.width(); i+=4) {
    display.drawLine(0, display.height()-1, i, 0, WHITE);
    display.display();
    delay(1);
  }
  for (int16_t i=display.height()-1; i>=0; i-=4) {
    display.drawLine(0, display.height()-1, display.width()-1, i, WHITE);
    display.display();
    delay(1);
  }
  delay(250);*/
  
  display.clearDisplay();
  for (int16_t i=display.width()-1; i>=0; i-=4) {
    display.drawLine(display.width()-1, display.height()-1, i, 0, WHITE);
    display.display();
    delay(1);
  }
  for (int16_t i=display.height()-1; i>=0; i-=4) {
    display.drawLine(display.width()-1, display.height()-1, 0, i, WHITE);
    display.display();
    delay(1);
  }
  delay(250);

  display.clearDisplay();
  for (int16_t i=0; i<display.height(); i+=4) {
    display.drawLine(display.width()-1, 0, 0, i, WHITE);
    display.display();
    delay(1);
  }
  for (int16_t i=0; i<display.width(); i+=4) {
    display.drawLine(display.width()-1, 0, i, display.height()-1, WHITE); 
    display.display();
    delay(1);
  }
  delay(250);
}

void testscrolltext(String text) {
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(10,0);
  display.clearDisplay();
  display.println(text);
  display.display();
  delay(1);
 
  display.startscrollright(0x00, 0x0F);
  delay(2000);
  display.stopscroll();
  delay(1000);
  display.startscrollleft(0x00, 0x0F);
  delay(2000);
  display.stopscroll();
  delay(1000);    
  display.startscrolldiagright(0x00, 0x07);
  delay(2000);
  display.startscrolldiagleft(0x00, 0x07);
  delay(2000);
  display.stopscroll();
}
