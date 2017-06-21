#include<iostream>
#include<string>
#include<bitset>

using namespace std;

int main(){
    int n;
    while( cin >> n ){
	bitset<32> b =  bitset<32>(n);
	bitset<32> c;
	for ( int i = 0; i < 32; i++ ) c[i] =  b[32 - i -1];

	string str = "";
	for ( int i = 31; i >= 0; i-- ) str += c[i]+'0';
	
	cout << bitset<32>(str).to_int() << endl;
    }
    return 0;
}
