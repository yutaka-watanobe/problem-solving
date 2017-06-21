#include<iostream>
#include<string>
using namespace std;

main(){
  string num;
  int d[10];

  while(cin >> num ){
    for ( int i = 0; i < 10; i++ ) d[i] = num[i]-'0';
    for ( int e = 8; e >= 0; e-- ){
      for ( int i = 0; i <= e; i++ ){
	d[i] = (d[i]+d[i+1])%10;
      }
    }
  cout << d[0] << endl;
  }

}
