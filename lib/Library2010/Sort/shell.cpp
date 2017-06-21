#include<iostream>
using namespace std;
#define MAX 100000

void shell( int n, int a[] ){
  int h;
  for ( h = 1; h <= n/9; h = 3*h + 1);
  for ( ; h > 0 ; h /= 3 ){ 
    for ( int i = h; i < n; i++ ){
      int j, v = a[i];
      for ( j = i; j >= h && a[j-h] > v; a[j] = a[j-h], j -= h);
      a[j] = v;
    }
  }
}

main(){
  int data[MAX];
  int n; //cin >> n;
  //for ( int i = 0; i < n; i++ ) cin >> data[i];
  n = 1000;
  for ( int i = 0; i < n ;i++) data[i] = rand()%1000000;
  shell(n, data);
  for ( int i = 0; i < n; i++ ) cout << data[i] << endl;
  cout << endl;
}
