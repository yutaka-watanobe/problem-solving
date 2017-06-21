#include<iostream>
#include<cassert>

using namespace std;

const int MAX_NUM = 200;
const int MIN_NUM = 0;
const int MAX_HIT = 1000;

main(){
  int b,r,g,c,s,t;
  
  while(cin >> b){
    
    cin >> r >> g >> c >> s >> t;

    if( !(b || r || g || c || s || t) )
      break;

    assert( MIN_NUM <= b && b <= MAX_NUM);
    assert( MIN_NUM <= r && r <= MAX_NUM);
    assert( MIN_NUM <= g && g <= MAX_NUM);
    assert( MIN_NUM <= c && c <= MAX_NUM);
    assert( MIN_NUM <= s && s <= MAX_NUM);
    assert( 6*b+4*r+g+c+s <= t && t <= MAX_HIT);

    cout << 100 + 15*(b+r) + 15*(5*b+3*r) + 7*g + 2*c - 3*(t-s-5*b-3*r) - 2*(5*b+3*r) << endl;
  }
  return 0;
}
   
      
