// @JUDGE_ID:  17051CA  10175  C++
// @begin_of_source_code
/* Geometory */
#include<stdio.h>
#include<iostream>
#include<string>
#include<cmath>

void work(){
  double PI = 2*acos(0);
  double R1, R2, d, W, S, d1, d2, h1, h2;
  cin >> R1 >> R2 >> d >> W >> S;

  double V, A;
  
  double cosA, theta, L, l;

  cosA = (R1*R1 +d*d - R2*R2)/(2*R1*d);
  theta = acos(cosA);
  theta *= 2;

  L = sqrt( 2*R1*R1 - 2*R1*R1*cos(theta));
  l = L/2;

  d1 = sqrt(R1*R1 - l*l);
  d2 = d - d1;

  h1 = R1 - d1;
  h2 = R2 - d2;
  V = PI*(4*R1*R1*R1 + 4*R2*R2*R2 - h1*h1*(3*R1-h1) - h2*h2*(3*R2-h2))/3;
  A = 2*PI*(2*R1*R1 + 2*R2*R2 - R1*h1 - R2*h2);
  printf("%.4f %.4f\n", V, A);
  if(W/V > S) cout << "The Paired-Sphere Sinks." << endl;
  else  cout << "The Paired-Sphere Floats." << endl;
}

main(){
  int t;
  cin >> t;
  for(int i=0; i<t; i++){
    work();
  }
}
// @end_of_source_code
