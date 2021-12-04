const int MZ80_A = 6;
const int MZ80_B = 8;

bool sS_1, sS_2 = 0;
int curr_state,  prev_state = 0;

bool check_reverse = false;
bool check_last = false;

int increment = 0;

unsigned char score_array[2915];
unsigned char reverse_array[2915];

unsigned long time_start;
unsigned long time_end;

int max_delay = 0;

void setup() {
	Serial.begin(9600);
	pinMode(MZ80_A, INPUT);
	pinMode(MZ80_B, INPUT);
}

void loop() {
	count_balls(MZ80_A, MZ80_B);
}

int calcstate(int s1, int s2){
	return s2<<1|s1;
}

void count_balls(int s1, int s2){

	sS_1 = !digitalRead(s1);
	sS_2 = !digitalRead(s2);

	curr_state = calcstate(sS_1, sS_2);
	int index = index_calculator(s1, s2);

	if(curr_state>>0&1 == 1 && curr_state != prev_state){
		if(check_reverse && curr_state != 3){
			reverse_array[index]++;
			score_array[index]--;
			Serial.print("Top tersten girdi: ");
			Serial.println(reverse_array[index]);
			Serial.print("Güncel geçmiş top sayısı: ");
			Serial.println(score_array[index]);
		}
		else{
			if(curr_state == 3){

			}
			else{
				score_array[index]++;
				Serial.print("Top doğru yönden girdi: ");
				Serial.println(score_array[index]);
			}
		}


		Serial.print("Sensor: ");
		Serial.println(curr_state);
		check_reverse = false;

	}

	else if(curr_state == 2 && curr_state != prev_state){
		Serial.print("Sensor: ");
		Serial.println(curr_state);
		check_reverse = true;
		check_last = true;
	}
	else if(curr_state == 0){
		if(prev_state == 2){
			check_reverse = true;
		}
		check_last = false;
	}


	prev_state = curr_state;
}

int index_calculator(int x, int y){
	return (54*--x + --y);
}
