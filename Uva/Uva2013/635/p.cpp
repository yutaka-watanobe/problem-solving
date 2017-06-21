#include<iostream>
#include<map>

using namespace std;

class Card{
    public:
    char symbol;
    bool covered;
    Card(char symbol):symbol(symbol){
	covered = true;
    }

    bool operator == ( const Card &c ) {
	return ((symbol == c.symbol) && (covered == c.covered));
    }

    bool operator != ( const Card &c ) {
	return ((symbol != c.symbol) || (covered != c.covered));
    }

    bool operator < ( const Card &c ){
	if ( symbol != c.symbol ) return symbol < c.symbol;
	if ( covered && !c.covered ) return true;
	return false;
    }
};

class Deck{
    public:
    Card buffer[52];

    Deck(){}

    bool operator < ( const Deck &deck ) const{
	for ( int i = 0; i < 52; i++ ){
	    if ( buffer[i] != deck.buffer[i] )
		return  buffer[i] < card.buffer[i];
	}
	return false;
    }
};

char initial[52];
Deck deck;
map<Deck, bool> visited;

bool recursive(int p){
    int s = p * 4;

    Deck tmp = deck;

    
}

void compute(){
    int cnt = 0;
    for ( int s = 0; s < 52; s++ ){
	deck = Deck();
	for ( int i = 4; i < 52; i++ ) deck.buffer[i] = Card([(i+s)%52]);
	for ( int i = 0; i < 4; i++ ) deck.buffer[i] = Card([(i+s)%52]);

	visited = map<Deck, bool>();
	if ( recursive(0) ) cnt++;
    }
    cout << cnt << endl;
}

bool input(){
    cin >> initial[0];
    if ( initial[0] == '0' ) return false;
    for ( int i = 1; i < 52; i++ ) cin >> initial[i];
    return true;
}

main(){
    while ( input() ){
	compute();
    }
}
