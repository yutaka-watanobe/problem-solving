#include<iostream>
using namespace std;

main(){
  int x = 37;
  
  int bit = (1 << 6 );
  cout << x << " - " << bit << endl;

  if ( x & bit == 0){
    cout << x << " - " << bit << endl;
  }
	
}
