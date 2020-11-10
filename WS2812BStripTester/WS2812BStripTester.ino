#include <FastLED.h>
#define LED_PIN     7
#define NUM_LEDS    150
CRGB leds[NUM_LEDS];
void setup() {
  Serial.begin(115200);
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  
}
void loop() {
  int speed = 50;
  int color = 96;
  int led_array[3] = {0, 0, 0};
  for (int i=0; i<16; i++)
  {
    led_array[0] = i;
    led_array[1] = 100 - i - 1;
    led_array[2] = 100 + i, color;
    setColorToLeds(led_array, color); 
    FastLED.show();
    delay(speed);    
  }
  
  color = -1;
  for (int i=16; i<33; i++)
  {
    led_array[0] = i;
    led_array[1] = 100 - i - 1;
    led_array[2] = 100 + i, color;
    setColorToLeds(led_array, color);
    FastLED.show();
    delay(speed);    
  }

  color = 0;
  for (int i=33; i<50; i++)
  {
    led_array[0] = i;
    led_array[1] = 100 - i - 1;
    led_array[2] = 100 + i, color;
    setColorToLeds(led_array, color);
    
    FastLED.show();
    delay(speed);    
  }
}


void setColorToLeds(int leds[], int color)
{
  int size = sizeof(leds)/sizeof(int);

  for (int i = 0; i < 3; i++)
  {
    setColorToLed(leds[i], color);
  }
}

void setColorToLed(int l, int color)
{
  if (color == -1) 
  {
    leds[l] = CRGB(255,255,255);
  } 
  else
  {
    leds[l] = CHSV(color, 255, 255);
  }
}
