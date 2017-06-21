#include<stdio.h>
#include<algorithm>

#define OMAX 23
#define SMAX 8

using namespace std;

class Order{
 public:
  int source, destination, npassenger;

  Order(){}
  Order( int s, int d, int n ){
    source = s;
    destination = d;
    npassenger = n;
  }

  bool operator < ( const Order &o ) const{
    return ( source < o.source );
  }
};

int limit, dstation, norder;
Order orders[OMAX];
int capacity[SMAX];
int maxP;
int currentP;

bool checkCapacity(int s, int d, int val){
  for ( int i = s; i < d; i++ ){
    if ( capacity[i] + val > limit ) return false;
  }
  return true;
}

void fillCapacity(int s, int d, int val ){
  for (int i = s; i < d; i++ ) capacity[i] += val;
}

void delCapacity(int s, int d, int val ){
  for (int i = s; i < d; i++ ) capacity[i] -= val;
}

void rec( int cursor ){
  if ( cursor == norder ) return;

  // not select
  rec( cursor + 1 );

  // select
  Order order = orders[cursor];
  
  if ( checkCapacity( order.source, order.destination, order.npassenger) ){
    fillCapacity( order.source, order.destination, order.npassenger );
    
    int earn = (order.destination - order.source) * order.npassenger;
    currentP += earn;

    maxP = max( maxP, currentP );

    rec( cursor + 1 );

    delCapacity( order.source, order.destination, order.npassenger );
    currentP -= earn;
  }
}

void work(){
  for ( int i = 0; i < dstation; i++ ) capacity[i] = 0;

  maxP = 0;
  currentP = 0;
  rec( 0 );

  printf("%d\n", maxP);
}

bool read(){

  scanf("%d %d %d", &limit, &dstation, &norder);
  if ( limit == 0 && dstation == 0 && norder == 0 ) return false;
  
  for ( int i = 0; i < norder; i++ ){
    int s, d, p;
    scanf("%d %d %d", &s, &d, &p);
    orders[i] = Order(s, d, p);
  }

  sort( orders, orders + norder );

  return true;
}

main(){
  while ( read() ) work();
}
