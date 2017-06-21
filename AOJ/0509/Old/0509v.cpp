#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define MAX 10000

class Segment{
    public:
    int s, t;
    Segment(){}
    Segment( int s, int t ): s(s), t(t){}

    bool operator < ( const Segment &seg ) const{
	return s < seg.s;
	if ( s == seg.s ) return t < seg.t;
	return s < seg.s;
    }
};


vector<Segment> generalize(vector<Segment> v ){
    if ( v.size() <= 1 ) return v;
    vector<Segment> nv;

    Segment cur = v[0];
    int s = cur.s;
    int t = cur.t;

    for ( int i = 1; i < v.size(); i++ ){
	if ( v[i].s > t ){
	    nv.push_back(Segment(s, t));
	    cur = v[i];
	    s = cur.s; t = cur.t;
	} else {
	    t = max( t, v[i].t );
	}
    }
    nv.push_back(Segment(s, t));

    return nv;
}

int n;
vector<Segment> G[MAX+1];

int getRound(){
    int sum = 0;
    int vsum = 0;
    int side = 0;

    for ( int i = 0; i <= MAX; i++ ){
	vsum += G[i].size()*2;
    }

    //    cout << "vsum = " << vsum << endl;

    int left = INT_MAX;
    int right = -1;
    for ( int i = 0; i <= MAX; i++ ){
	if ( G[i].size() ){
	    left = min(left, i);
	    right = max(right, i);
	}
    }

    for ( int i = 0; i < G[left].size(); i++ ) side += G[left][i].t - G[left][i].s;
    for ( int i = 0; i < G[right].size(); i++ ) side += G[right][i].t - G[right][i].s;
    //    cout << "side = " << side << endl;

    vector<Segment> source, target;
    for ( int x = left+1; x <= right-1; x++ ){
	source = G[x];
	
	target = G[x-1];
	for ( int i = 0; i < source.size(); i++ ){
	    Segment seg = source[i];
	    for ( int y = seg.s; y < seg.t; y++ ){
		bool isfree = true;
		for ( int j = 0; j < target.size(); j++ ){
		    Segment tt = target[j];
		    if ( tt.s > y ) continue;
		    if ( tt.s <= y && y < tt.t ) {isfree = false; break;}
		}
		if ( isfree ) sum++;
	    }
	}
	target = G[x+1];
	for ( int i = 0; i < source.size(); i++ ){
	    Segment seg = source[i];
	    for ( int y = seg.s; y < seg.t; y++ ){
		bool isfree = true;
		for ( int j = 0; j < target.size(); j++ ){
		    Segment tt = target[j];
		    if ( tt.s > y ) continue;
		    if ( tt.s <= y && y < tt.t ) {isfree = false; break;}
		}
		if ( isfree ) sum++;
	    }
	}


    }
    //    cout << "sum = " << sum << endl;

    return sum + vsum + side;
}


int main(){
    int r, x1, x2, y1, y2;

    while(1){
	scanf("%d %d", &n, &r);
	if ( n == 0 && r == 0 ) break;
	for ( int i = 0; i <= MAX; i++ ) G[i].clear();

	int gmax = 0;

	for ( int i = 0; i < n; i++ ){
	    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
	    for ( int x = x1; x <= x2-1; x++ ){
		G[x].push_back(Segment(y1, y2));
		//		cout << x << " <-- " << y1 << "," << y2-y1 << endl;
	    }
	}
	
	for ( int i = 0; i <= MAX; i++ ){
	    gmax = max(gmax, (int)(G[i].size()) );
	}
	cout << "max = " << gmax << endl;

	for ( int i = 0; i <= MAX; i++ ){
	    if ( G[i].size() ){
		sort( G[i].begin(), G[i].end() );
		G[i] = generalize(G[i]);
	    }
	}

	gmax = 0;
for ( int i = 0; i <= MAX; i++ ){
	    gmax = max(gmax, (int)(G[i].size()) );
	}
	cout << "max = " << gmax << endl;


	int area = 0;
	int round = 0;

	for ( int i = 0; i <= MAX; i++ ){
	    for ( int j = 0; j < G[i].size(); j++ ){
		Segment seg = G[i][j];
		area += (seg.t-seg.s);
	    }
	}

	if ( r == 1 ){
	    printf("%d\n", area);
	}  else if ( r == 2 ){
	    printf("%d\n", area);
	    printf("%d\n", getRound());
	}

    }

    

    return 0;
}
