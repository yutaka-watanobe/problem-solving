#include<iostream>
#include<string>
using namespace std;

int isPalindrome( string line ){
    int size = line.size();
    for ( int i = 0; i < size / 2; i++ ){
	if ( line[i] != line[size-1-i] ) return false;
    }
    return true;
}

int main(){
    string line;
    int sum = 0;
    while ( cin >> line ){
	if ( isPalindrome(line) ) sum++;
    }

    cout << sum << endl;
    return 0;
}
