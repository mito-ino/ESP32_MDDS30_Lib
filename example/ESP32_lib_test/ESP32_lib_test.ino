#include "Cytron_MDDS30_Serial.h"

Cytron_MDDS30_Serial motors; // インスタンスは一つだけ

void setup() {
  // ID 0 として1台目を登録
  motors.begin(0, &Serial2, 9600, 5, 4);
  
  // ID 1 として2台目を登録
  motors.begin(1, &Serial1, 9600, 14, 13);
}

void loop() {
  // ID 0 (1台目) を前進
  motors.control(0, 50, 50);
  motors.control(1, -50, -50);

  delay(1000);

  motors.control(0, 100, 100);
  motors.control(1, -100, -100);

  delay(1000);

  motors.control(0, -50, -50);
  motors.control(1, 50, 50);

  delay(1000);

  motors.control(0, 0, 0);
  motors.control(1, 0, 0);
  
  delay(2000);
}