// @JUDGE_ID:  17051CA  10412  C++
// @begin_of_source_code
/* シミュレーション グリッド＆ジオメトリ */
#include<stdio.h>
#include<stl.h>
#include<cmath>
#include<float.h>
#include<string>
#include<slist>

class tree{
 public:
  int x;
  int h;
  vector<int> leaf;

  tree(){}
  tree(int xx, int hh, vector<int> l){
    x = xx;
    h = hh;
    leaf = l;
  }

  int height(){return h;}

};

int n, m, k;
vector<tree> T;

void read(){
  cin >> n >> m >> k;
  T.clear();
  int h;
  int d = 0;
  for(int i=0; i<n; i++){
    cin >> h;
    vector<int> l;
    l.resize(h);
    for(int j=0; j<h ;j++){
      cin >> l[j];
    }
    
    if(i==0){
      d = *max_element(l.begin(), l.end());
    }

    tree t = tree(d+m*i, h, l);
    T.push_back(t);
  }
}

void work(){

  int total = 0;
  int d;
  
  for(int t=0; t<(int)T.size()-1; t++){
    d = INT_MAX;
    for(int i=0; i<T[t].h; i++){
//      if(T[t].leaf[i] <= 0) continue;
      for(int j=0; j<T[t+1].h; j++){
	//if(T[t+1].leaf[j] <=0 )continue;

	if(i==j){
	  if(m - (T[t].leaf[i]+T[t+1].leaf[j]) <= k){
	    d = min(d, T[t].leaf[i]+T[t+1].leaf[j]);
//	    cout << t << " " << i << " " << j << endl;
	  }
	} else{
	  int x1, y1, x2, y2;
	  x1 = T[t].leaf[i];
	  y1 = i;
	  x2 = m - T[t+1].leaf[j];
	  y2 = j;

	  double dis2 = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
	  bool in = true;

	  if( !(dis2 <= k*k ) ) goto next;

	  int W, H, L, X;
	  if(i<j){
	    W = x2 - x1;
	    H = j - i;
	    for(int a=i+1; a<=j-1; a++){
	      if(!(0<=a && a < T[t].h)) continue;
	      X = T[t].leaf[a];
	      if((a-i)*W+x1*H <= X*H) goto next;
	    }
	    for(int b=j-1; b>=i+1; b--){
	      if(!(0<=b && b < T[t+1].h)) continue;
	      X = m - T[t+1].leaf[b];
	      if(x2*H-(j-b)*W >= X*H) goto next;
	    }
	  }else if(i>j){
	    W = x2 - x1;
	    H = i - j;
	    for(int a=i-1; a>=j+1; a--){
	      if(!(0<=a && a < T[t].h)) continue;
	      X = T[t].leaf[a];
	      if((i-a)*W + x1*H <= X*H) goto next;
	    }
	    for(int b=j+1; b<=i-1; b++){
	      if(!(0<=b && b < T[t+1].h)) continue;
	      X = m - T[t+1].leaf[b];
	      if(x2*H-(b-j)*W >= X*H ) goto next;
	    }
	  }

	  in = false;
	next:;
	  if(!in){
	    d = min(d,  T[t].leaf[i]+T[t+1].leaf[j]);
	    //cout << t << " " << i << " " << j << endl;
	  }
	}
	
      }
    }
    if(d==INT_MAX) d = m;
    total += d;
  }
  
  cout << total << endl;

}

int main(){
  int t;
  cin >> t;
  for(int i=0; i<t; i++){
    read();
    work();
  }
  return 0;
}
// @end_of_source_code
