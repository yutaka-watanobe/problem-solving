// @JUDGE_ID:  17051CA  10573  C++
// @begin_of_source_code
/* Math */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#define TYPE1 0
#define TYPE2 1

void split ( vector<int> &d, const string &s, char c=' ' ) {
  string t = "";
  d.clear();

  for ( int i = 0; i < s.size(); i++ ){    
    if ( s[i] == c ){
      if ( t != "" ){ d.push_back(atoi(t.c_str()) ); t = ""; }
    }
    else t += s[i];
  }
  if ( t.size() ) d.push_back(atoi(t.c_str()));
}

double PI;

class GeometryParadox{
 public:
  int r1, r2, t;
  int type;

  void compute1(){
    if ( r1 <= 0 || r2 <= 0 ){
      printf("Impossible.\n");
      return;
    }

    printf("%.4lf\n", 2.0*r1*r2*PI );
  }

  void compute2(){
    if ( t <= 0 ) {
      printf("Impossible.\n");
      return;
    }
    printf("%.4lf\n", t*t*PI/8 );
  }

  void work(){
    if ( type == TYPE1 ){
      compute1();
    } else if ( type == TYPE2 ){
      compute2();
    }
  }

  void read(){
    string line;
    getline( cin, line );
    vector<int> sp;
    split( sp, line );

    if ( sp.size() == 2 ){
      type = TYPE1;
      r1 = sp[0]; r2 = sp[1];
    } else if ( sp.size() == 1 ){
      type = TYPE2;
      t = sp[0];
    } else {
      assert( false );
    }
  }

};

main(){
  PI = 2*acos( 0.0 );

  GeometryParadox GP;
  string line;
  int tcase;
  cin >> tcase;
  getline( cin, line );
  
  for ( int i = 0; i < tcase; i++ ){
    GP.read();
    GP.work();
  }
}

// @end_of_source_code


