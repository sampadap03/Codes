import time
import RPi.GPIO as GPIO
GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)
GPIO.setup(21,GPIO.IN)
GPIO.setup(20,GPIO.OUT)

while True:
    X=GPIO.input(21)
    if (X == False):
          GPIO.output(20,True)
    else:
          GPIO.output(20,False)
                  
      
