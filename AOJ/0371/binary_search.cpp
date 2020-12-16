#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
  int N = 7;
  int A[] = {1, 2, 2, 4, 5, 7, 8};
  vector<int> V = {1, 2, 2, 4, 5, 7, 8};

  cout << (binary_search(A, A + N, 2) ? "yes" : "no") << endl;           // yes
  cout << (binary_search(A, A + N, 3) ? "yes" : "no") << endl;           // no

  cout << (binary_search(V.begin(), V.end(), 2) ? "yes" : "no") << endl; // yes
  cout << (binary_search(V.begin(), V.end(), 3) ? "yes" : "no") << endl; // no

  return 0;
}
