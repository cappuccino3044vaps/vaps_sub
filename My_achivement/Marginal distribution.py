import matplotlib.pyplot as plt
import numpy as np

r=np.linspace(0,8,400)
sigma_array=np.array([0.3,0.6,1.0,2.0])
Md=np.zeros((len(sigma_array),len(r)))
for i in range(len(sigma_array)):
    sigma=sigma_array[i]
    Md[i]=(r*np.exp(-(r*r)/(2*sigma*sigma)))/(sigma*sigma)

fig = plt.figure()
ax=fig.add_subplot(1,1,1)
for j in range(len(sigma_array)):
    ax.plot(r,Md[j],label=f'σ={sigma_array[j]}')
ax.set_xlabel('r')
ax.set_ylabel('p_r(r)')
ax.legend()
plt.savefig('Marginal_distribution.pdf')
plt.show()

