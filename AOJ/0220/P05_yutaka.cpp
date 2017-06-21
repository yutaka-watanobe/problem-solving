#include<iostream>
#include<vector>
using namespace std;

void convert1(int x, vector<int> &v){
    if ( x == 0 ) return;
    convert1(x/2, v);
    v.push_back(x%2);
}

void convert2(double x, vector<int> &v){
    if ( x == 0 ) return;
    v.push_back(x >= 1.0);
    convert2((x >= 1.0) ? (x-1)*2 : x*2, v);
}

int main(){
    for( double x; cin >> x && x >= 0; ){
	int a = (int)x;    // 整数部
	double b = x - a;  // 小数点以下
	vector<int> A, B;

	convert1(a, A);
	convert2(b*2, B);

	while( A.size() < 8 ) A.insert(A.begin(), 0);
	while( B.size() < 4 ) B.push_back(0);

	if ( A.size() > 8 || B.size() > 4 ) cout << "NA" << endl;
	else {
	    for ( int i = 0; i < A.size(); i++ ) cout << A[i];
	    cout << ".";
	    for ( int i = 0; i < B.size(); i++ ) cout << B[i];
	    cout << endl;
	}
    }

    return 0;
}

/*
#include<iostream>
using namespace std;

void convert(int x, int p){
    if ( p == 12 ) return;
    convert(x/2, p+1);
    if ( p == 3 ) cout << ".";
    cout << x%2;
}

int main(){
    for ( double x; cin >> x && x >= 0; ){
	int shift = (int)(x*16);
	if ( x == shift/16.0 && shift < 4096 ){
	    convert(shift, 0);
	    cout << endl;
	} else {
	    cout << "NA" << endl;
	}
    }
    return 0;
}

*/

/*
１０進数の実数を２進数に変換し出力する問題です。整数部が８桁以内、小数部が４桁以内に収まらない場合は NA と出力しなければなりません。

実数(浮動小数点数)の基数変換を行うプログラムが記述できるかが問われています。


[解法１]
与えられた実数を整数にシフトして基数変換を行います。まず与えれた数に16を掛け２進数で4桁分シフトします。シフトした値を16.0で割ったものが x と異なる、またはシフトした値が 4096 以上(２進数で13桁以上)であれば、制限桁数に収まらないと判断できるので NA と出力します。桁数に収まる場合は基数変換を行い適切な位置に.を含め結果出力します。

[解法２]
与えられた実数を整数部分と小数部分に分けて基数変換を行います。小数部分の基数変換は、まず小数部を２倍した数 x から始め、xが1以上の場合は1を1より小さい場合は0をビット列に追加し、xが1以上の場合は x から1を引いて2倍した値、1より小さい場合は x を2倍した値を次の x として変換処理を繰り返します。

 */
