#include<stdio.h>
#include<map>


main(){
  map<char, int> mp1;
  map<char, int> mp2;

  mp1['a'] = 1;

  if(mp1 == mp2) cout<< "same" << endl;
  else cout << "def" << endl;

  mp2['a'] = 1;
if(mp1 == mp2) cout<< "same" << endl;
  else cout << "def" << endl;
  
}
