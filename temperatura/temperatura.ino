  #include <DHT11.h>
  int pin=2;
  int led = 7;
  int ventiladores = 8;
  int temperatura_ideal=22;
  DHT11 dht11(pin); 
  
  void setup()
  {
       Serial.begin(9600);
     // INniciar  led 
     pinMode(led, OUTPUT);
  // Declarar    ventilador
  
    pinMode(ventiladores,OUTPUT);
  }
  
  void loop()
  {
      int err;
      float temp, hum;
      if((err=dht11.read(hum, temp))==0)
        {
          Serial.print("Temperatura: ");
          Serial.print(temp);
          //Serial.print(" Humedad: ");
         // Serial.print(hum);
          Serial.println();

        // Hace frio  prender led o fuente emisora de calor
        if(temp<temperatura_ideal){
          // PREDEMOS EL LED
         Serial.println("prender led");
          digitalWrite(led, HIGH);   
          // APAGAR  EL VENTILADOR
          digitalWrite(ventiladores, LOW);
        }
        //HACE CALOR   PRENDER  VENTILADOR
        if(temp>temperatura_ideal){
          //Apagar el ledi
           Serial.println("pApagar led");
          digitalWrite(led, LOW);
          // PRENDER VENTILADOR
          digitalWrite(ventiladores,HIGH);
        }
            
    
        }
      else
        {
          Serial.println();
          Serial.print("Error Num :");
          Serial.print(err);
          Serial.println();    
        }
      delay(1000);		 //Recordad que solo lee una vez por segundo
  }
  


