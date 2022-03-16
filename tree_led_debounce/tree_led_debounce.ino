
#define BOUNCE_PIN 25
#define BOUNCE_PIN2 26
#define BOUNCE_PIN3 27

#define LED_PIN_1 16
#define LED_PIN_2 17
#define LED_PIN_3 18
#define LED_PIN_4 19
#define LED_PIN_5 21
#define LED_PIN_6 23
#include <Bounce2.h>

Bounce bounce = Bounce();
Bounce bounce2 = Bounce();
Bounce bounce3 = Bounce();
int led_1_state = LOW;
int led_2_state ;

int led_3_state = LOW;
int led_4_state ;

int led_5_state = LOW;
int led_6_state ;

void setup() {
  Serial.begin(115200);
  bounce.attach( BOUNCE_PIN, INPUT );
   bounce2.attach( BOUNCE_PIN2, INPUT );
    bounce3.attach( BOUNCE_PIN3, INPUT );
  bounce.interval(5);
  pinMode(LED_PIN_1, OUTPUT);
  pinMode(LED_PIN_2, OUTPUT);
  pinMode(LED_PIN_3, OUTPUT);
  pinMode(LED_PIN_4, OUTPUT);
  pinMode(LED_PIN_5, OUTPUT);
  pinMode(LED_PIN_6, OUTPUT);
  digitalWrite(LED_PIN_1, led_1_state);
  digitalWrite(LED_PIN_3, led_3_state);
  digitalWrite(LED_PIN_5, led_5_state);
}

void loop() {
  bounce.update();
    bounce2.update();
      bounce3.update();
  Serial.println(bounce.changed());
  if ( bounce.changed() ) {
    int deboucedInput = bounce.read();
    if ( deboucedInput == LOW ) {
      led_1_state = !led_1_state; 
      led_2_state= !led_1_state;
      
      digitalWrite(LED_PIN_1,led_1_state);
      
      digitalWrite(LED_PIN_2,led_2_state);
      if( led_1_state==HIGH){
        
      }
    }
  }

  if ( bounce2.changed() ) {
    int deboucedInput = bounce2.read();
    if ( deboucedInput == LOW ) {
      led_3_state = !led_3_state; 
      led_4_state= !led_3_state;
      
      digitalWrite(LED_PIN_3,led_3_state);
      
      digitalWrite(LED_PIN_4,led_4_state);
    }
  }

  if ( bounce3.changed() ) {
    int deboucedInput = bounce3.read();
    if ( deboucedInput == LOW ) {
      led_5_state = !led_5_state; 
      led_6_state= !led_5_state;
      
      digitalWrite(LED_PIN_5,led_5_state);
      
      digitalWrite(LED_PIN_6,led_6_state);
    }
  }

}