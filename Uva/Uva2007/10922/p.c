// recursive + convertion

#include<stdio.h>
#include<iostream>
#include<string>
#define MAX 1001

int buffer[MAX];
int size;

string itoa(int x){
  char a[20];
  
  sprintf(a, "%d", x);

  return string(a);
}

int recursive( int value, int depth ){
  if ( value == 9 ) return depth;

  string svalue = itoa(value);

  int sum = 0;
  for ( int i = 0; i < svalue.size(); i++ ) sum += (svalue[i] - '0');

  return recursive( sum, depth+1 );
}

void compute(){

  // output;
  for ( int i = 0; i < size; i++ ) printf("%d", buffer[i]);

  int sum = 0;
  for ( int i = 0; i < size; i++ ){
    sum += buffer[i];
  }

  if ( sum % 9 == 0 ){
    int depth = recursive( sum, 1 );
    printf(" is a multiple of 9 and has 9-degree %d.\n", depth);
  } else {
    printf(" is not a multiple of 9.\n");
  }
}

bool read(){
  char ch;
  size = 0;
  while (1){
    scanf("%c", &ch);
    if ( ch == '\n' ) break;
    buffer[size++] = ch - '0';
  }
  
  if ( size == 1 && buffer[0] == 0 ) return false;
  return true;
}

main(){
  while ( read() ){
    compute();
  }
}
