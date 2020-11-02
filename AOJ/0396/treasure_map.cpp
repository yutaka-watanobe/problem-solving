#include<iostream>
#include<vector>
using namespace std;

int main() {
  int w, h;
  cin >> w >> h;
    
  int sumC = 0, sumR = 0;
  vector<int> col(w);
  vector<int> row(h);
  for ( int i = 0; i < w; ++i ) {
    cin >> col[i];
    sumC += col[i];
  }
  for ( int i = 0; i < h; ++i ) {
    cin >> row[i];
    sumR += row[i];
  }

  if ( sumR != sumC ) {
    cout << "0" << endl;
    return 0;
  }
    
  for ( int i = 0; i < w; ++i ) {

    sort(row.rbegin(), row.rend());

    for ( int j = 0; j < h; ++j ) {
      if ( !col[i] || !row[j] ) break;
      --row[j];
      --col[i];
    }

    if ( col[i] > 0 ) {
      cout << "0" << endl;
      return 0;
    }
  }
  cout << "1" << endl;
  return 0;
}
