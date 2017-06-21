// @JUDGE_ID:  17051CA  202  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>

int n, m;

vector<int> rv;
int ra[3500];

int read(){
  cin >> n >> m;
  if(cin.eof()) return 0;
  return 1;
}

bool isContain(int r, int &index){
  /*
  for(int i=0; i<rv.size(); i++){
    if( rv[i]==r){
      index = i;
      return true;
    }
  }
  return false;
  */
  if( ra[r] > 0 ){
    index = ra[r];
    return true;
  }else{
    return false;
  }
}

void work(){
  int dec, rest, d, r, cnt, index;
  for(int i=0; i<3000; i++) ra[i] = -1;

  dec = n/m;
  rest = n%m;
  
  rv.clear();

  cnt = 0;

  cout << n << "/" << m << " = " << dec << ".";

  r = rest;
  ra[r] = 0;

  vector<int> dv;
  
  while(1){
    cnt++;
    ra[r] = cnt;

    r*=10;
    d = r/m;
    if(d!=0) r = r%m;
    dv.push_back(d);
    if( isContain(r, index)) break;

  }
  
  for(int i=0; i<dv.size(); i++){
    if(i>=50){
	cout << "...";
	break;
    }
    if(i==index-1) cout << "(";
    cout << dv[i];
  }
  
  cout << ")" << endl;
  
  cout << "   " << cnt - index + 1<< " = number of digits in repeating cycle" << endl;
}

main(){
  while(read()){
    work();
    cout << endl;
  }
}
// @end_of_source_code
