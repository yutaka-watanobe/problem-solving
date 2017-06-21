// median 

#include<stdio.h>
#include<algorithm>
#define MAX 1000001
#define SIZE 65537

int n;
int buffer[ MAX ];
int values[ SIZE ];

void work(){
  sort( buffer, buffer + n );
  
  int minValue1, minValue2, sum, defference;

  if ( n % 2 == 0 ){
    minValue1 = buffer[n / 2 - 1];
    minValue2 = buffer[n / 2];
    if ( minValue1 == minValue2 ){
      sum = values[ minValue1 ];
      defference = 1;
    } else {
      sum = values[ minValue1 ] + values[ minValue2 ];
      defference = minValue2 - minValue1 + 1;
    }
  } else {
    minValue1 = buffer[n / 2];
    sum = values[ minValue1 ];
    defference = 1;
  }
  
  printf("%d %d %d\n", minValue1, sum, defference);
}

void read(){
  for ( int i = 0; i < SIZE; i++ ) values[i] = 0;
  int x;
  for ( int i = 0; i < n; i++ ) {
    scanf("%d", &x);
    buffer[i] = x;
    values[ x ]++;
  }
}

main(){
  while ( scanf("%d", &n) != EOF ){
    read(); work();
  }
}
