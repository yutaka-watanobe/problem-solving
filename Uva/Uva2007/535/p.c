// @JUDGE_ID:  17051CA  535  C++
// @begin_of_source_code
/* Math ( Geometory ) */
#include<stdio.h>
#include<iostream>
#include<string>
#include<cmath>
#include<stl.h>
#include<map>
#include<vector>

class Point{
 public:
  double latitude, longitude;
  Point(double latitude, double longitude): 
    latitude(latitude), longitude(longitude){}
};

map<string, int> M; /* name -> index */
vector<Point> P;
double PI = 3.141592653589793;

void read(){
  string name;
  double latitude, longitude;
  int index = 0;
  while ( 1 ){
    cin >> name;
    if ( name == "#" ) break;
    cin >> latitude >> longitude;
    latitude = latitude * PI / 180.0;
    longitude = longitude * PI / 180.0;
    P.push_back( Point( latitude, longitude ) );
    M[ name ] = index++;
  }
}

int getDistance( Point p1, Point p2 ){
  double r = 6378.0;

  double x1 = r*cos( p1.latitude )*cos( p1.longitude );
  double y1 = r*cos( p1.latitude )*sin( p1.longitude );
  double z1 = r*sin( p1.latitude );

  double x2 = r*cos( p2.latitude )*cos( p2.longitude );
  double y2 = r*cos( p2.latitude )*sin( p2.longitude );
  double z2 = r*sin( p2.latitude );

  double l = sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) + (z1-z2)*(z1-z2) );

  double cosL = ( 2*r*r - l*l ) / (2*r*r);
  double theta = acos( cosL );

  return (int)( r * theta + 0.5 );
}

void query(string source, string target ){
  cout << source << " - " << target << endl;

  if ( M.find ( source ) == M.end() ||
       M.find ( target ) == M.end() ){
    cout << "Unknown" << endl;
    return ;
  }

  cout << getDistance( P[ M[source] ], P[ M[target] ] ) << " km" << endl;
}

void work(){
  string source, target;
  while ( 1 ){
    cin >> source >> target;
    if ( source == "#" && target == "#" ) return;
    query( source, target );
  }

}

main(){
  read();
  work();
}
// @end_of_source_code
