/*
  AudioSerial.cpp - Audio serial library for communication from Android smartphone to Arduino
  Created by Guillaume Dupre, Friday 26, 2013.
  Released into the public domain.
*/

#include "Arduino.h"
#include "AudioSerial.h"

AudioSerial::AudioSerial(int pin,int bps,int startingByte,int threshold)
{
  _pin = pin;
  _bps = bps;
  _startingByte=startingByte;
  _threshold=threshold;
  _readingBitState=false;
  _readingByteState=false;
  _bitPower=1;
  _receiveByte=-1;
}

void AudioSerial::run(){
  int receiveAnalog=analogRead(_pin);
  int receiveBit=0;
  // Compute bit from voltage
  if(receiveAnalog>_threshold){receiveBit=1;}
  // 
  if(!_readingBitState)
  {
 	 if(receiveBit==1){
  	_readingBitState=true;
 	 _bitPower=1;
 	 _byteBuffer=0;
	  }
  }else{
	_byteBuffer+=receiveBit*_bitPower;
        _bitPower=_bitPower*2;
  	if(_bitPower==256){	
 		_readingBitState=false;
	
 		if(_readingByteState){
		_receiveByte=_byteBuffer;
 		}else if(_byteBuffer==_startingByte){
		_readingByteState=true;		
		}
	}
        
  }
  }

int AudioSerial::read(){
  int receiveByte=_receiveByte;
  _receiveByte=-1;
  return receiveByte;

  }

int AudioSerial::getDelay(){
 return 1000/_bps;
}


