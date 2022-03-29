#include <stdio.h>
#include <math.h>
int main()
{
    /* 
      v = volume of the conical tent
      r = radius of the tent
      h = height of the tent 
    */  
    int v,r,h;
     //from problem
    r = 7;
    //for each person have 16 volume so for 77 
    v = (M_PI)*r*r*h/3;
    v = 77*16;

    h = 3*v/((M_PI)*r*r);
    printf("Height of the tent is %dm \n",h);

    //l = lateral height
    int l = sqrt(r*r + h*h);
    //s = curved surface area of the conical tent 
    float s = (M_PI)*r*l;
    printf("curved surface area of the conical tent is %fm2",s);
    return 0;
}