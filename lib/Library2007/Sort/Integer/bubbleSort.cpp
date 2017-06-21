#include<iostream>
using namespace std;

#define MAX 100

void bubbleSort( int size, int data[] ){
    for ( int end = size - 1; end > 0; end-- ){
        for ( int j = 0; j < end; j++ ){
	    // —×‚Ç‚¤‚µ‚ð”äŠr‚µ‚ÄA‹t‡‚È‚ç‚ÎŒðŠ·
            if ( data[j+1] < data[j] ){
		int tmp = data[j];
		data[j] = data[j+1];
		data[j+1] = tmp;
            }
        }
    }
}

int main(void){
    int size, data[MAX];

    cin >> size;
    for ( int i = 0; i < size; i++ ) cin >> data[i];

    bubbleSort(size, data);

    for ( int i = 0; i < size; i++ ) cout << data[i] << " ";
    cout << endl;
    
    return 0;
}