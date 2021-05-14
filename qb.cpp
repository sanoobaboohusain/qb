#include <Arduino.h>

/**
 *    layout
 *
 *		*	*	*	*
 * 		0	1	2	A4		 -------
 * 		*	*	*	*		|		|
 * 		5	4	3	A5
 * 		*	*	*	*		|arduino|
 * 		6	7	8	9
 * 		*	*	*	*		|		|
 * 		13	12	11	10		 -------
 */

int layers[4] = { A0, A1, A2, A3 };
int led[16] = { 0, 1, 2, A4, 5, 4, 3, A5, 6, 7, 8, 9, 13, 12, 11, 10 };

void initPins() {

	for (int i = 0; i < 16; i++) {
		pinMode(led[i], OUTPUT);
	}

	for (int i = 0; i < 4; i++) {
		pinMode(layers[i], OUTPUT);
	}

}

void turnOnLed(int pin) {
	digitalWrite(pin, LOW);
}

void turnOffLed(int pin) {
	digitalWrite(pin, HIGH);
}

void turnOnLayer(int layer) {
	digitalWrite(layer, HIGH);
}

void turnOffLayer(int layer) {
	digitalWrite(layer, LOW);
}

void turnOffAll() {

	for (int i = 0; i < 16; i++) {
		digitalWrite(led[i], 1);
	}

	for (int i = 0; i < 4; i++) {
		digitalWrite(layers[i], 0);
	}
}

void test() {

	for (int i = 0; i < 4; i++) {
		turnOnLayer(layers[i]);
		for (int j = 0; j < 16; j++) {
			turnOnLed(led[j]);
			delay(500);
			turnOffLed(led[j]);
		}
	}

	turnOffAll();
	delay(2000);

}

void turnOnOffWithDelay(int pins[], int delayTime, int size) {
	for (int i = 0; i < size; i++) {
		turnOnLed(pins[i]);
	}
	delay(delayTime);
	for (int i = 0; i < size; i++) {
		turnOffLed(pins[i]);
	}
}

void turnColumnsOn(int repeat) {
	int t = 80;
	for (int i = 0; i < 4; i++) {
		turnOnLayer(layers[i]);
	}

	int led_c1[16] = { 0, 1, 2, A4, A5, 9, 10, 11, 12, 13, 6, 5, 4, 3, 8, 7 };

	for (int j = 0; j < repeat; j++) {
		for (int i = 0; i < 16; i++) {
			turnOnLed(led_c1[i]);
			delay(t);
			turnOffLed(led_c1[i]);
		}

		delay(10);

		for (int i = 15; i >= 0; i--) {
			turnOnLed(led_c1[i]);
			delay(t);
			turnOffLed(led_c1[i]);
		}
	}

}
void turnColumnsOff() {
	for (int i = 0; i < 16; i++) {
		digitalWrite(led[i], 1);
	}
}

void propeller() {
	turnOffAll();
	int x = 90;
	for (int y = 4; y > 0; y--) {
		for (int i = 0; i < 6; i++) {
			//turn on layer
			digitalWrite(layers[y - 1], 1);
			//a1
			turnColumnsOff();
			digitalWrite(led[0], 0);
			digitalWrite(led[5], 0);
			digitalWrite(led[10], 0);
			digitalWrite(led[15], 0);
			delay(x);
			//b1
			turnColumnsOff();
			digitalWrite(led[4], 0);
			digitalWrite(led[5], 0);
			digitalWrite(led[10], 0);
			digitalWrite(led[11], 0);
			delay(x);
			//c1
			turnColumnsOff();
			digitalWrite(led[6], 0);
			digitalWrite(led[7], 0);
			digitalWrite(led[8], 0);
			digitalWrite(led[9], 0);
			delay(x);
			//d1
			turnColumnsOff();
			digitalWrite(led[3], 0);
			digitalWrite(led[6], 0);
			digitalWrite(led[9], 0);
			digitalWrite(led[12], 0);
			delay(x);
			//d2
			turnColumnsOff();
			digitalWrite(led[2], 0);
			digitalWrite(led[6], 0);
			digitalWrite(led[9], 0);
			digitalWrite(led[13], 0);
			delay(x);
			//d3
			turnColumnsOff();
			digitalWrite(led[1], 0);
			digitalWrite(led[5], 0);
			digitalWrite(led[10], 0);
			digitalWrite(led[14], 0);
			delay(x);
		}
	}
	//d4
	turnColumnsOff();
	digitalWrite(led[0], 0);
	digitalWrite(led[5], 0);
	digitalWrite(led[10], 0);
	digitalWrite(led[15], 0);
	delay(x);
}

void squareUp(int repeat) {
	int t = 100;
	int pins[] = { 4, 3, 7, 8 };
	int pins1[] = { 0, 1, 2, A4, 5, A5, 6, 9, 13, 12, 11, 10 };

	for (int i = 0; i < repeat; i++) {

		turnOnLayer(layers[0]);
		turnOnOffWithDelay(pins, t, 4);
		delay(t);
		turnOffAll();

		turnOnLayer(layers[1]);
		turnOnOffWithDelay(pins1, t, 12);
		delay(t);
		turnOffAll();

		turnOnLayer(layers[2]);
		turnOnOffWithDelay(pins1, t, 12);
		delay(t);
		turnOffAll();

		turnOnLayer(layers[3]);
		turnOnOffWithDelay(pins, t, 4);
		delay(t);
		turnOffAll();

		turnOnLayer(layers[3]);
		turnOnOffWithDelay(pins, t, 4);
		delay(t);
		turnOffAll();

		turnOnLayer(layers[2]);
		turnOnOffWithDelay(pins1, t, 12);
		delay(t);
		turnOffAll();

		turnOnLayer(layers[1]);
		turnOnOffWithDelay(pins1, t, 12);
		delay(t);
		turnOffAll();

		turnOnLayer(layers[0]);
		turnOnOffWithDelay(pins, t, 4);
		delay(t);
		turnOffAll();
	}

}

void diagonalUpDown(int repeat) {
	int t = 80;
	for (int i = 0; i < 4; i++) {
		turnOnLayer(layers[i]);
	}

	int pins[] = { 10 };
	int pins1[] = { 11, 9 };
	int pins2[] = { 12, 8, A5 };
	int pins3[] = { 13, 7, 3, A4 };
	int pins4[] = { 6, 4, 2 };
	int pins5[] = { 5, 1 };
	int pins6[] = { 0 };

	int pins7[] = { A4 };
	int pins8[] = { 2, A5 };
	int pins9[] = { 1, 3, 9 };
	int pins10[] = { 0, 4, 8, 10 };
	int pins11[] = { 5, 7, 11 };
	int pins12[] = { 6, 12 };
	int pins13[] = { 13 };

	for (int i = 0; i < repeat; i++) {

		turnOnOffWithDelay(pins, t, 1);
		turnOnOffWithDelay(pins1, t, 2);
		turnOnOffWithDelay(pins2, t, 3);
		turnOnOffWithDelay(pins3, t, 4);
		turnOnOffWithDelay(pins4, t, 3);
		turnOnOffWithDelay(pins5, t, 2);
		turnOnOffWithDelay(pins6, t, 1);
		turnOnOffWithDelay(pins6, t, 1);
		turnOnOffWithDelay(pins5, t, 2);
		turnOnOffWithDelay(pins4, t, 3);
		turnOnOffWithDelay(pins3, t, 4);
		turnOnOffWithDelay(pins2, t, 3);
		turnOnOffWithDelay(pins1, t, 2);
		turnOnOffWithDelay(pins, t, 1);
	}

	for (int i = 0; i < repeat; i++) {

		turnOnOffWithDelay(pins7, t, 1);
		turnOnOffWithDelay(pins8, t, 2);
		turnOnOffWithDelay(pins9, t, 3);
		turnOnOffWithDelay(pins10, t, 4);
		turnOnOffWithDelay(pins11, t, 3);
		turnOnOffWithDelay(pins12, t, 2);
		turnOnOffWithDelay(pins13, t, 1);
		turnOnOffWithDelay(pins13, t, 1);
		turnOnOffWithDelay(pins12, t, 2);
		turnOnOffWithDelay(pins11, t, 3);
		turnOnOffWithDelay(pins10, t, 4);
		turnOnOffWithDelay(pins9, t, 3);
		turnOnOffWithDelay(pins8, t, 2);
		turnOnOffWithDelay(pins7, t, 1);
	}

}

void turnEverythingOn() {
	for (int i = 0; i < 16; i++) {
		digitalWrite(led[i], 0);
	}

	for (int i = 0; i < 4; i++) {
		digitalWrite(layers[i], 1);
	}
}

void layerSideUpDown(int repeat) {
	int t = 80;
	turnOffAll();
	for (int i = 0; i < 4; i++) {
		turnOnLayer(layers[i]);
	}

	int layer1[] = { 13, 12, 11, 10 };
	int layer2[] = { 6, 7, 8, 9 };
	int layer3[] = { 5, 4, 3, A5 };
	int layer4[] = { 0, 1, 2, A4 };
	for (int i = 0; i < repeat; i++) {

		turnOnOffWithDelay(layer1, t, 4);
		turnOnOffWithDelay(layer2, t, 4);
		turnOnOffWithDelay(layer3, t, 4);
		turnOnOffWithDelay(layer4, t, 4);

		turnOnOffWithDelay(layer4, t, 4);
		turnOnOffWithDelay(layer3, t, 4);
		turnOnOffWithDelay(layer2, t, 4);
		turnOnOffWithDelay(layer1, t, 4);
	}

}

void layerSideRightLeft(int repeat) {
	int t = 80;
	turnOffAll();
	for (int i = 0; i < 4; i++) {
		turnOnLayer(layers[i]);
	}

	int layer1[] = { 0, 5, 6, 13 };
	int layer2[] = { 1, 4, 7, 12 };
	int layer3[] = { 2, 3, 8, 11 };
	int layer4[] = { A4, A5, 9, 10 };
	for (int i = 0; i < repeat; i++) {

		turnOnOffWithDelay(layer1, t, 4);
		turnOnOffWithDelay(layer2, t, 4);
		turnOnOffWithDelay(layer3, t, 4);
		turnOnOffWithDelay(layer4, t, 4);

		turnOnOffWithDelay(layer4, t, 4);
		turnOnOffWithDelay(layer3, t, 4);
		turnOnOffWithDelay(layer2, t, 4);
		turnOnOffWithDelay(layer1, t, 4);
	}

}

void squareBoundaryInner(int repeat, int t) {
	//int t = 100;
	turnOffAll();
	for (int i = 0; i < 4; i++) {
		turnOnLayer(layers[i]);
	}

	int layer1[] = { 4, 7 };
	int layer2[] = { 7, 8 };
	int layer3[] = { 8, 3 };
	int layer4[] = { 3, 4 };
	for (int i = 0; i < repeat; i++) {

		turnOnOffWithDelay(layer1, t, 2);
		turnOnOffWithDelay(layer2, t, 2);
		turnOnOffWithDelay(layer3, t, 2);
		turnOnOffWithDelay(layer4, t, 2);

		turnOnOffWithDelay(layer1, t, 2);
		turnOnOffWithDelay(layer2, t, 2);
		turnOnOffWithDelay(layer3, t, 2);
		turnOnOffWithDelay(layer4, t, 2);
	}

}

void squareBoundary(int repeat, int t) {
	//int t = 100;
	turnOffAll();
	for (int i = 0; i < 4; i++) {
		turnOnLayer(layers[i]);
	}

	int layer1[] = { 0, 5, 6, 13 };
	int layer2[] = { 13, 12, 11, 10 };
	int layer3[] = { 10, 9, A5, A4 };
	int layer4[] = { A4, 0, 1, 2 };
	for (int i = 0; i < repeat; i++) {

		turnOnOffWithDelay(layer1, t, 4);
		turnOnOffWithDelay(layer2, t, 4);
		turnOnOffWithDelay(layer3, t, 4);
		turnOnOffWithDelay(layer4, t, 4);

		turnOnOffWithDelay(layer1, t, 4);
		turnOnOffWithDelay(layer2, t, 4);
		turnOnOffWithDelay(layer3, t, 4);
		turnOnOffWithDelay(layer4, t, 4);
	}

}

void moveBoundary(int t) {
	//int t = 100;
	turnOffAll();
	for (int i = 0; i < 4; i++) {
		turnOnLayer(layers[i]);
	}

	int frame[] = { 0, 5, 6, 13, 12, 11, 10, 9, A5, A4, 2, 1 };
	for (int i = 0; i < 12; i = i++) {
		if ((i + 4) < 12) {
			int active[] =
					{ frame[i], frame[i + 1], frame[i + 2], frame[i + 3] };

			turnOnOffWithDelay(active, t, 4);
		} else if ((i + 4) == 13) {
			int active[] = { frame[i], frame[i + 1], frame[i + 2] };

			turnOnOffWithDelay(active, t, 3);
		} else if ((i + 4) == 14) {
			int active[] = { frame[i], frame[i + 1] };

			turnOnOffWithDelay(active, t, 2);
		} else if ((i + 4) == 15) {
			int active[] = { frame[i] };

			turnOnOffWithDelay(active, t, 1);
		}

	}

}

void squareRotation() {

	int t = 150;

	while (t > 0) {
		squareBoundaryInner(1, t);
		t = t - 20;
	}

	t = 150;
	while (t > 0) {
		squareBoundary(1, t);
		t = t - 20;
	}

}

void flickerOn() {
	int i = 150;
	while (i != 0) {
		turnEverythingOn();
		delay(i);
		turnOffAll();
		delay(i);
		i -= 5;
	}
}

void randomflicker() {
	turnOffAll();
	int x = 10;
	for (int i = 0; i != 750; i += 2) {
		int randomLayer = random(0, 4);
		int randomColumn = random(0, 16);

		digitalWrite(layers[randomLayer], 1);
		digitalWrite(led[randomColumn], 0);
		delay(x);
		digitalWrite(layers[randomLayer], 0);
		digitalWrite(led[randomColumn], 1);
		delay(x);
	}
}

void layerUp() {

	int t = 100;
	for (int i = 0; i < 16; i++) {
		turnOnLed(led[i]);
	}
	for (int i = 0; i < 4; i++) {
		turnOnLayer(layers[i]);

		delay(t);
		turnOffLayer(layers[i]);
	}

}

void layerDown() {

	int t = 100;
	for (int i = 0; i < 16; i++) {
		turnOnLed(led[i]);
	}

	for (int i = 3; i >= 0; i--) {
		turnOnLayer(layers[i]);
		delay(t);
		turnOffLayer(layers[i]);
	}
}

void turnLedsFromSide() {
	int x = 80;

	for (int i = 0; i < 4; i++) {
		turnOnLayer(layers[i]);
	}

	for (int y = 0; y < 3; y++) {
		//turn on 0-3
		for (int i = 0; i < 4; i++) {
			digitalWrite(led[i], 0);
			delay(x);
		}
		//turn on 4-7
		for (int i = 4; i < 8; i++) {
			digitalWrite(led[i], 0);
			delay(x);
		}
		//turn on 8-11
		for (int i = 8; i < 12; i++) {
			digitalWrite(led[i], 0);
			delay(x);
		}
		//turn on 12-15
		for (int i = 12; i < 16; i++) {
			digitalWrite(led[i], 0);
			delay(x);
		}
		//turn off 0-3
		for (int i = 0; i < 4; i++) {
			digitalWrite(led[i], 1);
			delay(x);
		}
		//turn off 4-7
		for (int i = 4; i < 8; i++) {
			digitalWrite(led[i], 1);
			delay(x);
		}
		//turn off 8-11
		for (int i = 8; i < 12; i++) {
			digitalWrite(led[i], 1);
			delay(x);
		}
		//turn off 12-15
		for (int i = 12; i < 16; i++) {
			digitalWrite(led[i], 1);
			delay(x);
		}
		//turn on 12-15
		for (int i = 12; i < 16; i++) {
			digitalWrite(led[i], 0);
			delay(x);
		}
		//turn on 8-11
		for (int i = 8; i < 12; i++) {
			digitalWrite(led[i], 0);
			delay(x);
		}
		//turn on 4-7
		for (int i = 4; i < 8; i++) {
			digitalWrite(led[i], 0);
			delay(x);
		}
		//turn on 0-3
		for (int i = 0; i < 4; i++) {
			digitalWrite(led[i], 0);
			delay(x);
		}
		//turn off 12-15
		for (int i = 12; i < 16; i++) {
			digitalWrite(led[i], 1);
			delay(x);
		}
		//turn off 8-11
		for (int i = 8; i < 12; i++) {
			digitalWrite(led[i], 1);
			delay(x);
		}
		//turn off 4-7
		for (int i = 4; i < 8; i++) {
			digitalWrite(led[i], 1);
			delay(x);
		}
		//turn off 0-3
		for (int i = 0; i < 4; i++) {
			digitalWrite(led[i], 1);
			delay(x);
		}
	}
}

void randomRain() {
	turnOffAll();
	int x = 100;
	for (int i = 0; i != 60; i += 2) {
		int randomColumn = random(0, 16);
		digitalWrite(led[randomColumn], 0);
		digitalWrite(layers[3], 1);
		delay(x + 50);
		digitalWrite(layers[3], 0);
		digitalWrite(layers[2], 1);
		delay(x);
		digitalWrite(layers[2], 0);
		digitalWrite(layers[1], 1);
		delay(x);
		digitalWrite(layers[1], 0);
		digitalWrite(layers[0], 1);
		delay(x + 50);
		digitalWrite(layers[0], 0);
		digitalWrite(led[randomColumn], 1);
	}
}

void intermediateDelay() {

	turnOffAll();
	delay(10);
}

void setup() {

	initPins();
	turnOffAll();

}

void loop() {
	int repeat = 5;

	flickerOn();
	turnEverythingOn();
	delay(100);
	turnOffAll();
	turnColumnsOn(2);
	intermediateDelay();
	diagonalUpDown(repeat);
	intermediateDelay();
	layerSideUpDown(repeat);
	intermediateDelay();
	layerSideRightLeft(repeat);
	intermediateDelay();
	squareBoundaryInner(repeat, 100);
	intermediateDelay();
	squareBoundary(repeat, 100);
	intermediateDelay();
	//moveBoundary(100);
	//intermediateDelay();
	squareRotation();
	intermediateDelay();
	randomflicker();
	intermediateDelay();
	for (int i = 0; i < repeat; i++) {
		layerUp();
		intermediateDelay();
		layerDown();
		intermediateDelay();
	}
	squareUp(repeat);
	intermediateDelay();
	propeller();
	intermediateDelay();
	turnLedsFromSide();
	intermediateDelay();
	randomRain();
	intermediateDelay();

}
