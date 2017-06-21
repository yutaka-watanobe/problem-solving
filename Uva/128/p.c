// @JUDGE_ID:  17051CA  128  C++
// @begin_of_source_code
/* Number CRC */
/* おそい！ 7.369 sec */
#include<stdio.h>
#include<iostream>
#include<string>
#include<math.h>
#include<stl.h>

string line;
int G = 34943;

int read(){
  getline(cin,  line);
  
    if(line[0]=='#') return 0;

  return 1;
}

void work(){
  int val = 0;
  int ans;
  int p = 1;

  for( int i = line.size()-1; i >= 0; i-- ){
    val += ((int)line[i])*p;
    p *= 256;
    p = p % G;
    val = val % G;
  }
  /* shift */
  val *= 256; val = val%G;
  val *= 256; val = val%G;

  ans = G - val;
  ans = ans % G;

  int first, second;
  first = ans/(16*16);
  second = ans%(16*16);
    
  if ( first < 16 ) cout << "0";
  printf("%X ", first);
  if ( second < 16 ) cout << "0";
  printf("%X", second);
  cout << endl;
}

main(){
  while(read()){
    work();
  }
}
// @end_of_source_code
