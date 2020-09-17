#include<iostream>
using namespace std;

int main(){
  string D[] = {"thu", "fri", "sat", "sun", "mon", "tue", "wed"}; // 曜日を表す配列
  int X; cin >> X;
  cout << D[X % 7] << endl; // 7で割った余りから曜日を求めてその文字列を出力
  return 0;
}
