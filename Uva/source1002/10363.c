// @ JUDGE_ID  17051CA  10363 C++
#include<stdio.h>
#include<string>
#include<iostream>

void read();
void work();
void judge();

int n;
int match, numX, numO;
char win1, win2;
char grid[3][3];

void work(){
  string line;

  for(int i=0; i<3; i++){
    cin >> line;
    for(int j=0; j<3; j++){
      grid[i][j] = line[j];
    }
  }

  judge();

  /*
  cout << "match " << match << endl;
  cout << "win " << win << endl;
  cout << "numX " << numX << endl;
  cout << "numO " << numO << endl;
  */
  bool valid = true;
  if(match >=3 ){
    valid = false; goto END;
  }else  if(match >=2 ){
    if( win1 != win2 ){ valid = false;    goto END;}
    if( win1 == 'O' ) { valid = false;    goto END;}
    if( numX != numO+1 ) { valid = false; goto END;}
  }else if(match==1){
    if(win1=='X'){
      if(numX != numO+1){ valid = false; goto END;}
    }
    if(win1=='O'){
      if(numX != numO){ valid = false; goto END;}
    }
  }else if(match==0){
    if( !(numX==numO || numX == numO+1) ) {valid = false; goto END;}
  }


 END:;
  if( valid ) cout << "yes" << endl;
  else cout << "no" << endl;
}

void judge(){
  int i, j;
  char c;
  int m;
  numX = 0; numO = 0;
  match = 0;

  for(i=0; i<3; i++){
    c = grid[i][0]; m=0;
    for(j=1; j<3; j++){
      if( c==grid[i][j] ) m++;
    }
    if(m==2 && c != '.'){
      if( match==0 ) win1 = c;
      else if( match==1 ) win2 = c;
      match++; 
    }
  }

  for(j=0; j<3; j++){
    c = grid[0][j]; m=0;
    for(i=1; i<3; i++){
      if( c==grid[i][j] ) m++;
    }
    if(m==2 && c != '.'){
      if( match==0 ) win1 = c;
      else if( match==1 ) win2 = c;
      match++; 
    }
  }

  j = 1;
  c = grid[0][0]; m=0;
  for(i=1; i<3; i++){
    if( c==grid[i][j] ) m++;
    j++;
  }
  if( m==2 && c != '.' ) {
      if( match==0 ) win1 = c;
      else if( match==1 ) win2 = c;
      match++; 
  }
  
  i=1;
  c = grid[2][0]; m= 0;
  for(int j=1; j<3; j++){
    if( c==grid[i][j] ) m++;
    i--;
  }
  if( m==2 && c != '.' ){
    if( match==0 ) win1 = c;
      else if( match==1 ) win2 = c;
    match++; 
  }
  
  /* number */
  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
      if(grid[i][j]=='X') numX++;
      if(grid[i][j]=='O') numO++;
    }
  }

}
main(){
  cin >> n;
  for(int i=0; i<n; i++){
    work();
  }
}

