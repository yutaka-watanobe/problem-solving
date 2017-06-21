#include<iostream>
#include<vector>
using namespace std;

main(){
  vector<int> v1, v2;
  v1.push_back(2);
  v1.push_back(2);
  v1.push_back(3);

  v2.push_back(6);
  v2.push_back(3);
  v2.push_back(3);

  if ( v1 < v2 ) cout << "v1 < v2" << endl;
  else cout << "v1 > v2" << endl;
}
