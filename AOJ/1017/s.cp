 #include<iostream>
 #include<vector>
 using namespace std;
 #define rep(i, n) for ( int i = 0; i < (int)n; i++)
 vector<int> A, B, C;
 int n, r, c;
 void shuffle( int c ){
     int a, b;
     a = (n%2)?n/2+1:n/2;
     b = n/2;
     rep(i, b) { B.push_back(C[0]); C.erase(C.begin());}
     rep(i, a) { A.push_back(C[0]); C.erase(C.begin());}
 
     while( A.size() || B.size() ){
 	a = A.size();
 	rep(i, min(a, c) ) { C.push_back(A[0]); A.erase(A.begin()); }
 	b = B.size();
 	rep(i, min(b, c) ) { C.push_back(B[0]); B.erase(B.begin()); }
     }
 }
 
 int main(){
 
     while ( cin >> n >> r && n && r ){
 	A.clear(); B.clear(); C.clear();
 	rep(i, n) C.push_back(i);
 	rep(i, r) {
 	    cin >> c;
 	    shuffle(c);
 	}
 	cout << C[C.size()-1] << endl;
     }
     return 0;
 }
