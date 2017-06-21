#include<iostream>
#include<algorithm>
using namespace std;

main(){
    double xa1, ya1, xa2, ya2, xb1, yb1, xb2, yb2 ;
    while( cin >> xa1 >> ya1 >> xa2 >> ya2 >> xb1 >> yb1 >> xb2 >> yb2 ){
	if ( min( xa2, xb2 ) < max(xa1, xb1) ||
	     min( ya2, yb2 ) < max(ya1, yb1) ) cout << "NO" << endl;
	else cout << "YES" << endl;
    }
}
