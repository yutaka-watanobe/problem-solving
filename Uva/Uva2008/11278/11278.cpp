#include<iostream>
#include<string>
#include<map>
using namespace std;

main(){
    string Q = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./~!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL:\"ZXCVBNM<>? ";
    string R = "`123qjlmfp/[]456.orsuyb;=\\789aehtdck-0zx,inwvg'~!@#QJLMFP?{}$%^>ORSUYB:+|&*(AEHTDCK_)ZX<INWVG\" ";

    map<char, char> M;
    for ( int i = 0; i < Q.size(); i++ ) M[Q[i]] = R[i];
    
    string line;
    while( getline( cin, line ) ){
	for ( int i = 0; i < line.size(); i++ ) cout << M[line[i]];
	cout << endl;
    }
}
