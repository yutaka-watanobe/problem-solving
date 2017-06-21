// @JUDGE_ID:  17051CA  466  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>

int n;
char original[15][15];
char modified[15][15];
char transform[15][15];
char temp[15][15];

int type;

int read(){
  string line;
  cin >> n;
  if(cin.eof()) return 0;

  for(int i=0; i<n; i++){
    cin >> line;
    for(int j=0; j<n; j++){
      original[i][j] = line[j];
    }
    cin >> line;
    for(int j=0; j<n; j++){
      transform[i][j] = line[j];
    }
  }

  return 1;
}

bool equal(){
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if( modified[i][j] != transform[i][j] ) return false;
    }
  }
  return true;
}

void rotate90(){
  temp = modified;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      modified[j][n-i-1] = temp[i][j];
    }
  }
}

void reflect(){
  temp = modified;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      modified[n-i-1][j] = temp[i][j];
    }
  }
}

void work(){
  type = 0;

  modified = original;
  if( equal() ){ type = 1; goto next; }

  rotate90();
  if( equal() ){ type = 2; goto next; }

  rotate90();
  if( equal() ){ type = 3; goto next; }
  
  rotate90(); 
  if( equal() ){ type = 4; goto next; }

  modified = original;

  reflect();
  if( equal() ){ type = 5; goto next; }

  rotate90(); 
  if( equal() ){ type = 6; goto next; }

  rotate90(); 
  if( equal() ){ type = 7; goto next; }

  rotate90(); 
  if( equal() ){ type = 8; goto next; }

  type = 9;

 next:;

  switch(type){
  case 1:
    cout << "preserved.";
    break;
  case 2:
    cout << "rotated 90 degrees.";
    break;
  case 3:
    cout << "rotated 180 degrees.";
    break;
  case 4:
    cout << "rotated 270 degrees.";
    break;
  case 5:
    cout << "reflected vertically.";
    break;
  case 6:
    cout << "reflected vertically and rotated 90 degrees.";
    break;
  case 7:
    cout << "reflected vertically and rotated 180 degrees.";
    break;
  case 8:
    cout << "reflected vertically and rotated 270 degrees.";
    break;
  case 9:
    cout << "improperly transformed.";
  }
}

main(){
  for(int i=1; read(); i++){
    cout << "Pattern " << i << " was ";
    work();
    cout << endl;
  }
}
// @end_of_source_code
