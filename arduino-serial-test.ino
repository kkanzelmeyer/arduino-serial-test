#include <MemoryFree.h>
#include <SoftwareSerial.h>


SoftwareSerial esp(10, 11); // RX, TX

String input;
boolean finished = false;

void setup() {
  Serial.begin(115200);
  Serial.println("Starting the Serial Listener");
  Serial.println("");
  esp.begin(57600);
  esp.setTimeout(250);
  
}

void loop() {

  while(!esp.available()){} // do nothing
  
  while (esp.available() > 0)
  {
    input = esp.readString();
  }

  finished = true;

  if(finished) {
    Serial.println("Request received from server:");
    Serial.println(input);
    Serial.print("request variable size = ");
    Serial.print(input.length()*8);
    Serial.print(" bytes");
    Serial.println("");
    input = "";
    Serial.print("freeMemory() = ");
    Serial.println(freeMemory());
    Serial.println("");

    // send a response to the ESP
    esp.println("{\"msg\":\"Hello from the Arduino!\"}");

    // reset flag
    finished = false;
  }

  
}
