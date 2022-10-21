#define ADC_VREF_mV    3300.0 // in millivolt
#define ADC_RESOLUTION 2048.0
#define PIN_LM35       36 // ESP32 pin GIOP36 (ADC0) connected to LM35

void setup() {
  Serial.begin(115200);
}

void loop() {

  int adcVal = analogRead(PIN_LM35);
  float milliVolt = adcVal * (ADC_VREF_mV / ADC_RESOLUTION);
  float tempC = milliVolt / 10;//10mV/

  Serial.print("Temperature: ");
  Serial.print(tempC);  
  Serial.println("°C");
  
  delay(500);
}
