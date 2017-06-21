// @JUDGE_ID:  40075EY  187  c++

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstdio>
#include <cstring>

using namespace std;


class D2 {
 public:
  string id;
  string name;

  D2( ) { }
  D2( string i, string n ) {
    id = i;
    name = n;
  }
};


static const string ilegal = "000";
static const string balance = "999";
static const string bc_string = "Out of Balance";

vector< D2 > account;


void input( map< string, long long int > &tr,  string id, long long int money )
{
  if( tr.find( id ) == tr.end( ) )  tr[ id ] = money;
  else                              tr[ id ] += money;
}


void Print( map< string, long long int > &tr, long long int ammount )
{
  for( unsigned int i = 0 ; i < account.size( ) ; i++ )
    if( tr.find( account[ i ].id ) != tr.end( ) ) {
      printf( "%s %-30s %10.2f\n", account[ i ].id.c_str( ), account[i].name.c_str( ),
            ( ( double ) tr[ account[ i ].id ] ) / 100 );
    }

  printf( "%s %-30s %10.2f\n", balance.c_str( ), bc_string.c_str( ), ( ( double ) -ammount ) / 100 );
  printf( "\n" );
}


int main( )
{
  string tmp;

  while( true ) {
    getline( cin, tmp );

    string id = tmp.substr( 0, 3 );
    string name = tmp.substr( 3, tmp.size( ) - 3 );

    if( id == ilegal ) break;

    account.push_back( D2( id, name ) );
  }

  getline( cin, tmp );
  string sequence_id = tmp.substr( 0, 3 );

  while( sequence_id != ilegal ) {
    map< string, long long int > transaction;

    string sid;
    string id = tmp.substr( 3, 3 );

    long long int money;
    sscanf( tmp.c_str( ) + 6, "%lld", &money );
    input( transaction, id, money );
    long long int ammount =  money;

    while( true ) {
      getline( cin, tmp );
      sid = tmp.substr( 0, 3 );
      if( sid != sequence_id )  break;

      id = tmp.substr( 3, 3 );
      sscanf( tmp.c_str( ) + 6, "%lld", &money );
      input( transaction, id, money );

      ammount += money;
    }


    if( ammount != 0 ) {
      printf( "*** Transaction %s is out of balance ***\n",
sequence_id.c_str( ) );
      Print( transaction, ammount );
    }

    sequence_id = sid;
  }

  return 0;
}


