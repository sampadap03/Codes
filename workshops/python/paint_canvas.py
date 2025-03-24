import numpy as np
import cv2

img=cv2.imread('demo.png',1)

img=np.zeros((300,300,3),dtype="uint8")   #uint8=unsigned integer of 8 bits| it prints

cv2.imshow("canvas",img)
cv2.waitKey(0)