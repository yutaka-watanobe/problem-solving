#include<stdio.h>

int main(){
  int n, current, i, rem; 
  scanf("%d", &n);

  current = 100000;

  for ( i = 0; i < n; i++ ){
    current += (int)( current * 0.05 );
    rem = current % 1000;
    current = current - rem + ( ( rem == 0 ) ? 0 : 1000 );
  }

  printf("%d\n", current);
  
  return 0;
}
