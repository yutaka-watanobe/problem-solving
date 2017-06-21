/*

与えられた範囲 L - U 間の素数テーブルを作成
エラトステネスの篩の応用
 */
#include<iostream>
#include<cmath>
#include<vector>
#define MAX 1000001
using namespace std;

void eratos ( int L, int U, int n, bool prime[]){

  int i, j;

  for ( i = 0; i <= n; i++ ) prime[i] = true;
  
  if ( L%2 == 0) i = L;
  else i = L + 1;
  i -= L;
  for ( ; i < n; i += 2 ) prime[i] = false;

  int limit = (int)sqrt((double)U) ;
  
  for ( i = 3; i <= limit; i += 2 ){
    if ( i >= L && !prime[i-L] ) continue;
    j = L/i*i;
    if (j<L) j+=i;
    if (j==i) j+=i; 
    j -= L;
    for ( ; j < n; j += i ) prime[j] = false;
  }

  if ( L <= 1 ) prime[1-L] = false;
  if ( L <= 2 ) prime[2-L] = true;
}

main(){
  int L, U, size;
  bool buffer[MAX];
  while ( cin >> L >> U ){
    eratos(L, U, U-L+1, buffer);
    vector<int> p;
    for ( int i = 0; i < U-L+1; i++ ){
      if ( buffer[i] ) p.push_back(i+L);
    }

    if ( p.size() < 2 ){
      cout << "There are no adjacent primes." << endl;
      continue;
    }

    int minv, mini, maxv, maxi;
    minv = MAX;
    maxv = 0;
    for ( int i = 0; i < p.size()-1; i++ ){
      if ( minv > p[i+1]-p[i] ){
	minv = p[i+1]-p[i];
	mini = i;
      }
      if ( maxv < p[i+1]-p[i] ){
	maxv = p[i+1]-p[i];
	maxi = i;
      }
    }
    cout << p[mini] << "," << p[mini+1] << " are closest, ";
    cout << p[maxi] << "," << p[maxi+1] << " are most distant." << endl;
  }
}
