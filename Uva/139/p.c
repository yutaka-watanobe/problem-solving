// @JUDGE_ID:  17051CA  139  C++
// @begin_of_source_code
/* Simulation */
#include<stdio.h>
#include<iostream>
#include<string>
#include<map>
#include<vector>

void trim(string &s){
  int l, r;

  l = s.find_first_not_of(" \n\r");
  r = s.find_last_not_of(" \n\r");

  if(l==string::npos) s = "";
  else  s = s.substr(l, r-l+1);
}

class Call{
 public:
  string name;
  int price;
  
  Call(){price = -1;}
  Call(string name, int price): name(name), price(price){}

};

map<string, Call> IDD_M;
map<string, Call> STD_M;
vector<string> IDD_H;
vector<string> STD_H;

void read(){
  string number, name;
  int price;

  while ( 1 ){
    cin >> number;
    char name[3000];
    string s;

    if ( number == "000000" ) return;
    cin.getline(name, 3000, '$' );
    s = name;
    trim(s);
    cin >> price;

    if ( number[0] == '0' && number[1] != '0' && 2 <= number.size() && number.size() <= 6){
      STD_M[number] = Call( s, price );
      STD_H.push_back( number );
    }

    if ( number[0] == '0' && number[1] == '0' && 3 <= number.size() && number.size() <= 5){
      IDD_M[number] = Call( s, price );
      IDD_H.push_back( number );
    }
    
  }
  
}

void telephone(string number, int duration ){
  string name;
  string local_number;

  bool unknown = false;

  double price, cost;

  if ( number[0] != '0' ){
    local_number = number;
    name = "Local";
    local_number = number;
    price = 0.0;
    cost = 0.0;
  }else if ( number[0] == '0' && number[1] != '0' && 6 <= number.size() && number.size() <= 13){ /* STD */
    for ( int i = 0; i < STD_H.size(); i++ ){
      if ( number.find( STD_H[i] ) == 0 ){
	local_number = number.substr( STD_H[i].size(), number.size() - STD_H[i].size());
	if ( !(4 <= local_number.size() && local_number.size() <= 7) ) continue;
	name = STD_M[ STD_H[i] ].name;
	price = STD_M[ STD_H[i] ].price / 100.0;
	cost = duration * price;
	goto next;
      }
    }
    unknown = true;
  }else if ( number[0] == '0' && number[1] == '0' && 7 <= number.size() && number.size() <= 15){ /* IDD */
    for ( int i = 0; i < IDD_H.size(); i++ ){
      if ( number.find( IDD_H[i] ) == 0 ){
	local_number = number.substr( IDD_H[i].size(), number.size() - IDD_H[i].size());
	if ( !(4 <= local_number.size() && local_number.size() <= 10) ) continue;
	name = IDD_M[ IDD_H[i] ].name;
	price = IDD_M[ IDD_H[i] ].price / 100.0;
	cost = duration * price;
	goto next;
      }
    }
    unknown = true;
  }else{
    unknown = true;
  }

 next:;

  if ( unknown ){
    cost = -1;
    local_number = "";
    name = "Unknown";
  }

  printf("%-16s%-26s%10s%5d", number.c_str(), name.c_str(), local_number.c_str(), duration);
  if ( unknown ){
    cout << "      ";
  }else printf( "%6.2f", price);
  printf( "%7.2f", cost);
  cout << endl;

}

void work(){
  string number;
  int duration;

  while ( 1 ){
    cin >> number;
    if ( number == "#" ) break;
    cin >> duration;
    telephone( number, duration );
  }
}

main(){
  read();
  work();
}
// @end_of_source_code
