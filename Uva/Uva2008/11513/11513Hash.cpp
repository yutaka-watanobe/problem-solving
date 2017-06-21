#include<stdio.h>
#include<queue>
#include<iostream>
#include<map>
#include<algorithm>
//#define SIZE 299977 //36 0.36
//#define SIZE 249943 // 0.34
//#define SIZE 329143
//#define SIZE 319093 // 32
#define SIZE 399149 // 25

//#define SIZE 319147
#define ADD 7
#define M 0
using namespace std;

class State{
    public:
    int v, d, p, c;
    State(){ v = -1; p = 0; d = 0; c = 0;}
    State( int v, int d, int p, int c ): v(v), d(d), p(p), c(c){}
};

int rshift(int v, int p ){
    static const int base[4] = {1, 1000, 1000000, 1000000000};
    p = 3 - p + 1;
    int t, r;
    t = v%base[p] - v%base[p-1];
    v -= t;
    r = t%(base[p-1]*10);
    t -= r;
    t /= 10;
    t += r*100;
    v += t;
    return v;
}

int ushift(int v,  int p ){
  static const int base[4] = {-1, 100000000, 10000000, 1000000};
  int b = base[p];
  int t1, t2, t3;
  t1 = ((v%(b*10))/b)*b; b /= 1000;
  t2 = ((v%(b*10))/b)*b; b /= 1000;
  t3 = ((v%(b*10))/b)*b;b /= 1000;
  v -= (t1 + t2 + t3);
  v += t1/1000000 + (t2+t3)*1000;
  return v;
}

int lshift(int v, int p ){
    static const int base[4] = {1, 1000, 1000000, 1000000000};
    static const int base2[4] = {1, 100, 100000, 100000000};
    p = 3 - p + 1;
    long long t, l;
    t = v%base[p] - v%base[p-1];
    v -= t;
    l = t/(base2[p]);
    t = 10*t%base[p] + l*base[p-1];
    v += t;
    return v;
}

int dshift(int v,  int p ){
    //static const int base[4] = {-1, 100000000, 10000000, 1000000};
    static const int base[4][3] = {{1000000000, 1000000, 1000},
				   {100000000, 100000, 100},
				   {10000000, 10000, 10},
				   {1000000, 1000, 1}};
  int b = base[p][0];
  int t1, t2, t3;
  //  t1 = ((v%(b*10))/b)*b; b = base[p][1];
  //  t2 = ((v%(b*10))/b)*b; b = base[p][2];
  //  t3 = ((v%(b*10))/b)*b; 

  //t1 = v%(b*10) - v%b; b = base[p][1];
  //t2 = v%(b*10) - v%b; b = base[p][2];
  //t3 = v%(b*10) - v%b;

  t1 = v%(base[p-1][0]) - v%base[p][0]; 
  t2 = v%(base[p-1][1]) - v%base[p][1]; 
  t3 = v%(base[p-1][2]) - v%base[p][2];


  v -= (t1 + t2 + t3);
  v += t3*1000000 + (t1+t2)/1000;
  return v;
}

//map<int, State> S;
State H[SIZE];
//int C[SIZE];

//int col, maxv;

int getIndex( int v ){
  int i = (v) % SIZE;
  //  C[i]++;
    if ( H[i].v == v ){
	return i;
    } else if ( H[i].v == -1 ) {
	H[i].v = v; return i;

    } else {
	//	col++;
	int d = 1;
	while(1){
	    i = (v+d)%SIZE;
	    if ( H[i].v == v || H[i].v == -1 ){
		H[i].v = v;
		return i;
	    }
	    //	    col++;
	    d+=ADD;
	}
    }
}

int getIndexALL(int v ){
  static const long long base[10] = {1000000000, 100000000, 10000000, 1000000, 100000, 10000, 1000, 100, 10, 1};
  static const long long fact[9] = {362880, 40320, 5040, 720, 120, 24, 6, 2, 1};

  v -= 111111111;
  int tmp = v;
  long long index = 0;
  int p = 1;
  for ( int i = 0; i < 9; i++ ){
    long long t = v%base[i]/base[i+1];
    index += t*fact[p++];
    for ( int j = i+1; j < 9; j++ ){
      long long t2 = v%base[j]/base[j+1];
      if ( t < t2 ) v -= base[j+1];
    }
  }
  //  cout << tmp <<  " " << index << endl;
  return (int)index;

}

void init(){
    for ( int i = 0; i < SIZE; i++ ) {
    	H[i].v = -1;
    }

    int g = 123456789;
    //    queue<int> Q;
    int Q[200000];
    int head, tail;
    head = tail = 0;

    //    S[g].d = 0;
    //    S[g].p = -1;
    H[getIndex(g)] = State(g, 0, -1, -1);

    //Q.push(g);
    Q[tail++] = g;

    int u, v, i;
    //    int cnt = 1;

    //    while(!Q.empty()){
    while(head != tail){
	//u = Q.front(); Q.pop();
	u = Q[head++];

	for ( int p = 1; p <= 3; p++ ){
	    /*
	    v = lshift( u, p );
	    if ( S[v].p == 0 ) {
		S[v] = State(S[u].d+1, u, p);
		Q.push(v);
		cnt++;
	    }
	    v = dshift( u, p );
	    if ( S[v].p == 0 ) {
		S[v] = State(S[u].d+1, u, p+3);
		Q.push(v);
		cnt++;
		}*/
	    v = lshift( u, p );
	    i = getIndex(v);
	    if ( H[i].p == 0 ) {
		H[i] = State(v, H[getIndex(u)].d+1, u, p);
		//Q.push(v);
		Q[tail++] = v;
		//		cnt++;
	    }
	    v = dshift( u, p );
	    i = getIndex(v);
	    if ( H[i].p == 0 ) {
		H[i] = State(v, H[getIndex(u)].d+1, u, p+3);
		//Q.push(v);
		Q[tail++] = v;
		//		cnt++;
	    }
	}
    }
    //    cout << cnt << endl;
}

void printPath(int v){
    if ( H[getIndex(v)].p == -1 ) return;
    int com = H[getIndex(v)].c;
    if ( com > 3 ) printf("V%d", com-3);
    else printf("H%d", com);
    printPath(H[getIndex(v)].p);
}

int main(){
  //  getIndex(123456789);
  //  return 0;
    //        col = 0;
    //    maxv = 0;
    //    for ( int i = 0; i < SIZE; i++ ) C[i] = 0;

    init();

    //    for ( int i = 0; i < SIZE; i++ ) {
      //      cout << i << " " << C[i] << endl;
    //      maxv = max( maxv, C[i] );
    //    }

    //        cout << "col = " << col << endl;
    //cout << "maxv = " << maxv << endl;
    int s, x;

    while(1){
	scanf("%d", &x);
	if ( x == 0 ) break;
	int p = 100000000;
	s = 0;
	s += x*p;
	p /= 10;
	for ( int i = 1; i < 9; i++ ){
	    scanf("%d", &x);
	    s += x*p;
	    p /= 10;
	}
	int cost = H[getIndex(s)].d;
	if ( s == 123456789 ) printf("0\n");
	else if ( cost == 0 ) printf("Not solvable\n");
	else {
	    printf("%d ", H[getIndex(s)].d);
	    printPath(s);
	    printf("\n");
	}
    }

    return 0;
}

