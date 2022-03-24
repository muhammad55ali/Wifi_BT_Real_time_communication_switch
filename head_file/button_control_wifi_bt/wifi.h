//button control wifi bluetooth communication
//header files wifi.h and bt.h are used.
//3 buttons are used, one button to switch between wifi and bluetooth
//other two buttons are used to switch between wifi sending/receiving and bluetooth sending and receiving each. 

#include <WiFi.h>
#include <WiFiUdp.h>

int led_5_state = LOW;
int led_6_state ;
boolean wf_print_flag;
boolean wf_print1_flag;
boolean wifi_com_flag = false;
const char * networkName = "Luqman IT";
const char * networkPswd = "222333444";
const char * udpAddress = "192.168.100.3";
unsigned int localPort_ = 3333;
const int udpPort = 3333;
WiFiUDP udp;
char packetBuffer[255];
void connectToWiFi(const char * ssid, const char * pwd);
void Wifi_connection(boolean flag);

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

void connectToWiFi(const char * ssid, const char * pwd){
  WiFi.begin(ssid, pwd);
  while (WiFi.status() != WL_CONNECTED) {delay(500);Serial.print(".");}
  Serial.print("\nConnected to ");  Serial.println(ssid);  Serial.print("IP address: ");  Serial.println(WiFi.localIP());
  udp.begin(localPort_);  
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
