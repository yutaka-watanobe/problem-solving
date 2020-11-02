#include<iostream>
#include<string>
#include<regex>

using namespace std;

int main(){
  string A = ">'(=+)#\\1~$";
  string B = ">\\^(Q=)+~~$";
  int n; cin >> n;
  for ( int i = 0; i < n; i++ ) {
    string snake; cin >> snake;
    if( regex_search(snake, regex(A)) )
      cout << "A" << endl;
    else if( regex_search(snake, regex(B)) )
      cout << "B" << endl;
    else
      cout << "NA" << endl;
  }
  return 0;
}



