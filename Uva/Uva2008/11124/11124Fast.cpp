#include<stdio.h>
#include<string>
#include<sstream>
using namespace std;
#define REP(i,e) for ( int i = 0; i < (int)(e); i++)
typedef long long llong;
#define MAX 1000000

char tmp;
void addNList(int buffer[], int &size ){
    int n, x;
    scanf("%d", &n);
    REP(i, n) {
	scanf("%c", &tmp);
	scanf("%d", &buffer[size++]);
    }
}

void addIList(int buffer[], int &size ){
    int n, s, d;
    //    scanf("%d", &n);
    //    scanf("%c", &tmp);
    //    scanf("%d", &s);
    //    scanf("%c", &tmp);
    //    scanf("%d", &d);
    scanf("%d%c%d%c%d", &n, &tmp, &s, &tmp, &d);
    REP(i, n) buffer[size++] = s + i*d;
}

void addRList(int buffer[], int &size ){
    llong n, l, h, s;
    //    unsigned int s;
    //    scanf("%lld", &n);
    //    scanf("%c", &tmp);
    //    scanf("%lld", &l);
    //    scanf("%c", &tmp);
    //    scanf("%lld", &h);
    //    scanf("%c", &tmp);
    //    scanf("%lld", &s);
    scanf("%lld%c%lld%c%lld%c%lld", &n, &tmp, &l, &tmp, &h, &tmp, &s);
    llong sub = h - l + 1;
    for ( int i = 0; i < n; i++ ){
	s = (s*17 + 11);
	//	s += (s << 4);
	//	s += 11;
	s &= 0x00000000ffffffffll; 
	buffer[size++] = s%sub + l;
    }
}

int main(){
    int index, size, tcase;;
    int buffer[MAX];
    tcase = 1;
    char ch;
    while(1){
	scanf("%d", &index);
	if ( index == 0 ) break;
	scanf("%c", &ch );
	size = 0;
	while(1){
	    scanf("%c", &ch );
	    if ( ch == '\n' ) break;
	    if ( ch == 'N' ){
		REP(i,5) scanf("%c", &ch);
		addNList(buffer,size);
		scanf("%c", &ch);
	    } else if ( ch == 'I' ){
		REP(i,5) scanf("%c", &ch);
		addIList(buffer,size);
		scanf("%c", &ch);
	    } else if ( ch == 'R' ){
		REP(i,5) scanf("%c", &ch);
		addRList(buffer,size);
		scanf("%c", &ch);
	    }
	}
	
	sort( buffer, buffer + size );

	printf("Case %d: %d\n", tcase++, buffer[index-1]);
    }
    return 0;
}
