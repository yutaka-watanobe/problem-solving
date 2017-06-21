#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cassert>

using namespace std;

const int MAX_SIZE = 10000;
const int MIN_SIZE = 1;

char getClass(int m,int e,int j){
  if( (m == 100 || e == 100 || j == 100) ||
      ( (m+e)/2. >= 90) ||
      ( (m+e+j)/3. >= 80))
    return 'A';

  if( ( (m+e+j)/3. >= 70) ||
      ( (m+e+j)/3. >= 50 && (e >= 80 || m >= 80) ) )
    return 'B';
  
  return 'C';
}

main(){
  int n;
  
  while(cin >> n && n){
    int pm,pe,pj;
    assert( MIN_SIZE <= n && n <= MAX_SIZE);

    for(int i = 0;i<n;i++){
      cin >> pm >> pe >> pj;
      assert( 0 <= pm && pm <= 100);
      assert( 0 <= pe && pe <= 100);
      assert( 0 <= pj && pj <= 100);
      
      cout << getClass(pm,pe,pj) << endl;
    }
  }
  return 0;
}
  
