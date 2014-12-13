

//Sistema Pan $ Tilt con 2 servos (ejes X,Y) controlados con 2 potenciometros
//En la Pantalla LCD podemos ver la posicion de cada uno de los potenciometros
//expresado en Grados.
//
//Adria Ch. 15/06-2012


//Incluimos las librerias:
#include <Servo.h>
#include <NewSoftSerial.h>


//Definimos Objetos:
Servo Pan; //Creamos el servo para el eje X
Servo Tilt; //Creamos el servo para el eje Y

//Variables:
int potenciometroPan = 0; //Definimos el pin para el potenciometro para el eje X
int potenciometroTilt = 3; //Definimos el pin para el potenciometro para el eje Y

int valPan; //Variable para leer el valor del potenciometro X
int valTilt; //Variable para leer el valor del potenciometro Y

//INICIO
void setup()
{
Pan.attach(8); //Conectamos el servo X al pin 8
Tilt.attach(9); //conectamos el servo Y al pin 9
}

void loop()
{
valPan = analogRead(potenciometroPan); //Leemos el valor del potenciometro (valor entre 0 y 1023)
valPan = map(valPan, 0, 1023, 0, 179); //Escala para usar con el servo (valor entre 0 y 180)
Pan.write(valPan); //Posicionamos el servo segun el valor de la escala
delay(15); //Esperamos a que el servo se posicione
valTilt = analogRead(potenciometroTilt); //Leemos el valor del potenciometro (valor entre 0 y 1023)
valTilt = map(valTilt, 0, 1023, 0, 179); //Escala para usar con el servo (valor entre 0 y 180)
Tilt.write(valTilt); //Posicionamos el servo segun el valor de la escala
delay(15); //Esperamos a que el servo se posicione
}
