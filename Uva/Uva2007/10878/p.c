#include<iostream>
#include<string>
#include<algorithm>
#include<stdio.h>

using namespace std;

void compute(string line){
  reverse( line.begin(), line.end() );

  int sum = 0;
  int p = 1;
  for ( int i = 1; i <= 9; i++ ){
    if ( line[i] == '.' ) continue;
    if ( line[i] == 'o' ) {
      sum += p;
    }
    p *= 2;
  }

  //  if ( 32 <= sum &&  sum <= 127 ){
    printf("%c", sum);
    //  }

}

main(){
  string line;
  
    getline(cin, line);
  while ( 1 ){
    getline(cin, line);
    if ( line == "___________" ) break;
    compute( line );
  }
  //  cout << endl;

}
