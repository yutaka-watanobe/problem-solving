// @JUDGE_ID:  17051CA  10161  C++
// @begin_of_source_code
/* ポイントのサーチ */
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h>

int n;
vector<int> v;
map<int, int> index;

int read(){
  cin >> n;
  return (n==0) ? false : true;
}

void init(){
  int x = 1;
  int f = 2;
  int i = 1;
  while(1){
    if(x>2100000000) break;
    v.push_back(x);
    index[x] = i++;
    x += f;
    f += 2;
  }
}

void work(){
  vector<int>::iterator pos;
  int a[3], in[3];
  pos = lower_bound(v.begin(), v.end(), n);
  
  a[0] = *pos;
  a[1] = *(pos-1);

  in[0] = index[a[0]];
  in[1] = index[a[1]];

  int sub;
  for(int c=0; c<2; c++){
    if(in[c]%2==0){
      if(a[c]-in[c]+1 <= n && n <= a[c]){
	cout << in[c]-(a[c]-n) << " " << in[c] << endl;
	return;
      }
      if(a[c] <= n && n <= a[c]+in[c]-1){
	cout << in[c] << " " << in[c]-(n-a[c]) << endl;
	return;
      }
    }else{
      if(a[c] <= n && n <= a[c]+in[c]-1){
	cout << in[c]-(n-a[c]) << " " << in[c] << endl;
	return;
      }
      if(a[c]-in[c]+1 <=n && n<= a[c]){
	cout << in[c] << " " << in[c]-(a[c]-n) << endl;
	return;
      }
    }
  }


}

main(){
  init();
  while(read()) work();
}
// @end_of_source_code
