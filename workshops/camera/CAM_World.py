import picamera
import time
camera = picamera.PiCamera()
camera.resolution = (640, 480)
camera.framerate = 24
camera.start_preview()
camera.annotate_text = 'Water Bottle!'
time.sleep(2)
# Take a picture including the annotation
camera.capture('fool.jpg')
