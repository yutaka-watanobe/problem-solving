#include<iostream>
using namespace std;
#define MAX 100
#define EMPTY (-1)

int main(){
    int W, Q, id, w, buffer[MAX];
    char com;

    while(1){
	cin >> W >> Q;
	if ( W == 0 && Q == 0 ) break;
	for ( int i = 0; i < W; i++ ) buffer[i] = EMPTY;
	
	for ( int q = 0; q < Q; q++ ){
	    cin >> com;
	    if ( com == 's' ){
		cin >> id >> w;
		int st = -1;
		for ( int s = W-w; s >= 0; s-- ){
		    bool hasSpace = true;
		    for ( int j = s; j < s+w; j++ ){
			if ( buffer[j] != EMPTY ) hasSpace = false;
		    }
		    if ( hasSpace ) st = s;
		}
		if ( st != -1 ){
		    cout << st << endl;
		    for ( int j = st; j < st + w; j++ ) buffer[j] = id;
		} else {
		    cout << "impossible" << endl;
		}
	    } else if ( com == 'w' ){
		cin >> id;
		bool checked = false;
		for ( int j = 0; j < W; j++ ){
		    if ( buffer[j] == id ){
			buffer[j] = EMPTY;
			checked = true;
		    }
		}
	    }
	}
	cout << "END" << endl;
    }
}
