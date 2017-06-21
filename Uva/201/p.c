// @JUDGE_ID:  17051CA  201  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<stl.h>

int n, m;

int read(){
  cin >> n >> m;
  if(cin.eof()) return 0;
  return 1;
}

void work(){
  map<pair<int, int>, bool> edge;
  char c;
  int i, j, t;
  pair<int, int> p;
  for(int a=0; a<m; a++){
    cin >> c >> i >> j;
    i--; j--;
    if(c=='H'){
      p.first = i*n + j;
      p.second = i*n + j + 1;
      //cout << p.first << " " << p.second << endl;
    }else{
      t = i;
      i = j;
      j = t;
      p.first = i*n + j;
      p.second = i*n + j + n;
      //cout << p.first << " " << p.second << endl;
    }
    edge[p] = true;
  }

  vector<int> v;
  v.resize(12, 0);

  for(int a=0; a<n-1; a++){
    for(int b=a+1; b<n; b++){
      for(int c=0; c<n-1; c++){
	for(int d=c+1; d<n; d++){
	  if(b-a==d-c){
	    /* check */
	    for(int k=a; k<b; k++){
	      p.first = k*n + c;
	      p.second = (k+1)*n + c;
	      if(!edge[p]) goto next;
	    }
	    for(int k=a; k<b; k++){
	      p.first = k*n + d;
	      p.second = (k+1)*n + d;
	      if(!edge[p]) goto next;
	    }
	    for(int k=c; k<d; k++){
	      p.first = a*n + k;
	      p.second = a*n + k + 1;
	      if(!edge[p]) goto next;
	    }
	    for(int k=c; k<d; k++){
	      p.first = b*n + k;
	      p.second = b*n + k + 1;
	      if(!edge[p]) goto next;
	    }
	    v[b-a]++;
	  }
	next:;
	}
      }
    }
  }

  bool empty = true;

  for(int i=0; i<v.size(); i++){
    if(v[i]>0){
      cout << v[i] << " square (s) of size " << i << endl;
      empty = false;
    }
  }
  if(empty) cout << "No completed squares can be found." << endl;

}

main(){
  for(int i=1; read(); i++){
    if(i!=1){
      cout << endl;
      cout << "**********************************" << endl;
      cout << endl;
    }
    cout << "Problem #" << i << endl;
    cout << endl;
    work();
  }
}
// @end_of_source_code
