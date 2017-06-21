#include<iostream>
#include<queue>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

#define FA 0 //fill A
#define FB 1//fill B
#define EA 2//empty A
#define EB 3 //empty B
#define AB 4//pour A B
#define BA 5//pour B A

class State{
    public:
    int a, b;
    vector<int> path;

    State(){}
    State( int a, int b): a(a), b(b){}

    bool operator < ( const State &s ) const{
	if ( a == s.a ) return b < s.b;
	else return a < s.a;
    }
};

void print(vector<int> v){
    for (int i =  0; i < v.size(); i++ ){
	int op = v[i];
	if ( op == FA ) cout << "fill A" << endl;
	else if ( op == FB ) cout << "fill B" << endl;
	else if ( op == EA ) cout << "empty A" << endl;
	else if ( op == EB ) cout << "empty B" << endl;
	else if ( op == AB ) cout << "pour A B" << endl;
	else if ( op == BA ) cout << "pour B A" << endl;
    }
    cout << "success" << endl;
}

void  bfs( int ca, int cb, int n ){
    queue<State> Q;
    map<State, bool> V;

    Q.push(State(0, 0));
    V[State(0, 0)] = true;

    State u, v;
    int amount;

    while( !Q.empty() ){
	u = Q.front(); Q.pop();
	if ( u.a == n || u.b == n ) {
	    print(u.path); return;
	}

	// fill A
	v = u;
	v.a = ca;
	v.path.push_back(FA);
	if ( !V[v] ) { V[v] = true; Q.push(v); }
	// fill B
	v = u;
	v.b = cb;
	v.path.push_back(FB);
	if ( !V[v] ) { V[v] = true; Q.push(v); }
	// empty A
	v = u;
	v.a = 0;
	v.path.push_back(EA);
	if ( !V[v] ) { V[v] = true; Q.push(v); }
	// empty B
	v = u;
	v.b = 0;
	v.path.push_back(EB);
	if ( !V[v] ) { V[v] = true; Q.push(v); }
	// pour B A
	v = u;
	amount = min(ca - v.a, v.b);
	v.a += amount;
	v.b -= amount;
	v.path.push_back(BA);
	if ( !V[v] ) { V[v] = true; Q.push(v); }
	// pour A B
	v = u;
	amount = min(cb - v.b, v.a);
	v.b += amount;
	v.a -= amount;
	v.path.push_back(AB);
	if ( !V[v] ) { V[v] = true; Q.push(v); }
    }
}

int main(){
    int ca, cb, n;
    while( cin >> ca >> cb >> n ) bfs(ca, cb, n);
    return 0;
}
