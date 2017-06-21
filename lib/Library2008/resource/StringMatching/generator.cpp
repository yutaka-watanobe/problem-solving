#include<iostream>
#include<stdlib.h>

using namespace std;

main(){
    int size = 1000;
    for ( int i = 0; i < size; i++ ){
	cout << rand()%2;
    }
    cout << endl;
    cout << "001001" << endl;
}
