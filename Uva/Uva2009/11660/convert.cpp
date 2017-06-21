#include<iostream>
#include<string>

using namespace std;

string itoa(int x){
  char a[20];
  sprintf(a, "%d", x);
  return string(a);
}

main(){
  string str = itoa(123);

  cout << str << endl;
}
