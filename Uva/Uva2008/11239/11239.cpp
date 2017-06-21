#include<iostream>
#include<string>
#include<set>
#include<algorithm>
using namespace std;
#define MAX 100


struct Project{
    string name;
    set<string> members;
    int count;

    bool operator < ( const Project &p ) const{
	if ( count == p.count ){
	    return name < p.name;
	} else return count > p.count;
    }
};

Project P[MAX];
int n;

bool isCapital( char ch ){
    return 'A' < ch && ch <'Z';
}

void compute(){
    /*
    for ( int i = 0; i < n; i++ ){
	cout << P[i].name << endl;
	set<string>::iterator it;
	for ( it = P[i].members.begin(); it != P[i].members.end(); it++ ){
	    cout << (*it) << endl;
	}
    }
    cout << endl;
    */

    for ( int i = 0; i < n; i++ ){
	Project project = P[i];
	set<string>::iterator it;

	for ( it = project.members.begin(); it != project.members.end(); it++ ){
	    string member = *it;

	    bool has = false;
	    for ( int j = 0; j < n; j++ ){
		if ( i == j ) continue;
		
		if ( P[j].members.find(member) != P[j].members.end() ) has = true;
	    }

	    if ( !has ) P[i].count++;
	}
    }

    sort( P, P + n );
    
    for ( int i = 0; i < n; i++ ){
	cout << P[i].name << " " << P[i].count << endl;
    }


}

int main(){
    string line;
    while(1){
	n = 0;
	while(1){
	    getline( cin, line );
	    if ( line == "1" ) break;
	    if ( line == "0" ) break;
	    if ( isCapital(line[0]) ){
		P[n++].name = line;
		P[n-1].members.clear();
		P[n-1].count = 0;
	    } else {
		P[n-1].members.insert( line );
	    }
	}

	compute();
	if ( line == "0" ) return 0;
    }

    return 0;
}
