import picamera
import time

camera=picamera.PiCamera()
camera.resolution=(1024,768)
camera.start_preview()
time.sleep(5)
camera.capture('imagee.jpg')
camera.start_preview()
