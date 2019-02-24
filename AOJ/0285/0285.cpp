#include<iostream>
#include<string>
using namespace std;

int J, Y;

void parse(int j, int y, string p){
  if ( j == J && y == Y ){
    cout << p << endl; return;
  } else if ( j == 5 && y <= 3 || y == 5 && j <= 3){
    return;
  }
  if ( j > J || y > Y ) return;
  parse(j+1, y, p + "A"); 
  parse(j, y+1, p + "B"); 

}

main(){
  cin >> J >> Y;
  parse(0, 0, "");
}
