#include <Arduino.h>
#include <ESP32Servo.h>

Servo ServoMotor;
int pino_motor = 4;

void setup() {
  Serial.begin(115200);
  ServoMotor.attach(pino_motor, 1000, 2000);
  Serial.println("Aguardando 5 segundos para armar ESC...");
  delay(5000);

  // Arma o ESC com pulso neutro
  ServoMotor.writeMicroseconds(1500);
  delay(2000);
}

void loop() {
  Serial.println("Girando para frente...");
  ServoMotor.writeMicroseconds(1700);  // Frente
  delay(3000);

  Serial.println("Girando para trás...");
  ServoMotor.writeMicroseconds(1300);  // Ré
  delay(3000);

  Serial.println("Parando...");
  ServoMotor.writeMicroseconds(1500);  // Parar
  delay(3000);
}
