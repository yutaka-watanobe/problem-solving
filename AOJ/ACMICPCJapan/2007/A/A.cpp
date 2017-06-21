#include<iostream>
#include<vector>
using namespace std;

main(){
  int n, k, pre, target; // m == pre
  vector<int> buffer;
  while( cin >> n >> k >> pre, n && k && pre ) {
    buffer.resize(n);
    for ( int i = 0; i < n; i++ ) buffer[i] = i+1;
    
    pre--;
    
    buffer.erase( buffer.begin() + pre%buffer.size() );
    
    while( buffer.size() > 1 ){
      target = (pre + k -1)%buffer.size();
      buffer.erase( buffer.begin() + target );
      pre = ( target == buffer.size() ) ? 0 : target;
    }
    
    cout << buffer[0] << endl;
  }
}
