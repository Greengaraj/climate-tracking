#include <TroykaDHT.h>

// constants
constexpr uint8_t DHT_PIN = 2;

// variables
int8_t TemperatureC;
float Humidity;

// declaring objects
DHT dht(DHT_PIN, DHT11);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  dhtTempRead();
  dhtHumRead();
}

void dhtTempRead(){
  dht.read();

  switch(dht.getState()) {
    case DHT_OK:
      TemperatureC = dht.getTemperatureC();
      
      Serial.print("Temperature = ");
      Serial.print(TemperatureC);
      Serial.println(" C \t");
      break;

    case DHT_ERROR_CHECKSUM:
      Serial.println("Checksum error");
      break;

    case DHT_ERROR_TIMEOUT:
      Serial.println("Time out error");
      break;

    case DHT_ERROR_NO_REPLY:
      Serial.println("Sensor not connected");
      break;
  }

  delay(2000);                                        // we are waiting for two swconds
}

void dhtHumRead(){
  dht.read();

  switch(dht.getState()) {
    case DHT_OK:
      Humidity = dht.getHumidity();

      Serial.print("Humidity = ");
      Serial.print(Humidity);
      Serial.println(" %");
      break;

    case DHT_ERROR_CHECKSUM:
      Serial.println("Checksum error");
      break;

    case DHT_ERROR_TIMEOUT:
      Serial.println("Time out error");
      break;

    case DHT_ERROR_NO_REPLY:
      Serial.println("Sensor not connected");
      break;
  }

  delay(2000);
}
