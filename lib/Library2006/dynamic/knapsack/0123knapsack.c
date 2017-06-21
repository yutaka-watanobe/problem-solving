/**********************
 * 0-1-2-3.. Knapsack *
 **********************/
#include<stdio.h>
#include<iostream>
#include<vector>

class Item{
 public:
  int value, size, count;
  Item(){}
  Item( int value, int size ): value(value), size(size){
    count = 0;
  }
};

class Knapsack{
 public:
  int n;
  int weight;
  vector<Item> I; /* item list */
  vector<int> gain, choice;

  Knapsack(){}
  Knapsack(int n, int weight, vector<Item> I): n(n), weight(weight), I(I){
    gain.resize( n + 1, 0 );
    choice.resize( n + 1, 0 );
  }
    
  void knap(){
    for ( int i = 0; i < n; i++ ){
      int size = I[i].size;
      int value = I[i].value;
      for ( int j = size; j <= weight; j++ ){
	int space = j - size;
	int new_value = value + gain[ space ];
	if ( gain[ j ] < new_value ){
	  gain[ j ] = new_value;
	  choice[ j ] = i;
	}
      }
    }
    countItem();
  }

  void countItem(){
    for ( int i = weight; i > 0; ){
      int k = choice[ i ];
      I[k].count++;
      i -= I[k].size;
    }
  }

  void printKnapsack(){
    for ( int i = 0; i < n; i++ ){
      cout << "Item " << i << " " << I[i].count << " unit" << endl;
    }
  }

};

main(){
  vector<Item> I;
  I.push_back( Item( 2, 2 ) );
  I.push_back( Item( 4, 3 ) );
  I.push_back( Item( 7, 5 ) );
  I.push_back( Item( 6, 10 ) );
  I.push_back( Item( 9, 14 ) );

  Knapsack knapsack = Knapsack( I.size()+1, 12, I );
  knapsack.knap();
  knapsack.printKnapsack();
  
  
}
