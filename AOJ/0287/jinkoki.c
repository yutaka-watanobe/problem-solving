#include<stdio.h>

const char* table[] = {"", "Man", "Oku", "Cho", "Kei", "Gai", "Jo", 
                       "Jou", "Ko", "Kan", "Sei", "Sai", "Gok", "Ggs",
                       "Asg", "Nyt", "Fks", "Mts"};//18種類
int main() {
  int m, n, i, j, carry;
  int block[18];

  while ( scanf("%d %d", &m, &n) == 2 && m != 0 || n != 0 ) {

    block[0] = m;
    for ( i = 1; i < 18; ++i ) block[i] = 0;

    for ( i = 1; i < n; ++i ) {
      for ( j = 0; j < 18; ++j ) block[j] *= m; //全ブロックにmを掛ける
      for ( j = 0; j < 18; ++j ) {//繰り上がり処理
        if ( block[j] >= 10000 ) {
          carry = block[j] / 10000;//繰り上がり分
          block[j + 1] += carry;
          block[j] -= carry * 10000;
        }
      }
    }

    //出力
    for ( i = 17; i >= 0; --i ) 
      if ( block[i] ) printf("%d%s", block[i], table[i]);
    printf("\n");
  }
  return 0;
}
