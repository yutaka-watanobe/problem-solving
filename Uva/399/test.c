#include<stdio.h>

void rec();

main(){
  rec();
}

void rec(){
  int a[1000];
  printf("rec\n");
  rec();
}
