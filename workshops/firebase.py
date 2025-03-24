from firebase import firebase
import RPi.GPIO as GPIO

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)
GPIO.setup(21,GPIO.OUT)
GPIO.setup(20,GPIO.OUT)
GPIO.setup(l6,GPIO.OUT)

firebase = firebase.FirebaseApplication('https://home-auto-3eb4b.firebaseio.com', None)
while(True):
    
    result1 = firebase.get('/home/door' ,None)

    if(result1 == 1):
        GPIO.output(21,True)
 
    if(result1 == 0):
        GPIO.output(21,False)
    
    result2 = firebase.get('/home/fan' ,None)
    print result

    if(result2 == 1):
        GPIO.output(20,True)
    
    if(result2 == 0):
        GPIO.output(20,False)

    result3 = firebase.get('/home/lamp' ,None)
    print result

    if(result3 == 1):
        GPIO.output(16,True)
    
 
    if(result3 == 0):
        GPIO.output(16,False)

      


    
