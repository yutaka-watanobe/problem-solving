// @JUDGE_ID:  17051CA  227  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>

char grid[5][5];
int si, sj;

int read();
void work();
bool move(char);

int read(){
  string line;
  char buf[100];
  char c;
  for(int i=0; i<5; i++){
    cin.getline(buf, 100);
    
    /* check */
    if( i == 0 && buf[0]=='Z'){
      string str = buf;
      if(str.size()==1) return 0;
    }

    for(int j=0; j<5; j++){
      c = buf[j];
      grid[i][j] = c;
      if( c==' '){si = i; sj = j;}
    }
  }
  return 1;
}

void work(){
  string command = "";
  string com;
  char buf[1000];
  while(1){
    cin.getline(buf, 1000);
    com = buf;
    command = command + com;
    if( com[com.size()-1]=='0' ) break;
  }

  for(int i=0; i<command.size()-1; i++){
    if( !move( command[i] ) ){
      cout << "This puzzle has no final configuration." << endl;
      goto end;
    }
  }

  for(int i=0; i<5; i++){
    for(int j=0; j<5; j++){
      if(j!=0) cout << " ";
      cout << grid[i][j]; 
    }
    cout << endl;
  }

 end:;
}

bool move(char com){
  int ii, jj, ni, nj;
  ii = jj = 0;
  if(com=='A') ii--;
  if(com=='B') ii++;
  if(com=='R') jj++;
  if(com=='L') jj--;
  ni = ii+si; nj = jj+sj;
  if(ni >=0 && nj >=0 && ni < 5 && nj < 5){
    grid[si][sj] = grid[ni][nj];
    grid[ni][nj] = ' ';
    si = ni; sj = nj;
    return true;
  }else{
    return false;
  }
}

main(){
  for(int i=1; read(); i++){
    if(i!=1) cout << endl;
    cout << "Puzzle #" << i << ":" << endl;
    work();
  }
}
// @end_of_source_code
