#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<cassert>
using namespace std;
#define MAX 100
#define rep(i, n) for ( int i = 0; i < n; i++ )

class Button{
public:
  int x1, y1, x2, y2;
  string target;
  Button(int x1, int y1, int x2, int y2, string target):x1(x1), y1(y1), x2(x2), y2(y2), target(target){}
};

class Page{
public:
  string name;
  int H, W;
  vector<Button> B;
  Page(string name="", int W=0, int H=0):name(name), W(W), H(H){}

  string click(int x, int y){
    rep(i, B.size()){
      Button b = B[i];

      if ( b.x1 <= x && x <= b.x2 &&
	   b.y1 <= y && y <= b.y2 ) {
	//assert( b.x1 != x );
	//assert( b.y1 != y );
	//assert( b.x2 != x );
	//assert( b.y2 != y );
	return b.target;
      }
    }
    return name;
  }

  bool over(int a, int b, int c, int d ){
    int p1, p2, p3, p4;
    if ( a <= c ){
      p1 = a; p2 = b; p3 = c; p4 = d;
    } else {
      p1 = c; p2 = d; p3 = a; p4 = b;
    }
    return  p2 >= p3;
  }
  void buttonCheck(){
    for ( int i = 0; i < (int)(B.size())-1; i++ ){
      for ( int j = i+1; j < B.size(); j++ ){
	Button b1 = B[i];
	Button b2 = B[j];
	
	if ( over(b1.x1, b1.x2, b2.x1, b2.x2) &&
	     over(b1.y1, b1.y2, b2.y1, b2.y2) ){
	  assert(false);
	}
	
      }
    }
  }
};

int n, H, W;
Page P[MAX];
map<string, int> PI;


void simulate(){
  int q; cin >> q;
  string com, target;
  int history[10000], x, y, cur, top, forward;
  top = forward = 0;

  cur = 0;
  history[top] = cur;

  rep(p, q){
    cin >> com;
    if ( com == "click" ){
      cin >> x >> y;
      assert( 1 <= x && x <= W );
      assert( 1 <= y && y <= H );
      target = P[cur].click(x, y);
      assert( PI.find(target) != PI.end());
      if ( target != P[cur].name ){
	cur = PI[target];
	history[++top] = PI[target];
	forward = top;
      }
    } else if ( com == "forward" ){
      if ( top < forward){
	top++;
	cur = history[top];
      }
    } else if ( com == "back"){
      if ( top > 0 ){
	top--;
	cur = history[top];
      }
    } else if ( com == "show" ){
      cout << P[cur].name << endl;
    } else assert(false);

  }
}

main(){
  string name, target;
  int  m, x1, y1, x2, y2;
  while( cin >> n && n ){
    cin >> W >> H;
    assert( 1 <= n && n <= 100 );
    rep(i, n){
      cin >> name >> m;
      assert( name.size() <= 20 );
      char h = name[0];
      assert( !('0' <= h && h <= '9') );
      assert( m <= 100);
      P[i] = Page(name, W, H);
      rep(j, m){
	cin >> x1 >> y1 >> x2 >> y2 >> target;
	assert( 0 <= x1 && x1 <= W);
	assert( 0 <= x2 && x2 <= W);
	assert( 0 <= y1 && y1 <= H);
	assert( 0 <= y2 && y2 <= H);
	P[i].B.push_back(Button(x1, y1, x2, y2, target));
      }
      PI[name] = i;

      P[i].buttonCheck();
    }
    simulate();
  }
}
