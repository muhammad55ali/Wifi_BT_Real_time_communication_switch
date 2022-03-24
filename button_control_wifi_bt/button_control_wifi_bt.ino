//button control wifi and bluetooth communication using header files wifi.h and bt.h.
//used 3 buttons to switch between wifi/bluetooth,sending/receiving.
#include "bt.h"
#include "wifi.h"


void bt_comm();
void wifi();
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
  if ( wifi_snd_rc_btn.pressed()){
    led_3_state = !led_3_state; 
     bt_print_flag=true;
     bt_print1_flag= true;
    led_4_state = !led_3_state; }
  if ( bt_snd_rc_btn.pressed() ) {led_5_state = !led_5_state; 
        wf_print_flag=true;
        wf_print1_flag= true;
     led_6_state = !led_5_state;  }

  digitalWrite(LED_PIN_1,led_1_state);
  digitalWrite(LED_PIN_2,led_2_state);

  if(led_1_state == HIGH){
    
   bluetooth_connection(false);
   if(!wifi_com_flag){
    Wifi_connection(true);
   }else{
    
  digitalWrite(LED_PIN_5,led_5_state);
  digitalWrite(LED_PIN_6,led_6_state);
  digitalWrite(LED_PIN_3,LOW);
  digitalWrite(LED_PIN_4,LOW);
  wifi();
   }
  } 
  else {  
  Wifi_connection(false);
    if(!bt_com_flag){
      bluetooth_connection(true);
      }else{
  digitalWrite(LED_PIN_5,LOW);
  digitalWrite(LED_PIN_6,LOW);
  digitalWrite(LED_PIN_3,led_3_state);
  digitalWrite(LED_PIN_4,led_4_state);
 bt_comm();
 }
}
}
