#include<stdio.h>
#include<map>
#include<iostream>
using namespace std;

void compute(){
    map<char, int > T;
    char ch, line[10001];
    int v, k, m, value;
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
	for(int j = 0; line[j] != '\0' ; j++) value += T[line[j]];
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
