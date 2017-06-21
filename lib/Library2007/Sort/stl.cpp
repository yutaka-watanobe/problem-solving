#include<iostream>
#include<algorithm>
#include<string>
#define MAX 1000
using namespace std;

class Data{
    public:
    int key; 
    string name;

    bool operator < ( const Data &d ) const{
	return key < d.key;
    }
};

Data data[MAX];
int size;

void input(){
    cin >> size;
    for ( int i = 0; i < size; i++ ) {
	cin >> data[i].key >> data[i].name;
    }
}

void output(){
    for ( int i = 0;i < size; i++ ) {
	cout << data[i].key << " " << data[i].name << endl;
    }
}

main(){
    input();
    sort( data, data + size );
    output();
}

