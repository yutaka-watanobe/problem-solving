#include<iostream>
#include<string>

using namespace std;

int monthTable[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int date[13];
string dayTable[7] = {"Thursday", "Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday"};

void initialize(){
    date[0] = 0;
    date[1] = monthTable[1];
    for ( int i = 2; i <= 12; i++ ){
	date[i] = date[i-1] + monthTable[i];
    }
}

main(){
    initialize();
    int month, day;
    while( cin >> month >> day && month){
	cout << dayTable[(date[month-1]+day-1)%7] << endl;
    }
}
