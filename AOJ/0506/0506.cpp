#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

string tranceform(string str){
    char pre = str[0];
    int cnt = 1;
    char a[1000];
    string v = "";
    for ( int i = 1; i < str.size(); i++ ){
	if ( pre != str[i] ){
	    sprintf(a, "%d", cnt);
	    v += string(a) + pre;
	    cnt = 1;
	} else cnt++;
	pre = str[i];
    }
    sprintf(a, "%d", cnt);
    v += string(a) + pre;
    return v;
}

int main(){
    int n;
    string str;
    while(1){
	cin >> n;
	if ( n == 0 ) break;
	cin >> str;

	for ( int i = 0; i < n; i++ ){
	    str = tranceform(str);
	}

	cout << str << endl;
    }

    return 0;
}
