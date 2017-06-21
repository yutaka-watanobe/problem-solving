#include<iostream>
using namespace std;

main(){
  cout << 2 << endl;
  cout << "31 31" << endl;

  cout << "page1 100" << endl;
  for ( int x = 1; x <= 28; x+=3 ){
    for ( int y = 1; y <= 28; y+=3 ){
      cout << x << " " << y << " " << x+2 << " " << y+2 << " " << "page2" << endl;
    }
  }

  cout << "page2 100" << endl;
  for ( int x = 1; x <= 28; x+=3 ){
    for ( int y = 1; y <= 28; y+=3 ){
      cout << x << " " << y << " " << x+2 << " " << y+2 << " " << "page1" << endl;
    }
  }

  static const int T[10] = {2, 5, 8, 11, 14, 17, 20, 23, 26, 29};
  int q = 1000;
  cout << q*4 << endl;
  for ( int i = 0; i < q; i++ ){
    cout << "click " << T[rand()%10] << " " << T[rand()%10] << endl;
    cout << "show" << endl;
  }
  for ( int i = 0; i < q; i++ ){
    cout << "back" << endl;
    cout << "show" << endl;
  }

  cout << 0 << endl;
}
