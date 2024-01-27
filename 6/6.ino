#include <LoRa.h>

/*
Распиновка подключения.
Lora pin - stm32 "blue pill" pin:
VCC - 3.3V
GND - GND
SCK - PA5 (SCK1)
MISO - PA6 (MISO1)
MOSI - PA7 (MOSI1)
NSS - PA4 (NSS1)
NRESET - PB1
DIO0 - PB0
*/


void setup(){
  Serial.begin(9600);
  LoRa.setPins(PA4, PB1, PB0);

  if (!LoRa.begin(915E6)) {
    Serial.println("LoRa module not found!");
    while (1);
  }
  LoRa.onReceive(onReceive);
  LoRa.receive();
}

void loop() {}

void onReceive(int packetSize) {
  if ((char)LoRa.read() != 'k') {return;}

  char f_str_num[4] = "";
  char s_str_num[4] = "";

  for (int i=0;i < 3;i++){
      f_str_num[i] = (char)LoRa.read();
  }

  for (int i=0;i < 3;i++){
      s_str_num[i] = (char)LoRa.read();
  }

  if ((char)LoRa.read() != 's') {return;}

  int first_number = atoi(f_str_num);
  int second_number = atoi(s_str_num);

  char* for_print_value;
  sprintf(for_print_value, "%d %d", first_number, second_number);
  Serial.println(for_print_value);
}
