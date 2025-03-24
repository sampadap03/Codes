import RPi.GPIO as GPIO
import time
GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)
GPIO.setup(21,GPIO.OUT)
GPIO.setup(20,GPIO.OUT)

while(True):
    
    GPIO.output(21,True)
    GPIO.output(20,False)
    print("Forward")
    time.sleep(2)
    GPIO.output(21,False)
    GPIO.output(20,True)
    print("Reverse")
    time.sleep(2)
    GPIO.output(21,False)
    GPIO.output(20,False)
    print("Stop")
    time.sleep(2)
    
