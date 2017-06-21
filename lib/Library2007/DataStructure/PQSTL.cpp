#include<iostream>
#include<queue>

using namespace std;

main(){
  priority_queue<int> PQ;
  int x;
    string command;
 
    while(1){
	cin >> command;
	if ( command == "insert" ){
	    cin >> x;
	    PQ.push(x);
	} else if ( command == "get" ){
	  cout << PQ.top() << endl; PQ.pop();
	} else break;
    }

  
}
