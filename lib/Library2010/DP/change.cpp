/*
コイン問題

1 円硬貨, 5 円硬貨, 10 円硬貨, 50 円硬貨, 100 円硬貨, 500 円硬貨
を使って, ちょうど n 円支払うとき、硬貨の枚数を最小にして下さい。
ただし、各硬貨について枚数の制限はありません。


    0  1  2  3  4  5  6  7  8  9  10  11  12  13  14  15
    0  X  X  X  X  X  X  X  X  X   X   X   X   X   X   X
1   0  1  2  3  4  5  6  7  8  9  10  11  12  13  14  15
5   0  1  2  3  4  1  2  3  4  5   2   3   4   5   6   3
10  0  1  2  3  4  1  2  3  4  5   1   2   3   4   5   2

    0  1  2  3  4  5  6  7  8  9  10  11  12  13  14  15
    0  X  X  X  X  X  X  X  X  X   X   X   X   X   X   X
5   0  X  X  X  X  1  X  X  X  X   2   X   X   X   X   3
10  0  X  X  X  X  1  X  X  X  X   1   X   X   X   X   2
1   0  1  2  3  4  1  2  3  4  5   1   2   3   4   5   2

    0  1  2  3  4  5  6  7  8  9  10  11  12  13  14  15
    0  X  X  X  X  X  X  X  X  X   X   X   X   X   X   X
10  0  X  X  X  X  X  X  X  X  X   1   X   X   X   X   X
1   0  1  2  3  4  5  6  7  8  9   1   2   3   4   5   6
5   0  1  2  3  4  1  2  3  4  5   1   2   3   4   5   2
*/


#include<iostream>
using namespace std;
#define MAX 3000

//static const int C[6] = {1, 5, 10, 50, 100, 500};
static const int C[6] = {1, 2, 7, 8, 12, 50};
int T[MAX+1];

void makeTable(){
    for ( int j = 0; j <= MAX; j++ ) T[j] = (1<<21);
    T[0] = 0;
    for ( int i = 0; i < 6; i++ ){
	for ( int j = C[i]; j <= MAX; j++ ){
	    T[j] = min(T[j], T[j-C[i]] + 1);
	}
    }
}

int main(){
    makeTable();
    int n;
    while( cin >> n ) cout << T[n] << endl;

    return 0;
}
