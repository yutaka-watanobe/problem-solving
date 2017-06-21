#include<iostream>
using namespace std;

main(){
    int n;
    int cola, empty, cnt;

    while( cin >> n ){
	cola = n;
	empty = 1;
	cnt = 0;
	while(1){
	    cnt += cola;
	    empty += cola;

	    if ( cola + empty < 3 ) break;
	    cola = empty/3;
	    empty = empty%3;
	}
	cout << cnt << endl;
    }
}
