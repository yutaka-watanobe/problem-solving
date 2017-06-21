// @JUDGE_ID:  17051CA  10540  C++
// @begin_of_source_code
/* Geometory + Mathmatic + Dynamic Programming */
#include<stdio.h>
#include<iostream>
#include<cmath>
#include<vector>

double PI;
double R;
double RR;
int N;

double per_angle;
int n_layer; /* number of layer */
vector<double> petal_areas;
vector<double> total_areas; /* i th layer total area */
vector<double> visible_total_areas;

void init(){
  PI = 2.0*acos(0.0);
}

int read(){
  cin >> R >> N;
  if ( R == 0 && N == 0 ) return 0;
  RR = R*R;
  return 1;
}

double getArea( double degree ){
  double theta = 180.0 - degree;
  double tmp = theta*PI/180.0;
  return RR*(tmp - sin( tmp ) );
}

void compute(){

  petal_areas.clear();
  total_areas.clear(); /* i th layer total area */
  visible_total_areas.clear();

  n_layer = ( N + 1 ) / 2;

  per_angle = 360.0 / N; /* degree */
  
  for ( int i = n_layer; i >= 2; i-- ){
    petal_areas.push_back( getArea( per_angle * ( i - 1 ) ) );
  }
  petal_areas.push_back( PI*RR ); /* circle area */
  
  for ( int i = 0; i < petal_areas.size(); i++ ){
    double area = N*petal_areas[i];
    total_areas.push_back( area  );
  }

  visible_total_areas.push_back( total_areas[0] );
  for ( int i = 1; i < total_areas.size(); i++ ){
    if ( i == 1 ){
      visible_total_areas[i] = petal_areas[i] - petal_areas[i-1]*2;
    }else{
      visible_total_areas[i] = petal_areas[i] - petal_areas[i-1]*2 + petal_areas[i-2];
    }
    visible_total_areas[i] *= N;
  }

  cout << total_areas.size() << endl;
  for ( int i = 0; i < total_areas.size(); i++ ){
    printf("%.4lf %.4lf\n", total_areas[i], visible_total_areas[i] );
  }
}

void work(){
  compute();
}

main(){
  init();

  for ( int i = 1; read(); i++ ){
    cout << "Set " << i << ":" << endl;
    work();
  }
}

// @end_of_source_code
