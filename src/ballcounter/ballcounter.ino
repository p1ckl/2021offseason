int MZ80_A = 7;
int MZ80_B = 8;
bool sS_1, sS_2, prevState_1, prevState_2 = 0;
int ball_count = 0;

unsigned long time;

void setup() {
	Serial.begin(9600);
	pinMode(MZ80_A, INPUT);
	pinMode(MZ80_B, INPUT);
}

void loop() {
	time = millis();
	Serial.println(time);
	sS_1 = !digitalRead(MZ80_A);
	sS_2 = !digitalRead(MZ80_B);

	if(sS_1 != prevState_1 && sS_1 == 1){
		ball_count++;
		Serial.print("Sensör 1 Top Sayısı : ");
		Serial.print(ball_count);
		Serial.print("\n--------------\n");
	}
	prevState_1 = sS_1;
	prevState_2 = sS_2;
}
