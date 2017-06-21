 #include<iostream>
 #include<algorithm>
 using namespace std;
 #define MAX 1000000
 int n;
 
 pair<int, int> T[MAX];
 
 main(){
     int id, m, s;
     while( cin >> n && n ){
 	for ( int i = 0; i < n; i++ ){
 	    cin >> id;
 	    int sum = 0;
 	    for ( int j = 0; j < 4; j++ ){
 		cin >> m >> s;
 		sum += m*60 + s;
 	    }
 	    T[i] = make_pair(sum, id);
 	}
 	sort( T, T + n );
 
 	cout << T[0].second << endl;
 	cout << T[1].second << endl;
 	cout << T[n-2].second << endl;
     }
 }
