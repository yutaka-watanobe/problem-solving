#include<iostream>
using namespace std;
#define N 10000000

bool P[N + 1];

void eratos(){
    for ( int i = 0; i <= N; i++ ) P[i] = true;
    P[0] = P[1] = false;
    for ( int i = 2; i*i <= N; i++ )
	if ( P[i] )
	    for ( int j = 2; i*j <= N; j++ ) P[i*j] = false;
}

int getQuads(int n){
    for ( int i = n; i >= 13; i--)
	if ( P[i] && P[i-2] && P[i-6] && P[i-8] ) return i;
}

main(){
    eratos();
    int n;
    while( cin >> n && n ) cout << getQuads(n) << endl;
}

/*
大きさがn以下になるような四つ子素数のうち、最大となるものの大きさを求める問題です。

素数表を作成し、高速な素数判定を行うプログラムが作成できるかが問われています。

まずエラトステネスの篩によって入力値の最大値である10,000,000以下の数についての素数表を作成します。この素数表を使い四つ子素数の位置をを n から始める線形探索によって探し出します。
 */
