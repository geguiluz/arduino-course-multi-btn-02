// Length in miliseconds
float pressLength = 0;

// Minimum ammount of time for each option
// Instant press
int optionOne = 100;
// Two second press
int optionTwo = 5000;
int optionThree = 10000;

int buttonPin = 2;

int greenLed = 12;
int redLed = 13;

void setup()
{
  pinMode(buttonPin, INPUT_PULLUP);

  pinMode(greenLed, OUTPUT);
  pinMode(redLed, OUTPUT);

  Serial.begin(9600);
}

void toggleLed(int ledPin)
{
  if (digitalRead(ledPin) == HIGH)
  {
    Serial.print("LED is ON, let's turn it OFF");
    Serial.print('\n');
    digitalWrite(ledPin, LOW);
  }
  else
  {
    Serial.print("LED is OFF, let's turn it ON");
    Serial.print('\n');
    digitalWrite(ledPin, HIGH);
  }
}

void loop()
{
  while (digitalRead(buttonPin) == LOW)
  {
    delay(100); // Lower this number for higher resolution
    pressLength = pressLength + 100;
  }
  if (pressLength >= optionThree)
  {
    Serial.print("Toggling red LED");
    Serial.print('\n');
    toggleLed(redLed);
  }
  else if (pressLength >= optionTwo)
  {
    Serial.print("Toggling green LED");
    Serial.print('\n');
    toggleLed(greenLed);
  }
  if (pressLength >= optionOne)
  {
    Serial.print("Toggling both LEDs");
    Serial.print('\n');
    toggleLed(greenLed);
    toggleLed(redLed);
  }
  pressLength = 0;
}