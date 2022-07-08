#Importing numpy, scipy, mpmath and pyplot
import numpy as np
import matplotlib
matplotlib.rcParams['backend'] = 'GTK3Agg'
import matplotlib.pyplot as plt
import scipy

x = np.linspace(-4,4,80)#points on the x axis
#Theory graph
#Obtained Theory graph points using function
def uniCdf(x):
    if (x < 0): return 0
    elif (0 <= x < 1): 
        return x*1.0
    else: return 1

func = scipy.vectorize(uniCdf, otypes=['double'])

#Analytical Graph
simlen = int(1e6) #number of samples
err = [] #declaring probability list
#randvar = np.random.normal(0,1,simlen)
randvar = np.loadtxt('uni.dat',dtype='double')
#randvar = np.loadtxt('gau.dat',dtype='double')
for i in range(0,80):
	err_ind = np.nonzero(randvar < x[i]) #checking probability condition
	err_n = np.size(err_ind) #computing the probability
	err.append(err_n/simlen) #storing the probability values in a list
	
plt.grid() #creating the grid

plt.plot(x,err,'bo')#plotting empirical CDF

plt.plot(x,func(x),color="orange")#plotting analytical CDF

plt.xlabel('$x$')
plt.ylabel('$F_X(x)$')
plt.legend(["Simulation", "Analysis"])
#plt.savefig('../figs/uni_cdf.png')
plt.show()
