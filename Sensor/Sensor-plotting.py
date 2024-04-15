import serial
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import numpy as np


ser = serial.Serial('COM18', 9600)  # Replace 'COM3' with the port where your Arduino is connected


fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')


colo = ["orange","red"]
count = True
a =0
s=0

ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('Z')

x = [0,0,0]
y = [0,1,0]
z = [0,0,1]

x3 = [0,0,0]
y3 = [0,-1,0]
z3 = [0,0,-1]

x1 = [0,0,0]
y1 = [0,0,0]
z1 = [0,0,0]

x2 = [0,0,0]
y2 = [0,0,0]
z2 = [0,0,0]

while True:
    if ser.in_waiting:
        line = ser.readline().decode('utf-8').strip()

        readings = line.split(',')

        data = [int(r) for r in readings]
        print(data)

            
        y1[1] = data[0]
        z1[2] = data[1]

        y2[1] = -(data[2])
        z2[2] = -(data[3])

        if a ==40:
            plt.cla() 
            a=0


        ax.scatter(0, y3, z3,color="black")
        ax.scatter(0, y, z,color="black")
        if count == True:
            ax.scatter(a, y2, z2,color=colo[0])
            ax.scatter(a, y1, z1,color=colo[0])
            count = False
        elif count == False:
            ax.scatter(a, y2, z2,color=colo[1])
            ax.scatter(a, y1, z1,color=colo[1])
            count = True
        ax.grid(True)
        ax.view_init(azim=45)

        a+=1
        s+=1

        plt.draw()
        plt.pause(0.01)

