#include<iostream>
#include<vector>
using namespace std;

const char* table[] = {"", "Man", "Oku", "Cho", "Kei", "Gai", "Jo", 
                       "Jou", "Ko", "Kan", "Sei", "Sai", "Gok", "Ggs",
                       "Asg", "Nyt", "Fks", "Mts"};//18種類
int main() {
  int m, n;

  while ( cin >> m >> n && m != 0 || n != 0 ) {

    vector<int> block(18);
    block[0] = m;
    for ( int i = 1; i < n; ++i ) {
      for ( int j = 0; j < 18; ++j ) block[j] *= m; //全ブロックにmを掛ける
      for ( int j = 0; j < 18; ++j ) {//繰り上がり処理
        if ( block[j] >= 10000 ) {
          int carry = block[j] / 10000;//繰り上がり分
          block[j + 1] += carry;
          block[j] -= carry * 10000;
        }
      }
    }

    //出力
    for ( int i = 17; i >= 0; --i ) 
      if ( block[i] ) cout << block[i] << table[i];
    cout << endl;
  }
  return 0;
}
