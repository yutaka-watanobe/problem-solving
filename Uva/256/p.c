// @JUDGE_ID:  17051CA  256  C++
// @begin_of_source_code
#include<stdio.h>
#include<vector>
#include<string>

int read();
void work();
void createTable();

vector<string> v2;
vector<string> v4;
vector<string> v6;
vector<string> v8;

int n;

int read(){
  cin >> n;
  if( cin.eof() ) return 0;
  else return 1;
}

void work(){
  switch(n){
  case 2:
    for( int i=0; i<v2.size(); i++){
      cout << v2[i] << endl;
    }
    break;
  case 4:
    for( int i=0; i<v4.size(); i++){
      cout << v4[i] << endl;
    }
    break;
  case 6:
    for( int i=0; i<v6.size(); i++){
      cout << v6[i] << endl;
    }
    break;
  case 8:
    for( int i=0; i<v8.size(); i++){
      cout << v8[i] << endl;
    }
    break;
  }
}

void createTable(){
  v2.clear();
  v4.clear();
  v6.clear();
  v8.clear();
  /*
  for(int x=0; x<= 9; x++){
    for(int y=0; y<= 9 ; y++){
      if( (x+y)*(x+y) == 10*x+y ){
	printf("%1d%1d", x, y);
	cout << endl;
      }
    }
  }
  for(int x=0; x<= 99; x++){
    for(int y=0; y<= 99 ; y++){
      if( (x+y)*(x+y) == 100*x+y ){
	printf("%2d%2d", x, y);
	cout<< endl;
      }
    }
  }
  for(int x=0; x<= 999; x++){
    for(int y=0; y<= 999 ; y++){
      if( (x+y)*(x+y) == 1000*x+y ){
	printf("%3d%3d", x, y);
	cout << endl;
      }
    }
  }
  for(int x=0; x<= 9999; x++){
    for(int y=0; y<= 9999 ; y++){
      if( (x+y)*(x+y) == 10000*x+y ){
	printf("%4d%4d", x, y);
	cout << endl;
      }
    }
  }
  */
  v2.push_back("00");
  v2.push_back("01");
  v2.push_back("81");
  v4.push_back("0000");
  v4.push_back("0001");
  v4.push_back("2025");
  v4.push_back("3025");
  v4.push_back("9801");
  v6.push_back("000000");
  v6.push_back("000001");
  v6.push_back("088209");
  v6.push_back("494209");
  v6.push_back("998001");
  v8.push_back("00000000");
  v8.push_back("00000001");
  v8.push_back("04941729");
  v8.push_back("07441984");
  v8.push_back("24502500");
  v8.push_back("25502500");
  v8.push_back("52881984");
  v8.push_back("60481729");
  v8.push_back("99980001");
  
}
main(){
  createTable();
  while(read()){
    work();
  }
}
// @end_of_source_code
