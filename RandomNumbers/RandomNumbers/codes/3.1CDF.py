#Importing numpy, scipy, mpmath and pyplot
import numpy as np
import matplotlib
matplotlib.rcParams['backend'] = 'GTK3Agg'
import matplotlib.pyplot as plt
import mpmath as mp


x = np.linspace(-10,10,50)#points on the x axis


simlen = int(1e6) #number of samples
err = [] #declaring probability list
#randvar = np.random.normal(0,1,simlen)
randvar = np.loadtxt('unit.dat',dtype='double')

for i in range(0,50):
	err_ind = np.nonzero(randvar < x[i]) #checking probability condition
	err_n = np.size(err_ind) #computing the probability
	err.append(err_n/simlen) #storing the probability values in a list

def g(x) :
   return (1-mp.exp(-x/2))

def cdf(x):

   if x<0 :
         return 0
   else:
         return g(x)
         
y=[-3,-2,1,2,3,4]
CDF = np.vectorize(cdf, otypes=['double'])

plt.plot(x,err,'bo',color="green")#plotting the CDF
plt.plot(x,CDF(x),color="blue")

plt.grid() #creating the grid
plt.xlabel('$v$')
plt.ylabel('$F_V(v)$')
plt.legend(["Numerical", "Theory"])
#plt.savefig('../figs/exp_cdf.png')
plt.show()
