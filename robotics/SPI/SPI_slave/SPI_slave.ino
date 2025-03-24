#include <SPI.h>

char buf [100];
volatile byte pos;
volatile boolean process_it;

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
     Serial.println("before interrupt");
  SPI.attachInterrupt();
   //Serial.println("after interrupt");
  
}


// SPI interrupt routine
ISR (SPI_STC_vect)
{
   Serial.println("in interrupt");
  byte c = SPDR;  // grab byte from SPI Data Register
  if (pos < sizeof buf)
  {
    buf [pos++] = c;
    //if (c == '\n')
      process_it = true;
      Serial.println(process_it);
       Serial.println("in interrupt");
  }
  Serial.println("TAdaa!"); 
}

void loop (void)
{
  
  if (process_it)
  {
    buf [pos] = 0;  
    Serial.println("jfg");
    Serial.println(pos);
    //for( int i=0;i<pos
    Serial.println("adasd");
    pos = 0;
    process_it = false;
  }
}
