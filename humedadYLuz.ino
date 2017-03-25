int luzValue = 0;
int tempValue = 0;
int humeValue = 0;
float temperatura;
int luz;
int humedad;
int regarPin = 2;
int sensorHumedad = A5;
int sensorLuz = A4;
int sensorTemperatura = A3;
void setup() {
 pinMode(regarPin, OUTPUT);
 Serial.begin(9600);
}
void loop() {
 luzValue = analogRead(sensorLuz);
 tempValue = analogRead(sensorTemperatura);
 humeValue = analogRead(sensorHumedad);
 delay(2000);
 // ----------------------------------------------------
 // Imprimir valores
 // ----------------------------------------------------
 temperatura = (5.0 * tempValue * 100.0) / 1024;
 Serial.print("Temperatura:");
 Serial.print(temperatura);
 Serial.println(" C");
 luz = (100.0 * luzValue) / 1024;
 Serial.print("Luz:");
 Serial.print(luz);
 Serial.println("%");
 humedad = (100.0 * humeValue) / 1024;
 Serial.print("Humedad:");
 Serial.println(humedad);

Serial.println("=======================================================================");

 // ----------------------------------------------------
 // Chequeo si debo regar
 // ----------------------------------------------------
 if( humedad <= 50 && luz < 70 && temperatura < 30) {
 digitalWrite(regarPin, HIGH);
 Serial.println("Debe regar");
 delay(2000);
 }
 else{
 digitalWrite(regarPin, LOW);
 Serial.println("NO debe regar");
 }

Serial.println("=======================================================================");
}
