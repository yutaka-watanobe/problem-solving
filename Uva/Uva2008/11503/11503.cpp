#include<iostream>
#include<stdio.h>
#include<map>

using namespace std;

#define MAX 100001
class DisjointSet{
    public:
    int rank[MAX], p[MAX];

    DisjointSet(){}
    DisjointSet(int size){
	fill(rank, rank + size, 0);
	fill(p, p + size, 0);
    }
    
    void makeSet(int x){
	p[x] = x;
	rank[x] = 0;
    }
    
    void merge(int x, int y){
	link(findSet(x), findSet(y));
    }
    
    void link(int x, int y){
	if(rank[x] > rank[y]){
	    p[y] = x;
	}else{   
	    p[x] = y;
	    if(rank[x] == rank[y]){
		rank[y] = rank[y] + 1;
	    }
	}
    }
    
    int findSet(int x){
	if(x != p[x]){
	    p[x] = findSet(p[x]);
	}
	return p[x];
    }
};

map<string, int> S_I;
int T[MAX];
DisjointSet dset;

int size;

int getIndex(string str){
    if ( S_I.find(str) == S_I.end() ){
	S_I[str] = size++;
    }
    return S_I[str];
}

void simulate(){
    S_I = map<string, int>();
    int f; cin >> f;
    dset = DisjointSet(f+1);
    size = 0;
    for ( int i = 0; i < f+1; i++ ) {
	dset.makeSet(i);
	T[i] = 1;
    }

    string name1, name2;

    int x, y, fx, fy;
    char s1[20], s2[20];
    for ( int i = 0; i < f; i++ ){
	//	cin >> name1 >> name2;
	scanf("%s", s1);
	scanf("%s", s2);
	//	x = getIndex(name1);
	//	y = getIndex(name2);
	x = getIndex( string(s1) );
	y = getIndex( string(s2) );
	fx = dset.findSet(x);
	fy = dset.findSet(y);
	if ( fx == fy ) {
	    printf("%d\n", T[fx]);
	    continue;
	}

	int sum = T[fx] + T[fy];
	dset.merge(fx, fy);
	int id = dset.findSet(fx);
	T[id] = sum;
	printf("%d\n", T[id]);
    }

}

int main(){
    int tcase; cin >> tcase;
    for ( int i = 0; i < tcase; i++ ){
	simulate();
    }
    return 0;
}
