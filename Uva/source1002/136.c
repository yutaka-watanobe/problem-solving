// @JUDGE_ID:  17051CA  136  C++
// @begin_of_source_code
#include<stl.h>
typedef unsigned long long ullong;
ullong ugly(int, int, int);
set<ullong> ar;
int compare (const ullong * a, const ullong * b)
{
  return ( *(int*)a - *(int*)b );
}

ullong ugly(int a, int b, int c){
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
  return x;
}

main(){
  ullong u;
  int cnt = 1;
  int N = 30;
  int n, m, l;
  vector<ullong> v;

  for(n=0 ; n <= N ; n++){
    for(m=0 ; m <= N ; m++){
      for(l=0 ; l <= N ; l++){
	u = ugly(n, m, l);
	if(u!=0) ar.insert(u);
	cnt++;
      }
    }
  }
  v.resize(ar.size());
  copy(ar.begin(), ar.end(), v.begin());

  /*qsort (uglyN, 1729, sizeof(ullong), (int(*)(const void*, const void*))compare);*/
  
  cout << "The 1500'th ugly number is " << v[1500-1] << "." << endl;
  
  return 0;
}
// @end_of_source_code
