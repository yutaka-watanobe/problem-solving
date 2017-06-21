#include<iostream>
using namespace std;

main(){
  char ch;
  while( cin >> ch ){
    if ( isdigit(ch) ){
      ch = ch+1;
    }
    cout << ch;
  }
}
