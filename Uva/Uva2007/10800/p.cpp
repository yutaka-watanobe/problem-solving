#include<iostream>
#include<string>
#include<climits>

#define MAX 100
#define SHIFT 50
#define END 'X'
using namespace std;

int sizeX, minY, maxY;
char buffer[MAX][MAX];

void work(){
  for ( int i = 0; i < MAX; i++ ){
    for ( int j = 0; j < MAX; j++ ){
      buffer[i][j] = ' ';
    }
  }

  string command; cin >> command;
  sizeX = command.size();
  minY = 0;
  maxY = 0;
  int x, y;

  x = y = 0;


  char pre;

  buffer[ y + SHIFT][0] = command[0];
  pre = command[0];

  for ( int i = 1; i < command.size(); i++ ){
    char ch = command[i];
    
    if ( ch == 'C' ){
      if ( pre == 'R' ) y++;
    } else if ( ch == 'R' ){
      if ( pre == 'R' ) y++;
    } else if ( ch == 'F' ){
      if ( pre == 'C' || pre == 'F' ) y--;
    }

    x++;

    if ( minY > y ) minY = y;
    if ( maxY < y ) maxY = y;

    buffer[y + SHIFT][x] = ch;

    pre = ch;
  }


  for ( int i = minY; i <= maxY; i++ ){
    int j = sizeX + 1;
    while ( buffer[i + SHIFT][j] == ' ' ){
      buffer[i + SHIFT][j] = END;
      j--;
    }
  }

  for ( int i = maxY; i >= minY; i-- ){
    cout << "| ";
    int j = 0;
    while(1){
      if ( buffer[i + SHIFT][j] == END ) break;

      switch( buffer[i + SHIFT][j] ){
      case 'F':
	cout << "\\" ; break;
      case 'C':
	cout << "_" ; break;
      case 'R':
	cout << "/" ; break;
      case ' ':
	cout << " ";
      }

      j++;
    }
    cout << endl;
  }
  cout << "+";
  for ( int j = 0; j < sizeX+2; j++ ) cout << "-";
  cout << endl << endl; 

}



main(){
  int tcase; cin >> tcase;
  for ( int i = 1 ; i <= tcase; i++ ){
    cout << "Case #" << i << ":" << endl;
    work();
  }

}
