/***********
 * dec2bin *
 ***********/
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<vector>

void createBit( int a, vector<int> &bit, int len ){
  bit.clear();
  int next;
  while(a>0 ){
    bit.push_back( a%2 );
    a = a/2;
  }

  while( bit.size() < len ){
    bit.push_back(0);
  }
}

/**
 * Solved
 */
void createBit( int a, vector<int> &bit ){
  bit.clear();
  int next;
  while(a>0 ){
    bit.push_back( a%2 );
    a = a/2;
  }
}

/* 16 char --> int */
int hexCdec( char ch ) {
  if ( isdigit(ch) ) return ch-'0';
  else return (ch - 'A') + 10;
}

main(){
  int in;
  cin >> in;

  vector<int> bit;
  
  createBit( in, bit );
    
  for(int i=0; i<bit.size(); i++){
    cout << bit[i] ;
  }
  cout << endl;
}
