// bit sequence
#include<iostream>
#include<vector>

int I;

void createBit( int a, vector<int> &bit ){
    bit.clear();
    int next;
    while( a>0 ){
	bit.push_back( a%2 );
	a = a/2;
    }
}


void compute(){
    vector<int> bits;
    createBit(I, bits);

    cout << "The parity of ";
    int sum = 0;
    for ( int i = bits.size()-1; i >= 0; i-- ){
	if ( bits[i] == 1 ) sum++;
	cout << bits[i];
    }
    cout << " is " << sum << " (mod 2)." << endl;
}

bool read(){
    cin >> I;
    if ( I == 0 ) return false;
    return true;
}

main(){
    while ( read() ){
	compute();
    }
}
