// @JUDGE_ID:  17051CA  115  C++
// @begin_of_source_code
// Family Tree simulation

#include<stdio.h>
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>

#define MAX 301
#define NOPARENT (-1)
using namespace std;

class Node{
    public:
    int parentID;

    Node(){
	parentID = NOPARENT;
    }
};


Node buffer[MAX];
int current;
map<string, int> nameToID;


void getLinear(vector<int> &line, int start){

    int id = buffer[start].parentID;

    while ( id != NOPARENT ){
	line.push_back(id);
	id = buffer[id].parentID;
    }
}

void ancestor(vector<int> line, int id){
    if ( line[0] == id ) cout << "parent" << endl;
    else if ( line[1] == id ) cout << "grand parent" << endl;
    else {
	for ( int i = 2; i < line.size(); i++ ){
	    cout << "great ";
	    if ( line[i] == id ) break;
	}
	cout << "grand parent" << endl;
    }
}

void descendent(vector<int> line, int id ){
    if ( line[0] == id ) cout << "child" << endl;
    else if ( line[1] == id ) cout << "grand child" << endl;
    else {
	for ( int i = 2; i < line.size(); i++ ){
	    cout << "great ";
	    if ( line[i] == id ) break;
	}
	cout << "grand child" << endl;
    }
}

void cousin(vector<int> line1, vector<int> line2){
    int m, n;
    bool matched = false;
    for ( m = 0; m < line1.size(); m++ ){
	for ( n = 0; n < line2.size(); n++ ){
	    if ( line1[m] == line2[n] ) {
		matched = true;
		goto next;
	    }
	}
    }

    if ( !matched || matched && line1[m] == NOPARENT){
	cout << "no relation" << endl;
	return;
    }

 next:;
    int k = min( n, m );
    int j = (n > m ) ? n - m : m - n;

    if ( n == 0 && m == 0 ) cout << "sibling" << endl;
    else if ( j == 0 ) cout << m << " cousin" << endl;
    else  cout << k << " cousin removed " << j << endl;
}


void compute(int source, int target){
    // source は target の 何？？
    vector<int> sourceLine; // prarents list
    vector<int> targetLine; // parentts list
    
    getLinear(sourceLine, source);
    getLinear(targetLine, target);


    if ( find( targetLine.begin(), targetLine.end(), source ) != targetLine.end() ){
	// target の親の列に source がいたら
	ancestor(targetLine, source);
    } else if ( find( sourceLine.begin(), sourceLine.end(), target ) != sourceLine.end() ){
	// source の親の列に target がいたら
	descendent(sourceLine, target);
    } else {
	cousin(sourceLine, targetLine);
    }

}

void work(){
    string source, target;
    while ( cin >> source >> target ){
	if ( nameToID.find(source) == nameToID.end() ||
	     nameToID.find(target) == nameToID.end() ){
	    cout << "no relation" << endl;
	} else {
	    compute(nameToID[source], nameToID[target]);
	}
    }
}

int getID(string name){
    if ( nameToID.find(name) != nameToID.end() ) return nameToID[name];
    
    int id = current++;
    nameToID[name] = id;

    return id;
}

bool read(){
    string child, parent;
    current = 0;

    while ( 1 ){
	cin >> child >> parent;
	if ( child == "no.child" && parent == "no.parent" ) break;
	
	int cid = getID(child);
	int pid = getID(parent);
	
	buffer[cid].parentID = pid;
    }
}

main(){
    read();
    work();
}









