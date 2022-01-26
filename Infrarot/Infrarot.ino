#define IR_LED 36
#define IR_REC 37
#define IR_FromESP 38

int ScoreboardMaster = 0;
int ScoreboardSlave = 0;

bool IRon = false;

unsigned long Timestamp = 0;

void setup() {
  pinMode(IR_LED, OUTPUT);
  pinMode(IR_REC, INPUT);
  pinMode(IR_FromESP, INPUT);

}

void loop() {
  if (IRon = false) {
    IRon = digitalRead(IR_FromESP);
    if (IR_FromESP = HIGH) {
      digitalWrite(IR_LED, HIGH);
      Timestamp = millis();
    }
  }
  else {
    if (millis() - Timestamp = 2000) {
      IRon = false;
      digitalWrite(IR_LED, LOW);
    }
  }
}
