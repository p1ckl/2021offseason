int MZ80_A = 7;
int MZ80_B = 8;
int snr_a_state = 0;
int snr_b_state = 0;

void setup() {
  Serial.begin(9600);
  pinMode(MZ80_A, INPUT);
  pinMode(MZ80_B, INPUT);
}

void loop() {
  snr_a_state = digitalRead(MZ80_A);
  snr_b_state = digitalRead(MZ80_A);
  snr_a_state
  Serial.print("Sensör 1 : ");
  Serial.print(snr_a_state);
  Serial.print("\n");
  Serial.print("Sensör 2 : ");
  Serial.print(snr_b_state);
  Serial.print("--------------\n");
  delay(500);
}
