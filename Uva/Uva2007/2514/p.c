// @JUDGE_ID:  17051CA  2514  C++
// @begin_of_source_code
/* Simulation */
#include<stdio.h>
#include<iostream>
#include<set>
#include<map>
#define POLICY1 1
#define POLICY2 2

class Manager{
 public:
  map<int, bool> removalList;
  set<int> request;
  int current;
  int policy;

  void removeProcess(){
    if ( request.size() == 0 ){
      cout << "-1" << endl;
      return ;
    }

    if ( policy == POLICY1 ){
      if ( removalList[ current ] ){
	cout << *request.begin() << endl;
      }
      request.erase( request.begin() );
      current++;
    } else if ( policy == POLICY2 ){
      int shift = request.size() - 1;
      if ( removalList[ current ] ){
	cout << *(--request.end() ) << endl;
      }
      request.erase( --request.end() );
      current++;
    }
  }

  void work(){
    char command;
    policy = POLICY1;
    request.clear();
    current = 1;

    while ( 1 ){
      cin >> command;
      
      if ( command == 'a' ){
	int process;
	cin >> process;
	request.insert( process );
      } else if ( command == 'p' ){
	cin >> policy;
      } else if ( command == 'r' ){
	removeProcess();
      } else if ( command == 'e' ){
	return ;
      } else {
	assert( false );
      }
    }
  }

  bool read(){
    int maximum_cost;
    if ( ! ( cin >> maximum_cost ) ) return false;
    removalList.clear();

    int l, k;
    cin >> l;
    for ( int i = 0; i < l; i++ ){
      cin >> k;
      removalList[ k ] = true;
    }

    return true;
  }
};

main(){
  Manager manager;

  while ( manager.read() ){
    manager.work();
    cout << endl;
  }

}

// @end_of_source_code


