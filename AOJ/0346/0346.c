#include<stdio.h>

int e[12];

int check(){
  int i, j, t;
  for ( i = 0; i < 12 - 1; i++ ){
    for ( j = 12 - 2; j >= i; j-- ){
      if ( e[j] > e[j+1] ){
	t = e[j];
	e[j] = e[j+1];
	e[j+1] = t;
      }
    }
  }
  
  for ( int i = 0; i < 12; i += 4)
    if ( e[i] != e[i+3] ) return 0;
  return 1;
}

int main(){
  int i;
  for ( i = 0; i < 12; i++ ) scanf("%d", &e[i]);
  if ( check() ) printf("yes\n");
  else printf("no\n");
  return 0;
}
