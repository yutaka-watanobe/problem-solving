#include<iostream>
using namespace std;
#define MAX 100

void insertion( int size, int D[] ){
    for ( int i = 1; i < size; i++ ){
	int j, v = D[i];
	for ( j = i; j && D[j-1] > v; D[j] = D[j-1], j--);
	D[j] = v;
    }
}

main(){
  int data[MAX];
  int n; cin >> n;
  for ( int i = 0; i < n; i++ ) cin >> data[i];
  insertion(n, data);
  for ( int i = 0; i < n; i++ ) cout << data[i] << " ";
  cout << endl;
}
