#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

#define MAX 10000

class Pair{
    public:
    int first, second, sum;
    Pair(int f = 0, int s = 0){
	first = max(f, s);
	second = min(f, s);
	sum = first + second;
    }
    bool operator < ( const Pair &p ) const{
	return sum < p.sum;
    }
};

class Ans{
    public:
    int p[4];
    Ans(int a=0, int b=0, int c=0, int d=0){
	p[0] = a;
	p[1] = b;
	p[2] = c;
	p[3] = d;
    }
    bool operator < ( const Ans &a ) const{
	for ( int i = 0; i < 4; i++ ){
	    if ( p[i] == a.p[i] ) continue;
	    return p[i] > a.p[i];
	}
	return false;
    }
};

Pair B2[MAX], W2[MAX];
int B[100], W[100];
int H, n, m, n2, m2;

int bsearch( int target ){
    int left = 0;
    int right = m2;
    int mid;
    while( left < right ){
	mid = (left + right)/2;
	if ( W2[mid].sum == target ) return mid;
	else if ( W2[mid].sum > target ) right = mid;
	else left = mid + 1;
    }
    return -1;
}

void compute(){
    n2 = m2 = 0;
    for ( int i = 0; i < n-1; i++ ){
	for ( int j = i+1; j < n; j++ ) {
	    B2[n2++] = Pair(B[i], B[j]);
	}
    }

    for ( int i = 0; i < m-1; i++ ){
	for ( int j = i+1; j < m; j++ ) {
	    W2[m2++] = Pair(W[i], W[j]);
	}
    }

    sort( B2, B2 + n2);
    sort( W2, W2 + m2);

    /*
    for ( int i = 0; i < n2; i++ ) cout << B2[i].sum << ":" << B2[i].first << ":" << B2[i].second << " ";
    cout << endl;
    for ( int i = 0; i < m2; i++ ) cout << W2[i].sum << ":" << W2[i].first << ":" << W2[i].second << " ";
    cout << endl;
    */

    vector<Ans> ans;

    for ( int i = 0; i < n2; i++ ){
	int target = H - B2[i].sum;
	if ( target < 0 ) continue;
	int pos = bsearch(target);
	if ( pos == -1 ) continue;
	ans.push_back(Ans(B2[i].first, W2[pos].first, B2[i].second,W2[pos].second));
	int j = pos-1;
	while( j >= 0 && W2[j].sum == target ){
	    ans.push_back(Ans(B2[i].first, W2[j].first, B2[i].second,W2[j].second));
	    j--;
	}
	j = pos+1;
	while( j < m2 && W2[j].sum == target ){
	    ans.push_back(Ans(B2[i].first, W2[j].first, B2[i].second,W2[j].second));
	    j++;
	}

    }

    sort( ans.begin(), ans.end());

    /*
    for ( int i = 0; i < ans.size(); i++ ){
	for ( int j = 0; j < 4; j++ ){
	    cout << ans[i].p[j] << " ";
	}
	cout << endl;
	}
    */

    if ( ans.size() == 0 ) cout << "no solution" << endl;
    else {
	for ( int i = 0; i < 4; i++ ){
	    if ( i ) cout << " ";
	    cout << ans[0].p[i];
	}
	cout << endl;
    }



}

main(){
    string line;
    int x;
    while( cin >> H){
	n = m = 0;
	getline(cin, line);
	getline(cin, line);
	stringstream sinb(line);
	while( sinb >> x )  B[n++] = x;
	getline(cin, line);
	stringstream sinw(line);
	while( sinw >> x )  W[m++] = x;
	getline(cin, line);

	compute();
    }
}
