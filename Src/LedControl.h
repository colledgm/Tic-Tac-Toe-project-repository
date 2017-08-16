/*
 * Fixed version of final code. Thanks to FarhanR16.
 */

#include <Arduino.h>

#define PIN_R_X_1 (2)	//0 is on, 1 is off
#define PIN_R_X_2 (1)
#define PIN_R_X_3 (0)

#define PIN_W_X_1 (5)
#define PIN_W_X_2 (4)
#define PIN_W_X_3 (3)

#define PIN_Y_1 (6)
#define PIN_Y_2 (7)
#define PIN_Y_3 (8)

#define WIDTH (3)
#define HEIGHT (3)

#define ALL_OFF (0)
#define RED_LED_ON (1)
#define WHITE_LED_ON (2)
#define BOTH_LEDS_ON (3)

int state[WIDTH][HEIGHT] = {{ALL_OFF,ALL_OFF,ALL_OFF},{ALL_OFF,ALL_OFF,ALL_OFF},{ALL_OFF,ALL_OFF,ALL_OFF}};

int x_r_pins[WIDTH] = {PIN_R_X_1, PIN_R_X_2, PIN_R_X_3};
int x_w_pins[WIDTH] = {PIN_W_X_1, PIN_W_X_2, PIN_W_X_3};
int y_pins[HEIGHT] = {PIN_Y_1, PIN_Y_2, PIN_Y_3};

////////////// TURN INDICATOR LEDS  //////////////

#define PIN_RED_TURN_INDICATOR (9)
#define PIN_WHITE_TURN_INDICATOR (10)

void showRedTurn(){
//	digitalWrite(PIN_RED_TURN_INDICATOR, HIGH);
	digitalWrite(PIN_RED_TURN_INDICATOR, LOW);
//	digitalWrite(PIN_WHITE_TURN_INDICATOR, LOW);
	digitalWrite(PIN_WHITE_TURN_INDICATOR, HIGH);
}

void showWhiteTurn(){
//	digitalWrite(PIN_RED_TURN_INDICATOR, LOW);
	digitalWrite(PIN_RED_TURN_INDICATOR, HIGH);
//	digitalWrite(PIN_WHITE_TURN_INDICATOR, HIGH);
	digitalWrite(PIN_WHITE_TURN_INDICATOR, LOW);
}

////////////// LED FUNCTIONS //////////////

void turnOnRedColumn(unsigned int x){
//	digitalWrite(x_r_pins[x], LOW);
	digitalWrite(x_r_pins[x], HIGH);
}
void turnOffRedColumn(unsigned int x){
//	digitalWrite(x_r_pins[x], HIGH);
	digitalWrite(x_r_pins[x], LOW);
}
void turnOnWhiteColumn(unsigned int x){
//	digitalWrite(x_w_pins[x], LOW);
	digitalWrite(x_w_pins[x], HIGH);
}
void turnOffWhiteColumn(unsigned int x){
//	digitalWrite(x_w_pins[x], HIGH);
	digitalWrite(x_w_pins[x], LOW);
}
void turnOnRow(unsigned int y){
//	digitalWrite(y_pins[y], HIGH);
	digitalWrite(y_pins[y], LOW);
}
void turnOffRow(unsigned int y){
//	digitalWrite(y_pins[y], LOW);
	digitalWrite(y_pins[y], HIGH);
}

void showLeds(){
	for(unsigned int y=0; y < HEIGHT; y++){
		turnOnRow(y);
		for(unsigned int x=0; x < WIDTH; x++){
		
			switch(state[x][y]){
				case WHITE_LED_ON:
					turnOffRedColumn(x);
					turnOnWhiteColumn(x);
					break;
					
				case RED_LED_ON:
					turnOnRedColumn(x);
					turnOffWhiteColumn(x);
					break;
					
				case BOTH_LEDS_ON:
					turnOnRedColumn(x);
					turnOnWhiteColumn(x);
					break;

				case ALL_OFF:
				default:
					turnOffRedColumn(x);
					turnOffWhiteColumn(x);
			}
		}
		delay(1);
		turnOffRow(y);
		for(unsigned int x=0; x < WIDTH; x++){
			turnOffRedColumn(x);
			turnOffWhiteColumn(x);
		}
	}
}
