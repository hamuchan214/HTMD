#include <Arduino.h>
#include <CAN.h>

void setup() {
  delay(100);
  Serial.begin(115200);
  CAN.setPins(33,27);
  if(!CAN.begin(1000E3))
  {
    Serial.println("CAN start failed!");
    while (1);
  }
}

void loop() {
// send packet: id is 11 bits, packet can contain up to 8 bytes of data
  Serial.print("Sending packet ... ");

  CAN.beginPacket(0x12);
  CAN.write('h');
  CAN.write('e');
  CAN.write('l');
  CAN.write('l');
  CAN.write('o');
  CAN.endPacket();

  Serial.println("done");

  delay(1000);
}