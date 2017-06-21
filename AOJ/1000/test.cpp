#include<iostream>

using namespace std;
#define MAX 500
main(){
  int v[MAX][MAX][MAX];

  int a, b;

  while( cin >> a >> b ){
    int sum = 0;
    for ( int i = 0; i < MAX; i++ ){
      for ( int j = 0; j < MAX; j++ ){
	for ( int k = 0; k < MAX; k++ ){
	  v[i][j][k] = 0;
	}
      }
    }
    v[a%MAX][b%MAX][(a+b)%MAX] = 30;
    sum =     v[a%MAX][b%MAX][(a+b)%MAX] *20;
    cout << sum << endl;
  }

  
}
