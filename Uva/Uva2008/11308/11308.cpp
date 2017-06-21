#include<iostream>
#include<string>
#include<sstream>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

class Recipe{
    public:
    string name;
    int cost;
    Recipe(){}
    Recipe( string n, int c ): name(n), cost(c){}

    bool operator < ( const Recipe &r ) const{
	if ( cost == r.cost )
	    return name < r.name;
	return cost < r.cost;
    }
};

map<string, int> price;
string title, rline;
int m, n, budget;

void compute(){
    price = map<string, int>();
    string str, name;
    getline( cin, title );

    getline( cin, str );
    stringstream sin(str);
    sin >> m >> n >> budget;
    int p, k;

    for ( int i = 0; i < m; i++ ){
	cin >> str >> p;
	price[str] = p;
	getline( cin, rline);;
    }

    set<Recipe> R;

    for ( int i = 0; i < n; i++ ){
	getline( cin, str );
	cin >> k;
	getline( cin, rline);;
	int total = 0;
	for ( int j = 0; j < k; j++ ){
	    cin >> name >> p; getline( cin, rline);;
	    total += price[name]*p;
	}
	if ( total <= budget ) R.insert( Recipe(str, total) );
    }
    
    for ( int i = 0; i < title.size(); i++ ) title[i] = toupper(title[i]);
    cout << title << endl;

    if ( R.size() == 0 ){
	cout << "Too expensive!" << endl << endl;
	return;
    }

    set<Recipe>::iterator it;
    for ( it = R.begin(); it != R.end(); it++ ){
	cout << (*it).name << endl; 
    }
    cout << endl;
}

main(){
    int tcase; cin >> tcase;
    getline( cin, rline);;
    for ( int i = 0; i < tcase; i++ ) compute();
}
