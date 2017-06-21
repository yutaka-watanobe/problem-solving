#include<iostream>
using namespace std;

main(){
  int s1 = (1<<5);
  int s2 = (1<<0);

  cout << (s1|s2) << endl;
  cout << (s1&s2) << endl;
}
