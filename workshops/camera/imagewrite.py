import cv2
import numpy
img1 = cv2.imread('myimage.jpg',1)
img2 = cv2.imread('Hopetoun_falls.jpg',0)
cv2.imshow('Image1',img1)
cv2.imshow('Image2',img2)
cv2.imwrite('xyz.jpg',img2)
cv2.waitKey(0)
cv2.destoryAllWindows()
