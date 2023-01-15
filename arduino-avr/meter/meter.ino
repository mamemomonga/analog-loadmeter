// https://content.arduino.cc/assets/Pinout-NANOevery_v1.png

#define CMD_CPULOAD 1
#define CMD_SEGCHAR 2 

#define PWM_OUT 3

int cpuVal;
int curVal;

void setup() {
	Serial.begin(115200);
	while(!Serial);

	pinMode(LED_BUILTIN, OUTPUT);
	pinMode(PWM_OUT, OUTPUT);

	for(uint8_t i=0; i<10; i++) {
		digitalWrite(LED_BUILTIN, HIGH);
		delay(50);
		digitalWrite(LED_BUILTIN, LOW);
		delay(50);
	}
	analogWrite(PWM_OUT,0);
	cpuVal = 0;
	curVal = 0;
}

void loadValue() {
	digitalWrite(LED_BUILTIN, LOW);
	if(Serial.available() == 0) return;
	int cmd = Serial.read();
	if(cmd == -1) return;

	int val;
	int retry=10;
	while(retry--) {
		if(Serial.available() != 0) break;
		delay(10);
	}
	if(Serial.available() == 0) return;
	val = Serial.read();
	if(val == -1 ) return;

	switch(cmd) {
		case CMD_CPULOAD:
			digitalWrite(LED_BUILTIN, HIGH);
			cpuVal = val;
			break;
		default:
			delay(1000);
			break;
	}
}


void loop() {
	loadValue();
	if(cpuVal > curVal) {
		curVal++;
		analogWrite(PWM_OUT,curVal);
	} else if (cpuVal < curVal) {
		curVal--;
		analogWrite(PWM_OUT,curVal);
	}
	delay(5);
}
