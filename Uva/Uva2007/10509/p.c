// @JUDGE_ID:  17051CA  10509  C++
// @begin_of_source_code
/* Mathmatic */
#include<stdio.h>
#include<string>
#include<stl.h>
#include<vector>
#include<cmath>

double F;
vector<double> T;
map<double, int> I;

void init(){
  int i = 0;
  double triple;
  while( 1 ) {
    triple = 1.0* i * i * i;
    T.push_back( triple );
    I[triple] = i;
    if ( triple > 1000000 ) break;
    i++;
  }

}

int read(){
  cin >> F;
  if ( F == 0 ) return 0;
  return 1;
}

void work(){
  double a, dx, ans;

  a = I[ *(upper_bound( T.begin(), T.end(), F )-1) ];

  dx = (F - a*a*a) / ( 3*a*a );

  ans = a + dx;

  printf("%.4f\n", ans );
}

main(){
  init();
  while(read()){
    work();
  }
}
// @end_of_source_code
