import numpy as np
import matplotlib.pyplot as plt
import matplotlib.patches as patches

csv = np.genfromtxt('sail.csv', delimiter=',')
time = csv[:,0]
x = csv[:,1]
y = csv[:,2]
setpoint = csv[:,3]
heading = csv[:,4]
rudder = csv[:,5]

obs = np.genfromtxt('obstacles.txt', delimiter=',')

path = np.genfromtxt('source/path.csv', delimiter=',')

# nxn size of the mesh
meshSize = 20;



# Creates mesh, colours nodes for path and obstacle.
fig1 = plt.figure()
ax1 = fig1.add_subplot(1,1,1, aspect='equal')
for i in range(0, meshSize):
    for j in range(0, meshSize):
	color = 'none'
	vis = 1	
	for n in obs:
	    if i - meshSize/2 == n[0] and j - meshSize/2 == n[1]:
		color = 'black'
		vis = 0.6
	for n in path:
	    if (i - meshSize/2) == n[0] and (j - meshSize/2) == n[1]:
		color = 'magenta'
		vis = 0.6
	if i - meshSize/2 == (path[len(path) - 1,0]) and j - meshSize/2 == (path[len(path) - 1,1]):
	    color = 'red'
	    vis = 0.9
	if i == meshSize/2 and j == meshSize/2:
	    color = 'green'
	    vis = 0.8
		
	ax1.add_patch(
	    patches.Rectangle(
		(-2.5 - meshSize*5/2 + 5*i , -2.5 - meshSize*5/2 + 5*j),
		5,
		5,
		alpha = vis,
		facecolor=color
	    )
	)

ax1.plot(x,y)
plt.show()
