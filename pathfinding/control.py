# Creating the control system for the sailBot

import numpy as np
import "./modelFunc.py"

# System Constants
m = 1					# Mass of sailbot
kw = 1					# Wind to force coefficient
tr = 0.1				# Forward velocity to turn rate coeff
b = 1					# Water drag coefficient
dt = 0.1				# System time period
wind
n = 20					# Number of iterations

# System Variables
aileron
rudder
pos
vel

# Initialization

for i in range(1,n)
    [vel[i], pos[i]] = sailbot(dt, m, b, kw, tr, aileron[i-1], rudder[i-1], wind, vel[i-1], pos[i-1])
