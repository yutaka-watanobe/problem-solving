/* @JUDGE_ID: 13511WK 445 C++ */

#include <stdio.h>
#include <stl.h>
#include <ctype.h>

main(){
  char ch, pch;
  int n = 0;
  int f = 0;

  while(scanf("%c", &ch)!=EOF){
    if(ch!='\n' && f==2){ cout << endl; f = 0; }
    if(isdigit(ch)){
      n += ch-'0';
    }
    else if(ch=='\n'){
      if(f<1 && pch!='!') cout << endl;
      f++;
    }
    else if(ch=='!' && pch!='!'){ cout << endl; }
    else {
      if(ch=='b') ch = ' ';
      for(int i=0; i<n; i++) cout << ch;
      n = 0;
    }
    pch = ch;
  }
  cout << endl;
}
