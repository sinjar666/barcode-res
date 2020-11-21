#!/usr/bin/python
import sys
x=sys.argv[1]
print x[0:3]
c=1
for i in range(3,45):
    print x[i],
    if(c==7): 
        print ' '
        c=0
    c+=1
c=1
print x[45:50]
for i in range(50,92):
    print x[i],
    if(c==7): 
        print ' '
        c=0
    c+=1
print x[92:95]
