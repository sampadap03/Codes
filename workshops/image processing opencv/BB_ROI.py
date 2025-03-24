import cv2
import numpy as np
#if __name__ == '__main__' :
# Read image
x = cv2.imread("rd3.jpeg",0)
# Select ROI
r = cv2.selectROI(x)
# Crop image
imCrop = x[int(r[1]):int(r[1]+r[3]),int(r[0]):int(r[0]+r[2])]
# Display cropped image
cv2.imshow("Image", imCrop)
cv2.waitKey(0)
