import numpy as np
import cv2
img=cv2.imread('2.jpg')
cv2.imshow("original",img)

resized=cv2.resize(img,(100,100),interpolation=cv2.INTER_AREA)
cv2.imshow("Resized(Width)",resized)

cv2.waitKey(0)