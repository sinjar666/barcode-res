#!/usr/bin/python
#@author -- Srijan Mukherjee

#Thresholding by median method (Otsu thresholding)



import math,sys

assert(len(sys.argv)==2), "Usage:otsu.py filepath"

try:
    import Image
except:
    raise "Unable to find python imaging library"

im=Image.open(sys.argv[1])
tmp=im.resize((1024,768))
tmp=tmp.convert("L")

hist=tmp.histogram()
prob=[val/786432.0 for val in hist]
u=0
var_b=[0 for i in range(0,256)]
for i in range(0,256):
    u+=(prob[i]*i)
    
for t in range(1,256):
    wk=uk=0
    for k in range(0,t+1):
        wk+=prob[k]
        uk+=prob[k]*k
    w0=wk
    if(wk==0):
        u0=0
    else:
        u0=uk/wk
    w1=1-wk
    u1=(u-uk)/w1
    var_b[t]=(w0*w1*(u1-u0)*(u1-u0)) #for t

threshold=0
for i in range(0,256):
    if(var_b[i]==max(var_b)):
        threshold=i

print("The calculated threshold is " , threshold)

def thresh(x):
    if(x>=threshold):
        return 255
    else:
        return 0


tmp=tmp.point(thresh)
tmp.show()


