// Simulation
#include<stdio.h>
#define EPS 0.99999999
using namespace std;

int byte;

void work(){
  int second = 0;
  int sum = 0;
  int pre = 0;
  int buffer[6];
  int pos;
  int size;

  for ( int i = 1; i <= 5; i++ ) buffer[i] = 0;

  while ( 1 ){
    scanf("%d", &size);

    sum += size;

    second++;

    pos = second % 5 + 1;
    pre -= buffer[pos];
    pre += size;
    buffer[pos] = size;

    if ( second % 5 == 0 ){
      if ( pre == 0 ){
	printf("   Time remaining: stalled\n");
      } else {
	double rate = (byte - sum)/(pre/5.0);
	printf("   Time remaining: %d seconds\n", (int)( rate + EPS ));
      }

    }

    if ( byte <= sum ) break;
  }

  printf("Total time: %d seconds\n\n", second);
}

bool read(){
  scanf("%d", &byte);
  if ( byte == 0 ) return false;
  return true;
}

main(){
  for ( int i = 1; read(); i++ ){
    printf("Output for data set %d, %d bytes:\n", i, byte);
    work();
  }
}



