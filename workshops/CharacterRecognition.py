import cv2
import numpy as np
from PIL import Image
import pytesseract
import argparse
import cv2
import os
cap = cv2.VideoCapture(0)

while(1):
    ret, frame = cap.read()
    #image=cap.read()
    cv2.imshow("image",frame)
    if not ret:
        break
    k = cv2.waitKey(1)
    if k%256 == 27:
        # ESC pressed
        print("Escape hit, closing...")
        break
    elif k%256 == 32:
        cv2.imwrite("image27.png",frame)
        img=Image.open("image27.png")
        hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
        # fluroscent pink
        '''
        lower_bound = np.array([151,100,100])        
        upper_bound = np.array([171,255,255])'''
        # fluroscent yellow
        lower_bound = np.array([20,100,100])        
        upper_bound = np.array([40,255,255])
        
        mask = cv2.inRange(hsv, lower_bound, upper_bound)
        res = cv2.bitwise_and(frame,frame, mask= mask)
        median = cv2.medianBlur(res,15)
        cv2.imwrite("median.png",median)
        grayscaled = cv2.cvtColor(median,cv2.COLOR_BGR2GRAY)
        ret,thresh = cv2.threshold(grayscaled,10,255,cv2.THRESH_BINARY)
        #thresh = cv2.adaptiveThreshold(grayscaled, 255, cv2.ADAPTIVE_THRESH_GAUSSIAN_C, cv2.THRESH_BINARY, 115, 1)
        #retval2,thresh2 = cv2.threshold(grayscaled,125,255,cv2.THRESH_BINARY+cv2.THRESH_OTSU)
        #masked = cv2.bitwise_and(frame, frame, mask = thresh)
        #_, contours, _ = cv2.findContours(thresh, 1, 2)
        #cv2.imshow("thresh",thresh)
        edged = cv2.Canny(thresh, 30, 150)
        cv2.imshow('res',res)
        cv2.imshow("Edges", edged)
        (_, cnts, _) = cv2.findContours(edged.copy(), cv2.RETR_EXTERNAL,cv2.CHAIN_APPROX_SIMPLE)
        print("cnts : {}" .format((cnts)))
        #print("cnts access : {}" .format((cnts[2][0][0][1])))
        '''
        cnt=cnts[0]
        rect = cv2.minAreaRect(cnt)
        box = cv2.boxPoints(rect)
        box = np.int0(box)
        cv2.drawContours(median,[box],0,(0,0,255),2)'''
        for i in range(0,len(cnts)):
            minCol=cnts[i][0][0][0]
            maxCol=cnts[i][0][0][0]
            minRow=cnts[i][0][0][1]
            maxRow=cnts[i][0][0][1]

            for j in range(0,len(cnts[i])):
                if(minCol>(cnts[i][j][0][0])):
                    minCol=cnts[i][j][0][0]
                if(maxCol<(cnts[i][j][0][0])):
                    maxCol=cnts[i][j][0][0]
                if(minRow>(cnts[i][j][0][1])):
                    minRow=cnts[i][j][0][1]
                if(maxRow<(cnts[i][j][0][1])):
                    maxRow=cnts[i][j][0][1]
            print("minCol : {} ,maxCol : {} , minRow : {} , maxRow : {} ".format(minCol,maxCol,minRow,maxRow))
            cropOriginal=img.crop((minCol,minRow,maxCol,maxRow))
            cropOriginal=cropOriginal.convert("RGB")
            cropOriginal.save("CroppedWord"+str(i)+".jpg")
            imgCrop=cv2.imread("CroppedWord"+str(i)+".jpg")
            cv2.imshow("CroppedWord"+str(i)+".jpg",imgCrop)
            #image = cv2.imread("CroppedWord1.jpg")
            gray = cv2.cvtColor(imgCrop, cv2.COLOR_BGR2GRAY)
            gray = cv2.threshold(gray, 0, 255,cv2.THRESH_BINARY | cv2.THRESH_OTSU)[1]
            filename = "{}.png".format(os.getpid())
            cv2.imwrite(filename, gray)
            text = pytesseract.image_to_string(Image.open(filename),lang='mar',config='--psm 8')
            #text = pytesseract.image_to_string(Image.open(filename),lang='eng',config='--psm 8')
            os.remove(filename)
            print(text)
            #cv2.waitKey(0)
        #cv2.imshow("masked",masked)
        #cv2.imshow("thresh2",thresh2)
        #cnt = contours[0]
        #M = cv2.moments(cnt)
        #print (M)
        #cv2.imshow('frame',frame)
        #cv2.imshow('mask',mask)
        #cv2.imshow('res',res)
        #cv2.imshow('Median Blur',median)    
    
cap.release()
cv2.destroyAllWindows()

