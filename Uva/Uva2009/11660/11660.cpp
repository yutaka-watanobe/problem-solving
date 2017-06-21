#include<iostream>
#include<string>
using namespace std;
#define LIMIT 10000
string str;
int n, k;

string itoa(int x){
  char a[20];
  sprintf(a, "%d", x);
  return string(a);
}

string convert(string s){
    string str = "";
    int i = 0;
    int cnt = 1;

    while(1){
	if ( i == s.size()-1 ){
	    str += itoa(cnt);
	    str += s[i];
	    break;
	}
	if ( s[i] == s[i+1] ){
	    cnt++; i++;
	} else {
	    str += itoa(cnt);
	    str += s[i];
	    cnt = 1; i++;
	}
	if ( str.size() > k+1000 ) break;
    }
    //    cout << str << endl;
    return str;
}

void simulate(){
    for ( int i = 0; i < n-1; i++ ) str = convert(str);
    //    cout << str << endl;
    cout << str[k-1] << endl;
}

main(){
    while(1){
	cin >> str >> n >> k;
	if ( str == "0" && n == 0 && k == 0 ) break;
	simulate();
    }
}
