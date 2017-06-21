#include<iostream>
using namespace std;

main(){
  int n, h, m, w, b, e, tm;
  int L, D, M;
  int nL, nD, nM;
  char ch;

  while(1){
    cin >> n;
    if ( n == 0 ) break;
    L = D = M = nL = nD = nM = 0 ;

    for ( int i = 0; i < n; i++ ){
      cin >> h >> ch >> m >> w;
      
      if ( h <= 2 ) h += 24;
      
      b = 60*h + m;
      if ( w < m ){
	tm = 60+w - m;
      } else {
	tm = w - m;
      }
      
      if ( 660 <= b && b < 900 ) {
	nL++;
	if ( tm <= 8 ) L++;
      } else if ( 1080 <= b && b <1260 ){
	nD++;
	if ( tm <= 8 ) D++;
      } else if ( 1260 <= b && b < 1560 ){
	nM++;
	if ( tm <= 8 ) M++;
      }
    }
    cout << "lunch ";
    if ( nL == 0 ) cout << "no guest" << endl;
    else cout << 100*L/nL << endl;
    
    cout << "dinner ";
    if ( nD == 0 ) cout << "no guest" << endl;
    else cout << 100*D/nD << endl;
    
    cout << "midnight ";
    if ( nM == 0 ) cout << "no guest" << endl;
    else cout << 100*M/nM << endl;
  }
}
