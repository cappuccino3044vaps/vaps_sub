import matplotlib.pyplot as plt
import numpy as np
import random


times=int(input("input_times: "))
cpts=int(input("input_cpts: "))

k=0
n=0
pi_values=[]
pi_n=[cpts]
fig = plt.figure()
ax=fig.add_subplot(1,1,1)
for i in range(1,cpts+1):
    for j in range(times):
        x=random.random()
        y=random.random()
        if x**2 + y**2 <= 1:
            k += 1
    n=(i+1)*times
    pi=4.0*k/n
    pi_values.append(pi)
    ax.plot((i+1),pi,marker='o',markersize=2, linestyle='-', color='b')
ax.set_xlabel('n')
ax.set_ylabel('4k/n')
ax.set_ylim(3,3.5)
ax.grid()
plt.savefig('Montecarlo.pdf')
plt.show()