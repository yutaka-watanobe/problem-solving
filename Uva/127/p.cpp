// @JUDGE_ID:  17051CA  127  C++
// @begin_of_source_code
// 速度が求められる
// vector や 配列確保は現実的ではない
// ポインタ操作で解決

#include<stdio.h>
#include<iostream>
#define MAX 60

using namespace std;

struct Card {
    char rank, suit;
};

struct Pile {
    int size;
    Card cards[MAX];
};

Card deck[MAX];
Pile *piles[MAX];
Pile buffer[MAX];

int current;

void check(){
    bool changed;
    int target;
    Card card;
    Pile *tmp;

    while ( 1 ){
	changed = false;

	for ( int i = 3; i < current; i++ ){
	    target = i;
	    card = piles[i]->cards[piles[i]->size -1];

	    while ( 1 ){
		if ( card.suit == piles[target-3]->cards[piles[target-3]->size-1].suit ||
		     card.rank == piles[target-3]->cards[piles[target-3]->size-1].rank ){
		    target -= 3;
		    continue;
		}

		if ( card.suit == piles[target-1]->cards[piles[target-1]->size-1].suit ||
		     card.rank == piles[target-1]->cards[piles[target-1]->size-1].rank ){
		    target -= 1;
		    continue;
		}
		break;
	    }

	    if ( target == i ) continue;

	    piles[target]->cards[piles[target]->size++] = card;
	    piles[i]->size--;

	    if ( piles[i]->size == 0 ){
		tmp = piles[i];

		for ( int j = i + 1; j < current; j++ ){
		    piles[j - 1] = piles[j];
		}

		piles[current-1] = tmp;
		
		current--;
	    }
	    
	    changed = true;
	    break;
	    
	}

	if ( !changed ) break;
    }
}

void output(){
    if ( current == 4 ) printf("1 pile ");
    else printf("%d piles ", current - 3);
    printf("remaining:");

    for ( int i = 3; i < current; i++ ){
	printf(" %d", piles[i]->size);
    }
    printf("\n");
}

void init(){
   for ( int i = 0; i < MAX; i++ ){
	piles[i] = &buffer[i];
    }
    
    for ( int i = 0; i < 3; i++ ){
	buffer[i].size = 1;
	buffer[i].cards[0].rank = 'X';
	buffer[i].cards[0].suit = 'X';
    }
}

void work(){

    current = 3;

    for ( int i = 0; i < 52; i++ ){
	piles[current]->size = 1;
	piles[current]->cards[0] = deck[i];

	current++;
	check();
    }
}

bool input(){
    char ch;
	
    cin >> ch;
    if ( ch == '#' ) return false;
    cin.unget();
    
    for ( int i = 0; i < 52; i++ )
	cin >> deck[i].rank >> deck[i].suit;
    
    return true;
}

main(){

    init();

    while ( input() ) {
	work();
	output();
    }
}
