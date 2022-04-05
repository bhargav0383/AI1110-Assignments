#include <stdio.h>
#include <math.h>

int height(int v,int r)
{
  int h;
   // v = (M_PI)*r*r*h/3;
    h = 3*v/((M_PI)*r*r);
  return h;
}
int CSA(int r,int h)
{
   //l = lateral height
   int l = sqrt(r*r + h*h);
   //s = curved surface area of the conical tent 
   int s = ceil((M_PI)*r*l);
   return s;
}
int main()
{
    /* 
      v = volume of the conical tent
      r = radius of the tent
      h = height of the tent 
    */  
    int v,r,h;
    scanf("%d %d",&v,&r);
    printf("Height of the tent is %dm \n",height(v,r));
    h = height(v,r);
    printf("curved surface area of the conical tent is %dm2",CSA(r,h));
    return 0;
}