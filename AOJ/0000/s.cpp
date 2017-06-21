#include<cstdio>
#define r i%10
main(){for(int i=10;i++<=99;)if(r)printf("%dx%d=%d\n",i/10,r,i/10*(r));}

//main(){for(int b,c,a=-1;++a<81;b=1+a/9,c=1+a%9,printf("%dx%d=%d\n",b,c,c*b));}
//main(){for(int b,a=-1;++a<81;b=1+a/9,printf("%dx%d=%d\n",b,c,c*b));}
main(){for(int i=11;i++<=99;)if(i%10)printf("%dx%d=%d\n",i/10,i%10,(i/10)*(i%10));}
