#ifndef _BUTTON_CONTROL_BT_WIFI_H
#define _BUTTON_CONTROL_BT_WIFI_H

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
#include <WiFi.h>
#include <WiFiUdp.h>

void connectToWiFi(const char * ssid, const char * pwd);
void bluetooth_connection(boolean flag);
void Wifi_connection(boolean flag);

BluetoothSerial SerialBT;
#endif 
