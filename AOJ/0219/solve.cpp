#include<iostream>
#include<cassert>
#include<map>

using namespace std;

const int MAX_SIZE = 10000;
const int MIN_SIZE = 1;
const int MAX_ICE = 9;
const int MIN_ICE = 0;

main(){
  int n;
  while(cin >> n && n != -1){
    map<int,int> ice;

    int num;
    for(int i = 0;i<n;i++){
      cin >> num;
      ice[num]++;
    }
     
    for(int i = 0;i<=9;i++){
      for(int j = 0;j<ice[i];j++)
	cout << '*';
      if(ice[i] == 0)
	cout << "-";
      cout << endl;
    }
  }
  return 0;
}
