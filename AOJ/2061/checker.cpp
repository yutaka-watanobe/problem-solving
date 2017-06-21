#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<algorithm>
#include<cassert>
using namespace std;

//ifstream fin("outputAll.txt");
ifstream fin("../data/2061/outputAll.txt");

class Ans{
    public:
	int nans, mleng;
    vector<vector<string> > ans;
    Ans(){}
    Ans(int nans, int mleng): nans(nans), mleng(mleng){
	ans.clear();
    }
};

bool isDigit( char ch ){
    return ( '0' <= ch && ch <= '9' );
}

bool eq( vector<string> v1, vector<string> v2 ){
    assert( v1.size() == v2.size() );
    for ( int i = 0; i < v1.size(); i++ ){
	if ( v1[i] != v2[i] ) return false;
    }
    return true;
}

bool check(vector<Ans> A ){
    int nans, mleng;
    string str;
    int size;
    for ( int i = 0; i < A.size(); i++ ){
	nans = A[i].nans;
	mleng = A[i].mleng;

	if ( nans == -1 ){
	    cin >> str;
	    if ( cin.eof() ) return false;
	    if ( str != "Impossible" ) return false;
	} else {
	    cin >> size;
	    if ( cin.eof() || size != mleng ) return false;
	    vector<string> v;
	    for ( int k = 0; k < size; k++ ){
		cin >> str;
		if ( cin.eof() ) return false;
		v.push_back(str);
	    }
	    sort( v.begin(), v.end() );

	    bool ok = false;
	    assert( nans == A[i].ans.size() );
	    for ( int j = 0; j < A[i].ans.size(); j++ ){
		if ( ok ) continue;
		if ( eq(v, A[i].ans[j] ) ) ok = true;
	    }
	    if ( !ok ) return false;
	}
    }

    return true;
}

int main(){
    vector<Ans> A;
    string str;
    while( fin >> str ){
	if ( isDigit(str[0]) ){
	    int nans = atoi(str.c_str());
	    int mleng; fin >> mleng;
	    string lang;
	    Ans a = Ans(nans, mleng);
	    for ( int i = 0; i < nans; i++ ){
		vector<string> l;
		for ( int j = 0; j < mleng; j++ ){
		    fin >> lang;
		    l.push_back(lang);
		}
		sort(l.begin(), l.end());
		a.ans.push_back(l);
	    }
	    assert( a.nans == a.ans.size() );
	    A.push_back(a);
	}  else {
	    A.push_back(Ans(-1, -1));
	}
    }
    
    if ( !check(A) ){
    	cout << "Wrong Answer" << endl;
    }

    /*
    for ( int p = 0; p < A.size(); p++ ){
	if (p) cout << endl;
	if ( A[p].nans == -1 ) cout << "Impossible" << endl;
	else{
	    cout << A[p].nans << " " << A[p].mleng << endl;
	    for ( int i = 0; i < A[p].nans; i++ ){
		for ( int j = 0; j < A[p].mleng; j++ ){
		    cout << A[p].ans[i][j] << " ";
		}
		cout << endl;
	    }
	}
	}
    */

    return 0;
}
