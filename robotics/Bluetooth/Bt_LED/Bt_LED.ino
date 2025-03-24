
volatile int IRQcount;
int result;
int pin = 2;
int pin_irq = 0; //IRQ that matches to pin 2

void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600);
  attachInterrupt(pin_irq, IRQcounter, RISING);
}

void IRQcounter() {
  IRQcount++;
}
void count() {
  cli();//disable interrupts
  IRQcount = 0;
  sei();//enable interrupts
  delay(500);
  cli();//disable interrupts
  result = IRQcount;
  sei();//enable interrupts
  Serial.print(F("Counted LED Blink: "));
  Serial.println(result);
}
void ifCount() {
  if (result == 0) {
    Serial.println(F("LED On or Off"));
    Serial.println(F(" "));
    }
    else if (result >= 1) {
    Serial.println(F("LED Blink")); // 1 blink or more
    Serial.println(F(" "));
}
}
void loop() {
  count();
}
