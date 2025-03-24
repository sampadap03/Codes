import numpy as np
import cv2

cv2.namedWindow('out1',cv2.WINDOW_NORMAL)
img=cv2.imread('demo.png',1)

#cv2.imshow('out1',img)
px=img[100,100]
print (px)

#cv2.waitKey()
blue=[255,0,0]
red=[0,0,255]
img[102,102]=blue
img[100,101]=blue
img[100,102]=blue
img[101,100]=blue
img[101,101]=blue
img[101,102]=blue
img[102,100]=blue
img[102,101]=blue
for i in range(3,100):
    for j in range(3,100):
        n=100+i
        m=100+j
        if i%4==0|j%3==0:
            img[m,n]=red
        else:
            img[m,n]=blue
cv2.imshow("out1",img)
cv2.waitKey()

