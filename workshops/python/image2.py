#used to create a window and load image

import numpy as np
import cv2

cv2.namedWindow('out1',cv2.WINDOW_NORMAL)  #creates a window of nrmal size
#cv2.namedWindow('out1',cv2.WINDOW_AUTOSIZE)
img=cv2.imread('demo.png',1)

#cv2.imshow('out1',img)
#cv2.waitKey(0)
#cv2.destroyAllWindows()

