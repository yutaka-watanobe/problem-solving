// @JUDGE_ID:  17051CA  10364  C++
// @begin_of_source_code

#include<stdio.h>
#include<vector>
#define MAX 21

class Used{
    public:
    bool content[MAX];
    Used(){}
    Used( int n ){
	for ( int i = 0; i < n; i++ ) content[i] = false;
    }
};

int sticks[MAX];
int size;
int sum, length;

vector<Used> possible;

void rec( int pos, int len, Used &used ){
    
    if ( len == length ){
	possible.push_back( used );
	return;
    } else if ( len > length ) return;

    if ( pos >= size ) return;

    // no take
    rec( pos + 1, len, used );

    // take
    used.content[pos] = true;
    rec( pos + 1, len + sticks[pos], used );
    used.content[pos] = false;
}

bool check( Used source, Used &target ){
    for ( int i = 0; i < size; i++ ){
	if ( target.content[i] && source.content[i] ) return false;
    }

    for ( int i = 0; i < size; i++ ){
	if ( source.content[i] ) target.content[i] = true;
    }
    return true;
}

void refresh( Used source, Used &target ){
    for ( int i = 0; i < size; i++ ){
	if ( source.content[i] ){
	    target.content[i] = false;
	}
    }
}

bool excrusive(){
    int psize = possible.size();

    Used used = Used( size );

    for ( int a = 0; a < psize-3; a++ ){
	if ( !check( possible[a], used ) ) continue;

	for ( int b = a+1; b < psize-2; b++ ){
	    if ( !check( possible[b], used ) ) continue;

	    for ( int c = b+1; c < psize-1; c++ ){
		if ( !check( possible[c], used ) ) continue;

		for ( int d = c+1; d < psize; d++ ){
		    if ( check( possible[d], used ) ) return true;
		}
		refresh( possible[c], used );
	    }
	    refresh( possible[b], used );
	}
	refresh( possible[a], used );
    }
    return false;
}

void work(){
    if ( sum % 4 != 0 ){
	cout << "no" << endl;
	return;
    }

    length = sum / 4;

    Used used = Used( size );
    for ( int i = 0; i < size; i++ ) used.content[i] = false;

    possible.clear();
    rec( 0, 0, used );

    if ( excrusive() ) cout << "yes" << endl;
    else cout << "no" << endl;
}

void read(){
    sum = 0;
    scanf("%d", &size);
    for ( int i = 0; i < size; i++ ){
	scanf("%d", &sticks[i]);
	sum += sticks[i];
    }
}

main(){
    int tcase; scanf("%d", &tcase);
    for ( int i = 0; i < tcase; i++ ){
	read();
	work();
    }
}
// @end_of_source_code
