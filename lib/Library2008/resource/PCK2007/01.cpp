#include<iostream>
using namespace std;

main(){
    static const int nstudent = 39;
    int ncandy, target;
    cin >> ncandy;
    target = ncandy % nstudent;
    if ( target == 0 ) target = nstudent;
    cout << "3C";
    if ( target < 10 ) cout << "0";
    cout << target << endl;
}
