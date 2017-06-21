#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Book{
    public:
    vector<int> pages;
    Book(){}
};

main(){
    string name;
    int page;
    map<string, Book> B;
    map<string, Book>::iterator it;

    while( cin >> name >> page ){
	B[name].pages.push_back(page);
    }

    for ( it = B.begin(); it != B.end(); it++ ){
	Book b = (*it).second;
	cout << (*it).first << endl;
	sort( b.pages.begin(), b.pages.end() );
	for ( int i = 0; i < b.pages.size(); i++ ){
	    if ( i ) cout << " ";
	    cout << b.pages[i];
	}
	cout << endl;
    }
}
