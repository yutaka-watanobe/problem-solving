#include<iostream>
#include<vector>
#include<stdio.h>
#include<string>
#include<stdlib.h>
#define MAX 10002

using namespace std;

class Target{
 public:
  char buffer[102];
  Target(){}
};

char line[MAX];
Target targets[52];

int size;
int ntarget;

int match( int cursor, char *target ){
  int tsize = strlen(target);
  if ( cursor - tsize < 0 ) return -1;

  bool m = true;
  for ( int i = 0; i < tsize; i++ ){
    if ( target[ tsize - i - 1] != line[ cursor - i   -1] ){
      m = false;
      break;
    }
  }

  if ( m ){
      return cursor - tsize;
  }

  // reverse
  for ( int i = 0; i < tsize; i++ ){
    if ( target[ i ] != line[ cursor - i   -1] ) return -1;
  }

  return cursor - tsize;
}


void work(){

  int n;

  scanf("%s", &line);
  scanf("%d", &ntarget);

  size = strlen(line);
  
  for ( int i = 0; i < ntarget; i++ ) {
    Target target;
    scanf("%s", &target.buffer);
    targets[i] = target;
  }
  

  int cost[ MAX ];
  for ( int i = 0; i <= size; i++ ) cost[i] = INT_MAX;
  
  cost[0] = 0;

  for ( int cursor = 1; cursor <= size; cursor++ ){
    for ( int i = 0; i < ntarget; i++ ){
      char *target = targets[i].buffer;

      int pos = match( cursor, target );
      if ( pos != -1 ){
	if ( cost[pos] != INT_MAX ){
	  cost[cursor] = min( cost[cursor], cost[pos] + 1);
	}
      }
    }
    /*
    for ( int i = 0; i < size; i++ ){
      int x = cost[i];
      if ( x == INT_MAX ) cout << "x ";
      else cout << x << " ";
    }
    cout << endl;
    */
  }

  if ( cost[ size ] == INT_MAX ) printf("Not possible.\n");
  else {
    printf("%d.\n", cost[size]);
  }
}

main(){
  int tcase;
  scanf("%d", &tcase);
  for ( int i = 1; i <= tcase; i++ ){
    printf("Set %d: ", i);
    work();
  }
}
