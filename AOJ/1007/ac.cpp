#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
static const int N = 100;

main(){
  int r, c, T[N][N];
  int bi, ei, bj, ej, di, dj, d;

  cin >> r >> c;
  int cnt = 1;
  for ( int k = 0; k < (r+c-1); k++ ){
    //ej = k%2?max(0, k-r+1):min(k, c-1);
    bj = k%2?min(k, c-1):max(0, k-r+1);
    //ei = k%2?min(k, r-1):max(0, k-c+1);
    bi = k%2?max(0, k-c+1):min(k, r-1);
    d = k<min(r, c)?k:r+c-k-2;
    //cout << bi << "->" << ei << "   " << bj << "->" << ej << endl;
    //cout << d << endl;
    //for ( int l = 0; l < max(bj, ej)-min(bj, ej)+1; l++ ){
    for ( int l = 0; l < d+1; l++ ){
      int i = bi + ((k%2==0)?-1:1)*l;
      int j = bj + ((k%2==0)?1:-1)*l;
      T[i][j] = cnt++;
    }  
  }

  for ( int i = 0; i < r; i++ ){
    for ( int j = 0; j < c; j++ ){
      printf("%5d", T[i][j]);
    }
    cout << endl;
  }
}
