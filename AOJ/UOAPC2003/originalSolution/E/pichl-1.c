#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define N 100
int b;
double s36, s72, vertex[N][2], acc=10.0e-5, Pi=3.14159265358979323846264338328;
double tri(double, double, double);
int legal(double vertex[N][2], double *);

main(){
	FILE *fp;
	double s,x; 
	int i,j,n72;	
	if ((fp=fopen("vertex.txt", "r"))== NULL){
		printf("could not open file vertex.txt\n"); exit(1);}
	while(fscanf(fp,"%d",&b)==1){
      for(i=0;i<b;i++) if(fscanf(fp,"%lg %lg",&vertex[i][0],&vertex[i][1])!=2){
	   	printf("...is that coordinates?\n");exit(1);}
	  if(!legal(vertex, &s)){printf("%5d %5d \n",-1,-1);}
	  else{
	    n72=(int)((s+acc)/s72);
        for(i=0;i<=n72;i++){
		  x=s-(double)i*s72; j=(int)((x+acc)/s36);
		  if((double)fabs(x-(double)j*s36)<acc) {printf("%5d %5d\n",j,i);break;}
		}
	  }
	}
}

int legal(double vertex[N][2], double *s){
	int i,il; 
	double a=0,x,l[N],c,c36,c72; 
    for(i=0;i<b;i++){
		l[i]=pow(vertex[i][0]-vertex[(i+1)%b][0],2);
		l[i]+=pow(vertex[i][1]-vertex[(i+1)%b][1],2); 
		l[i]=(double)sqrt(l[i]); il=(int)(l[i]+acc); x=(double)il;
		//printf("%f\n",l[i]);
		if((double)fabs(x-l[i])>acc) return 0;
	}
    c36=cos(36.0e0*Pi/180.0e0); c72=cos(72.0e0*Pi/180.0e0);
	s36=sin(36.0e0*Pi/180.0e0); s72=sin(72.0e0*Pi/180.0e0);
    for(i=0;i<b;i++){
    c=(vertex[i][0]-vertex[(i+b-1)%b][0])*(vertex[i][0]-vertex[(i+1)%b][0]);
    c+=(vertex[i][1]-vertex[(i+b-1)%b][1])*(vertex[i][1]-vertex[(i+1)%b][1]);
	c=c/(l[i]*l[(i+b-1)%b]);
	if((double)fabs((double)fabs(c)-c36)>acc && (double)fabs((double)fabs(c)-c72)>acc) return 0;
    a+=vertex[i][0]*vertex[(i+1)%b][1]-vertex[(i+1)%b][0]*vertex[i][1];
	}
	a=(double)fabs(a)*0.5e0; *s=a;
	return 1;
}
