// @JUDGE_ID:  17051CA  10096  C++
// @begin_of_source_code
#include<stdio.h>
#include<math.h>
#include<iostream.h>

#define PI 3.14159265358979323846

int N;
int read();
void work();
void fission(double, double, double);
void fussion(double, double, double);

int read(){
  if( scanf("%d", &N) == EOF ) return 0;
  else return 1;
}

void work(){
  char c;
  double i1, i2, i3;
  cin >> c >> i1 >> i2 >> i3;
  if( c == 'S' ){
    fission(i1, i2, i3);
  }else{
    fussion(i1, i2, i3);
  }
}

void fission(double l, double w, double r){
  double d, s;
  s = r/sqrt(2);
  
  d = sqrt( (w-2*s)*(w-2*s) + (l-2*s)*(l-2*s) );
  
  if( d <= 2*r ){
    cout << "Not enough space for fission." << endl;
  }else{
    printf("%.4f\n", d);
  }
}

void fussion(double r1, double r2, double d){
  if( r1+r2 <= d ){
    printf("%.4f\n", (double)1);
    cout << "No compaction has occurred." << endl;
    return;
  }

  double d1, h, cosAA, AA, cosA, cosB, A, B, R1, R2, ratio;
  /*
  d1 = r1 - (r1+r2-d)/2;
  h = sqrt( r1*r1 - d1*d1 );
  */
  cosAA = (r1*r1+r2*r2-d*d)/(2*r1*r2);
  /*AA = (acos(cosAA)*180)/PI;*/
  AA = acos(cosAA); /*degree*/
  h = ( r1*r2*sin(AA) )/d;
			
  h = 2*h;

  cosA = (r1*r1+d*d-r2*r2)/(2*r1*d);
  cosB = (r2*r2+d*d-r1*r1)/(2*r2*d);

  A = (acos(cosA)*180.0)/PI;
  B = (acos(cosB)*180.0)/PI;
  A = A*2;
  B = B*2;
  /*
  cosA = (r1*r1*2 - h*h)/(2*r1*r1);
  cosB = (r2*r2*2 - h*h)/(2*r2*r2);
  A = (acos(cosA)*180.0)/PI;
  B = (acos(cosB)*180.0)/PI;
  */
  R1 = ((360-A)/360)*r1*r1*PI;
  R2 = ((360-B)/360)*r2*r2*PI;
  ratio = (R1+R2+(d*h)/2)/(r1*r1*PI + r2*r2*PI);
  printf("%.4f\n", ratio);

}
main(){
  read();
  for( int i=1; i<=N; i++){
    work();
    cout << endl;
  }
}
// @end_of_source_code
