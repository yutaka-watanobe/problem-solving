// @JUDGE_ID:  17051CA  10683  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<cmath>
#include<string>

class DecadaryWatch{
 public:
  int time;

  void work(){
    double dtime = time * 125.0 / 108;
    time = (int)(dtime + 1e-10);
    printf("%07d\n", time);
    return;
  }

  bool read(){
    int hh, mm, ss, cc;
    string line;
    if ( !(cin >> line)  ) return false;
    // 最後の改行がないと間違える！！
    //    if ( cin.eof() ) return false; // Wrong Answer

    hh = (line[0] - '0')*10 + (line[1] - '0');
    mm = (line[2] - '0')*10 + (line[3] - '0');
    ss = (line[4] - '0')*10 + (line[5] - '0');
    cc = (line[6] - '0')*10 + (line[7] - '0');

    time = 0;
    time += hh * 360000;
    time += mm * 6000;
    time += ss * 100;
    time += cc;
    return true;
  }
};

int main(){
  DecadaryWatch DW;
  while ( DW.read() ){
    DW.work();
  }
  return 0;
}
// @end_of_source_code
