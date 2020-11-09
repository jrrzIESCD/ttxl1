#include <FastLED.h>
#define LED_PIN     7
#define NUM_LEDS    150
CRGB leds[NUM_LEDS];
void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  
}
void loop() {
  for (int i=0; i<150; i++)
  {
    leds[i] = CRGB(random(0,255), random(0,255), random(0,255));
    FastLED.show();
    delay(500);    
  }
}
