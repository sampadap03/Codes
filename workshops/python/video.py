import numpy as np
import cv2

cap=cv2.VideoCapture()
while True:
    ret.img=cap.read()

    cv2.imshow("video",img)
    k=cv2.waitKey(10)&0xFF
    if k==27:
        break

cap.release()
video.release()

cv2.destroAllWindows()