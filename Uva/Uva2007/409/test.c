#include<stdio.h>
#include<string>
#include<stdlib.h>
#include<algorithm>

main(){
  string str1 = "abcdefghijk";

  cout << str1.find("abc") << endl;
  cout << str1.find("bc") << endl;
  cout << str1.find("zz") << endl;
  cout << string::npos << endl;
}
