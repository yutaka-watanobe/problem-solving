// @JUDGE_ID:  17051CA  405  C++
// @begin_of_source_code
/* Simulation - Routing ( parsing ) */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<map>

class OriginatorRecipient{
 public:
  string next, country, ADMD, PRMD, organization;
  OriginatorRecipient(){}
  OriginatorRecipient( string next, string country, string ADMD, string PRMD, string organization): next(next), country(country), ADMD(ADMD), PRMD(PRMD), organization( organization ){}

};

class MTA{
 public:
  string name;
  vector<OriginatorRecipient> OR;

  MTA(){}
  MTA( string name ): name(name){}
  
};

class MessageRouting{
 public:
  vector<MTA> M;
  vector<int> visited;

  map<string, int> StoI;
  map<int, string> ItoS;
  OriginatorRecipient target;
  

  void parse( int pos ){

    MTA mta = M[ pos ];
    
    if ( visited[ pos ] ){
      cout << "circular routing detected by " << mta.name << endl;
      return;
    }

    visited[ pos ] = true;
    for ( int i = 0; i < mta.OR.size(); i++ ){
      OriginatorRecipient nextOR = mta.OR[i];
      if (  (target.country == nextOR.country || nextOR.country == "*" ) &&
	    (target.ADMD == nextOR.ADMD || nextOR.ADMD == "*" ) &&
	    (target.PRMD == nextOR.PRMD || nextOR.PRMD == "*" ) &&
	    (target.organization == nextOR.organization || nextOR.organization == "*" ) ){

	if ( nextOR.next == mta.name ){
	  cout << "delivered to " <<  mta.name << endl;
	  return;
	} else {
	  parse( StoI[ nextOR.next] );
	  return;
	}
	
      } 
    }

    cout << "unable to route at " << mta.name << endl;
  }


  void work(){
    int n;
    cin >> n;
    string next, country, ADMD, PRMD, organization;

    for ( int i = 0; i < n; i++ ){
      cin >> next >> country >> ADMD >> PRMD >> organization;
      target = OriginatorRecipient( next, country, ADMD, PRMD, organization );

      cout << i+1 << " -- ";
      visited.clear();
      visited.resize( M.size(), 0 );
      parse( StoI[ target.next ] );
    }
    
  }

  bool read(){
    int m;
    if ( ! ( cin >> m ) ) return false;
    M.clear();
    M.resize( m );
    StoI.clear();
    ItoS.clear();

    string name, next, country, ADMD, PRMD, organization;
    int a;

    for ( int i = 0; i < m; i++ ){
      cin >> name >> a;
      M[i] = MTA( name );
      StoI[ name ] = i;
      ItoS[ i ] = name;
      for ( int k = 0; k < a; k++ ){
	cin >> next >> country >> ADMD >> PRMD >> organization;
	M[i].OR.push_back( OriginatorRecipient( next, country, ADMD, PRMD, organization ) );
      }
    }

    return true;
  }
  
};

main(){
  MessageRouting MR;
  for ( int i = 1; MR.read(); i++ ){
    cout << "Scenario # " << i << endl;
    MR.work();
    cout << endl;
  }
}

// @end_of_source_code


