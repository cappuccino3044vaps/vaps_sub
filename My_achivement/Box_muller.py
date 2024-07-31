import numpy as np

data_array=np.zeros(1000)
for i in range(0,len(data_array),2):
    d1=np.random.rand()
    d2=np.random.rand()

    z1=np.sqrt(-2*np.log(d1))*np.cos(2*np.pi*d2)
    z2=np.sqrt(-2*np.log(d1))*np.sin(2*np.pi*d2)

    data_array[i]=z1
    data_array[i+1]=z2

np.savetxt('Box_muller.csv',data_array,delimiter=' ')