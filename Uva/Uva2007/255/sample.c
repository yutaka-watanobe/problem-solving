#include <stdio.h>
#include <stl.h>

class point {
 public:
  int x, y;

  point(){}
  point(int i): x(i/8), y(i%8){}
  bool operator==(int i) const {
    return i==x*8+y;
  }
  bool operator==(const point &p)const{
    return x==p.x && y==p.y;
  }
};

point q1, q2, k;

int read();
void work();

main(){
  while(read()){
    work();
  }
}

void work(){
  if(q1==k){ 
    cout << "Illegal state" << endl;
  }
  else if(q1==q2 || q1.x!=q2.x && q1.y!=q2.y ||
	  q1.x==k.x && ((q1.y<k.y && k.y<=q2.y) || (q2.y<=k.y && k.y<q1.y)) ||
	  q1.y==k.y && ((q1.x<k.x && k.x<=q2.x) || (q2.x<=k.x && k.x<q1.x))){
    cout << "Illegal move" << endl;
  }
  else if(q2.x==k.x && (q2.y+1==k.y || q2.y-1==k.y) ||
	  q2.y==k.y && (q2.x+1==k.x || q2.x-1==k.x)){
    cout << "Move not allowed" << endl;
  }
  else if(k==0 && q2==9 || k==7 && q2==14 ||
	  k==56 && q2==49 || k==63 && q2==54){
    cout << "Stop" << endl;
  }
  else {
    cout << "Continue" << endl;
  }
}

int read(){
  int x, y, z;

  cin >> x >> y >> z;
  if(cin.eof()) return 0;


  k = point(x);
  q1 = point(y);
  q2 = point(z);

  return 1;
}
