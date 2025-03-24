import picamera
import time

camera = picamera.PiCamera()
camera.start_preview()

camera.start_recording('vide.h264')
time.sleep(10)
camera.stop_recording()
camera.stop_preview()

