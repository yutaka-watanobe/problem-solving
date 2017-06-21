#include<iostream>
using namespace std;

int main(){
    int A = 0, B = 0, x;

    for ( int i = 0; i < 4; i++ ) { cin >> x; A += x; }
    for ( int i = 0; i < 4; i++ ) { cin >> x; B += x; }
    
    if ( A > B ) cout << A << endl;
    else cout << B << endl;
    
    return 0;
}
