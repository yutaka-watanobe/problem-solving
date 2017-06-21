// @JUDGE_ID:  17051CA  10579  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<vector>
#define MAX 1005
#define MAX_INDEX 5000

using namespace std;

class Fibonacci{
 public:
  short array[ MAX ];

  Fibonacci(){
    for ( int i = 0; i < MAX; i++ ) array[i] = 0;
  }
};

class FibonacciNumbers{
 public:
  
  vector<Fibonacci> F;

  int index;

  bool read(){

    if ( scanf("%d", &index ) == EOF ) return false;
    return true;
    cout << "read " << index << endl;
    if ( cin.eof() ) return false;

    return true;
  }

  void generate(){
    F.resize( MAX_INDEX + 1);
    F[1].array[0] = 1;
    F[2].array[0] = 1;

    int cursor = 0;
    short carry = 0;
    short sum;
    for ( int i = 3; i < MAX_INDEX; i++ ){
      carry = 0;
      for ( int p = 0; p <= cursor; p++ ){
	sum = F[i-1].array[p] + F[i-2].array[p] + carry;
	F[i].array[p] = sum % 10;
	carry = sum / 10;
      }
      if ( carry ){
	cursor++;
	F[i].array[cursor] += carry;
      }
    }
  }

  void work(){
    int sum = 0;
    int p = MAX - 1;
    while (F[index].array[p] == 0 ) p--;

    for ( int i = p; i >= 0; i-- ){
      cout << F[index].array[i];
    }
    cout << endl;

  }

};

main(){
  FibonacciNumbers FN;
  
  FN.generate();

  while ( FN.read() ){
    FN.work();
  }
}

// @end_of_source_code


