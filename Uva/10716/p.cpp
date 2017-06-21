// Greedy
#include<iostream>
#include<stdio.h>
#include<string>
#include<climits>

using namespace std;

bool visited[26];

void initVisited(){
  for ( int i = 0; i < 26; i++ ) visited[i] = false;
}

int searchPost( string str, char t ){
  int size = str.size();
  for (int i = 0; i < size; i++ ){
    if ( str[size-i-1] == t ) return i;
  }
}

void work(){
  string line; cin >> line;
  int sum = 0;

  if ( line.size() == 1 ) {
    printf("0\n");
    return;
  }

  while ( 1 ){

    int pre, post;
    int cost = INT_MAX;

    initVisited();

    for ( int i = 0; i < line.size(); i++ ){
      if ( visited[ line[i] - 'a' ] ) continue;

      visited[ line[i] - 'a' ] = true;

      int tmp = searchPost( line, line[i] );

      if ( cost > i + tmp ){
	pre = i;
	post = line.size() - tmp -1;
	cost = i + tmp;
      }
    }

    if ( cost + 1 == line.size() && line.size() != 1 ){
      printf("Impossible\n");
      return;
    }
    
    sum += cost;


    line.erase( line.begin() + pre );
    line.erase( line.begin() + (post - 1) );
    
    if ( line.size() <= 1 ) break;
  }

  printf("%d\n", sum);

}

main(){
  int tcase; cin >> tcase;
  for (int i = 0; i < tcase; i++ ){
    work();
  }
}
