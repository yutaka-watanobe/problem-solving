#include<iostream>
#include<string>
using namespace std;

main(){
    string str = "abcedgf";
    
    //str.insert(2+1, "x" );
    
    str.erase( str.begin() + 2 );


    cout << str << endl;
}
