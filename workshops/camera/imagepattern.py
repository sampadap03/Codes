import os
import cv2
import numpy as np
x=input('enter any number to capture image')
os.system('fswebcam -r 640,480 --no-banner --save /home/pi/img1.jpg')
y=input('enter any number to capture image')
os.system('fswebcam -r 640,480 --no-banner --save /home/pi/img2.jpg')
img1=cv2.imread('img1.jpg',0)
img2=cv2.imread('img2.jpg',0)
img3=abs(img1-img2)
cv2.imshow('different image',img3)
cv2.waitKey(0)
cv2.destroyAllWindows()
