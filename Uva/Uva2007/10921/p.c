// Phone push simulation
#include<iostream>
#include<string>

string line;

char T[255];

void work(){
  for ( int i = 0; i < line.size(); i++ ){
    char ch = line[i];
    cout << T[ ch ];
  }
  cout << endl;
}

void init(){
  T['A'] = '2';
  T['B'] = '2';
  T['C'] = '2';
  T['D'] = '3';
  T['E'] = '3';
  T['F'] = '3';
  T['G'] =  '4';
  T['H'] =  '4';
  T['I'] =  '4';
  T['J'] = '5';
  T['K'] = '5';
  T['L'] = '5';
  T['M'] = '6';
  T['N'] =  '6';
  T['O'] = '6';
  T['P'] = '7';
  T['Q'] = '7';
  T['R'] = '7';
  T['S'] = '7';
  T['T'] = '8';
  T['U'] = '8';
  T['V'] = '8';
  T['W'] = '9';
  T['X'] = '9';
  T['Y'] = '9';
  T['Z'] = '9';
  T['-'] = '-';
  T['1'] = '1';
  T['0'] = '0';
}

main(){
  init();
  while ( cin >> line ){
    work();
  }
}
