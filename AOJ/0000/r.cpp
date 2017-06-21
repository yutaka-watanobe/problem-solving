#include<cstdio>
//main(){for(int i=1,j=0;i<10;printf("%dx%d=%d\n",i,j,i*j))if(++j==10)i++,j=1;}
main(){for(int i=1,j=1;i<10; j%10?0:i++,j=1)printf("%dx%d=%d\n",i,j++,i*j);}
