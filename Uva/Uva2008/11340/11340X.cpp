#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

void compute(){
    int T[256], v, k, m, value;
    fill( T, T + 256, 0 );
    char ch, line[10001];
    cin >> k;
    for ( int i = 0; i < k; i++ ){
	cin >> ch >> v;
	T[ch] = v;
    }
    cin >> m;
    value = 0;
    gets(line);
    for(int i = 0; i < m; i++){
	gets(line);
	for(int j = 0; line[j] != '\0' ; j++){
	    value += T[line[j]];
	}
    }
    printf("%.2f$\n",(float)value/100);
}

main(){
    int tcase; 
    char ch;
    cin >> tcase;
    for ( int i = 0; i < tcase; i++ ){
	compute();
    }
}
