
#include<iostream>
#include<string>
#include<map>

using namespace std;

main(){

  map<char, string> e;
  
  e['A'] = "00000"; 
  e['B'] = "00001";
  e['C'] = "00010";
  e['D'] = "00011";
  e['E'] = "00100";
  e['F'] = "00101";
  e['G'] = "00110"; 
  e['H'] = "00111"; 
  e['I'] = "01000";
  e['J'] = "01001";
  e['K'] = "01010";
  e['L'] = "01011";
  e['M'] = "01100";
  e['N'] = "01101";
  e['O'] = "01110"; 
  e['P'] = "01111";
  e['Q'] = "10000";
  e['R'] = "10001";
  e['S'] = "10010";
  e['T'] = "10011";
  e['U'] = "10100"; 
  e['V'] = "10101";
  e['W'] = "10110";
  e['X'] = "10111";
  e['Y'] = "11000";
  e['Z'] = "11001";
  e[' '] = "11010"; 
  e['.'] = "11011";
  e[','] = "11100";
  e['-'] = "11101";
  e['\'']= "11110";
  e['?'] = "11111";

  map<string, char> d;
  d["101"] = ' ';
  d["000000"] = '\'';
  d["000011"] = ','; 
  d["10010001"] = '-'; 
  d["010001"] = '.';
  d["000001"] = '?'; 
  d["100101"] = 'A'; 
  d["10011010"] = 'B'; 
  d["0101"] = 'C';
  d["0001"] = 'D'; 
  d["110"] = 'E'; 
  d["01001"] = 'F'; 
  d["10011011"] = 'G';
  d["010000"] = 'H'; 
  d["0111"] = 'I'; 
  d["10011000"] = 'J'; 
  d["0110"] = 'K';
  d["00100"] = 'L'; 
  d["10011001"] = 'M'; 
  d["10011110"] = 'N';
  d["00101"] = 'O';
  d["111"] = 'P'; 
  d["10011111"] = 'Q'; 
  d["1000"] = 'R'; 
  d["00110"] = 'S'; 
  d["00111"] = 'T'; 
  d["10011100"] = 'U';  
  d["10011101"] = 'V'; 
  d["000010"] = 'W'; 
  d["10010010"] = 'X'; 
  d["10010011"] = 'Y'; 
  d["10010000"] = 'Z'; 

  string s;
  while(getline(cin, s)){
    if(s == "")break;
    string t = "";
    for(int i=0; i<s.length(); i++){
      t += e[s[i]];
    }
    
    string ans = "";
    
    for(int i=0; i<t.length(); i++){
      string tmp = "";
      for(int j=i; j<t.length(); j++){
	tmp += t[j];	  
	i = j;
	if(d[tmp] != 0){
	  ans += d[tmp];
	  break;
	}
      }
    }
    cout << ans << endl;
  }
}
      
    


