#include<iostream>
using namespace std;

main(){
  pair<int, pair<int, int> > y1, y2;
  cin >> y1.first >> y1.second.first >> y1.second.second;
  cin >> y2.first >> y2.second.first >> y2.second.second;

  if ( y1 > y2 ) swap(y1, y2);
  cout <<  y2.first - y1.first + (y1.second < y2.second ? 1 : 0) << endl;
}



