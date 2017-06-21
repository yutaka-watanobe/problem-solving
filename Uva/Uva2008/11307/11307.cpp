#include<stdio.h>
#include<vector>
using namespace std;
#define MAX 10000
#define CMAX 6 // we need 6 colors

struct Node{
    bool isRoot;
    vector<int> children;
};

int nnode, T[MAX][CMAX+1];
Node buffer[MAX];

int dfs( int pos, int prec ){
    if ( buffer[pos].children.size() == 0 ){
	return ((prec >=2) ? 1 : 2);
    }

    int minv = INT_MAX;
    for ( int color = 1; color <= CMAX; color++ ){
	if ( color == prec ) continue;
	if ( T[pos][color] == INT_MAX ){
	    int sum = 0;
	    for ( int j = 0; j < buffer[pos].children.size(); j++ ){
		sum += dfs( buffer[pos].children[j], color );
	    }
	    T[pos][color] = min( T[pos][color], sum + color);
	}
	minv = min( minv, T[pos][color]);
    }

    return minv;
}

void compute(){
    for ( int i = 0; i < nnode; i++ ){
	for ( int k = 0; k <= CMAX; k++ ) T[i][k] = INT_MAX;
    }

    int root;
    for ( int i = 0; i < nnode; i++ ){
	if (buffer[i].isRoot) { root = i; break;}
    }

    printf("%d\n", dfs(root, INT_MAX));
}

main(){
    int id, child;
    char ch;
    while ( scanf("%d", &nnode) != EOF && nnode){
	for ( int i = 0; i < nnode; i++ ){
	    buffer[i].children.clear();
	    buffer[i].isRoot = true;
	}
	for ( int i = 0; i < nnode; i++ ){
	    scanf("%d:", &id);
	    if(getchar() == '\n') continue;
	    ch = ' ';
	    while(ch == ' '){
		child = 0;
		while('0' <= (ch = getchar()) && ch <= '9')
		    child = 10*child + ch - '0';
		buffer[id].children.push_back(child);
		buffer[child].isRoot = false;
	    }
	}
	compute();
    }
}
