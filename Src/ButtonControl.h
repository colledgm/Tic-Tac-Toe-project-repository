#define BUTTON_POWER_PIN_1 (11)
#define BUTTON_POWER_PIN_2 (12)
#define BUTTON_POWER_PIN_3 (13)

#define BUTTON_WHITE_1 (5)
#define BUTTON_WHITE_2 (4)
#define BUTTON_WHITE_3 (3)

#define BUTTON_RED_1 (0)
#define BUTTON_RED_2 (1)
#define BUTTON_RED_3 (2)

int button_power_pins[HEIGHT] = {BUTTON_POWER_PIN_1, BUTTON_POWER_PIN_2, BUTTON_POWER_PIN_3};
int button_white_pins[WIDTH] = {BUTTON_WHITE_1, BUTTON_WHITE_2, BUTTON_WHITE_3};
int button_red_pins[WIDTH] = {BUTTON_RED_1, BUTTON_RED_2, BUTTON_RED_3};

unsigned int button_conversion_x[WIDTH][HEIGHT] = { {2, 0, 1}, {1, 2, 0}, {0, 1, 2}};
unsigned int button_conversion_y[WIDTH][HEIGHT] = { {1, 2, 2}, {1, 0, 1}, {0, 0, 2}};


void turnOnButtonSet(unsigned int s){
	digitalWrite(button_power_pins[s], HIGH);
}

void turnOffButtonSet(unsigned int s){
	digitalWrite(button_power_pins[s], LOW);
}

bool readWhiteSet(unsigned int s){
	return (analogRead(button_white_pins[s]) > 100);
}
bool readRedSet(unsigned int s){
	return (analogRead(button_red_pins[s]) > 100);
}

unsigned int convert_button_red_x(unsigned int x, unsigned int y){
	return button_conversion_x[x][y];
}

unsigned int convert_button_red_y(unsigned int x, unsigned int y){
	return button_conversion_y[x][y];
}

unsigned int convert_button_white_x(unsigned int x, unsigned int y){
	return (WIDTH - 1 - button_conversion_x[x][y]);
}
unsigned int convert_button_white_y(unsigned int x, unsigned int y){
	return button_conversion_y[x][y];
}
