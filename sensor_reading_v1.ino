int s1, s2, s3, s4, s5, reading;

void setup() {
  Serial.begin(9600);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
}

void loop() {
  sensor(); // Call the sensor function to read and process sensor data
  show();   // Call the show function to display the sensor values and reading
  delay(1000);
}

void sensor() {
  s1 = analogRead(A1);
  s2 = analogRead(A2);
  s3 = analogRead(A3);
  s4 = analogRead(A4);
  s5 = analogRead(A5);

  s1 = (s1 > 500) ? 1 : 0;
  s2 = (s2 > 500) ? 1 : 0;
  s3 = (s3 > 500) ? 1 : 0;
  s4 = (s4 > 500) ? 1 : 0;
  s5 = (s5 > 500) ? 1 : 0;

  reading = s1 + s2 * 2 + s3 * 4 + s4 * 8 + s5 * 16;
}

void show() {
  Serial.print(s1);
  Serial.print("  ");
  Serial.print(s2);
  Serial.print("  ");
  Serial.print(s3);
  Serial.print("  ");
  Serial.print(s4);
  Serial.print("  ");
  Serial.print(s5);
  Serial.print("  ");
  Serial.print(reading, 2);
  Serial.println("  ");
}
