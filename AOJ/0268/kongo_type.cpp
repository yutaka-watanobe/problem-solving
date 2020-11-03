#include<iostream>
#include<iomanip>
#include<sstream>
using namespace std;

int main() {
  int q;
  cin >> q;

  while ( q-- ) {
    unsigned int b;
    cin >> hex >> b;

    double res = (b&0x7fffffff) >> 7;//整数部の値で初期化
	
    //小数部を加算
    double frac = 0.5;
    for ( int i=6; i>=0; --i ) {
      if ( (b>>i)&1 ) res += frac;
      frac *= 0.5;
    }

    //フォーマット
    stringstream ss;
    ss << setprecision(15) << fixed << res;
    string s = ss.str();
    for ( int i=s.size()-1; i>0; --i ) {
      if ( s[i] != '0' ) {
        s.erase( i+1, s.size() );
        break;
      }
    }
    cout << ((b>>31)?"-":"") << s << ((b&0x0000007f)?"":"0") << endl;
  }
  return 0;
}
