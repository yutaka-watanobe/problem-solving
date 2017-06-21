/*********************
 * Towers Of Hanoi ! *
 *********************/
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>

vector<vector<int> > Hanoi;
int n; /* size */
int m; /* limit */
int cnt;
bool lastMove;

/* Print Hanoi */
void printHanoi(){
  if(lastMove) return;
  cout << endl;
  cout << "A=>  ";
  for(int j=0; j<Hanoi[0].size(); j++) cout << " " << Hanoi[0][j];
  cout << endl;
  cout << "B=>  ";
  for(int j=0; j<Hanoi[1].size(); j++) cout << " " << Hanoi[1][j];
  cout << endl;
  cout << "C=>  ";
  for(int j=0; j<Hanoi[2].size(); j++) cout << " " << Hanoi[2][j];
  cout << endl;
}

/* move n, form x to y, use z */
void moveHanoi(int n, int x, int y, int z){
  if(lastMove) return;

  int k;
  if(n==1){
    /* cout << x << " --> " << y << endl; */ 
    k = Hanoi[x][Hanoi[x].size()-1]; 
    Hanoi[x].erase(Hanoi[x].end()-1);
    Hanoi[y].push_back(k);

    if(++cnt>m) lastMove = true;
    printHanoi();
  }else{

    moveHanoi(n-1, x, z, y); /* x --> z, use y */

    /* cout << x << " --> " << y << endl; */
    k = Hanoi[x][Hanoi[x].size()-1]; 
    Hanoi[x].erase(Hanoi[x].end()-1);
    Hanoi[y].push_back(k);
    if(++cnt>m) lastMove = true;

    printHanoi();

    moveHanoi(n-1, z, y, x); /* z --> y, use x */
  }

}

int read(){
  cin >> n >> m;
  if(n==0 && m==0) return 0;
  return 1;
}

void work(){

  Hanoi.clear();
  Hanoi.resize(3);
  Hanoi[0].resize(n);
  for(int i=0; i<n; i++){
    Hanoi[0][i] = n-i;
  }
  cnt = 0;
  lastMove = false;
  printHanoi();
  moveHanoi(n, 0, 2, 1);

}

main(){
  for(int i=1; read(); i++){
    if(i!=1) cout << endl;
    cout << "Problem #" << i << endl;
    cout << endl;
    work();
  }
}
