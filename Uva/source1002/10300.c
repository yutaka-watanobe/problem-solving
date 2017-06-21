// @JUDGE_ID:  17051CA  10300  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream.h>

int read();
void work();

int n;

int read(){
  cin >> n;
}

void work(){
  int p;
  int s, a, f;
  long long sum = 0;
  
  cin >> p;
  for(int i=0; i<p; i++){
    cin >> s >> a >> f;
    sum += s*f;
  }

  cout << sum << endl;
}

main(){
  read();
  for(int i=0; i<n; i++){
    work();
  }
}
// @end_of_source_code
