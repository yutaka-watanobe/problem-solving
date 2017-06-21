#include<stdio.h>
#include<algorithm>
using namespace std;
#define MAX 100000
typedef long long llong;

class Data{
    public:
    llong v, mv, rem;
    Data(){}
    Data(llong v, llong m):v(v){
	mv  = v%m;
	rem = v%2;
	if ( rem < 0 ) rem *= (-1);
    }

    bool operator < ( const Data &d ) const{
	if ( mv == d.mv ){
	    if ( rem == 0 && d.rem == 1 ){
		return false;
	    } else if ( rem == 1 && d.rem == 0 ){
		return true;
	    } else if ( rem == 1 && d.rem == 1 ){
		return v > d.v;
	    } else if ( rem == 0 && d.rem == 0 ){
		return v < d.v;
	    }
	} else {
	    return mv < d.mv;
	}
    }
};

main(){
    Data data[MAX];
    llong n, m, x;
    while(1){
	scanf("%lld %lld", &n, &m);
	printf("%lld %lld\n", n, m);
	if ( n == 0 && m == 0 ) break;
	for ( int i = 0; i < n; i++ ){
	    scanf("%lld", &x);
	    data[i] = Data(x, m);
	}

	sort( data, data + n );

	for ( int i = 0; i < n; i++ ) printf("%lld\n", data[i].v);
    }
}
