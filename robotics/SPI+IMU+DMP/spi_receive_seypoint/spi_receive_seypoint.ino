#include <SPI.h>

int buf ;
volatile byte pos;
volatile boolean process_it;
int c1=0;
int count=0;
int setpoint;

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
 
      process_it = true;
  buf=c1*10+(c);
  c1 =c;
  count++;
  if(count==3)
  {
   setpoint = buf;
   Serial.print("Setpoint is: ");Serial.println(setpoint);
  }
}
void loop (void)
{
  if (process_it)
  {
    Serial.println (buf);
      process_it = false;
  }
}

