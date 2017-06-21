#include<iostream>
#include<string>
#include<sstream>
using namespace std;

main(){
    string line;
    int tcase; cin >> tcase;
    getline( cin, line );
    char op;
    long long buffer1[1000], buffer2[1000], v;
    int size1, size2;
    for ( int i= 0; i < tcase; i++ ){
	getline( cin, line );
	stringstream sin(line);
	size1 = size2 = 0;

	
	sin >> buffer1[size1++];
	buffer2[size2++] = buffer1[0];

	while( sin >> op >> v ){
	    if ( op == '*' ){
		buffer1[size1-1] *= v;
		buffer2[size2++] = v;
	    } else {
		buffer1[size1++] = v;
		buffer2[size2-1] += v;

	    }
	}
	long long sum = 0;
	long long mul = 1;
	for ( int i = 0; i < size1; i++ ) sum += buffer1[i];
	for ( int i = 0; i < size2; i++ ) mul *= buffer2[i];

	cout << "The maximum and minimum are " << mul << " and " << sum << "." << endl;
    }
}
