#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "functions.h"

//main function begin
int  main(void)
{

double var=meansqr("gau.dat")-mean("gau.dat")*mean("gau.dat");

printf("%lf\n",mean("gau.dat"));
printf("%lf\n",var);

return 0;
}
