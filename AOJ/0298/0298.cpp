#include <cstdio>
#include <algorithm>
using namespace std;

main() {
  int total = 0;
  int bus[2*23*59];
  int n, h, m;
  
  for ( int k = 0; k < 2; ++k ) {
    scanf("%d", &n);
    for ( int i = 0; i < n; ++i ) {
      scanf("%d %d", &h, &m);
      bus[total+i] = h*100 + m;
    }
    total += n;
  }
  
  sort(bus, bus + total);
  total = unique(bus, bus + total) - bus;

  for ( int i = 0; i < total; ++i )
    printf("%d:%02d%c", bus[i]/100, bus[i]%100, (i+1) == total ? '\n' : ' ');
}
