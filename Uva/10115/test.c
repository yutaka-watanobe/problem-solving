#include<stdio.h>
#include<string>

main(){
  string s = "yutaka watanobe";
  string::size_type pos = s.find("watanobe");
  string::size_type t = 3;
  cout << pos << endl;
  s.replace(s.begin()+pos, s.begin()+pos+3, "HOW");

  cout << s << endl;
}
