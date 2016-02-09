#include <MemoryFree.h>
#include <SoftwareSerial.h>


SoftwareSerial esp(10, 11); // RX, TX

String input;
boolean finished = false;

void setup() {
  Serial.begin(115200);

  esp.begin(115200);
  esp.setTimeout(100);
  
}

void loop() {

  while(!esp.available()){} // do nothing
  
  while (esp.available() > 0)
  {
    input = esp.readString();
  }

  finished = true;

  if(finished) {
    Serial.print(input);
    Serial.print("input variable size = ");
    Serial.print(input.length()*8);
    Serial.print(" bytes");
    Serial.println("");
    input = "";
    Serial.print("freeMemory() = ");
    Serial.println(freeMemory());
    Serial.println("");

    // send a response to the ESP
    esp.print("Hello from the Arduino!");

    // reset flag
    finished = false;
  }

  
}
