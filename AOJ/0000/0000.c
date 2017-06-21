#include<stdio.h>
main(){int i;for(i=0;i<81;i++)printf("%dx%d=%d\n",i/9+1,i%9+1,(i/9+1)*(i%9+1));
return 0;}
