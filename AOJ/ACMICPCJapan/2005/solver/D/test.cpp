#include<iostream>
#include<string>
using namespace std;

int N = 10000;

main(){
  int x = 10000;


  string st = "";
  for ( int i = 0; i < N; i++ ) st += 'a';
  for ( int i = 0; i < x; i++ ){
    st = st.substr(N - N/2) + st.substr(0, N/2);
    }
  
  /*
  char ch[10000];
  for ( int i = 0; i < N; i++ ) ch[i] = 'a';
  for ( int i = 0; i < x; i++ ){
    for ( int i = 0; i < N/2; i++ ) ch[i] = ch[i];
    for ( int i = N/2; i < N; i++ ) ch[i] = ch[i];
    }*/
  
}
