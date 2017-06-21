#include<stdio.h>
#define MAX 100000

char s[MAX], t[MAX];
int ssize, tsize;

bool check(){
    if ( ssize > tsize ) return false;
    
    int j = 0;
    for ( int i = 0; i < ssize; i++ ){
	while( j < tsize && t[j] != s[i] ) j++;
	if ( j >= tsize ) return false;
	j++;
    }
    return true;
}

int main(){

    while ( scanf("%c", &s[0]) != EOF){
	ssize = 1;
	while(1){
	    scanf("%c", &s[ssize]);
	    if ( s[ssize] == ' ' ) break;
	    ssize++;
	}
	tsize = 0;
	while(1){
	    scanf("%c", &t[tsize]);
	    if ( t[tsize] == '\n' ) break;
	    tsize++;
	}

	if ( check() ) printf("Yes\n");
	else printf("No\n");
    }

    return 0;
}
