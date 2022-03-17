
const int wifi_bt_button_pin  = 25;
const int wifi_led_pin        = 16;
const int bt_led_pin          = 17;
int wifi_bt_led_state         = LOW;
int wifi_bt_button_state_last = LOW;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay    = 50;  

int wifi_bt_button_state_current = 0;

void setup() {
  Serial.begin(115200);
  pin_defination();
}


void loop() {  
    debouncer();
    state_writing();
    }

void state_writing(){

    digitalWrite(wifi_led_pin, wifi_bt_led_state);
    digitalWrite(bt_led_pin, !wifi_bt_led_state);
2}
void debouncer(){

  int reading = digitalRead(wifi_bt_button_pin);

  if(reading != wifi_bt_button_state_last){
    lastDebounceTime = millis();
    } 

  if( (millis() - lastDebounceTime) > debounceDelay){

    if(reading != wifi_bt_button_state_current){
      wifi_bt_button_state_current = reading;  
      if (wifi_bt_button_state_current == HIGH){
        wifi_bt_led_state =! wifi_bt_led_state;
      }
    }
  }
  
  wifi_bt_button_state_last = reading;
}


// void IRAM_ATTR isr() {
//      debouncer();
//     Serial.println("Asd");
// }
void pin_defination(){
  pinMode(wifi_led_pin, OUTPUT);
  pinMode(bt_led_pin, OUTPUT);
  pinMode(wifi_bt_button_pin, INPUT_PULLUP);
  digitalWrite(wifi_led_pin, wifi_bt_led_state);


//   attachInterrupt(wifi_bt_button_pin, isr, RISING);
}



