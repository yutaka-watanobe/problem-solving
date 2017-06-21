#include<stdio.h>
#include<cmath>
using namespace std;

main(){
  int s, n, u, sum = 0;
  scanf("%d", &n);
  for ( int i = 0; i < n; i++ ){
    scanf("%d", &s);
    u = sqrt(s)+1;
    bool f = false;
    for ( int y = 1; y <= u; y++ ){
      if ( (s-y)%(2*y+1) == 0) { f = true; break; }
    }
    if ( !f ) sum++;
  }
  printf("%d\n", sum);
}
