#include<iostream>

char G[100][100];

main(){

  for ( int y = 0; y < 100; y++ ){
    for ( int x = 0; x < 100; x++ ){
      G[y][x] = '.';
    }
  }

  int x, y;

  cin >> x >> y;

  G[y][x] = '*';

  while (1 ){
    cin >> x >> y;
    if ( x == 0 && y == 0  ) break;
    G[y][x] = 'x';
  }

  for ( int y = 99; y >= 0; y-- ){
    for ( int x = 0; x < 100; x++ ){
      cout << G[y][x];
    }
    cout << endl;
  }
}
