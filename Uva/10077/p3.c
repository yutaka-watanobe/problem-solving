// @JUDGE_ID:  17051CA  10077  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<queue>

class Stern{
 public:
  int lm, ln, rm, rn;
  vector<char> p;
  Stern(){}
  Stern(int a, int b, int c, int d){
    lm = a; ln = b; rm = c; rn = d;
    p.clear();
  }
};

int read();
void work();
void rec(Stern stern);
int M, N;

int read(){
  cin >> M >> N;
  if(M==1&&N==1) return 0;
  return 1;
}

void work(){
  Stern stern;
  if( M > N ) { 
    stern = Stern(1, 1, 1, 0 );
    stern.p.push_back('R');
    rec(stern);
  }else{
    stern = Stern(0, 1, 1, 1);
    stern.p.push_back('L');
    rec(stern);
  }
}

void rec(Stern stern){
  
  queue<Stern> q;
  q.push(stern);
  Stern u, l, r;
  
  vector<char> tp;

  while( !q.empty() ){
    u = q.front(), q.pop();
    
    if(u.lm+u.rm == M && u.ln+u.rn == N ){
      for(int i=0; i<u.p.size(); i++) cout << u.p[i];
      cout << endl;
      return;
    }
    /* to left */
    tp = u.p; tp.push_back('L');
    l = Stern(u.lm, u.ln, u.lm+u.rm, u.ln+u.rn);
    l.p = tp;
    q.push(l);
    /* to right */
    tp = u.p; tp.push_back('R');
    r = Stern(u.lm+u.rm, u.ln+u.rn, u.rm, u.rn);
    r.p = tp;
    q.push(r);
  }
}

main(){
  while(read()){
    work();
  }
}
// @end_of_source_code
