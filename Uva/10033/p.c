// @JUDGE_ID:  17051CA  10033  C++
// @begin_of_source_code
/* Simulation */
#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<stl.h>

string itoa(int x){
  char a[5];
  sprintf(a, "%d", x);
  return string(a);
}

class RAM{
 public:
  int x, y, z;
  RAM(){}
  RAM(int x, int y, int z ): x(x), y(y), z(z){};
  void setValue( int v ){
    x = v/100;
    y = (v - (v/100)*100)/10;
    z = v%10;
  }
};

string line;
vector<int> R;
vector<RAM> M;

void read(){
  R.clear();
  M.clear();
  R.resize( 10, 0 );
  M.resize( 1001, RAM(0, 0, 0) );

  string str;
  
  int index = 0;
  while ( 1 ){
    getline( cin, str );
    if ( str == "" || cin.eof() ) break;;
    M[index] = RAM( str[0] - '0', str[1] - '0', str[2] - '0' ); 
    index++;
  }
}

void work(){
  int pos = 0;
  int instruction = 0;
  int op1, op2, op3, add;

  while ( 1 ){
    op1 = M[pos].x;
    op2 = M[pos].y;
    op3 = M[pos].z;
    switch(op1){
    case 1:
      if ( op2 == 0 && op3 == 0 ){
	instruction++;
	goto next;
      }
      break;
    case 2:
      R[ op2 ] = op3;
      break;
    case 3:
      R[ op2 ] = ( R[ op2 ] + op3 ) % 1000;
      break;
    case 4:
      R[ op2 ] = ( R[ op2 ] * op3 ) % 1000;
      break;
    case 5:
      R[ op2 ] = R[ op3 ];
      break;
    case 6:
      R[ op2 ] = ( R[ op2 ] + R[ op3 ] ) % 1000;
      break;
    case 7:
      R[ op2 ] = ( R[ op2 ] * R[ op3 ] ) % 1000;
      break;
    case 8:
      add = R[ op3 ];
      R[ op2 ] = M[add].x * 100 + M[add].y * 10 + M[add].z;
      break;
    case 9:
      add = R[ op3 ];
      M[ add ].setValue( R[ op2 ] );
      break;
    case 0:
      if ( R[ op3 ] != 0 ){
	pos = R[ op2 ] - 1;
      }
      break;
    }
    instruction++;
    pos++;
  }
  
 next:;
  cout << instruction << endl;
}

main(){
  int t;
  getline( cin, line );
  t = atoi ( line.c_str() );
  getline( cin, line );
  for ( int i = 0; i < t; i++ ){
    if ( i ) cout << endl;
    read();
    work();
  }
}
// @end_of_source_code
