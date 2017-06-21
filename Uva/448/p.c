// @JUDGE_ID:  17051CA  448  C++
// @begin_of_source_code
/* シミュレーション */
/* バイトコードからもとのアセンブラ言語へ変換する */
/* input は逐次読み込まないとダメ */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<stl.h>

string com;

string itoa(long x){
  char a[20];
  sprintf(a, "%ld", x);
  return string(a);
}

void getMode(int a, vector<int> &mode, int t){
  mode.clear();
  while( 1 ){
    mode.push_back( a%2 );
    a = a/2;
    if(a==0 ) break;
  }
  while(mode.size()<4) mode.push_back(0);
  reverse(mode.begin(), mode.end());
}

string getOperand(string com){
  string top = "";
  top += com[0];
  string value = com.substr(1, 3);
  int m;
  long v;
  sscanf(top.c_str(), "%x", &m);
  sscanf(value.c_str(), "%x", &v);

  int add;
  vector<int> mode;

  getMode(m, mode, add);

  v += mode[2]*8192 + mode[3]*4096;

  if(mode[0]+mode[1]==0){
    return "R" + itoa(v);
  }else if(mode[0]==0 && mode[1]==1){
    return "$" + itoa(v);
  }else if(mode[0]==1 && mode[1]==0){
    return "PC+" + itoa(v);
  }else if(mode[0]+mode[1]==2){
    return itoa(v);
  }

}

void work(){
  string s;
  char operand, ch;

  while(scanf("%c", &operand)!=EOF){
    if(operand=='\n') continue;
    int n;
    switch(operand){
    case '0':
    case '1':
    case '2':
    case '3':
    case '4': n = 2; break;
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    case 'A':
    case 'B': n = 1; break;
    case 'C':
    case 'D':
    case 'E': n = 3; break;
    case 'F': n = 1; break;
    }
    switch(operand){
    case '0': cout << "ADD "; break;
    case '1': cout << "SUB "; break;
    case '2': cout << "MUL "; break;
    case '3': cout << "DIV " ; break;
    case '4': cout << "MOV "; break;
    case '5': cout << "BREQ "; break;
    case '6': cout << "BRLE "; break;
    case '7': cout << "BRLS " ; break;
    case '8': cout << "BRGE "; break;
    case '9': cout << "BRGR "; break;
    case 'A': cout << "BRNE "; break;
    case 'B': cout << "BR "; break;
    case 'C': cout << "AND "; break;
    case 'D': cout << "OR "; break;
    case 'E': cout << "XOR "; break;
    case 'F': cout << "NOT "; break;
    }

    for(int i=0; i<n; i++){
      if(i!=0) cout << ",";
      s = "";
      for(int j=0; j<4; j++){
	scanf("%c", &ch);
	if(ch=='\n') j--;
	else s += ch;
      }
      cout << getOperand(s);
    }
    cout << endl;
  }
}

main(){
  work();
}
// @end_of_source_code
