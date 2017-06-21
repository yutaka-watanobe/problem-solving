#include<iostream>
#include<string>
using namespace std;

main(){
  string s = "abcdef";
  s.replace(1,2, "xxxx");
  cout << s << endl;
}
