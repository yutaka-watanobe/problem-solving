#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream.h>
#include<string>

main(){
  string s1 = "";
  string s2 = "";
  int i;
  int carryCount = 0;
  int carry = 0;

  do{
    cin >> s1;
    cin >> s2;
    
    for(i=0 ; i < s1.size() ; i++){
      int index = s1.size() - i -1;
      cout << "index " << index << " ";
      cout << s1[index] << " " << s2[index] << "\n";
      
      int v1 = atoi( s1[index]+"" );
      int v2 = atoi( s2[index]+"" );
      carry = v1 + v2 + carry;
      cout << v1 << " " << v2 << "\n";
    }

  } while ( s1 != "0" && s2 != "0");

  return 0;
}
