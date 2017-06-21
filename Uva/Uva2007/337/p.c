// @JUDGE_ID:  17051CA  337  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#define N 0
#define W 1
#define S 2
#define E 3
#define OVER 0
#define INSERT 1

int read();
void work();
void clear();
void move(int);
void write(char);
bool isDigit(char);

char grid[10][10];

int pi, pj, mode;

void work(){
  int testCase = 1;
  char buff[1000];
  string line;
  char com;
  char ncom;
  int n;

  while(1){
    /* init */
    clear();
    pi = pj = 0;
    mode = OVER;

    cin.getline(buff, 1000);
    n = atoi(buff);

    if( n==0 ) return;

    for(int i=0; i<n; i++){
      cin.getline(buff, 1000);
      line = buff;
      
      for(int s=0; s<line.size(); s++){
	com = line[s];
	if(com=='^'){
	  ncom = line[s+1];
	  if( isdigit(ncom) ){
	    string s1 = line.substr(s+1, 1);
	    string s2 = line.substr(s+2, 1);
	    pi = atoi(s1.c_str());
	    pj = atoi(s2.c_str());
	    s +=2;
	  }else if( ncom=='b'){
	    pj = 0; s++;
	  }else if( ncom=='c'){
	    clear(); s++;
	  }else if( ncom=='d'){
	    move(S); s++;
	  }else if( ncom=='e'){
	    grid[pi][pj] = ' '; s++;
	  }else if( ncom=='h'){
	    pi = pj = 0; s++;
	  }else if( ncom=='i'){
	    mode = INSERT; s++;
	  }else if( ncom=='l'){
	    move(W); s++;
	  }else if( ncom=='o'){
	    mode = OVER; s++;
	  }else if( ncom=='r'){
	    move(E); s++;
	  }else if( ncom=='u'){
	    move(N); s++;
	  }else if( ncom=='^'){
	    write('^'); s++;
	  }
	}else{
	  write(com);
	}
      }
    }

    /* out */
    cout << "Case " << testCase << endl;
    cout << "+----------+" << endl;
    for(int i=0; i<10; i++){
      cout << "|";
      for(int j=0; j<10; j++){
	cout << grid[i][j];
      }
      cout << "|" << endl;
    }
    cout << "+----------+" << endl;

    testCase++;
  }
}

void write(char c){
  if(mode == OVER){
    grid[pi][pj] = c;
  }else if(mode == INSERT){
    for(int j=9; j>=pj+1; j--){
      grid[pi][j] = grid[pi][j-1];
    }
    grid[pi][pj] = c;
  }
  move(E);
}

void move(int d){
  int ii, jj, ni, nj;
  ii = jj = 0;
  if(d==N) ii--;
  if(d==W) jj--;
  if(d==S) ii++;
  if(d==E) jj++;
  ni = ii + pi; nj = jj + pj;
  if( ni >=0 && nj >= 0 && ni < 10 && nj < 10 ){
    pi = ni; pj = nj;
  }
}

bool isDigit(char c){
  if( 48 <= c && c <= 57 ) return true;
  else return false;
}

void clear(){
  for(int i=0; i<10; i++){
    for(int j=0; j<10; j++){
      grid[i][j] = ' ';
    }
  }
}

main(){
  work();
}
// @end_of_source_code
