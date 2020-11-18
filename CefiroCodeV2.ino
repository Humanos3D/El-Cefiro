// For: Humanos3D-Enable Medellin
// By: Mauricio Cano Bedoya June 2020

// Control Céfiro V2
// Este código es para el control básico del servomotor con
// un botón táctil para el dispositivo "Céfiro"

// Declaraciones
#include <Servo.h>
#include <avr/sleep.h>
#define PinBoton 11 
#define PinServo 10
Servo servo; 

// Variables
int Estado = 0; 
const int POS1 = 165;
const int POS2 = 20;
const int TIME_OUT1 = 100;
const int TIME_OUT2 = 1000;
const int TIME_SLEEP = 30000;
int band = 1;
bool FLAG = false;   
unsigned long time;  

// Configuración
void setup() {
  //Serial.begin(9600);
  servo.attach(PinServo);
  pinMode(PinBoton, INPUT); 
}

void loop() {
  
  // Modo de bajo consumo luego de 30 segundos
  time = millis();
  if (time > TIME_SLEEP) sleep_mode();
  
  // Lectura estado del botón
  Estado = digitalRead(PinBoton);
  if (Estado == HIGH)
  {
    FLAG = !FLAG;
    band = 1;
    delay(TIME_OUT2);
  }

  // Condiciones que activan el servomotor en las diferentes posiciones
  if (FLAG && band)
  {
    //Serial.println("Posicion 1");
    band = 0;
    servo.attach(PinServo);
    servo.write(POS1);
    delay(TIME_OUT1);
    servo.detach();
  }
  else if (FLAG == 0 && band)
  {
    //Serial.println("Posicion 2");
    band = 0;
    servo.attach(PinServo);
    servo.write(POS2);
    delay(TIME_OUT1);
    servo.detach();
  }
}
