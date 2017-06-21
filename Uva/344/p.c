// @JUDGE_ID:  17051CA  344  C++
// @begin_of_source_code
#include<stdio.h>
#include<vector>
#include<string>

void work(int);
void init();

vector<vector<string> > v;

void init(){
  vector<string> v0, v1, v2, v3, v4, v5, v6, v7, v8, v9;
  v0.resize(11);
  v1.resize(11);
  v2.resize(11);
  v3.resize(11);
  v4.resize(11);
  v5.resize(11);
  v6.resize(11);
  v7.resize(11);
  v8.resize(11);
  v9.resize(11);
  v0[1] = "i";
  v0[2] = "ii";
  v0[3] = "iii";
  v0[4] = "iv";
  v0[5] = "v";
  v0[6] = "vi";
  v0[7] = "vii";
  v0[8] = "viii";
  v0[9] = "ix";
  v0[10] = "x";

  for(int i=1; i<=10; i++){
    v1[i] = "x" + v0[i];
    v2[i] = "xx" + v0[i];
    v3[i] = "xxx" + v0[i];
    v4[i] = "xl" + v0[i];
    v5[i] = "l" + v0[i];
    v6[i] = "lx" + v0[i];
    v7[i] = "lxx" + v0[i];
    v8[i] = "lxxx" + v0[i];
    v9[i] = "xc" + v0[i];
  }
  v3[10] = "xl";
  v4[10] = "l";
  v8[10] = "xc";
  v9[10] = "c";
  v.push_back(v0);
  v.push_back(v1);
  v.push_back(v2);
  v.push_back(v3);
  v.push_back(v4);
  v.push_back(v5);
  v.push_back(v6);
  v.push_back(v7);
  v.push_back(v8);
  v.push_back(v9);
}

void work(int n){
  int i, V, x, l, c;
  string line;
  int count = 0;
  i = V = x = l = c = 0;

  for(int a=0; a<=9; a++){
    for(int b=1; b<=10; b++){
      line = v[a][b];
      count++;
      for(int s=0; s<line.size(); s++){
	char d = line[s];
	if(d=='i') i++;
	if(d=='v') V++;
	if(d=='x') x++;
	if(d=='l') l++;
	if(d=='c') c++;
      }
      if( count==n ) goto next;
    }
  }

 next:;
  cout << n << ": " << i <<" i, " << V << " v, " << x << " x, " << l << " l, " << c << " c" << endl;
}
main(){
  int n;
  init();
  while(1){
    cin >> n;
    if( n==0 ) break;
    work(n);
  }
}
// @end_of_source_code
