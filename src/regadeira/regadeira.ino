
/*   ______    ______    ______    ______    _____     ______    __    ______    ______   
 *  /\  == \  /\  ___\  /\  ___\  /\  __ \  /\  __-.  /\  ___\  /\ \  /\  == \  /\  __ \  
 *  \ \  __<  \ \  __\  \ \ \__-. \ \  __ \ \ \ \/\ \ \ \  __\  \ \ \ \ \  __<  \ \  __ \ 
 *   \ \_\ \_\ \ \_____\ \ \_____\ \ \_\ \_\ \ \____-  \ \_____\ \ \_\ \ \_\ \_\ \ \_\ \_\
 *    \/_/ /_/  \/_____/  \/_____/  \/_/\/_/  \/____/   \/_____/  \/_/  \/_/ /_/  \/_/\/_/
 */

/* --- Incluímos as librarías ------------------ */
#include "SensorTemperaturaHumidade.h"
#include "SensorHumidadeTerra.h"
#include "MotorDC.h"
#include "Constantes.h"

/* --- Inicializamos sensores/actuadores ------- */
SensorTemperaturaHumidade aire(2, DHT11);
SensorHumidadeTerra terra(A0);
MotorDC ventilador(5, 255);
MotorDC bomba(3, 255);

/**
 * Esta función execútase unha única vez ao principio do programa
 */
void setup() {
  Serial.begin(9600); // Inicializamos a consola para escribir nela
}

/**
 * Esta outra función execútase de forma cíclica 
 */
void loop() {
  
  // Esperamos 2 segundos
  delay(2000);

  // Pasados 2 segundos lemos dos sensores
  float temperatura    = aire.lerTemperatura();
  float humidade_aire  = aire.lerHumidade();
  float humidade_terra = terra.lerHumidade();

  // Regamos se a humidade da terra é inferior ao 20%
  if (humidade_terra < 20) {
    bomba.activar();
  } else {
    bomba.desactivar();
  }

  // Ventilamos se a temperatura ambiente sobrepasa os 30ºC
  if (temperatura > 30) {
    ventilador.activar();
  } else {
    ventilador.desactivar();
  }

  // Escribimos por consola os datos recompilados
  Serial.println(titulo);
  Serial.println(" Temperatura ambiente:    " + String(temperatura)    + " ºC");
  Serial.println(" Humidade ambiente:       " + String(humidade_aire)  + " %");
  Serial.println(" Humidade terra:          " + String(humidade_terra) + " %");
}
