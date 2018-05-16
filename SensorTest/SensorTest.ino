
const int pot    = A0;
const int sensor = A1;
const int button = 7;

int button_state =0;
int sensor_reading;
int pot_reading;

void setup() {
  // put your setup code here, to run once:
  pinMode(button,INPUT_PULLUP);
  pinMode(pot,INPUT);
  pinMode(sensor,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  button_state = digitalRead(button);
  sensor_reading = analogRead(sensor);
  pot_reading = analogRead(pot);
  Serial.println(" ");
  Serial.print("Button: ");
  Serial.print(button_state);    
  Serial.print("  sensor: ");
  Serial.print(sensor_reading);
  Serial.print("  pot: ");
  Serial.print(pot_reading);
}
