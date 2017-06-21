#include<cstdio>
//main(){for(int a=-1;++a<81;printf("%dx%d=%d\n",1+a/9,1+a%9,(1+a/9)*(1+a%9)));}
main(){for(int b,c,a=-1;++a<81;c=b=1,b+=a/9,c+=a%9,printf("%dx%d=%d\n",b,c,c*b));}
