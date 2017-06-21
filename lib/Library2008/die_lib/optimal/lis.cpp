#include <iostream>
#include <algorithm>

using namespace std;

const int NMAX = 100;

int prev[NMAX];        // 配列の i 番目の要素の直前の index
int l[NMAX], id[NMAX]  // 現在の lis (偽) の中身とその id

int lis(int a[], int n){
  int len = 0;
  for(int i = 0; i < n; ++i){
    int tgt = lower_bound(l, l+len, a[i]) - l;
    if(tgt == len)
      ++len;

    l[tgt] = a[i];
    id[tgt] = i;
    prev[i] = (tgt == 0 ? -1 : id[tgt-1]);
  }
  return len;
}

void output(int a[], int curr){
  if(curr != -1){
    output(a, prev[curr]);
    cout << a[curr] << ' ';
  }
}

int main(void){
  int n = 8;
  int v[8] = {-7, 10, 9, 2, 3, 8, 8, 1};
  int len = lis(v, n);
  cout << "length : " << len << endl;
  output(v, id[len-1]); cout << endl;
  return 0;
}
