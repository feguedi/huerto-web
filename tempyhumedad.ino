const int sensorPin= A0;
int Valor;  

 
void setup()
{
  Serial.begin(9600);
}
 
void loop()
{
  int value = analogRead(sensorPin);
  float millivolts = (value / 1023.0) * 5000;
  float celsius = millivolts / 100; 
  Serial.print(celsius);
  Serial.println(" C");
  delay(1000);
 Serial.print("Sensor de Humedad valor:");  
Valor = analogRead(1);  
Serial.print(Valor);  
if (Valor <= 300)  
   Serial.println(" Encharcado");  
if ((Valor > 300) and (Valor <= 700))  
    Serial.println(" Humedo, no regar");   
if (Valor > 700)  
    Serial.println(" Seco, necesitas regar");  
delay(1000);
}

        
      


