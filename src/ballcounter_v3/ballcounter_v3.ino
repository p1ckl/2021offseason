const int MZ80_A = 6;
const int MZ80_B = 8;

bool sS_1, sS_2 = 0;
int curr_state,  prev_state = 0;

unsigned char sensor_list[1000];
unsigned short sensor_index;
unsigned short checker_index = 0;

bool check_score = false;

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

void print_array(unsigned char arr[1000]){
	for(unsigned short i=0; i < 1000; i++){
		Serial.print(arr[i]);
	}
	Serial.println("");
}

int calcstate(int s1, int s2){
	return s2<<1|s1;
}

int index_calculator(int x, int y){
	return (54*--x + --y);
}

void reset_array(unsigned char arr[100]){
	for(unsigned short i; i < 1000; i++){
		arr[i] = 0;
	}
}

bool checker(unsigned char arr[1000], unsigned short state){
	for(unsigned short i = 0; i < 1000; i++){
		if(!arr[i]){
			return false;
		}

		if(arr[i]%2 != state%2){
			return true;
		}
	}
	return false;
}

void count_balls(int s1, int s2){

	sS_1 = !digitalRead(s1);
	sS_2 = !digitalRead(s2);

	curr_state = calcstate(sS_1, sS_2);
	int index = index_calculator(s1, s2);

	if(curr_state>>0&1 != prev_state>>0&1){
		sensor_list[sensor_index] = 1;
		sensor_index++;
		check_score = true;

	}
	else if(curr_state>>1&1 != prev_state>>1&1){
		sensor_list[sensor_index] = 2;
		sensor_index++;
	}
	
	if(checker(sensor_list, 2)){
		score_array[index]++;
		reset_array(sensor_list);
		sensor_index = 0;
		Serial.print("Skor: ");
		Serial.println(score_array[index]);
	}
	else if(checker(sensor_list, 1)){
		reverse_array[index]++;
		print_array(sensor_list);
		reset_array(sensor_list);
		sensor_index = 0;
		Serial.print("Tersten Girme: ");
		Serial.println(reverse_array[index]);
	}


	prev_state = curr_state;
}

