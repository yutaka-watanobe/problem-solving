// @JUDGE_ID:  17051CA  159  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<stl.h>
#include<algorithm>

string h1, v1, h2, v2;


int read(){
  cin >> h1 >> v1 >> h2 >> v2;
  if(h1=="#") return 0;
  return 1;
}

void work(){
  int l1, l2, d1, d2, w1, w2;
  
  l1 = l2 = -1;
  for(int i=0; i<h1.size(); i++){
    for(int j=0; j<v1.size(); j++){
      if(h1[i]==v1[j]){
	l1 = j;
	w1 = i;
	goto next;
      }
    }
  }

  next:;
  
  for(int i=0; i<h2.size(); i++){
    for(int j=0; j<v2.size(); j++){
      if(h2[i]==v2[j]){
	l2 = j;
	w2 = i;
	goto next2;
      }
    }
  }

 next2:;

  if(l1==-1 || l2==-1){
    cout << "Unable to make two crosses" << endl;
    return;
  }

  d1 = v1.size() - l1 -1 ;
  d2 = v2.size() - l2 -1 ;

  w2 = w2 + h1.size() + 3;

  vector<vector<char> > v;
  int h = max(l1, l2);
  int n = max(l1, l2) + 1 + max(d1, d2);
  int m = h1.size() + 3 + h2.size();
  v.resize(n);
  for(int i=0; i<n; i++) v[i].resize(m, ' ');

  for(int j=0; j<h1.size(); j++){
    v[h][j] = h1[j];
  }
  for(int j=0; j<h2.size(); j++){
    v[h][h1.size()+3+j] = h2[j];
  }

  int s = h - l1;
  for(int i=s; i<s+v1.size(); i++){
    v[i][w1] = v1[i-s];
  }

  s = h - l2;
  for(int i=s; i<s+v2.size(); i++){
    v[i][w2] = v2[i-s];
  }

  /* for(int i=0; i<n; i++){ */
/*     for(int j=m-1; j>=0; j--){ */
/*       if(j!=m-1 && v[i][j]!=' '){ */
/* 	v[i][j+1] = '#'; */
/* 	break; */
/*       } */
/*     } */
/*   } */
  
  char c;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      c = v[i][j];
      cout << c;
    /*   if(c=='#' || j==m-1){ */
/* 	cout << endl; */
/* 	break; */
/*       } */
/*       else cout << c; */
    }
    cout << endl;
  }
}

main(){
  for(int i=0; read(); i++){
    if(i!=0) cout << endl;
    work();
  }
}
// @end_of_source_code
