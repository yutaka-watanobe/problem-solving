#include<iostream>

using namespace std;

string rec( string cur ){
    for ( int i = 0; i < cur.size(); i++ ){
	if ( cur[i] == '0' ) return "";
    }

    if ( cur[0] == '2' ) return cur.substr(1, cur.size()-1);

    if ( cur[0] != '3' ) return "";

    string Y = rec( cur.substr(1, cur.size()-1));
    
    if ( Y == "" ) return "";

    return Y + "2" + Y;
    

}

main(){
    string number;
    while( cin >> number && number != "0"){
	number = rec( number );
	if ( number == "" ) cout << "NOT ACCEPTABLE" << endl;
	else cout << number << endl;
    }
}
