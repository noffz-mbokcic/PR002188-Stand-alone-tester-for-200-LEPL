const unsigned long BAUD_RATE = 115200;
const int OUT_PIN = 4; // D13 on Nano
bool state = LOW;
 
void setup() {
  Serial.begin(BAUD_RATE);
  pinMode(OUT_PIN, OUTPUT);
  digitalWrite(OUT_PIN, state);
  Serial.println(F("Commands: ON | OFF | TOGGLE | STATUS"));
}
 
void loop() {
  if (Serial.available()) {
    String cmd = Serial.readStringUntil('\n');
    cmd.trim();
    cmd.toUpperCase();
 
    if (cmd == "ON") state = LOW ;
    else if (cmd == "OFF") state = HIGH;
    else if (cmd == "TOGGLE") state = !state;
    else if (cmd == "STATUS") {
      Serial.print(F("STATE: "));
      Serial.println(state ? F("OFF") : F("ON"));
    } else if (cmd.length() > 0) {
      Serial.println(F("ERR"));
    }
 
    digitalWrite(OUT_PIN, state);
  }
}
 