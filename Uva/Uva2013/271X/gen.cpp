#include<iostream>
#include<string>

using namespace std;

main(){
  string test = "pqrstuvwxyzNCDEI";

  for ( int  i = 0; i < 1000; i++ ){
    for ( int j = 0; j < 10; j++ ){
      cout << test[rand()%test.size() ];
    }
    cout << endl;
  }
}
