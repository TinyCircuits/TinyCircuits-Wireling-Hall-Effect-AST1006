//*******************************************************************
// TinyCircuits - A1454 Allegro Linear Hall-Effect Sensor Library 
// Written by: Brandon Farmer for TinyCircuits 
//
// Initiated: Wed. 8/ 8/2017 @  2:30PM 
//   Updated: Mon. 8/28/2017 @  7:15PM 
//
// Revision 0 - Original Release
//	RELEASED: 07/04/2018 ***Not Yet Released***
//
//*******************************************************************

//

#ifndef _TinyCircuits_A1454_H_
#define _TinyCircuits_A1454_H_

#include <Arduino.h>
#include <Wire.h>

#define A1454_ADDRESS 			(0x60)				//I2C Device Address

#define A1454_ACCESS_ADDRESS 	(0x24)				//Register which enables or disables customer write access to internal registers
#define A1454_ACCESS_CODE 		(0x2C413534)		//Access code - must be entered into the access register to gain write access to internal registers

#define A1454_TEMPOUT			(0x1D)				//Stores temperature data  
#define A1454_OUTPUT			(0x1F)				//Stores the magnetic field strength value 
#define A1454_SLEEP 			(0x20)				//Stores the bit for setting/clearing SLEEP mode 



class TinyCircuits_A1454 {
	public: 
		TinyCircuits_A1454(void); 			//Constructor
		
		void begin(void); 					//Begin I2C Communications, access and wake sensor 
		int16_t readMag(void);				//Read magnetometer value 
		int16_t readTemp(void);				//Read temperature value 
		void sleep(void);					//Put sensor into sleep mode 
		void wake(void); 					//Wake sensor up from sleep mode 
		uint8_t readMode(void); 			//Check for wake/sleep mode 
	
	private: 
		void access(void); 					//Allow user to write to sensor registers 
};

#endif