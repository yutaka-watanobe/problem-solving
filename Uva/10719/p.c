// simple division operation

#include<iostream>
#include<stdio.h>
#include<string>
#define MAX 10002

int k, n;
int buffer[MAX];


void work(){
  int answer[ MAX ];

  for ( int current = 0; current < n; current++ ){
    answer[current] = buffer[current];
    buffer[current+1] += (buffer[current] * k );
  }

  printf("q(x):");
  for ( int i = 0; i < n - 1; i++ ) printf(" %d", answer[i]);
  printf("\nr = %d\n", answer[n-1]);
}

bool read(){
  string line;
  getline( cin, line );
  if ( cin.eof() ) return false;
  k = atoi( line.c_str() );

  getline( cin, line );

  // split
  n = 0;
  string t = "";

  for ( int i = 0; i < line.size(); i++ ){    
    if ( line[i] == ' ' ){
      if ( t != "" ){ 
	buffer[n++] = atoi( t.c_str() ) ;
	t = "";
      }
    }
    else t += line[i];
  }
  if ( t.size() ) buffer[n++] = atoi( t.c_str() );

  return true;
}

main(){
  while ( read() ){
    work();
    printf("\n");
  }
}
