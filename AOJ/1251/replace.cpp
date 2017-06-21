#include<iostream>
#include<string>
using namespace std;

main(){
  string str = "af./fadf./aaffff./xxxx";

  cout << str.substr(1, 3) << endl;
  /*
  bool f;
  while(1){
    int p = str.find("./");
    if ( p == string::npos ) break;
    str.replace(p, 2, "");
  }

  cout << str << endl;
  */
}
