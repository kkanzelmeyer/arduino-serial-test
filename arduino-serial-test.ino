#include <MemoryFree.h>

String input;
boolean finished = false;

void setup() {
  Serial.begin(115200);     // opens serial port, sets data rate to 9600 bps
  Serial.setTimeout(100);
}

void loop() {

  while(!Serial.available()){} // do nothing
  
  while (Serial.available() > 0)
  {
    input = Serial.readString();
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
    finished = false;
  }

  
}
