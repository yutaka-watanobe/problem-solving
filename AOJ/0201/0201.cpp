#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<cassert>
using namespace std;

#define MAX 200

class Item{
    public:
    string name;
    int cost;
    vector<vector<string> > recipes;

    Item(){}
    Item( string name, int cost ): name(name), cost(cost){ recipes.clear(); }

    void addRecipe(vector<string> r ){ recipes.push_back(r);}
};

int n;
map<string, int> N_I;
Item items[MAX];

int getCost( string name ){
    Item item = items[ N_I[name] ];
    int cost = item.cost;

    for ( int i = 0; i < item.recipes.size(); i++ ){
	vector<string> recipe = item.recipes[i];
	int sum = 0;
	for ( int j = 0; j < recipe.size(); j++ ){
	    sum += getCost( recipe[j] );
	}
	cost = min( cost, sum );
    }

    return cost;
}

main(){
    int q, cost, nr, k;
    string name, source;
    while( cin >> n && n){
	for ( int i = 0; i < n; i++ ){
	    cin >> name >> cost;
	    assert( name.size() <= 100 );
	    items[i] = Item(name, cost);
	    N_I[name] = i;
	}
	cin >> nr;
	for ( int i = 0; i < nr; i++ ){
	    cin >> name >> k;
	    vector<string> recipe;
	    for ( int j = 0; j < k; j++ ){
		cin >> source;
		recipe.push_back(source);
	    }
	    items[ N_I[name] ].addRecipe(recipe);
	}
	cin >> name;
	cout << getCost( name ) << endl;
    }
}
