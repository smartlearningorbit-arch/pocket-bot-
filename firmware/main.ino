#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Eye parameters :>
int eyeX1 = 45, eyeY1 = 30, eyeX2 = 85, eyeY2 = 30;  
int pupilX1 = 45, pupilY1 = 30, pupilX2 = 85, pupilY2 = 30;  

void setup() {
  Serial.begin(115200);

  if (!display.begin(SSD1306_I2C_ADDRESS, OLED_RESET)) {
    Serial.println(F("SSD1306 allocation failed Yo Robo is blind"));
    for (;;);
  }

  display.display();  // Initial 
  delay(2000);
  display.clearDisplay();
}


void loop() {
  // Random movement 
  int eyeMoveX1 = random(-2, 3); 
   int eyeMoveY1 = random(-2, 3);  
    int  eyeMoveY2 = random(-2, 3);  
      int eyeMoveX2 = random(-2, 3);  

  // Update eyes' positions with slight randomness
  eyeX1 += eyeMoveX1;
  eyeY1 += eyeMoveY1;
   eyeX2 += eyeMoveX2;
  eyeY2 += eyeMoveY2;

  eyeX1 = constrain(eyeX1, 30, 60);
   eyeY1 = constrain(eyeY1, 20, 40);
  eyeX2 = constrain(eyeX2, 70, 100);
  eyeY2 = constrain(eyeY2, 20, 40);

  display.fillCircle(eyeX1, eyeY1, 10, WHITE);
  display.fillCircle(eyeX2, eyeY2, 10, WHITE);


   int pupilMoveX1 = random(-2, 3);  
  int pupilMoveY1 = random(-2, 3);  
  int pupilMoveX2 = random(-2, 3);  
  int pupilMoveY2 = random(-2, 3);

   pupilX1 += pupilMoveX1;
  pupilY1 += pupilMoveY1;
  pupilX2 += pupilMoveX2;
  pupilY2 += pupilMoveY2;

  pupilX1 = constrain(pupilX1, eyeX1 - 4, eyeX1 + 4);
  pupilY1 = constrain(pupilY1, eyeY1 - 4, eyeY1 + 4);
  pupilX2 = constrain(pupilX2, eyeX2 - 4, eyeX2 + 4);
  pupilY2 = constrain(pupilY2, eyeY2 - 4, eyeY2 + 4);

  display.fillCircle(pupilX1, pupilY1, 5, BLACK);
  display.fillCircle(pupilX2, pupilY2, 5, BLACK);

  display.display();
  delay(100); 
//  delay(500); 
 // delay(2000); 
  display.clearDisplay();  
}