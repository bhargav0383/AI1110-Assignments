#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Defining the function for generating uniform random numbers
void uniform(char *str, int len)
{
int i;
FILE *fp;

fp = fopen(str,"w");
//Generate numbers
for (i = 0; i < len; i++)
{
double v=-2*log(1-(double)rand()/RAND_MAX);
fprintf(fp,"%lf\n",v);
}
fclose(fp);

}
//End function for generating uniform random numbers

int  main(void)
{
 
//Uniform random numbers
uniform("unit.dat", 1000000);

return 0;
}
