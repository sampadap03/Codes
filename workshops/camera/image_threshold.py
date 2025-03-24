import cv2
import numpy as np
img=cv2.imread('myimage.jpg',0)
a,img=cv2.threshold(img,127,255,cv2.THRESH_BINARY)
b,img=cv2.threshold(img,127,255,cv2.THRESH_BINARY_INV)
cv2.imshow('Image1',img)
cv2.imshow('Image2',img)
cv2.waitKey(0)
cv2.destroyAllWindows()
