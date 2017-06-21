#include<stdio.h>
#include<set>
#include<vector>
#include<algorithm>
#define MAX 1001

using namespace std;

int gcd(int a, int b){
  int tmp;

  if(a<b) swap(a, b);

  while(b){
    a %= b;
    
    tmp = a;
    a = b;
    b = tmp;
  }

  return a;
}

class Item{
    public:
    int num, den;
    double value;
    Item(){}
    Item( int num, int den): num(num), den(den){
	value = 1.0*num/den;
    }

    bool operator < ( const Item i ) const{
	return ( i.value > value);
    }

    bool operator == ( const Item i ) const{
	return ( i.num==num && i.den==den);
    }
};

int n, k;

void work(){
    bool used[MAX][MAX];
    for ( int i = 0; i <= n; i++ ){
	for ( int j = 0; j <= n; j++ ){
	    used[i][j] = false;
	}
    }

    set<Item> S;
    set<Item>::iterator pos;

    vector<Item> V;

    for ( int i = 1; i <= n; i++ ){
	for ( int j = i; j <= n; j++ ){
	    int g = gcd(i, j);
	    int ni, nj;
	    ni = i/g;
	    nj = j/g;

	    if ( !used[ni][nj]  ){
	      //		S.insert( Item(ni, nj) ) ;
	      V.push_back(Item(ni, nj));
		used[ni][nj] = true;
	    }
	}
    }

    sort(V.begin(), V.end());

    int i = 0;
    //    for ( pos = S.begin(); pos != S.end() && i < k ; i++, pos++ ){

    //    }

    //    pos--;
    //    Item item = *pos;
    Item item = V[k-1];

    cout << item.num << "/" << item.den << endl;
}

main(){
    while ( scanf("%d %d", &n, &k) != EOF  ){
	work();
    }
}

