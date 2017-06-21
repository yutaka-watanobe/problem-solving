#include <stdio.h>
#include <stl.h>
#include <string>

int B[10][10], TB[10][10];
int M;
string name;

int read();
void work();

main(){
  while(read()){
    work();
  }
}

void press(int x, int y){
  if(x>0) TB[x-1][y] = !TB[x-1][y];
  if(x<9) TB[x+1][y] = !TB[x+1][y];
  if(y>0) TB[x][y-1] = !TB[x][y-1];
  if(y<9) TB[x][y+1] = !TB[x][y+1];
  TB[x][y] = !TB[x][y];
}

void work(){
  M = INT_MAX;
  int m;

  for(int b=0; b<1024; b++){
    m = 0;
    for(int i=0; i<10; i++){
      for(int j=0; j<10; j++) TB[i][j] = B[i][j];
    }

    for(int t=b, j=0; t; j++, t>>=1){
      if(t&1){
	press(0, j);
	m++;
	if(m>=M) goto next;
      }
    }

    for(int i=1; i<10; i++){
      for(int j=0; j<10; j++){
	if(TB[i-1][j]){
	  press(i, j);
	  m++;
	  if(m>=M) goto next;
	}
      }
    }

    for(int j=0; j<10; j++){
      if(TB[9][j]) goto next;
    }
    M = min(m, M);
    /*
    cout << m << endl;
    for(int i=0; i<10; i++){
      for(int j=0; j<10; j++) cout << TB[i][j];
      cout << endl;
    }
    */
  next:;
  }
  if(M==INT_MAX) M = -1;
  cout << name << " " << M << endl;
}

int read(){
  cin >> name;
  if(name=="end") return 0;

  char ch;

  for(int i=0; i<10; i++){
    for(int j=0; j<10; j++){
      cin >> ch;
      B[i][j] = ch=='O';
    }
  }
  return 1;
}
