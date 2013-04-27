/* Display
 * Receive data from audio serial and display it through serial
 */ 

#include <AudioSerial.h>

// Open audio serial communication on pin A0 at 20 bits per seconds
// with starting byte 138 and voltage threshold 30
AudioSerial audioserial(A0,20,138,30);

void setup()
{
 Serial.begin(9600);
}

void loop(){
  
  audioserial.run();
  // Read one byte
  int receivebyte=audioserial.read();
  if(receivebyte>-1){
  Serial.println(receivebyte);
  }
  
  delay(audioserial.getDelay());
} 


