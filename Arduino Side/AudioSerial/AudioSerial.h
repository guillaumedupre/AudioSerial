/*
  AudioSerial.h - Audio serial library for communication from Android smartphone to Arduino
  Created by Guillaume Dupre, Friday 26, 2013.
  Released into the public domain.
*/
#ifndef AudioSerial_h
#define AudioSerial_h

#include "Arduino.h"

class AudioSerial
{
  private:
    int _pin;
    int _bps;
    int _startingByte;
    int _threshold;
    boolean _readingBitState;
    boolean _readingByteState;
    int _bitPower;
    int _receiveByte;
    int _byteBuffer;
    	
  public:
    AudioSerial(int pin,int bps,int startingByte,int threshold);
    void run();
    int read();
    int getDelay();

};

#endif
