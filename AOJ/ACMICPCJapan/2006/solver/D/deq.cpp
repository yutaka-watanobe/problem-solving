/**
 *  Sum of Different Primes (PKU 3132)
 *  by Kenji Inoue, 2006-12-23
 **/

#include <iostream>

using namespace std;

int p[1130]; // primes
int pnum;
int c[1121][15][188]; // cache

void calc_primes() {
  p[0] = 2;
  pnum = 1;
  for (int i=3; i<=1120; i+=2) {
    bool add = true;
    for (int j=0; j<pnum; j++) {
      if (p[j]*p[j] > i) { break; }
      if (i % p[j] == 0) {
        add = false;
        break;
      }
    }
    if (add) { p[pnum++] = i; }
  }
}

int solve(int n, int k, int idx) {
  if (n == 0 && k == 0) {
    return 1;
  } else if (n == 0 || k == 0) {
    return 0;
  }
  if (c[n][k][idx] >= 0) { return c[n][k][idx]; }

  int cnt = 0;
  for (int i=idx; i<pnum; i++) {
    if (p[i] > n) {
      break;
    } else {
      cnt += solve(n - p[i], k - 1, i+1);
    }
  }
  c[n][k][idx] = cnt;
  
  return cnt;
}

int main() {
  calc_primes();
//cout << pnum << endl;
//for (int i=0; i<pnum; i++) { cout << p[i] << ", "; }
  memset(c, -1, sizeof(c));
  
  int n, k;
  while (cin >> n >> k, (n || k)) {
    cout << solve(n, k, 0) << endl;
  }
  
  return 0;
}

