/*
 Control Céfiro V1
 By: Mauricio Cano Bedoya 
 For: Humanos3D-Enable Medellin
 June 2020 

 Este código es para el control básico del servomotor con
 un botón táctil para el dispositivo "Céfiro"

*/
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
const int TIME_SLEEP = 30000;
int FLAG = 0;     
unsigned long time;   

// Configuración 
void setup() 
{
  //Serial.begin(9600);
  servo.attach(PinServo);
  pinMode(PinBoton, INPUT); 
}

void loop() 
{
  // Modo de bajo consumo luego de 30 segundos
  time = millis();
  if (time > TIME_SLEEP) sleep_mode();
  
  // Lectura estado del botón
  Estado = digitalRead(PinBoton);
  
  // Si el botón es presionado el motor se activa
  if (Estado == HIGH)
  {    
    servo.attach(PinServo);
    servo.write(POS1); 
    delay(TIME_OUT1);
    servo.detach();
    FLAG = 1;
  } else 
  // De lo contrario vuelve a su posición original  
  {
    if (FLAG)
    {
      FLAG = 0;
      servo.attach(PinServo);
      servo.write(POS2);
      delay(TIME_OUT1);
      servo.detach();
    }
  } 
}
