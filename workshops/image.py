import cv2
import numpy
img = cv2.imread('myimage.jpg',0)
cv2.imshow('Image',img)
cv2.waitKey(0)
cv2.destoryAllWindows()
