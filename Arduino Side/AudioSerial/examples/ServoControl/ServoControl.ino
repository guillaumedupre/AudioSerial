/* ServoControl
*  Receive servo position from audio serial
*/

#include <AudioSerial.h>
#include <Servo.h> 

// Open audio serial communication on pin A0 at 20 bits per seconds
// with starting byte 138 and voltage threshold 30
AudioSerial audioserial(A0,20,138,30);
Servo myservo; 

void setup(){
  myservo.attach(9);
  
   Serial.begin(9600);
 Serial.println("hello"); 
}

void loop(){
  audioserial.run(); 
  // Read one byte
  int receivebyte=audioserial.read();
  if(receivebyte>-1){
  myservo.write(receivebyte);
  Serial.println(receivebyte);
  } 
  
  delay(audioserial.getDelay());
}
