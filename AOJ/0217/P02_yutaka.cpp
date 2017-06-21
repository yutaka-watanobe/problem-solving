#include<iostream>
using namespace std;

int main(){
    int n, p, maxp, maxv, d1, d2;

    while( cin >> n && n ){
	maxv = -1;
	for ( int i = 0; i < n; i++ ){
	    cin >> p >> d1 >> d2;
	    if ( maxv < d1 + d2 ){
		maxp = p;
		maxv = d1 + d2;
	    }
	}
	cout << maxp << " " << maxv << endl;
    }

    return 0;
}

/*
n 人の患者がそれぞれ d1i + d2i だけ歩いたときに、最も長い距離を歩いた患者の番号pi を求める問題です。

与えられたリストについて最大値を求めるプログラムを記述できるかが問われています。

現在の最大の距離を maxv, その最大の距離を歩いた患者の番号を maxp とします。最初に maxv を -1 に初期化し、それぞれの患者の情報 p, d1, d2 を読み込み、d1 + d2 が maxv よりも大きければ maxv を d1 + d2 に、maxp を p に置き換えます。データセットについて全ての患者の情報を調べた後の maxp 及び maxv を出力します。 

*/
