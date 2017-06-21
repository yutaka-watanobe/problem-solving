/* @JUDGE_ID: 17051CA 10377 C++ "" */
/** Submited via Valladolid ACM Online Judge Submit page v4 **/
/** IP: 163.143.43.50 **/
/** Date: 2002-10-26 03:42:55 **/

#include<stdio.h>
#include<string>
#include<iostream>

#define N 0
#define E 1
#define S 2
#define W 3
#define MAX 65

char grid[MAX][MAX];
int r, c;
int pi, pj, dir;

void rotate(char);

void init(){
  for(int i=0; i<r; i++){
    for(int j=0; j<c; j++){
      grid[i][j] = ' ';
    }
  }
} 

void getV(int &a, int &b, string line){
  string s1, s2;
  s1 = s2 = "";
  bool f = true;
  for(int i=0; i<line.size(); i++){
    char cc = line[i];
    if(cc==' ') {
      f = false;
      continue;
    }
    if(f) s1 += cc;
    else s2 += cc;
  }
  a = atoi(s1.c_str());
  b = atoi(s2.c_str());
}

void work(){
  string line;
  while(1){
    getline(cin, line);
    if(line.size()==0) break;
  }


  getline(cin, line);

  getV(r, c, line);
  
  for(int i=0; i<r; i++){
    getline(cin, line);
    for(int j=0; j<c; j++){
      char cc = line[j];
      grid[i][j] = cc;
    }
  }
  
  getline(cin, line);
  getV(pi, pj, line);
  pi--;
  pj--;
  dir = N;

  char cc;
  
  while(1){
    getline(cin, line);
    for(int i=0; i<line.size(); i++){
      char cc = line[i];
      if(cc=='Q') goto next;
      if(cc=='R'){
	rotate('R');
      }else if(cc=='L'){
	rotate('L');
      }else if(cc=='F'){
	int ni, nj;
	ni = pi;
	nj = pj;
	switch(dir){
	case N:
	  ni = pi -1;
	  break;
	case E:
	  nj = pj + 1;
	  break;
	case S:
	  ni = pi + 1;
	  break;
	case W:
	  nj = pj - 1;
	  break;
	}
	if(ni>=0 && nj>=0 && ni<r && nj<c){
	  if(grid[ni][nj]==' '){
	    pi = ni; pj = nj;
	  }
	}
      }
    }
  }
 next:;
  cout << pi+1 << " " << pj+1 << " ";
  if(dir==N) cout << "N" << endl;
  else if(dir==S) cout << "S" << endl;
  else if(dir==E) cout << "E" << endl;
  else if(dir==W) cout << "W" << endl;
}

void rotate(char c){
  if(c=='R'){
    dir++;
    if(dir==4) dir = N;
  }else if(c=='L'){
    dir--;
    if(dir==-1) dir = W;
  }
}

main(){
  int n;
  char buff[1000];
  cin.getline(buff, 1000);
  n = atoi(buff);
  for(int i=0; i<n; i++){
    if(i!=0) cout << endl;
    work();
  }
}
