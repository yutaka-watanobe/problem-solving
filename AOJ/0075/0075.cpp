#include<iostream>
using namespace std;

main(){
  int id;
  double w, h, bmi;
  char ch;
  while( cin >> id >> ch >> w >> ch >> h ){
    bmi = w/(h*h);
    if ( bmi >= 25.0 ) cout << id << endl;
  }

}
