#include <stdio.h>
#include <math.h>

int main()
{   
    double pa = 0.5;
    double paub = 0.6;
    double pb,pab;
    // pa denotes P(A), pb denotes P(B), pab denotes P(A intersection B), paub denotes P(A union B)
    // condition  paub = pa + pb - pab
      pb = paub + pab - pa ;
   
    // for independent events 
      pab = pa*pb;
      printf("value of p = %lf",pb);
     
  return 0;
}