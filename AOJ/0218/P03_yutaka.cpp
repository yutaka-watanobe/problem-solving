#include<iostream>
using namespace std;

char getClass(int m, int e, int j){
    if ( m == 100 || e == 100 || j == 100 ||
	 (m + e)/2 >= 90 || (m + e + j)/3 >= 80 ) return 'A';
    if ( (m + e + j)/3 >= 70 ||
	 (m + e + j)/3 >= 50 && m >= 80 || e >= 80 ) return 'B';
    return 'C';
}

int main(){
    int n, pm, pe, pj;
    while( cin >> n && n ){
	for ( int i = 0; i < n; i++ ){
	    cin >> pm >> pe >> pj;
	    cout << getClass(pm, pe, pj) << endl;
	}
    }
    return 0;
}

/*
生徒を数学、英語、国語の点数から条件に従ってA、B、Cのクラスに振り分ける問題です。

等価演算、比較演算、論理演算等を用いて簡単な条件分岐が記述できるかが問われています。

３科目それぞれの点数 m, e, j を引数として、クラスを表す文字を返す関数 getClass()を作成します。getClassは問題文で与えられた条件に従って、該当するクラスの文字を返します。 main関数ではそれぞれの点数 pm, pe, pjを読み込み getClass(pm, pe, pj)を出力します。
 */
