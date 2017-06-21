// Simulation
#include<stdio.h>
#include<iostream>
#include<vector>

int n;

void work(){
  vector<int> v;
  for ( int i = 0; i < n; i++ ) v.push_back(i+1);

  int tmp;
  cout << "Discarded cards:";

  while ( v.size() > 1 ){
    cout << " " <<v[0];



    v.erase( v.begin() );

    if ( v.size() != 1 ) cout << ",";

    tmp = v[0];
    v.erase( v.begin() );

    v.push_back(tmp);
  }
  cout << endl;
  cout << "Remaining card: " << v[0] << endl;

}


main(){
  
  while (1 ){
    cin >> n;
    if ( n == 0 ) break;
    work();
  }
}
