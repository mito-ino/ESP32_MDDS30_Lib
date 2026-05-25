#include "Cytron_MDDS30_Serial.h"

Cytron_MDDS30_Serial::Cytron_MDDS30_Serial() {
  _serials[0] = NULL;
  _serials[1] = NULL;
}

void Cytron_MDDS30_Serial::begin(uint8_t id, HardwareSerial* serial, uint32_t baudrate, int8_t rxPin, int8_t txPin) {
  if (id > 1) return; // IDが範囲外なら無視
  
  _serials[id] = serial;
  _serials[id]->begin(baudrate, SERIAL_8N1, rxPin, txPin);
  
  delay(100);
  _serials[id]->write(0x80); // オートボーレート用
  delay(100);
}

void Cytron_MDDS30_Serial::control(uint8_t id, signed int motorLSpeed, signed int motorRSpeed) {
  if (id > 1 || _serials[id] == NULL) return;

  // 左モーター
  if (motorLSpeed >= 0) {
    commandByte = 0x00;
    motorLSpeed = map(motorLSpeed, 0, 100, 0, 63);
  } else {
    commandByte = 0x40;
    motorLSpeed = map(motorLSpeed, 0, -100, 0, 63);
  }
  _serials[id]->write(commandByte | (uint8_t)motorLSpeed);

  // 右モーター
  if (motorRSpeed >= 0) {
    commandByte = 0xC0;
    motorRSpeed = map(motorRSpeed, 0, 100, 0, 63);
  } else {
    commandByte = 0x80;
    motorRSpeed = map(motorRSpeed, 0, -100, 0, 63);
  }
  _serials[id]->write(commandByte | (uint8_t)motorRSpeed);
}