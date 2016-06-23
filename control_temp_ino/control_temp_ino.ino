  #include <DHT11.h>
 
  int sensor_temp=3;
  // En pwm
  const int led = 6;
  const int ven = 9;
  
  
  int temp_muy_baja = 15;
  int temp_baja=17;
  int temperatura_ideal=22;
  int temp_alta=27;
  int temp_muy_alta=32;

  int hume_muy_baja=25;
  int hume_baja=35;
  int humedad_ideal=45;
  int hume_alta=55;
  int hume_muy_alta=65;

  DHT11 dht11(sensor_temp); 

  void setup()
  {
    
       Serial.begin(9600);
      pinMode(led, OUTPUT);
      pinMode(ven,  OUTPUT) ;

  }
  
  void loop()
  {
      int err;
      float temp, hum;
      if((err=dht11.read(hum, temp))==0)
        {
          Serial.print("Temperatura: ");
          Serial.print(temp);
          Serial.print(" Humedad: ");
          Serial.print(hum);
          Serial.println();
          
          // Logica difusa led max 255 minimo 0
          // Temperatura muy baja y humedad muy baja
            if(esta_rango(temp_muy_baja,temp) == true && esta_rango(hume_muy_baja,hum) == true){
                // Subida pequeña
                Serial.print("Subida pequeña: ");
                analogWrite(led,63); 
            }
              else
           // temp  baja y    humedad baja
            if(esta_rango(temp_muy_baja,temp) == true && esta_rango(hume_baja,hum) == true){
                // Subida pequeña
                Serial.print("Subida pequeña: ");
                analogWrite(led,63); 
            }
            else
              // tem mb y hume normal
            if(esta_rango(temp_muy_baja,temp) == true && esta_rango(humedad_ideal,hum) == true){
                // Subida grande
                Serial.print("Subida grande: ");
                analogWrite(led,255); 
            }
            else
             // tem mb y hume alta
            if(esta_rango(temp_muy_baja,temp) == true && esta_rango(hume_alta,hum) == true){
                // Subida grande
                  Serial.print("Subida grande: ");
                analogWrite(led,255); 
            }
            else
             // tem mb y hume muy alta
            if(esta_rango(temp_muy_baja,temp) == true && esta_rango(hume_muy_alta,hum) == true){
                // Subida grande
                  Serial.print("Subida grande: ");
                analogWrite(led,255); 
            }
            else
            // temp baja y hume normal
             if(esta_rango(temp_baja,temp) == true && esta_rango(humedad_ideal,hum) == true){
               // subida pequeña
                Serial.print("Subida pequeña: ");
               analogWrite(led,63); 
            }
            else
            // temp baja y hume alta
            if(esta_rango(temp_baja,temp) == true && esta_rango(hume_alta,hum) == true){
               // subida pequeña
                Serial.print("Subida pequeña: ");
               analogWrite(led,63); 
            }
            else
              // temp baja y hume muy alta
            if(esta_rango(temp_baja,temp) == true && esta_rango(hume_muy_alta,hum) == true){
               // subida normal
                Serial.print("Subida normal: ");
               analogWrite(led,127); 
            }
            else
            // temp normal y humedad alta
            if(esta_rango(temperatura_ideal,temp) == true && esta_rango(hume_muy_alta,hum) == true){
               // bajada pequeña
                Serial.println("bajada pequeña: xD ");
                analogWrite(ven,200); 
               
            }
            else
            // temp alta y humedad norma
            if(esta_rango(temp_alta,temp) == true && esta_rango(humedad_ideal,hum) == true){
               // bajada pequeña
               Serial.println("bajada pequeña: xP ");
               analogWrite(ven,200); 
               
            }
            else
            // temp alta y humedad alta
            if(esta_rango(temp_alta,temp) == true && esta_rango(hume_alta,hum) == true){
               // bajada pequeña
               Serial.println("bajada pequeña: xE ");
               analogWrite(ven,200); 
               
            }
            else
            // temp alta y humedad muy alta
            if(esta_rango(temp_alta,temp) == true && esta_rango(hume_muy_alta,hum) == true){
               // bajada normal
               Serial.print("bajada normal: ");
               analogWrite(ven,240); 
               
            }
            else
          // temp muy alta y humedad muy baja
            if(esta_rango(temp_muy_alta,temp) == true && esta_rango(hume_muy_baja,hum) == true){
               // bajada pequeña
               Serial.println("bajada pequeña: xV ");
               analogWrite(ven,200); 
               
               
            }
            else
          // temp muy alta y humedad  baja
            if(esta_rango(temp_muy_alta,temp) == true && esta_rango(hume_baja,hum) == true){
               // bajada normal
                Serial.print("bajada normal: ");
                analogWrite(ven,240); 
               
               
            }
            else

          // temp muy alta y humedad  normal
            if(esta_rango(temp_muy_alta,temp) == true && esta_rango(humedad_ideal,hum) == true){
               // bajada normal
                Serial.print("bajada normal: ");
                analogWrite(ven,240); 
               
               
            }
            else
            
              // temp muy alta y humedad  altal
            if(esta_rango(temp_muy_alta,temp) == true && esta_rango(hume_alta,hum) == true){
               // bajada grande
                Serial.print("bajada grande: ");
                analogWrite(ven,255); 
               
               
            }
            else
                // temp muy alta y humedad muy altal
            if(esta_rango(temp_muy_alta,temp) == true && esta_rango(hume_muy_alta,hum) == true){
                Serial.print("bajada grande: ");
               analogWrite(ven,255); 
            }
        }
      else
        {
          Serial.println();
          Serial.print("Error Num :");
          Serial.print(err);
          Serial.println();    
        }
      delay(1000);     //Recordad que solo lee una vez por segundo
  }


  boolean esta_rango(int referencia,int valor){
      boolean esta = false;
      int limite_sup = referencia+2;
   // if(valor >= referencia -1){
      if(valor <= limite_sup ){
        esta = true;
      }
    //}
          
      return esta;
  }
  
