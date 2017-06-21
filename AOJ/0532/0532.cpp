#include<iostream>
using namespace std;

main(){
  int h, m, s, hh, mm, ss, te, ts, t;

  for ( int i = 0; i < 3; i++ ){
    cin >> h >> m >> s >> hh >> mm >> ss ;
    ts = 3600*h + 60*m + s;
    te = 3600*hh + 60*mm + ss;
    t = te - ts;
    cout << t/3600 << " "; t %= 3600;
    cout << t/60 << " "; t %= 60;
    cout << t << endl;
  }
}
