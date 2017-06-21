#include<iostream>
using namespace std;

int main(){
    int n, T[10], x;
    while( cin >> n && n ){
	for ( int i = 0; i < 10; i++ ) T[i] = 0;
	for ( int i = 0; i < n; i++ ){ cin >> x; T[x]++; }
	for ( int i = 0; i < 10; i++ ){
	    if (T[i] == 0 ) cout << "-" << endl;
	    else {
		for ( int j = 0; j < T[i]; j++ ) cout << "*";
		cout << endl;
	    }
	}
    }
    return 0;
}

/*
入力として与えられる数字がそれぞれ何回現われたか数え、結果を棒グラフとして画面上に出力する問題です。

与えられる数字は0〜9と小さい数であるため、簡単な配列の操作を行うプログラムが作成できるかが問われています。

それぞれの数字をカウントするための整数型配列 T[10] を用意します。T[x] に数字 x の出現回数を記録します。
 */
