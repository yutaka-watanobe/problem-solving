// sumが３の倍数なら,３の倍数の数でチェック
// sumが３の倍数でないなら、消せるかのチェック
// 消せないならTの勝ち
// 消せるなら３の倍数の数+1でチェック
#include<iostream>
#include<string>

using namespace std;

char check ( int ndiv3 ){
    if ( ndiv3 % 2 == 0 ) return 'T';
    else return 'S';
}

char judge(){
    string line;
    cin >> line;
    int ndiv3 = 0;
    int sum = 0;
    if ( line.size() == 1 ) return 'S';

    for ( int i = 0; i < line.size(); i++ ){
	int d = line[i]-'0';
	sum += d;
	if ( d % 3 == 0 ) ndiv3++;
    }

    if ( sum % 3 == 0 ) return check( ndiv3 );

    for ( int i = 0; i < line.size(); i++ ){
	int d = line[i]-'0';
	if ( (sum-d) % 3 == 0 ) return check( ndiv3 + 1 );
    }

    return 'T';
}

int main(){
    int tcase; cin >> tcase;
    for ( int i = 1; i <= tcase; i++ ){
	cout << "Case " << i << ": ";
	cout << judge() << endl;
    }
    return 0;
}
