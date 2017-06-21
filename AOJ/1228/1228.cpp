#include<iostream>
#include<string>
using namespace std;
#define rep(i, n) for ( int i = 0; i < (int)n; i++ )
#define MAX 250

bool compute(string str1, string str2){
  bool V1[MAX][MAX], V2[MAX][MAX];
  int ldy1, ldx1, rty1, rtx1;
  int dy[6] = {1, 1, 0, -1, -1, 0};
  int dx[6] = {0, -1, -1, 0, 1, 1};
  if ( str1.size() != str2.size() ) return false;
  int n = (int)str1.size()*2+2;
  rep(y, n) rep(x, n) V1[y][x] = false;

  int py = n/2;
  int px = n/2;
  V1[py][px] = true;
  ldy1 = rty1 = py;
  ldx1 = rtx1 = px;
  rep(i, str1.size()){
    int r = (str1[i]-'a')%6;
    py += dy[r];
    px += dx[r];
    V1[py][px] = true;
    ldy1 = min(ldy1, py);
    ldx1 = min(ldx1, px);
    rty1 = max(rty1, py);
    rtx1 = max(rtx1, px);
  }

  rep(d, 6){
    int ldy2, ldx2, rty2, rtx2;
    py = n/2;
    px = n/2;
    ldy2 = rty2 = py;
    ldx2 = rtx2 = px;
    rep(y, n) rep(x, n) V2[y][x] = false;
    V2[py][px] = true;
    rep(i, str2.size()){
      int r = (str2[i]-'a'+d)%6;
      py += dy[r];
      px += dx[r];
      V2[py][px] = true;
      ldy2 = min(ldy2, py);
      ldx2 = min(ldx2, px);
      rty2 = max(rty2, py);
      rtx2 = max(rtx2, px);
    }
    if ( !(rty1-ldy1 == rty2-ldy2 && rtx1-ldx1 == rtx2-ldx2 ) ) continue;
    int h = rty1-ldy1+1;
    int w = rtx1-ldx1+1;
    bool same = true;
    rep(y, h) rep(x, w){
      if ( V1[y+ldy1][x+ldx1] != V2[y+ldy2][x+ldx2] ) {same = false; break;}
    }
    if ( same ) return true;
  }
  return false;
}

main(){
  int tcase; cin >> tcase;
  string str1, str2, kasu;
  getline(cin, kasu);
  rep(t, tcase) {
    getline(cin, str1);
    getline(cin, str2);
    if (compute(str1, str2) ) cout << "true" << endl;
    else cout << "false" << endl;
    getline(cin, kasu);
  }
}
