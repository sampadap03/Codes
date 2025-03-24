void setup() {
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(A0, INPUT);
    pinMode(A1, INPUT);
    pinMode(A2, INPUT);
    pinMode(A3, INPUT);
}

void loop() {
 int p,q,r,s;
  int a,b,c,d,e,f,g;
  p=digitalRead(A0);
  q=digitalRead(A1);
  r=digitalRead(A2);
  s=digitalRead(A3);
  
if(p==0&&q==0&&r==0&&s==0)
{
  a=1;b=1;c=1;d=1;e=1;f=1;g=0;
  }

if(p==0&&q==0&&r==0&&s==1)
{
  a=0;b=1;c=1;d=0;e=0;f=0;g=0;
  }
if(p==0&&q==0&&r==1&&s==0)
{
  a=1;b=1;c=0;d=1;e=1;f=0;g=1;
  }

if(p==0&&q==0&&r==1&&s==1)
{
  a=1;b=1;c=1;d=1;e=0;f=0;g=1;
  }

if(p==0&&q==1&&r==0&&s==0)
{
  a=0;b=1;c=1;d=0;e=0;f=1;g=1;
  }
if(p==0&&q==1&&r==0&&s==1)
{
  a=1;b=0;c=1;d=1;e=0;f=1;g=1;
  }
 if(p==0&&q==1&&r==1&&s==0)
{
  a=1;b=0;c=1;d=1;e=1;f=1;g=1;
  }
if(p==0&&q==1&&r==1&&s==1)
{
  a=1;b=1;c=1;d=0;e=0;f=0;g=0;
  }
if(p==1&&q==0&&r==0&&s==0)
{
  a=1;b=1;c=1;d=1;e=1;f=1;g=1;
  }
 if(p==1&&q==0&&r==0&&s==1)
{
  a=1;b=1;c=1;d=1;e=0;f=1;g=1;
  }
digitalWrite(13,a);
digitalWrite(12,b);
digitalWrite(8,c);
digitalWrite(7,d);
digitalWrite(4,e);
digitalWrite(3,f);
digitalWrite(2,g);

}
