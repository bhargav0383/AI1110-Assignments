#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "functions.h"

//main function begin
int  main(void)
{

double var=meansqr("uni.dat")-mean("uni.dat")*mean("uni.dat");

printf("%lf\n",mean("uni.dat"));
printf("%lf\n",var);

return 0;
}
