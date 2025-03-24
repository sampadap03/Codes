import time
import RPi.GPIO as GPIO

buzzer = 20
GPIO.setmode(GPIO.BCM)
GPIO.setup(buzzer,GPIO.OUT)


while (True):
        GPIO.output(buzzer,True)
        time.sleep(1)
        GPIO.output(buzzer,False)
        time.sleep(1)