#include<iostream>
#include<vector>
#include<string>
using namespace std;

void compute(){
  string num; cin >> num;
  vector<int> v;
  for ( int i = 0; i < num.size(); i++ ) v.push_back(num[i]-'0');
  
  int cnt = 0;
  while(1){
    if ( v.size() == 1 ) break;
    int a = v[0];
    int b = v[1];
    v.erase(v.begin());
    v.erase(v.begin());
    a += b;
    if ( a < 10 ) v.insert(v.begin(), a);
    else {
      v.insert(v.begin(), a%10);
      v.insert(v.begin(), 1);
    }
    cnt++;
  }
  if ( cnt%2 ) cout << "Fabre wins." << endl;
  else cout << "Audrey wins." << endl;
}

main(){
  int tcase; cin >> tcase;
  for ( int i = 0; i < tcase;i++ ) compute();
}
