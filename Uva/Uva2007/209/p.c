// @JUDGE_ID:  17051CA  209  C++
// @begin_of_source_code
/* Geometory - Cordinate */
#include<stdio.h>
#include<iostream>
#include<vector>
#include<stl.h>
#include<string>

#define MAX 32768

class point{
 public:
  int x, y;
  point(){}
  point( int x, int y ): x(x), y(y){}
};

void split(vector<int> &d, const string &s, char c=' '){
  string t = "";
  d.clear();
  for(int i=0; i<s.size(); i++){    
    if(s[i]==c){
      if(t!=""){ d.push_back( atoi(t.c_str())); t = ""; }
    }
    else t += s[i];
  }
  if(t.size()) d.push_back( atoi(t.c_str()) );
 }

point MP[ MAX ];
vector<int> p;
string line;

void init(){
  int pos = 1;
  for ( int si = 0; si <= MAX; si++ ){
    int i, j;
    for ( i = si, j = 0; i >= 0; i--, j++ ){
      if ( pos >= MAX ) return;
      MP[ pos++ ] = point( i, j );
    }
  }
}

void print(){
  for ( int i = 0; i < p.size(); i++ ){
    cout << p[i] << " ";
  }
}

void printFig( string str ){
  print();
  cout << "are the vertices of a " << str << endl;
}

void printNo(){
  print();
  cout << "are not the vertices of an acceptable figure" << endl;
}

bool read(){
  getline( cin, line );
  if ( cin.eof() ) return false;
  return true;
}

bool isTriangle( vector<int> v ){
  sort ( v.begin(), v.end() );
  point p1 = MP[ v[0] ];
  point p2 = MP[ v[1] ];
  point p3 = MP[ v[2] ];

  if ( p1.y == p2.y && p1.x == p3.x && p2.x - p1.x == p3.y - p1.y ) return true;
  if ( p1.x == p3.x && p2.y == p3.y && p3.y - p1.y == p3.x - p2.x ) return true;
  return false;
}

bool isParallel( vector<int> v ){
  sort ( v.begin(), v.end() );
  point p1 = MP[ v[0] ];
  point p2 = MP[ v[1] ];
  point p3 = MP[ v[2] ];
  point p4 = MP[ v[3] ];

  /* regular */
  if ( p1.y == p2.y && p1.x == p3.x && p2.x == p4.x && p3.y == p4.y ){
    if ( p2.x - p1.x == p3.y - p1.y )     return true;
  }
  if ( p1.x == p3.x && p2.y == p3.y && p2.x == p4.x ){
    if ( p3.y - p1.y == p3.x - p2.x && p3.y - p1.y == p4.y - p2.y ) return true;
  }
  if ( p1.y == p3.y && p1.x == p4.x && p2.y == p4.y ){
    if ( p3.x - p1.x == p4.y - p1.y && p3.x - p1.x == p4.x - p2.x ) return true;
  }

  return false;
}

bool isHexagon( vector<int> v ){
  sort ( v.begin(), v.end() );
  point p1 = MP[ v[0] ];
  point p2 = MP[ v[1] ];
  point p3 = MP[ v[2] ];
  point p4 = MP[ v[3] ];
  point p5 = MP[ v[4] ];
  point p6 = MP[ v[5] ];

  if ( p1.y == p3.y && p1.x == p6.x && p2.x == p4.x && p2.y == p5.y && 
       p4.y == p6.y && p3.x == p5.x ) return true;

  return false;
}


void work(){

  split( p, line );

  if ( p.size() == 3 ){
    if ( isTriangle( p ) ){
      printFig("triangle");
    } else {
      printNo();
    }
  } else if ( p.size() == 4 ){
    if ( isParallel( p ) ){
      printFig("parallelogram");
    } else {
      printNo();
    }
  } else if ( p.size() == 6 ){
    if ( isHexagon( p ) ){
      printFig("hexagon");
    } else {
      printNo();
    }
  } else {
    printNo();
  }
}

main(){
  init();
  while ( read() ){
    work();
  }
}

// @end_of_source_code
