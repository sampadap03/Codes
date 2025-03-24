import cv2
import numpy as np

def shiftit(imagein,x,y):
    M=np.float32([[1,0,x],[0,1,y]])
    cv2.imshow('out1',imagein)
    shiftedimage=cv2.warpAffine(imagein,M,(imagein.shape[1],image.shape[0]))
    return shiftedimage


