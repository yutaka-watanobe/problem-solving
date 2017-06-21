#include<iostream>
#include<algorithm>
#include<map>

using namespace std;
#define MAX 1000000

int n;
map<int, int> A;

int main(){
  while( cin >> n && n ){
    A = map<int, int>();

    int x;
    for ( int i = 0; i < n; i++ ){
      cin >> x;
      A[x]++;
    }

    map<int, int>::iterator it;
    int index, maxv;
    maxv = 0;
    for ( it = A.begin(); it != A.end(); it++ ){
      if ( maxv < (*it).second ){
	maxv = (*it).second;
	index = (*it).first;
      }
    }

    if ( maxv > n/2 ) cout << index << endl;
    else cout << "NO COLOR" << endl;

  }
  return 0;
}
