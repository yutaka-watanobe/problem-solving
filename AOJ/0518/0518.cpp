// speed
// map < set find
#include<cstdio>
#include<set>
using namespace std;
#define MAX  3000

int n;

pair<int, int> P[MAX];
set<pair<int, int> > S;

int main(){
    while(1){
	scanf("%d", &n);
	if ( n == 0 ) break;
	S.clear();
	for ( int i = 0; i < n; i++ ){
	    scanf("%d %d", &P[i].first, &P[i].second);
	    S.insert(P[i]);
	}

	int x1, y1, x2, y2, x3, y3, x4, y4;
	int area = 0;
	for ( int i = 0; i < n-1; i++ ){
	    for ( int j = i+1; j < n; j++ ){
		x1 = P[i].first; y1 = P[i].second;
		x2 = P[j].first; y2 = P[j].second;

		x3 = x1 + (y2 - y1);
		y3 = y1 - (x2 - x1);
		
		x4 = x2 + (y2 - y1);
		y4 = y2 - (x2 - x1);

		if ( S.find(make_pair(x3, y3)) != S.end() && S.find(make_pair(x4, y4)) != S.end()){
		    area = max( area, (y2-y1)*(y2-y1)+(x2-x1)*(x2-x1));
		}
	    }
	}
	printf("%d\n", area);
    }
}
