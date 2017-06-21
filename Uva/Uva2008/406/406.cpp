#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

#define MAX 1000
void eratos ( int n, bool prime[], vector<int> &v){
    for ( int i = 0; i <= n; i++ ) prime[i] = false;
    for ( int i = 3; i <= n; i += 2 ) prime[i] = true;
    prime[2] = true;
    int limit = (int)sqrt((double)n) + 1;
    
    for ( int i = 3; i <= limit; i += 2 ){
         if ( !prime[i] ) continue;
         for ( int j = i + i; j <= n; j += i ) prime[j] = false;
    }
    
    v.clear();
    v.push_back(1);
    for ( int i = 2; i <= n; i++ ) if ( prime[i] ) v.push_back(i);
}

int main(){
    bool prime[MAX+1];
    
    int n, c, s;
    while( cin >> n >> c ){
	cout << n << " " << c << ":";
	vector<int> v;
	eratos(n, prime, v);
	if ( v.size()%2== 0){
	    s = v.size()/2-c;
	    for ( int i = max(0, s); i < min(s + c*2, (int)v.size()); i++ ) cout << " " << v[i];
	} else {
	    s = v.size()/2-c + 1;
	    for ( int i = max(0, s); i < min(s + c*2-1, (int)v.size()); i++ ) cout << " " << v[i];
	}
	cout << endl;
	cout << endl;
    }
    return 0;
}
