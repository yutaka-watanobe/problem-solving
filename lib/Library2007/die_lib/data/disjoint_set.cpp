#include <iostream>

using namespace std;

const int NMAX = 100000;

// -1 に初期化しとく
int pi[NMAX];

int find(int i){
  if(pi[i] == -1) return i;
  return pi[i] = find(pi[i]);
}

void unite(int a, int b){
  int pa = find(a), pb = find(b);
  if(pa != pb) pi[pa] = pb;
}

bool same(int a, int b){
  return find(a) == find(b);
}
