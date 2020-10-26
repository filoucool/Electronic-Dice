int 1led = 2;
int 2led = 3;
int 3led = 4;
int 4led = 5;
int 5led = 6;
int 6led = 7;
int button = 8;
int buttondown = 0;

void setup() {
  
 pinMode(1led, OUTPUT);
 pinMode(2led, OUTPUT);
 pinMode(3led, OUTPUT);
 pinMode(4led, OUTPUT);
 pinMode(5led, OUTPUT);
 pinMode(6led, OUTPUT);
 pinMode(button, INPUT);
 randomSeed(analogRead(0));
}

void flashylights() {
  
  for (int i=1led; i<=6led; i++) {
    if (i!=1led) {
      digitalWrite(i-1, LOW);}
    digitalWrite(i, HIGH);
    delay(50);}
  
  for (int i=6led; i>=1led; i--) {
    if (i!=1led) {
      digitalWrite(i+1, LOW);}
    digitalWrite(i, HIGH);
    delay(50);}
      digitalWrite(1led, LOW);
}

void showNumber(int number) {
 
if (number == 1) {
    digitalWrite(first, HIGH);
  }
  if (number == 2) {
    digitalWrite(second, HIGH);
  }
  if (number == 3) {
    digitalWrite(third, HIGH);    
  }
  if (number == 4) {
    digitalWrite(fourth, HIGH);    
  }
  if (number == 5) {
    digitalWrite(fifth, HIGH);    
  }
  if (number == 6) {
    digitalWrite(sixth, HIGH);    
  }
}

int throwDice() {
  int randNumber = random(1,7);
  return randNumber;
}

void setAllLEDs(int value) {
  for (int i=1led; i<=6led; i++) {
    digitalWrite(i, value);
  }
}

void loop() {
  buttondown = digitalRead(button);

  if (buttondown == HIGH) {
    setAllLEDs(LOW);
    
    flashylights();
    int thrownNumber = throwDice();
    showNumber(thrownNumber);
  } 

}
