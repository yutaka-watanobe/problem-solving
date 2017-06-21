#include<stdio.h>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;
#define MAX 10001 
typedef vector<int> vint;

pair<int, int> bugs[MAX];
int n, size;

class scmp {
public:
    bool operator()(const vint& a,const vint &b){
	return a.size() < b.size();
    }
};

void compute(){
    multiset<vint, scmp> pieces;
    for ( int i = 0; i < size; i++ ){
	int nn = min( bugs[i].second,(int)pieces.size() );
	vector<vint> nextp(nn);
	for ( int j = 0; j < nn; j++ ){
	    nextp[j] = *pieces.begin(); pieces.erase(pieces.begin());
	    nextp[j].push_back(bugs[i].first);
	}
	for ( int j = 0; j < nn; j++ ){
	    pieces.insert(nextp[j]);
	}
	for ( int j = 0; j < bugs[i].second - nn; j++ ){
	    vint p;
	    p.push_back(bugs[i].first);
	    pieces.insert(p);
	}
    }

    printf("%d\n", pieces.size());
    for ( multiset<vint>::iterator it = pieces.begin(); it != pieces.end(); it++ ){
	vint p = *it;
	for ( int i = 0; i < p.size(); i++ ){
	    if (i) printf(" ");
	    printf("%d", p[i]);
	}
	printf("\n");
    }
}

void initialize(){
    int buffer[MAX];
    for ( int i = 0; i < n; i++ ) scanf("%d", &buffer[i]);
    sort( buffer, buffer + n );

    int x, pre, cnt;
    pre = buffer[0];
    cnt = size = 1;
    for ( int i = 1; i < n; i++ ){
	if ( buffer[i] == pre ){
	    cnt++;
	} else {
	    bugs[size].first = pre;
	    bugs[size++].second = cnt;
	    cnt = 1;
	}
	pre = buffer[i];
    }
    bugs[size].first = pre;
    bugs[size++].second = cnt;
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


