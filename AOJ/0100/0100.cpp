#include<iostream>
#include<map>
#include<vector>
using namespace std;

void push(vector<long long> &v, long long id ){
  for ( int i = 0; i < v.size(); i++ )
    if ( v[i] == id ) return;
  v.push_back(id);
}

main(){
  long long n, id, p, q;
  while( cin >>n && n ){
    map<long long, long long> M;
    map<long long, long long>::iterator it;
    vector<long long> v;
    for ( int i = 0; i < n; i++ ){
      cin >> id >> p >> q;
      push(v, id);
      M[id] += p*q;
    }

    long long cnt = 0;
    for ( int i = 0; i < v.size(); i++ ){
      if ( M[v[i]] >= 1000000 ){
	cout << v[i] << endl;
	cnt++;
      }
    }

    if ( cnt == 0 ) cout << "NA" << endl;

  }
}
