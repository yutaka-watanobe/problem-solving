// @JUDGE_ID:  17051CA  255  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream.h>
#include<vector>

int read();
void work();

int k, q1, q2;

class point {
 public:
  int x, y;
  point(){}
  point(int i){
    x = i/8;
    y = i%8;
  }
};

int read(){
  cin >> k >> q1 >> q2;
  if( cin.eof() ) return 0;
  else return 1;
}

void work(){
  point pk = point(k);
  point pq1 = point(q1);
  point pq2 = point(q2);

  if( k == q1 ){
    cout << "Illegal state" << endl;
  }else if( q1 == q2 || pq1.x != pq2.x && pq1.y != pq2.y ||
	  pq1.x == pk.x && ((pq1.y<pk.y && pk.y<=pq2.y) || (pq2.y<=pk.y && pk.y<pq1.y)) ||
	  pq1.y == pk.y && ((pq1.x < pk.x && pk.x <= pq2.x) || (pq2.x <= pk.x && pk.x < pq1.x))){
    cout << "Illegal move" << endl;
  } 
  else if(pq2.x == pk.x && (pq2.y+1 == pk.y || pq2.y-1 == pk.y) ||
          pq2.y == pk.y && (pq2.x+1 == pk.x || pq2.x-1 == pk.x)){
    cout << "Move not allowed" << endl;
  }
  else if( k==0 && q2==9 || k==7 && q2==14 || k==56 && q2==49 || k==63 && q2==54 ){
    cout << "Stop" << endl;
  }
  else {
    cout << "Continue" << endl;
  }
}

main(){
  while( read() ){
    work();
  }
}
// @end_of_source_code
