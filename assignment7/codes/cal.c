#include <stdio.h>
#include <math.h>

int main()
{  
    // pa denotes P(A), pb denotes P(B), pab denotes P(A intersection B), paub denotes P(A union B) 
    double pa = 0.5;
    double paub = 0.6;
    double pb,pab;

    // condition  paub = pa + pb - pab
      pb = paub + pab - pa ;
   
    // for mutually exclusive events
      pab = 0;
      printf("value of p = %lf\n",pb);

    // for independent events  pab = pa*pb
       pb = 2*(paub - pa);
       printf("value of p = %lf",pb);
  
  return 0;
}