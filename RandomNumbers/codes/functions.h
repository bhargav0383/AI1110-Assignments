//begin declaation
void uniform(char *str,int len);
double mean(char *str);
double meansqr(char *str);
void gaussian(char *str, int len);
void sumfunc(char *tri,int len);
void equiprobable(char *str,int len);
int signum(double a);
void combo(char *str,char *str2,char *str3,int len);
double estimator(char *str1,char *str2,int len,int req);
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

int signum(double a)
{
    if(a>=0)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

//Function to generate equiprobable distribution belongs to {-1,1}
void equiprobable(char *str,int len)
{
    int i;
    FILE *fp;
    fp=fopen(str,"w");
    for (i = 0; i < len; i++)
    {
    fprintf(fp,"%d\n",signum(2*(double)rand()/(double)RAND_MAX - 1));
    }
    fclose(fp);
}

void combo(char *str,char *str2,char *str3,int len)
{
  //Y=AX+N
int i,j,equi;//equi refers to numbers in BErnoulli
double temp;//temp referes to numbers in gaussian
FILE *fp,*gaufile,*equifile;
fp = fopen(str,"w");//destiny file
gaussian(str2,len);//genererate N
equiprobable(str3,len);//generate X
gaufile=fopen(str2,"r");
equifile=fopen(str3,"r");
//Generate numbers
for (i = 0; i < len; i++)
{
fscanf(equifile,"%d",&equi);
fscanf(gaufile,"%lf",&temp);
fprintf(fp,"%lf\n",0.5*equi+temp);
}
fclose(fp);
}

double  estimator(char *str1,char *str2,int len,int req)
{
// str1 represents AX+N //combo
// str2 reprsenst X brnoulii equiprob
int i;
long double temp1,temp2,counter1=0,counter2=0,counter=0;
//counter represents X=1
combo(str1,"gau.dat","equi.dat",len);
equiprobable(str2,len);
FILE *fp1,*fp2;
fp1=fopen(str1,"r");// AX+N
fp2=fopen(str2,"r");//Bernoullii
//calculation of P(e|0)
for(i=0;i<len;i++)
{
  fscanf(fp1,"%Lf",&temp1);
  fscanf(fp2,"%Lf",&temp2);
  if(temp2==1)
  {
    counter++;
  }
  if(temp1<0&&temp2==1)
  {
    counter1++;
  }
  if(temp1>0&&temp2==-1)
  {
    counter2++;
  }
}
fclose(fp1);
fclose(fp2);
if(req==1)
{
  return (double)counter1/counter;
}
else
{
  return (double)counter2/(len-counter);
}
}
