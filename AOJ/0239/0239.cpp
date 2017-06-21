#include<iostream>
using namespace std;

struct Item{
  int id, p, l, c;
};

main(){
  int n;
  int vp, vl, vc, vC;

  Item I[1001];

  while(1){
    cin >> n;
    if ( n == 0 ) break;

    for ( int i = 0; i < n; i++ ){
      cin >> I[i].id >> I[i].p >> I[i].l >> I[i].c;
    }
    cin >> vp >> vl >> vc >> vC;

    int cnt = 0;
    for ( int i = 0; i < n; i++ ){
      if ( I[i].p > vp || I[i].l > vl || I[i].c > vc ) continue;
      if ( I[i].p*4 + I[i].l*9 + I[i].c*4 > vC ) continue;
      cout << I[i].id << endl;
      cnt++;
    }
    if ( cnt == 0 ) cout << "NA" << endl;
  }
  return 0;
}
