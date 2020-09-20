#include<iostream>
using namespace std;

int j, y;

void parse(int a, int b, string path){
  if ( a == j && b == y ){
    cout << path << endl; return;
  } else if ( a == 5 && b <= 3 || b == 5 && a <= 3 ){
    return;
  }
  if ( a > j || b > y ) return;
  parse(a + 1, b, path + "A"); 
  parse(a, b + 1, path + "B"); 

}

int main(){
  cin >> j >> y;
  parse(0, 0, "");
  return 0;
}
