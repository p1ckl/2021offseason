int MZ80_A = 7;
int MZ80_B = 8;
bool sS_1, sS_2, prevState_1, prevState_2 = 0;
int sensor_array[10];

unsigned long time_start;
unsigned long time_end;

int max_delay = 0;

void setup() {
	Serial.begin(9600);
	pinMode(MZ80_A, INPUT);
	pinMode(MZ80_B, INPUT);
}

void loop() {
	time_start = micros();
	sS_1 = !digitalRead(MZ80_A);
	sS_2 = !digitalRead(MZ80_B);

	count_balls(MZ80_A, sS_1, prevState_1);
	count_balls(MZ80_B, sS_2, prevState_2);

	prevState_1 = sS_1;
	prevState_2 = sS_2;

	time_end = micros();

	max_delay = max(max_delay, time_end-time_start);

	Serial.println(max_delay);
}

void count_balls(int sensor_id, bool sensor, bool prev){
	if(sensor != prev && sensor == 1){
		sensor_array[sensor_id]++;
		Serial.print("Sensor ");
		Serial.print(sensor_id);
		Serial.print(" Top Sayısı: ");
		Serial.print(sensor_array[sensor_id]);
		Serial.print("\n--------------\n");
	}
}
