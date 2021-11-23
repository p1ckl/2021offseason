int MZ80_A = 7;
int MZ80_B = 8;
bool sensor_state, prev_state = 0;
int ball_count = 0;

void setup() {
	Serial.begin(9600);
	pinMode(MZ80_A, INPUT);
	pinMode(MZ80_B, INPUT);
}

void loop() {

	sensor_state = !digitalRead(MZ80_A);
	if(sensor_state != prev_state && sensor_state == 1){
		ball_count++;
		Serial.print("Sensör Top Sayısı : ");
		Serial.print(ball_count);
		Serial.print("\n--------------\n");
	}

	prev_state = sensor_state;
}
