#include<iostream>
#include<algorithm>
using namespace std;

int main(){
  int n;
  int sum;
  while( cin >> n && n ){
    int x;
    sum = 0;
    for ( int i = 0; i < n*(n-1)/2; i++ ){
      cin >> x;
      sum += x;
    }
    cout << sum/(n-1) << endl;
  }
}
