#include<iostream>
#include<vector>
using namespace std;
#define MAX 100

class Guard{
    public:
    vector<pair<int, int> > C; // cycle;
    Guard(){}

    void init(){
	C.clear();
    }
};

Guard  G[MAX];
int n, T;

void simulate(){
    
}

main(){
    int p, c;
    while( cin >> n >> T && n && T ){
	for ( int i = 0; i < n; i++ ){
	    G[i].init();
	    while(1){
		cin >> p;
		if ( p == 0 ) break;
		cin >> c;
		G[i].C.push_back(make_pair(p, c));
	    }
	}
	simulate();
    }
}
