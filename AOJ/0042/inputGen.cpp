#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main(){
  int n = 1000;

  srand(1);

  cout << 1000 << endl;
  cout << n << endl;

  for(int i=0; i<n; i++){
    cout << rand()%200 << "," << rand()%200 << endl;
  }

  return 0;
}
