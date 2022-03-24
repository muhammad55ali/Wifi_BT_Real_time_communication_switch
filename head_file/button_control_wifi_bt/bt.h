
#define wifi_bt_btn_pin     25 
#define wifi_snd_rc_btn_pin 26 
#define bt_snd_rc_btn_pin   27
#define LED_PIN_1 16
#define LED_PIN_2 17
#define LED_PIN_3 18
#define LED_PIN_4 19
#define LED_PIN_5 21
#define LED_PIN_6 23
#include "BluetoothSerial.h"
#include <Bounce2.h>

//#include "wifi.h"

Bounce2::Button wifi_bt_btn     = Bounce2::Button();
Bounce2::Button wifi_snd_rc_btn = Bounce2::Button();
Bounce2::Button bt_snd_rc_btn   = Bounce2::Button();
int led_1_state = LOW;
int led_2_state ;
int led_3_state = LOW;
int led_4_state ;

int received;
char receivedChar;
char sendChar;
boolean bt_com_flag = false;
boolean bt_print_flag;
boolean bt_print1_flag;
void bluetooth_connection(boolean flag);
BluetoothSerial SerialBT;
void bluetooth_connection(boolean flag){
  if(flag){
    SerialBT.begin("Haider55");
  Serial.println("The device started, now you can pair it with bluetooth!");
      bt_com_flag=true;
      delay(3000);
  }
  else {
  SerialBT.flush();
  SerialBT.disconnect();
  SerialBT.end();
  bt_com_flag=false;
  }
}
 void bt_comm(){
    if(led_3_state == HIGH){
       if(bt_print_flag){
       Serial.println("bluetooth receiving");
       bt_print_flag=!bt_print_flag;
      }
 receivedChar =(char)SerialBT.read();
  if (SerialBT.available()) {
    SerialBT.println(receivedChar);      
    Serial.println(receivedChar); 
    delay(1000);
  }
    }
        else{
     if(bt_print1_flag){
   Serial.println("bluetooth sending");
   bt_print1_flag=!bt_print1_flag;
}
     sendChar =(char)Serial.read();
   if (Serial.available()) {
    Serial.println(sendChar);
     SerialBT.println(sendChar);
  }
  }
  }
