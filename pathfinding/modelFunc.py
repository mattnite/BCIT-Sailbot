#This is a python function to model the sailbot.

import numpy as np

"""
This function models the system by taking system constants, control variables
and past system state, and will give the new system state. 

Variables for this model:

dt	    Time interval of the discrete system
m	    Mass of the sailbot
b 	    Water drag coefficient
kw 	    Wind speed to sail force coefficient
tr 	    Forward velocity to turn rate coefficient
aileron	    Relative aileron position (-1 to 1)
rudder	    Relative rudder position (-1 to 1)
vkm1 	    velocity at k-1
pkm1 	    position at k-1
"""

def sailBot(dt, m, b, kw, tr, aileron, rudder, wind, vkm1, pkm1):
    R = np.array([[0, 1], [-1, 0]])
    Fw = kw*wind.dot(R)*aileron
    Ff = vkm1*(Fw.dot(vkm1)/(np.square(vkm1[1]) + np.square(vkm1[0]))) # Project Wind force onto heading of boat
    a = Ff/m -(b/m)*vkm1	# Forward acceleration
    dTheta = rudder*tr*np.sqrt(np.square(vkm1[0]) + np.square(vkm1[1]))
    ang = dTheta*dt
    R = np.array([[np.cos(ang), -np.sin(ang)], [np.sin(ang), np.cos(ang)]])
    v = vkm1.dot(R) + a*dt
    p = pkm1 + v*dt
    return(v, p)

