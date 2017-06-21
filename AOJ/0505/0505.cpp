#include<cstdio>
#include<algorithm>
using namespace std;
#define MAX 100

class Place{
    public:
    int id, v;
    Place(){}
    Place( int id, int v): id(id), v(v){}

    bool operator < ( const Place &p ) const{
	if ( v == p.v ){
	    return id < p.id;
	} else {
	    return v > p.v;
	}
    }
};

int main(){
    int n, m, x;
    Place P[MAX];

    while(1){
	scanf("%d %d", &n, &m);
	if ( n == 0 && m == 0 ) break;
	for ( int i = 0; i < m; i++ ) P[i] = Place(i+1, 0);

	for ( int i = 0; i < n; i++ ){
	    for ( int j = 0; j < m; j++ ){
		scanf("%d", &x);
		if ( x ) P[j].v++;
	    }
	}

	sort( P, P + m );

	for ( int i = 0; i < m; i++ ){
	    if ( i ) printf(" ");
	    printf("%d", P[i].id);
	}
	printf("\n");

    }
}
