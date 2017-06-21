#include<stl.h>
#include<string>
main(){

  string line[25];
  line[0] = "gbbbbbgbbbbb";
  line[1] = "ggbbbbggbbbb";
  line[2] = "gggbbbgggbbb";
  line[3] = "ggggbbggggbb";
  line[4] = "gggggbgggggb";
  line[5] = "rbbbbbrbbbbb";
  line[6] = "rgbbbbrgbbbb";
  line[7] = "rggbbbrggbbb";
  line[8] = "rgggbbrgggbb";
  line[9] = "rggggbrggggb";
  line[10] = "rgggggrggggg";
  line[11] = "rrbbbbrrbbbb";
  line[12] = "rrgbbbrrgbbb";
  line[13] = "rrggbbrrggbb";
  line[14] = "rrgggbrrgggb";
  line[15] = "rrggggrrgggg";
  line[16] = "rrrbbbrrrbbb";
  line[17] = "rrrgbbrrrgbb";
  line[18] = "rrrggbrrrggb";
  line[19] = "rrrgggrrrggg";
  line[20] = "rrrrbbrrrrbb";
  line[21] = "rrrrgbrrrrgb";
  line[22] = "rrrrggrrrrgg";
  line[23] = "rrrrrbrrrrrb";
  line[24] = "rrrrrgrrrrrg";





  for( int i=0; i<25; i++ ){
    string s = line[i];
    sort(s.begin(), s.end() );
    do{
      
      cout << s << endl;
      
    }while( next_permutation( s.begin(), s.end() ));
  }

}
