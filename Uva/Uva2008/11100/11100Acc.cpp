#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;
#define MAX 10000
typedef vector<int> vint;

int bugs[10000001];
int n, size;

class scmp {
public:
  bool operator()(const vint& a,const vint &b){
    return a.size() < b.size();
  }
};

void compute(){
    multiset<vint, scmp> pieces;
    for ( int i = 0; i < 1000001; i++ ){
	if ( !bugs[i] ) continue;
	int nn = min( bugs[i],(int)pieces.size() );
	vector<vint> nextp(nn);
	for ( int j = 0; j < nn; j++ ){
	    nextp[j] = *pieces.begin(); pieces.erase(pieces.begin());
	    nextp[j].push_back(i);
	}
	for ( int j = 0; j < nn; j++ ){
	    pieces.insert(nextp[j]);
	}
	for ( int j = 0; j < bugs[i] - nn; j++ ){
	    vint p;
	    p.push_back(i);
	    pieces.insert(p);
	}
    }

    /*
    printf("%d\n", pieces.size());
    for ( multiset<Piece>::iterator it = pieces.begin(); it != pieces.end(); it++ ){
	Piece p = *it;
	for ( int i = 0; i < p.size; i++ ){
	    if (i) printf(" ");
	    printf("%d", p.buffer[i]);
	}
	printf("\n");
    }
    */
    
    cout << pieces.size() << endl;
    int ss=pieces.size();
    for ( int i = 0; i < ss; i++ ){
	vint o=*pieces.begin();
	for ( int j = 0; j < o.size(); j++ ){
	    cout << o[j] << (j+1==o.size() ? '\n' : ' ');
	}
	pieces.erase(pieces.begin());
    }

    
}

void initialize(){
    int x;
    for ( int i = 0; i < 1000001; i++ ) bugs[i] = 0;
    for ( int i = 0; i < n; i++ ){
	scanf("%d", &x); bugs[x]++;
    }
}

int main(){
    while(1){
	scanf("%d", &n);
	if ( n == 0 ) break;
	initialize();
	compute();
    }
    return 0;
}
