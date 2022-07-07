//begin declaation
void uniform(char *str,int len);
double mean(char *str);
double meansqr(char *str);
void gaussian(char *str, int len);
void sumfunc(char *tri,int len);
//end declaration


//function for generating uniform random numbers
void uniform(char *str, int len)
{
int i;
FILE *fp;

fp = fopen(str,"w");
//Generate numbers
for (i = 0; i < len; i++)
{
fprintf(fp,"%lf\n",(double)rand()/RAND_MAX);
}
fclose(fp);

}


//function for calculating the mean of random numbers
double mean(char *str)
{
int i=0,c;
FILE *fp;
double x, temp=0.0;

fp = fopen(str,"r");
//get numbers from file
while(fscanf(fp,"%lf",&x)!=EOF)
{
//Count numbers in file
i=i+1;
//Add all numbers in file
temp = temp+x;
}
fclose(fp);
temp = temp/(i-1);
return temp;

}


//function for calculating mean of squared numbers of random numbers
double meansqr(char *str)
{
int i=0,c;
FILE *fp;
double x, temp=0.0;

fp = fopen(str,"r");
//get numbers from file
while(fscanf(fp,"%lf",&x)!=EOF)
{
//Count numbers in file
i=i+1;
//Squaring and adding numbers in file
temp = temp+x*x;
}
fclose(fp);
temp = temp/(i-1);
return temp;
}


//function for generating Gaussian random numbers
void gaussian(char *str, int len)
{
int i,j;
double temp;
FILE *fp;

fp = fopen(str,"w");
//Generate numbers
for (i = 0; i < len; i++)
{
temp = 0;
for (j = 0; j < 12; j++)
{
temp += (double)rand()/RAND_MAX;
}
temp-=6;
fprintf(fp,"%lf\n",temp);
}
fclose(fp);

}

//Function to generate the sum of two uniform distributions
void sumfunc(char *sum,int len)
{
int i;
double x,y;
FILE *fp,*fp2,*destinyfile;
//get two uniform distributions 
uniform("uni1.dat",len);
uniform("uni2.dat",len);
//open the two files
fp = fopen("uni1.dat","r");
fp2=fopen("uni2.dat","r");
destinyfile=fopen(sum,"w");
//Generate numbers
while(fscanf(fp,"%lf",&x)!=EOF)
{
fscanf(fp2,"%lf",&y);
fprintf(destinyfile,"%lf\n",(double)(x+y));
}
fclose(fp);
fclose(fp2);
fclose(destinyfile);
remove("uni1.dat");
remove("uni2.dat");
}
