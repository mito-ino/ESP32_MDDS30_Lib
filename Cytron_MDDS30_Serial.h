#ifndef CYTRON_MDDS30_SERIAL_h
#define CYTRON_MDDS30_SERIAL_h

#include "Arduino.h"

class Cytron_MDDS30_Serial {
  public:
    Cytron_MDDS30_Serial();
    
    // 特定のインデックス（0番、1番...）にシリアルポートを登録
    void begin(uint8_t id, HardwareSerial* serial, uint32_t baudrate, int8_t rxPin, int8_t txPin);
    
    // IDを指定して制御
    void control(uint8_t id, signed int motorLeftSpeed, signed int motorRightSpeed);

  private:
    HardwareSerial* _serials[2]; // 最大2台まで対応（必要に応じて増やせます）
    uint8_t commandByte;
};

#endif