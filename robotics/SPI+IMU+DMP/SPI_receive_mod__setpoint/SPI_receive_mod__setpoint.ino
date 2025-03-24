#include <SPI.h>

int buf , buf1 = 0;
volatile byte pos;
volatile boolean process_it;
int c1 = 0;
int setpoint;
char str[3];
int c2;

void setup (void)
{
  Serial.begin (115200);
  // have to send on master in, *slave out*
  pinMode(MISO, OUTPUT);

  // turn on SPI in slave mode
  SPCR |= _BV(SPE);

  // get ready for an interrupt
  pos = 0;   // buffer empty
  process_it = false;

  // now turn on interrupts
  SPI.attachInterrupt();
}


// SPI interrupt routine
ISR (SPI_STC_vect)
{
  int c = SPDR;  // grab byte from SPI Data Register
  //itoa(c,str,3)
  process_it = true;
  buf = c * 10 + (c1);
  c1 = c;
  //Serial.println(buf);
  if (buf == 999)
  {
    c2= SPDR;
    getSetpoint(c2);
  }

}

void getSetpoint( int d)
{

  int d1 = 0;
  process_it = true;
  buf1 = d * 10 + (d1);
  d1 = d;
  Serial.println(buf1);
  setpoint = buf1;
  Serial.print("Setpoint is:  "); Serial.println(setpoint);

}
void loop (void)
{
  if (process_it)
  {
    //Serial.println (buf);
    process_it = false;
  }
  Serial.flush();
}

