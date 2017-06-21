#include<stdio.h>
#include<math.h>
#include<string>
#define MAX 101

char buffer[MAX*MAX];
char T[MAX][MAX];
int size;

bool checkPalindrome(){
    int sq = (int)sqrt(size);
    if ( sq*sq != size ) return false;
    
    int n = (int)sqrt(size);
    int pos = 0;
    for ( int i = 0; i < n; i++ ){
	for ( int j = 0; j < n; j++ ){
	    T[i][j] = buffer[pos++];
	}
    }

    for ( int i = 0; i < n; i++ ){
	for ( int j = 0; j < n; j++ ){
	    if ( !( T[i][j] == T[j][i] &&
		    T[i][j] == T[n-i-1][n-j-1] &&
		    T[i][j] == T[n-j-1][n-i-1] ) ) return false;
	}
    }
    
    return true;
}

void compute(){
    char ch;
    size = 0;

    while(1){
	scanf("%c", &ch);
	if ( ch == '\n' ) break;
	if ( isalpha(ch) ) buffer[size++] = ch;
    }

    if ( checkPalindrome() ) printf("%d\n", (int)sqrt(size));
    else printf("No magic :(\n");
}

main(){
    int tcase; scanf("%d", &tcase);
    char ch; scanf("%c", &ch); // line
    for ( int i = 0; i < tcase; i++ ){
	printf("Case #%d:\n", i + 1);
	compute();
    }
}
