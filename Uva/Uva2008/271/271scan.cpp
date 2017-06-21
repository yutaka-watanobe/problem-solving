#include<stdio.h>
#define MAX 10000

char line[MAX];
int size, pos;

bool parse(){
    if ( pos >= size ) return false;

    char ch = line[pos];

    if ( 'p' <= ch && ch <= 'z' ) return true;
    else if ( ch == 'N' ){
	pos++;
	return parse();
    } else {
	pos++;
	bool left = parse();
	if ( !left ) return false;
	pos++;
	bool right = parse();
	return left && right;
    }
}

bool check(){
    pos = 0;
    if ( !parse() ) return false;
    return pos == size-1;
}

int main(){
    char ch;
    while(1){
	size = 0;
	if ( scanf("%c", &line[size++]) == EOF ) break;
	while(1){
	    scanf("%c", &ch);
	    if ( ch == '\n' ) break;
	    line[size++] = ch;
	}
	if ( check()) printf("YES\n");
	else printf("NO\n");
    }
    return 0;
}
