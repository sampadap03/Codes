import numpy as np
import cv2
#argument: name,start coordinate,end coordinate,color, thickness
img=cv2.imread('demo.png',1)
red=(0,0,255)
cv2.line(img,(300,0),(0,300),red,2)

#argument:name,start,end,color, thickness/fill in

green=(0,255,0)
cv2.rectangle(img,(10,10),(60,60),green,-100)

canvas=np.zeros((400,400,3),dtype="uint8") #np.zeros fills all zeros
(x,y)=(canvas.shape[1]//2,canvas.shape[0]//2)
white=(255,255,255)
for r in range(0,150,25):
    cv2.circle(canvas,(x,y),r,green)

print(list(range(0,150,25)))

canvas=np.zeros((300,300,3),dtype="uint8")
for i in range(0,5):
    radius=np.random.randint(5,high=200)  #random is function which generates any random number and randint generate random integer
    color=np.random.randint(0,high=256,size=(3,)).tolist()  #tolist is used to combine the generated numbers in a list or vector form
    center_pt=np.random.randint(0,high=300,size=(2,))  #size=(2,) generate two numbers
    cv2.circle(canvas,tuple(center_pt),radius,color,-1)  #tuple couples two numbers genearated
    print radius; print color; print center_pt;

cv2.imshow("canvas",canvas)

cv2.waitKey(0)

