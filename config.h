#ifndef _CONFIG_h
#define _CONFIG_h


#include "arduino.h"

#define DEBUG

#define PIN_BUTTON 13

/*
*  EEPROM-Settings
*/
#define CONFIG_VERSION "aaa"

#define EEPROM_COMMON_SETTINGS_ADDRESS_OFFSET 4
#define EEPROM_FEEDER_SETTINGS_ADDRESS_OFFSET 32

#define NUMBER_OF_FEEDERS 10
#define SERIAL_BAUD 115200

/*
* Set the G-Code as desired.
* Feeders (up to 12) will be mapped to an incrementing number:
* Example: GCODE_ADVANCE_4MM is set to 640
* Feeder 1 will advance if sending G641, Feeder 2 if sending G642 and so on...
*
* Futher implementation will handle multiple or half feed-lengths to advance tapes with sprocket pitch more/less than 4mm.
* e.g. Feed 8mm send G
*
*/
#define MAX_BUF 64


#define GCODE_ADVANCE 600						        //
//1st Parameter: feederNo
//2nd Parameter: feedlength
//3rd Parameter: speed	//maybe
#define GCODE_UPDATE_FEEDER_CONFIG	601			// set new angles in eeprom for given feeder
//1st Parameter: feederNo
//2nd Parameter: idle-angle
//3rd Parameter: pull-angle
//4th Parameter: settletime
#define GCODE_RETRACT 602
/*
* Servo-Motor to spool tape
*/
#define USE_SERVO_TO_SPOOL_COVER_TAPE     1
#if USE_SERVO_TO_SPOOL_COVER_TAPE == 1
	#define SPOOLSERVO_PIN                     12
	#define SPOOLSERVO_MIN_PULSEWIDTH          544
	#define SPOOLSERVO_MAX_PULSEWIDTH          2400
	#define SPOOLSERVO_SPEED_RATE              88    //[°]
#endif


/* -----------------------------------------------------------------
* --------------- FEEDER CONFIG ----------------------------------- */
#define FEEDER_PITCH  4                   // [mm]  default: 4 mm. given by mechanical design.

/*
* Configurable/EEPROMed default values
*/
#define FEEDER_DEFAULT_RETRACT_ANGLE  0				      // [°]  usually 0, might be adjusted to servo or feeder
#define FEEDER_DEFAULT_FULL_ADVANCED_ANGLE  90				      // [°]  usually about 80-110. Is effected by motor constants as well!
#define FEEDER_DEFAULT_HALF_ADVANCED_ANGLE  40              // [°]  usually about 80-110. Is effected by motor constants as well!
#define FEEDER_DEFAULT_TIME_TO_SETTLE  300			  // [ms] time the servo needs to travel from ANGLE_IDLE to ANGLE_PULL
#define FEEDER_DEFAULT_MOTOR_MIN_PULSEWIDTH 544		// [µs] see motor specs or experiment at bit. Value set here should bring the servo to 0°
#define FEEDER_DEFAULT_MOTOR_MAX_PULSEWITH 2400		// [µs] see motor specs or experiment at bit. Value set here should bring the servo to 180° (even if 180° cannot be reached) (?)

const static uint8_t feederPinMap[NUMBER_OF_FEEDERS] = {
	2,    // Feeder 1
	3,    // Feeder 2
	4,
	5,
	6,
	7,
	8,
	9,
	10,
	11
};

#endif


