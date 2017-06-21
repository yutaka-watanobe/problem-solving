#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cassert>
#include<string>

using namespace std;

const int MIN_SIZE = 1;
const int MAX_SIZE = 100;

string digit[10] = { "1111110",
		     "0110000",
		     "1101101",
		     "1111001",
		     "0110011",
		     "1011011",
		     "1011111",
		     "1110010",
		     "1111111",
		     "1111011"};

void changeDigit(int pre,int num){
  if(pre == -1){
    for(int i = 6;i>=0;i--)
      cout << digit[num][i];
    cout << endl;
    return;
  }

  for(int i = 6;i>=0;i--)
    cout << (string)( digit[pre][i] != digit[num][i] ? "1" : "0");
  cout << endl;
}

main(){
  int n;
  while(cin >> n && n != -1){
    assert(MIN_SIZE <= n && n <= MAX_SIZE);

    int pre = -1;

    for(int i = 0;i<n;i++){
      int num;
      cin >> num;
      assert(0 <= n && n <= 9);

      changeDigit(pre,num);
      pre = num;
    }
  }
  return 0;
}
      
