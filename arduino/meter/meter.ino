// https://content.arduino.cc/assets/Pinout-NANOevery_v1.png

#define CMD_CPULOAD 1
#define CMD_SEGCHAR 2 

#define PWM_OUT 3

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
}

void loop() {
	if(Serial.available() == 0) return;
	int cmd = Serial.read();
	if(cmd == -1) return;

	int val;
	for(uint8_t i=0;i<10;i++) {
		val = Serial.read();
		if(val != -1) break;
		delay(10);
	}
	if(val == -1 ) return;
	digitalWrite(LED_BUILTIN, HIGH);

	switch(cmd) {
		case CMD_CPULOAD:
			analogWrite(PWM_OUT,val);
			break;
		default:
			digitalWrite(LED_BUILTIN, LOW);
			delay(1000);
			break;
	}
	delay(10);
}
