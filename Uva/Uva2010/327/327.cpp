#include<iostream>
#include<string>
using namespace std;
#define N 26

bool isVariable(char ch){
  return 'a' <= ch && ch <= 'z';
}

string normalize(string line){
  string str = "";
  for ( int i = 0; i < line.size(); i++ ){
    if ( line[i] == ' ' ) continue;
    str += line[i];
  }
  return str;
}

void compute(string exp){
  int B[N], A[N], V[N];
  bool U[N];
  for ( int i = 0; i < 26; i++ ) B[i] = A[i] = V[i] = 0;
  for ( int i = 0; i < 26; i++ ) U[i] = false;
  

  for ( int i = 0; i < exp.size()-1; i++ ){
    if( exp[i] != exp[i+1] ) continue;
    if ( i > 0 && isVariable(exp[i-1]) ){
      if ( exp[i] == '+' ) A[exp[i-1]-'a']++;
      if ( exp[i] == '-' ) A[exp[i-1]-'a']--;
    }
    if ( i+1 < exp.size()-1 && isVariable(exp[i+2])){
      if ( exp[i] == '+' ) B[exp[i+2]-'a']++;
      if ( exp[i] == '-' ) B[exp[i+2]-'a']--;
    }
    exp[i] = exp[i+1] = ' ';
  }
  exp = normalize(exp);

  int value = 0;
  int op = 1;
  for ( int i = 0; i < exp.size(); i++ ){
    if ( !isVariable(exp[i])) continue;
    char v = exp[i];
    if ( i-1 < 0 ) op = 1;
    else if ( exp[i-1] == '+' ) op = 1;
    else op = -1;
    
    U[v-'a'] = true;
    V[v-'a'] = v-'a'+1 + B[v-'a'];
    value += op*V[v-'a'];
    V[v-'a'] += A[v-'a'];
  }

  cout << "    value = " << value << endl;
  for ( int i = 0; i < N; i++ ){
    if (!U[i]) continue;
    cout << "    " << (char)(i+'a') << " = " << V[i] << endl;
  }

}

main(){
  string line;
  while(1){
    getline(cin, line);
    if ( cin.eof() ) break;
    cout << "Expression: " << line << endl;
    compute(normalize(line));
  }
}
