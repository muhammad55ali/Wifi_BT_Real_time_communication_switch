#include <Arduino.h>

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

void Wifi_connection(boolean flag){
  if(flag){
    connectToWiFi(networkName, networkPswd);
    wifi_com_flag=true;
    delay(3000);
  }
  else {
    
  WiFi.disconnect(true,true);
    wifi_com_flag=false;
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
   
void wifi(){
  if(led_5_state == HIGH){
    if(wf_print_flag){
Serial.println("Wifi Recieving");
wf_print_flag=!wf_print_flag;
}
      if(udp.parsePacket() ){  
    udp.read(packetBuffer, 255);
    Serial.println("\nReceived message is:");
    Serial.println(packetBuffer); 
    delay(1000);
    }
    }
  else{
    if(wf_print1_flag){
     Serial.println("Wifi Sending");
     wf_print1_flag=!wf_print1_flag;}
     udp.beginPacket(udpAddress,udpPort);
     udp.printf("Seconds since boot: %lu", millis()/1000);
     udp.endPacket();
    }
}
void connectToWiFi(const char * ssid, const char * pwd){
  WiFi.begin(ssid, pwd);
  while (WiFi.status() != WL_CONNECTED) {delay(500);Serial.print(".");}
  Serial.print("\nConnected to ");  Serial.println(ssid);  Serial.print("IP address: ");  Serial.println(WiFi.localIP());
  udp.begin(localPort_);  
}
