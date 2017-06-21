// @JUDGE_ID:  17051CA  2486  C++
// @begin_of_source_code
/* Dynamic Programming */
#include<stdio.h>
#include<iostream>
#include<string>
#include<map>
#include<queue>

string companyName;
int ceoIndex;

int nemployee;
vector<int> invitedCounter;
vector<int> unaskedCounter;
vector<int> childrenCounter;
vector<string> parentIDList;
map< string, int> IDtoIndex;

void printResult(){
  cout << companyName << ": " << invitedCounter[ ceoIndex ] << endl;
}

void work(){
  queue<int> Q;

  for ( int i = 0; i < nemployee; i++ ){
    if ( childrenCounter[i] == 0 ) Q.push( i );
  }

  int current;
  while ( !Q.empty() ){
    current = Q.front(), Q.pop();
    if ( current == ceoIndex ) continue;

    int parentIndex = IDtoIndex[ parentIDList[ current ] ];

    int candidate = max( unaskedCounter[ current ], invitedCounter[ current ] );
    unaskedCounter[ parentIndex ] += candidate;
    invitedCounter[ parentIndex ] += unaskedCounter[ current ];

    childrenCounter[ parentIndex ]--;

    if ( childrenCounter[ parentIndex ] == 0 ) Q.push( parentIndex );
  }

  printResult();
}

void init(){
  invitedCounter.clear();
  unaskedCounter.clear();
  parentIDList.clear();
  childrenCounter.clear();
  IDtoIndex.clear();
  invitedCounter.resize( nemployee, 0 );
  unaskedCounter.resize( nemployee, 0 );
  parentIDList.resize( nemployee, "" );
  childrenCounter.resize( nemployee, 0 );
}

bool read(){
  getline( cin, companyName );
  if ( companyName == "#" ) return false;
  cin >> nemployee;

  init();
  
  string ID, parentID;
  int sociability;

  for ( int i = 0; i < nemployee; i++ ){
    cin >> ID >> sociability >> parentID;
    IDtoIndex[ ID ] = i;
    
    if ( parentID == "-" ) ceoIndex = i;

    invitedCounter[ i ] = sociability;
    unaskedCounter[ i ] = 0;
    parentIDList[ i ] = parentID;
  }

  for ( int i = 0; i < nemployee; i++ ){
    string parentID = parentIDList[ i ];
    if ( parentID == "-" ) continue;
    int parentIndex = IDtoIndex[ parentID ];
    childrenCounter[ parentIndex ]++;
  }

  string empty_line;
  getline( cin, empty_line );
  return true;
}

main(){
  while ( read() ){
    work();
  }
}
// @end_of_source_code
