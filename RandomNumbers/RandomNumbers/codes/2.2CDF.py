#Importing numpy, scipy, mpmath and pyplot
import numpy as np
import mpmath as mp
from scipy.stats import norm 
import matplotlib.pyplot as plt


maxrange=50
maxlim=6.0
x = np.linspace(-maxlim,maxlim,maxrange)#points on the x axis
simlen = int(1e6) #number of samples
err = [] #declaring probability list


randvar = np.loadtxt('gau.dat',dtype='double')

for i in range(0,maxrange):
	err_ind = np.nonzero(randvar < x[i]) #checking probability condition
	err_n = np.size(err_ind) #computing the probability
	err.append(err_n/simlen) #storing the probability values in a list

def Q(x):
    return (1-mp.erf(x/mp.sqrt(2)))/2
    
def f(x):
    return 1-Q(x)	

cdf = np.vectorize(f)

plt.plot(x,err,'bo',color="blue")
plt.plot(x,cdf(x),color='orange')
plt.grid() #creating the grid
plt.xlabel('$x_i$')
plt.ylabel('$F_X(x_i)$')
plt.legend(["Numerical", "Theory"])
#plt.savefig('../figs/gau_cdf.png')

plt.show()
