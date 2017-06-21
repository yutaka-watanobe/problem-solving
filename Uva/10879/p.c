// mathematic
#include<stdio.h>
#include<iostream>
#include<cmath>
#include<cassert>

void work(){
  int K; scanf("%d", &K);

  int lim = (int)sqrt((int)K);
  int size = 0;

  int buffer[1000];

  int A, B, C, D;
  for ( int i = 2; i <= lim; i++ ){
    if ( K % i != 0 ) continue;

    A = i;
    B = K/i;

    if ( A == B ) continue;

    for ( int j = i+1; j <= lim; j++ ){
      if ( K % j != 0 ) continue;

      C = j;
      D = K/j;

      if ( C == D ) continue;

      if ( A != C && A != D && B != C && B != D ){
	printf("%d = %d * %d = %d * %d\n", K, A, B, C, D);
	return;
      }
    }
  }

  //assert(false );
  //  cout << "size = " << size << endl;
  /*
  for ( int i = 0; i < size-1; i++ ){
    A = buffer[i];
    B = K / buffer[i];

    for ( int j = i + 1; j < size; j++ ){
      C = buffer[j];
      D = K / buffer[j];

      if ( A != C && A != D && B != C && B != D ){
	printf("%d = %d * %d = %d * %d\n", K, A, B, C, D);
	return;
      }

    }
    }*/

}

main(){
  int tcase; scanf("%d", &tcase);
  for ( int i = 1; i <= tcase; i++ ){
    printf("Case #%d: ", i);
    work();
  }
}
