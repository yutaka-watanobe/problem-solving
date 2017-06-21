// @JUDGE_ID:  17051CA  10549  C++
// @begin_of_source_code
#include<stdio.h>
#include<algorithm>
#define MAX 201
using namespace std;

class Doll{
 public:
  int h, d, w, H, D;
  Doll(){}
  Doll(int h, int d, int w ): h(h), d(d), w(w){
    H = h - 2*w;
    D = d - 2*w;
  }
  
  bool operator < ( const Doll &doll ) const{
    if ( H == doll.H ){
      return D > doll.D;
    } else {
      return H > doll.H;
    }
    /*
    if ( h == doll.h ){
      return d > doll.d;
    } else {
      return h > doll.h;
      }*/
  }
};

int n, N;
Doll D[MAX];
Doll S1[MAX];
Doll S2[MAX];
int p1, p2;

bool read(){
  int h,d, w;
  scanf("%d", &n); if ( n == 0 ) return false;
  N = 2*n;
  for ( int i = 0; i < N; i++ ){
    scanf("%d %d %d", &h, &d, &w);
    D[i] = Doll(h, d, w );
  }
  return true;
}

void printResult(){
  for ( int i = 0; i < n; i++ ){
    printf("%d %d %d\n", S1[i].h, S1[i].d, S1[i].w );
  }
  printf("-\n");
  for ( int i = 0; i < n; i++ ){
    printf("%d %d %d\n", S2[i].h, S2[i].d, S2[i].w );
  }
}

bool rec( int pos ){

  if ( p1 >= 2 && ( S1[p1-1].h > S1[p1-2].H || S1[p1-1].d > S1[p1-2].D ) ) return false;
  if ( p2 >= 2 && ( S2[p2-1].h > S2[p2-2].H || S2[p2-1].d > S2[p2-2].D ) ) return false;

  
  if ( p1 == n && p2 == n ) {
    printResult();
    return true;
  }

  if ( p1 < n && p2 < n ){
    S1[p1++] = D[pos];
    S2[p2++] = D[pos+1];
    if ( rec( pos + 2 ) ) return true;
    p1--; p2--;
    S1[p1++] = D[pos+1];
    S2[p2++] = D[pos];
    if ( rec( pos + 2 ) ) return true;
    p1--; p2--;
  } 
  
  if ( p1 < n-1 ) {
    S1[p1++] = D[pos];
    S1[p1++] = D[pos+1];
    if ( rec( pos + 2 ) ) return true;
    p1-=2;
  } 
  
  if ( p2 < n-1 ) {
    S2[p2++] = D[pos];
    S2[p2++] = D[pos+1];
    if ( rec( pos + 2 ) ) return true;
    p2-=2;
  }

  return false;
}

void work(){
  sort( D, D + N );
  p1 = p2 = 0;
  rec( 0 );
}

main(){
  for ( int i = 0; read(); i++ ){
    if ( i ) printf("\n");
    work();
  }
}

// @end_of_source_code


