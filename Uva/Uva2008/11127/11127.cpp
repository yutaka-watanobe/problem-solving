#include<iostream>
using namespace std;
#define MAX 32
int size;
char str[MAX];

int cnt;

void recursive(int cur){
    //check

    for ( int w = 1; w*3 <= cur; w++ ){
	bool triple = true;
	for ( int j = 0; j < w; j++ ){
	    if ( str[cur-w+j] != str[cur-2*w+j] ||
		 str[cur-w+j] != str[cur-3*w+j] ||
		 str[cur-2*w+j] != str[cur-3*w+j] ){
		triple = false; continue;
	    }
	}
	if ( triple ) return;
    }


    if ( cur == size ) {
	cnt++;
	return ;
    }
    
    if ( str[cur] == '*' ){
	str[cur] = '1';
	recursive(cur+1);
	str[cur] = '0';
	recursive(cur+1);
	str[cur] = '*';
    } else {
	recursive(cur+1);
    }
}

int compute(){
    cnt = 0;
    recursive(0);
    return cnt;
}

int main(){
    int tcase = 1;
    while( cin >> size && size){
	for ( int i = 0; i < size; i++ ) cin >> str[i];
	cout << "Case " << tcase++ << ": " << compute() << endl;
    }
    return 0;
}
