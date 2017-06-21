#include <string.h>
#include <cctype>
#include <iostream>
#include <fstream.h>


int gcd(int ab, int cd) {
  int temp;
  while (cd) {
    temp = ab;
    ab = cd;
    cd = temp % cd;
  }
  return ab;
}

void main()
{
	ifstream inFile;
	int a, b;

	inFile.open("gcd.txt");
	
	while(!inFile.eof()) {
	    inFile >> a >> b;
	    cout << gcd(a,b) <<'\n';
	}

	inFile.close();	
}