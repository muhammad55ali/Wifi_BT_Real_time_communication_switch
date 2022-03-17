
/*
using 3 button and 6 leds 
one button to toggle led 1 and led 2
2nd button to toggle  led 3 and 4
reading the states of led1 and led 2 
if led 1 is high then toggle leds 3 and 4 also turn off leds 5 and 6 ( when button 2 is pressed)
if led 2 is high then toggle leds 5 ans 6 also turn off leds 3 and 4(when button 3 is pressed)

*/
#define wifi_bt_btn_pin     25 
#define wifi_snd_rc_btn_pin 26 
#define bt_snd_rc_btn_pin   27


#define LED_PIN_1 16
#define LED_PIN_2 17
#define LED_PIN_3 18
#define LED_PIN_4 19
#define LED_PIN_5 21
#define LED_PIN_6 23
#include <Bounce2.h>
Bounce2::Button wifi_bt_btn     = Bounce2::Button();
Bounce2::Button wifi_snd_rc_btn = Bounce2::Button();
Bounce2::Button bt_snd_rc_btn   = Bounce2::Button();

int led_1_state = LOW;
int led_2_state ;

int led_3_state = LOW;
int led_4_state ;

int led_5_state = LOW;
int led_6_state ;

void setup() {
  Serial.begin(115200);
  wifi_bt_btn.attach( wifi_bt_btn_pin, INPUT );
  wifi_bt_btn.interval(5);
  wifi_bt_btn.setPressedState(LOW);

  wifi_snd_rc_btn.attach( wifi_snd_rc_btn_pin, INPUT );
  wifi_snd_rc_btn.interval(5);
  wifi_snd_rc_btn.setPressedState(LOW);

  bt_snd_rc_btn.attach( bt_snd_rc_btn_pin, INPUT );
  bt_snd_rc_btn.interval(5);
  bt_snd_rc_btn.setPressedState(LOW);
  
  pinMode(LED_PIN_1, OUTPUT);
  pinMode(LED_PIN_2, OUTPUT);
  pinMode(LED_PIN_3, OUTPUT);
  pinMode(LED_PIN_4, OUTPUT);
  pinMode(LED_PIN_5, OUTPUT);
  pinMode(LED_PIN_6, OUTPUT);

}

void loop() {
  wifi_bt_btn.update();
  wifi_snd_rc_btn.update();
  
  bt_snd_rc_btn.update();
  if ( wifi_bt_btn.pressed() )   {led_1_state = !led_1_state; led_2_state = !led_1_state;  }
  if ( wifi_snd_rc_btn.pressed()){led_3_state = !led_3_state; led_4_state = !led_3_state; }
  if ( bt_snd_rc_btn.pressed() ) {led_5_state = !led_5_state; led_6_state = !led_5_state;  }


  
  
  digitalWrite(LED_PIN_1,led_1_state);
  digitalWrite(LED_PIN_2,led_2_state);


  if(led_1_state == HIGH){
  digitalWrite(LED_PIN_5,led_5_state);
  digitalWrite(LED_PIN_6,led_6_state);
  digitalWrite(LED_PIN_3,LOW);
  digitalWrite(LED_PIN_4,LOW);
  wifi();
  
  }else {
  digitalWrite(LED_PIN_5,LOW);
  digitalWrite(LED_PIN_6,LOW);
  digitalWrite(LED_PIN_3,led_3_state);
  digitalWrite(LED_PIN_4,led_4_state);
  bluetooth();
 }
}

 void wifi(){
  if(led_5_state == HIGH){
    Serial.println("Wifi Sending");
  }else{
    Serial.println("Wifi Recieving");
  }
 }
 void bluetooth(){
    if(led_3_state == HIGH){
    Serial.println("Bluetooth Sending");
  }else{
    Serial.println("Bluetooth Recieving");
  }
  }


 
 
  
  
  

  
