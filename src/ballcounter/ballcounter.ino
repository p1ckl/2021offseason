int MZ80_A = 7;
int MZ80_B = 8;
int snr_a_state = 0;
int prev_a_state = 0;
int snr_b_state = 0;
int prev_b_state = 0;
int ball_count_a = 0;
int ball_count_b = 0;

void setup() {
  Serial.begin(9600);
  pinMode(MZ80_A, INPUT);
  pinMode(MZ80_B, INPUT);
}

void loop() {
  snr_a_state = !digitalRead(MZ80_A);
  snr_b_state = !digitalRead(MZ80_B);
  if(snr_a_state != prev_a_state){
    if(snr_a_state == 1){
      ball_count_a++;
    }
  }
  if(snr_b_state != prev_b_state){
    if(snr_b_state == 1){
      ball_count_b++;
    }
  }
  Serial.print("1. Sensör Top Sayısı : ");
  Serial.print(ball_count_a);
  Serial.print("\n");
  //Serial.print("2. Sensör Top Sayısı : ");
  //Serial.print(ball_count_b);
  Serial.print("\n--------------\n");
  prev_a_state = snr_a_state;
  prev_b_state = snr_b_state;
}
