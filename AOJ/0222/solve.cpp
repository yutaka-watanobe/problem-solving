#include<iostream>
#include<vector>
#include<cassert>

using namespace std;

const int MAX_NUM = 10000000;
const int MIN_NUM = 13;

vector<int> qprime;
bool isPrime[MAX_NUM+10];

void makePrime(){
  for(int i = 0;i<=MAX_NUM+10;i++)
    isPrime[i] = true;
  isPrime[0] = isPrime[1] = true;

  for(int i = 2;i<=MAX_NUM+10;i++)
    if(isPrime[i]){
      for(int j = i*2;j<=MAX_NUM+10;j+=i)
	isPrime[j] = false;
    }
}

void makeQuad(){
  for(int i = 8;i<=MAX_NUM;i++)
    if(isPrime[i-8] && isPrime[i-6] && isPrime[i-2] && isPrime[i])
      qprime.push_back(i);
}

main(){
  makePrime();
  makeQuad();
  
  int num;
  while(cin >> num && num){
    assert(MIN_NUM <= num && num <= MAX_NUM);

    for(int i = 0;i<qprime.size();i++){
      if(qprime[i] > num){
	cout << qprime[i-1] << endl;
	break;
      }
      if(i == qprime.size()-1)
	cout << qprime[qprime.size()-1] << endl;
    }
  }
  return 0;
}
