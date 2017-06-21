#include<iostream>
using namespace std;

#define MAX 100

void selectionSort( int size, int data[]){
    for ( int front = 0; front < size - 1; front++ ){
	int minIndex = front; 
        for ( int j = front + 1; j < size; j++ ){
            if ( data[j] < data[minIndex] ) minIndex = j;
        }
	int tmp = data[front];
	data[front] = data[minIndex];
	data[minIndex] = tmp;
    }
}

int main(void){
    int size, data[MAX];

    cin >> size;
    for ( int i = 0; i < size; i++ ) cin >> data[i];

    selectionSort(size, data);

    for ( int i = 0; i < size; i++ ) cout << data[i] << " ";
    cout << endl;
    
    return 0;
}

