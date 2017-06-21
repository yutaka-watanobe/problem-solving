// @JUDGE_ID:  17051CA  10338  C++
// @begin_of_source_code
#include<stdio.h>
#include<string>

typedef unsigned long long ullong;

char ac[26];
int getIndex(char);
int count[26];

void initA();
void init();

ullong kajijo(ullong);

void init(){
  for(int i=0; i<26; i++){
    count[i] = 0;
  }
}

ullong kaijo(int n){
  ullong k = 1;

  while( n > 0 ){
    k = k*n;
    n--;
  }

  return k;
}
main(){
  int n;
  string line;
  initA();
  
  scanf("%d", &n);
  
  for(int a=0; a<n; a++){
    init();
    cin >> line;
    int s = line.size();

    /*parse*/
    for(int i=0; i<s; i++){
      char c = line[i];
      count[getIndex(c)]++;
    }
    
    ullong p = kaijo(s);
    ullong q = 1;
    for(int i=0; i<26 ;i++){
      q = q*kaijo(count[i]);
    }
    
    if( a>0 ) cout << endl;

    cout << "Data set " << a+1 << ": " << p/q << endl;
  }

}

void initA(){
  ac[0] = 'A';
  ac[1] = 'B';
  ac[2] = 'C';
  ac[3] = 'D';
  ac[4] = 'E';
  ac[5] = 'F';
  ac[6] = 'G';
  ac[7] = 'H';
  ac[8] = 'I';
  ac[9] = 'J';
  ac[10] = 'K';
  ac[11] = 'L';
  ac[12] = 'M';
  ac[13] = 'N';
  ac[14] = 'O';
  ac[15] = 'P';
  ac[16] = 'Q';
  ac[17] = 'R';  
  ac[18] = 'S';
  ac[19] = 'T';
  ac[20] = 'U';
  ac[21] = 'V';
  ac[22] = 'W';
  ac[23] = 'X';
  ac[24] = 'Y';
  ac[25] = 'Z';
}

int getIndex(char c){
  for(int i=0; i<26; i++){
    if(ac[i] == c ) return i;
  }
}
// @end_of_source_code
