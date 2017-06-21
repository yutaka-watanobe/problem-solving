// @JUDGE_ID:  17051CA  10196  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#define WHITE 1
#define BLACK 2

int read();
void work();
bool valid(int, int);
int isKing(int, int);
int check(int, int);

char board[8][8];

int read(){
  string line;
  char c;
  bool flag = false;
  for(int i=0; i<8; i++){
    cin >> line;
    for(int j=0; j<8; j++){
      c = line[j];
      board[i][j] = c;
      if(c!='.') flag = true;
    }
  }
  return flag;
}

int check(int i, int j){
  char c = board[i][j];
  int ni, nj, ii, jj;

  /* Pawn */
  if(c=='p'){
    ni = i+1; nj = j-1;
    if(valid(ni, nj)){
      if(isKing(ni, nj)==WHITE) return BLACK;
    }
    ni = i+1; nj = j+1;
    if(valid(ni, nj)){
      if(isKing(ni, nj)==WHITE) return BLACK;
    }
  }else if(c=='P'){
    ni = i-1; nj = j-1;
    if(valid(ni, nj)){
      if(isKing(ni, nj)==BLACK) return WHITE;
    }
    ni = i-1; nj = j+1;
    if(valid(ni, nj)){
      if(isKing(ni, nj)==BLACK) return WHITE;
    }
  }

  /* Rook */
  if(c=='r' || c=='R' || c=='q' || c=='Q'){
    for(int n=i; n>=0; n--) {
      if(board[n][j]!='.' && n!=i){
	if(isKing(n, j)==WHITE && (c=='r' || c=='q')) return BLACK;
	if(isKing(n, j)==BLACK && (c=='R' || c=='Q')) return WHITE;
	n = -1;
      }
    }
    for(int n=i; n<8; n++) {
      if(board[n][j]!='.' && n!=i){
	if(isKing(n, j)==WHITE && (c=='r' || c=='q')) return BLACK;
	if(isKing(n, j)==BLACK && (c=='R' || c=='Q')) return WHITE;
	n = 8;
      }
    }
    for(int n=j; n<8; n++) {
      if(board[i][n]!='.' && n!=j){
	if(isKing(i, n)==WHITE && (c=='r' || c=='q')) return BLACK;
	if(isKing(i, n)==BLACK && (c=='R' || c=='Q')) return WHITE;
	n = 8;
      }
    }
    for(int n=j; n>=0; n--) {
      if(board[i][n]!='.' && n!=j){
	if(isKing(i, n)==WHITE && (c=='r' || c=='q')) return BLACK;
	if(isKing(i, n)==BLACK && (c=='R' || c=='Q')) return WHITE;
	n = -1;
      }
    }
  }
  

  /* Bishop */
  int m;
  if(c=='b' || c=='B' || c=='q' || c=='Q'){
    m = j;
    for(int n=i; n>=0 && m<8; n--, m++) {
      if(board[n][m]!='.' && n!=i && m!=j){
	if(isKing(n, m)==WHITE && (c=='b' || c=='q')) return BLACK;
	if(isKing(n, m)==BLACK && (c=='B' || c=='Q')) return WHITE;
	n = -1;
      }
    }
    m = j;
    for(int n=i; n<8 && m<8; n++, m++) {
      if(board[n][m]!='.' && n!=i && m!=j){
	if(isKing(n, m)==WHITE && (c=='b' || c=='q')) return BLACK;
	if(isKing(n, m)==BLACK && (c=='B' || c=='Q')) return WHITE;
	n = 8;
      }
    }
    m = j;
    for(int n=i; n<8 && m>=0; n++, m--) {
      if(board[n][m]!='.' && n!=i && m!=j){
	if(isKing(n, m)==WHITE && (c=='b' || c=='q')) return BLACK;
	if(isKing(n, m)==BLACK && (c=='B' || c=='Q')) return WHITE;
	n = 8;
      }
    }
    m = j;
    for(int n=i; n>=0 && m>=0; n--, m--) {
      if(board[n][m]!='.' && n!=i && m!=j){
	if(isKing(n, m)==WHITE && (c=='b' || c=='q')) return BLACK;
	if(isKing(n, m)==BLACK && (c=='B' || c=='Q')) return WHITE;
	n = -1;
      }
    }
  }

  /* King */
  if(c=='k' || c=='K'){
    for(int r=0; r<8; r++){
      ii = jj = 0;
      if(r==0) ii++;
      if(r==1) jj++;
      if(r==2) ii--;
      if(r==3) jj--;
      if(r==4) {ii++; jj++;}
      if(r==5) {ii++; jj--;}
      if(r==6) {ii--; jj++;}
      if(r==7) {ii++; jj--;};
      ni = ii+i; nj = jj+j;
      if(valid(ni, nj)){
	if(isKing(ni, nj)==WHITE && c=='k') return BLACK;
	if(isKing(ni, nj)==BLACK && c=='K') return WHITE;
      }
    }
  }
  
  /* Knight */
  if(c=='n' || c=='N'){
    for(int r=0; r<8; r++){
      ii = jj = 0;
      if(r==0) {ii =-2; jj = 1;}
      if(r==1) {ii =-1; jj = 2;}
      if(r==2) {ii = 1; jj = 2;}
      if(r==3) {ii = 2; jj = 1;}
      if(r==4) {ii = 2; jj =-1;}
      if(r==5) {ii = 1; jj =-2;}
      if(r==6) {ii =-1; jj =-2;}
      if(r==7) {ii =-2; jj =-1;}
      ni = ii+i; nj = jj+j;
      if(valid(ni, nj)){
	if(isKing(ni, nj)==WHITE && c=='n') return BLACK;
	if(isKing(ni, nj)==BLACK && c=='N') return WHITE;
      }
    }
  }
  return 0;
  
}

bool valid(int i, int j){
  if(i>=0 && j>=0 && i<8 && j<8) return true;
  else return false;
}

int isKing(int i, int j){
  if(board[i][j]=='K') return WHITE;
  if(board[i][j]=='k') return BLACK;
  return 0;
}

void work(){
  int v;
  for(int i=0; i<8; i++){
    for(int j=0; j<8; j++){
      v = check(i, j);
      if(v==WHITE){
	cout << "black king is in check." << endl;
	return;
      }else if(v==BLACK){
	cout << "white king is in check." << endl;
	return;
      }
    }
  }
  cout << "no king is in check." << endl;
}

main(){
  for(int i=1; read(); i++){
    cout << "Game #" << i << ": ";
    work();
  }
}
// @end_of_source_code
