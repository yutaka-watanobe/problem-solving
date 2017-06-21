#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;

const int MODULO = 10000;
const int UNIT_LENGTH = 4;
const int DATA_LENGTH = 400;

class BigInt{
public:
  
  int pos;
  int data[DATA_LENGTH];

  BigInt(){
    setData("0");
  }

  BigInt(const char *data){
    setData(data);
  }

  void init(void){
    fill(data, data+DATA_LENGTH, 0);
    pos = 0;
  }

  void setData(const char str[]){
    init();

    int length = strlen(str);
    for(int i = 0; length > 0; ++i){
      if(i == UNIT_LENGTH){
	i = 0;
	++pos;
      }
      data[pos] += (str[--length]-'0') * (int)pow(10.0, i);
    }
    ++pos;
  }
  
  void output(void) const{
    cout << data[pos-1];
    cout << setfill('0');
    for(int i = pos-2; i >= 0; --i)
      cout << " " << setw(UNIT_LENGTH) << data[i];
    cout << endl;
  }

  void operator+=(const BigInt &bint){
    pos = max(pos, bint.pos);
    for(int i = 0; i < pos; i++){
      data[i] += bint.data[i];
      data[i+1] += data[i] / MODULO;
      data[i] %= MODULO;
    }

    if(data[pos] > 0)
      ++pos;
  }
  
  void operator-=(const BigInt &bint){
    for(int i = 0; i < pos; i++){
      data[i] -= bint.data[i];
      while(data[i] < 0){
	--data[i+1];
	data[i] += MODULO;
      }
    }
    while(data[pos-1] <= 0)
      --pos;
  }

  void operator*=(const int &num){ // num <= INT_MAX / MODULO
    for(int i = 0; i < pos; i++)
      data[i] *= num;
    for(int i = 0; i < pos; ++i){
      data[i+1] += data[i] / MODULO;
      data[i] %= MODULO;
    }
    while(data[pos] > 0){
      data[pos+1] += data[pos] / MODULO;
      data[pos] %= MODULO;
      ++pos;
    }
  }
    
  void operator/=(const int &divider){ // divider < MODULO ?
    for(int i = pos-1; i > 0; --i){
      int reminder = data[i] % divider;
      data[i] /= divider;
      data[i-1] += reminder * MODULO;
    }
    while(data[pos-1] <= 0)
      --pos;
    data[0] /= divider;
  }
  
  bool operator<(const BigInt &bint) const{
    if(pos < bint.pos)
      return true;
    else if(pos > bint.pos)
      return false;
    for(int i = pos-1; i >= 0; i--){
      if(data[i] < bint.data[i])
	return true;
      else if(data[i] > bint.data[i])
	return false;
    }
    return false;
  }
  
  bool operator>(const BigInt &bint) const{
    if(pos > bint.pos)
      return true;
    else if(pos < bint.pos)
      return false;
    for(int i = pos-1; i >= 0; i--){
      if(data[i] > bint.data[i])
	return true;
      else if(data[i] < bint.data[i])
	return false;
    }
    return false;
  }

  bool operator==(const BigInt &bint) const{
    if(pos != bint.pos)
      return false;
    for(int i = 0; i < pos; ++i)
      if(data[i] != bint.data[i])
	return false;
    return true;
  }

  double log(void) const{
    if(pos == 0)
      return -1;
    return log10((double)data[pos-1]) + (pos-1)*UNIT_LENGTH;
  }
  
  BigInt &operator--(void){
    for(int i = 0; i < pos; i++){
      --data[i];
      if(data[i] < 0)
	data[i] += MODULO;
      else
	break;
    }
    if(data[pos-1] <= 0)
      --pos;
    
    return *this;
  }

  void operator>>=(const int &num){
    for(int i = 0; i < num; i++){
      for(int j = 0; j < pos; j++){
	data[j] /= 10;
	data[j] += (data[j+1]%10) * (MODULO/10);
      }
      while(data[pos-1] <= 0)
	--pos;
    }
  }
};
