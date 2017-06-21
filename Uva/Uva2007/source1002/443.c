// @JUDGE_ID:  17051CA  443  C++
// @begin_of_source_code
#include<stl.h>
#include<stdio.h>
#include<string>

typedef unsigned long long ullong;
ullong ugly(int, int, int, int);
string getSuffix(int);

set<ullong> ar;

ullong humble(int a, int b, int c, int d){
  ullong x = 1;

  for(int i=1; i<=a; i++){
    x *= 2;
  }
  for(int i=1; i<=b; i++){
    x *= 3;
  }
  for(int i=1; i<=c; i++){
    x *= 5;
  }
  for(int i=1; i<=d; i++){
    x *= 7;
  }
  return x;
}

string getSuffix(int in){
  int n, n100;
  n = in%10;
  n100 = in%100;

  if( n == 1 && !( 11 <= n100 && n100 <= 13) ){
    return "st";
  }else if( n == 2 && !( 11 <= n100 && n100 <= 13)  ){
    return "nd";
  }else if( n == 3 && !( 11 <= n100 && n100 <= 13)  ){
    return "rd";
  }else{
    return "th";
  }

}

main(){
  ullong h, hum;
  int N = 30;
  int n, m, l, k;
  vector<ullong> v;
  for(n=0; n <= N; n++){
    for(m=0; m <= N; m++){
      for(l=0; l <= N; l++){
	for(k=0; k <=N; k++){
	  h = humble(n, m, l, k);
	  if(h!=0) ar.insert(h);
	}
      }
    }
  }

  v.resize(ar.size());
  copy(ar.begin(), ar.end(), v.begin());
  
  int in;
  while(1){
    scanf("%d", &in);
    if( in == 0 ) return 0;
    
    cout << "The " << in << getSuffix(in) << " humble number is " << v[in-1] << "." << endl;
    
  }
  return 0;
}
// @end_of_source_code
