#include<stdio.h>
#include<iostream>
#define N 8
#define SUCCESS 1
#define FAIL 0
#define FREE 1
#define NOT_FREE 0

int row[N], col[N], pos[2*N-1], neg[2*N-1];

void print(){
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      if(row[i]==j) cout << "Q";
      else cout << ".";
    }
    cout << endl;
  }
}

int rec(int i, int j){
  for(int j=0; j<N; j++){
    if(col[j]==FREE && pos[i+j]==FREE && neg[i-j+N-1]==FREE){
      row[i] = j; 
      col[j] = NOT_FREE;
      pos[i+j] = NOT_FREE;
      neg[i-j+N-1] = NOT_FREE;
      if(i>=N-1) return SUCCESS;
      else{
	if(rec(i+1)==SUCCESS) return SUCCESS;
	else{
	  row[i] = -1;
	  col[j] = FREE;
	  pos[i+j] = FREE;
	  neg[i-j+N-1] = FREE;
	}
      }
    }
  }
  return FAIL;
}


main(){
  for(int i=0; i<N; i++) {row[i] = -1; col[i] = FREE;}
  for(int i=0; i<2*N-1; i++){pos[i] = FREE; neg[i] = FREE;}
  for(int j=0; j<N; j++){
    if(rec(0, j)==SUCCESS){
      print();
    }else{
      cout << "No solution is fount." << endl;
    }
  }

}

