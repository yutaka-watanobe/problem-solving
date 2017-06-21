#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool judge(int x, string y){
    if ( x % 3 == 0 && x % 5 == 0 ) return y == "FizzBuzz";
    if ( x % 3 == 0 ) return y == "Fizz";
    if ( x % 5 == 0 ) return y == "Buzz";
    if ( !isdigit(y[0]) ) return false;
    return x == atoi(y.c_str());
}

int main(){
    int m, n;
    string num;
    while( cin >> m >> n && m ){
	vector<int> P;
	int cur = 0, w = -1;
	for ( int i = 1; i <= m; i++ ) P.push_back(i);

	for ( int i = 1; i <= n; i++ ){
	    cin >> num;
	    if ( w != -1 ) continue;
	    if ( judge(i, num) ) cur++;
	    else P.erase(P.begin() + cur);
	    cur = cur%P.size();
	    if ( P.size() == 1 ) w = P[0];
	}

	if ( w != -1 ) cout << w << endl;
	else {
	    for ( int i = 0; i < P.size(); i++ ) 
		cout << ((i)?" ":"") << P[i];
	    cout << endl;
	}
    }
    return 0;
}

/*
Fizz Buzzのシミュレーションを行う問題です。プレイヤーの発言が順番に与えられたときの、途中経過あるいは最後まで残っていたプレイヤーを出力しなければなりません。

簡単なシミュレーションを行うプログラムが記述できるかが問われています。

可変長の配列として扱える vector<int> を使って、残っているプレイヤーを管理しシミュレーションを行います。まず、発言の順番 x と発言された言葉 y を引数にとり、発言が正答かどうかを判定する関数 judge() を定義します。この関数では問題に定義されたように、3の倍数かつ5の倍数番目では発言が"FizzBuzz"であるか、3の倍数番目では発言が"Fizz"であるか、5の倍数番目では発言が"Buzz"であるか、それ以外では順番 x が y に等しいかどうかを判定します。

シミュレーション本体では、現在の発言者をカーソル cur で示し、１つずつ発言 num を読み込み、発言が正答であれば cur を１つ進め、そうでなければ cur の位置のプレイヤーを削除します。カーソルは残っているプレイヤーを循環するように cur = cur%P.size() とし、途中でプレイヤーが一人になった場合は、読み込み処理を除いてシミュレーション処理を終了します。

 */
