// @JUDGE_ID:  17051CA  10336  C++
// @begin_of_source_code
#include<stdio.h>
#include<string>

char world[1000][1000];
int  blank[1000][1000];

char ac[26];
int alpha[26];

void init();
void initA();
void scan(int, int, char);
int getMaxIndex();

int getIndex(char);

int N, n, m;

void init(){
  for(int i=0; i<26; i++){
    alpha[i] = 0;
  }
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      blank[i][j] = 0;
    }
  }

}

main(){

  initA();
  string line;

  scanf("%d", &N);
  
  for(int a=0; a<N; a++){
    scanf("%d %d", &n, &m);
    
    init();

    for(int i=0; i<n; i++){
      cin >> line;
      for(int j=0; j<m; j++){
	world[i][j] = line[j];
      }
    }
    
    /* scan */
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
	char c = world[i][j];
	if( blank[i][j]==0) {
	  alpha[ getIndex(c) ]++;
	  scan(i, j, c);
	}
      }
    }

    /* test print 
    for(int i=0; i<26; i++){
      printf("index %d %d \n", i, alpha[i]);
    }
    */

    if( a != 0 ) cout << endl;

    cout << "World #" << a+1 << endl;

    while(1){
      int mi = getMaxIndex();
      if(mi == -1 ) break;
      cout << endl;
      cout << ac[mi] << ": " << alpha[mi] << endl;
      alpha[mi] = -2;
    }
    
  }
  
}
 
int getIndex(char c){
  for(int i=0; i<26; i++){
    if(ac[i] == c ) return i;
  }
}

void scan( int i, int j, char c){
  if( blank[i][j] == 0 ){
    blank[i][j] = 1;
    
    int x, y;
  
    x = i-1;
    y = j;
    if( x >=0 && y >=0 && x<n && y<m && world[x][y] == c){
      scan( x, y, c);
    }
    x = i;
    y = j+1;
    if( x >=0 && y >=0 && x<n && y<m && world[x][y] == c){
      scan( x, y, c);
    }
    x = i+1;
    y = j;
    if( x >=0 && y >=0 && x<n && y<m && world[x][y] == c){
      scan( x, y, c);
    }
    x = i;
    y = j-1;
    if( x >=0 && y >=0 && x<n && y<m && world[x][y] == c){
      scan( x, y, c);
    }
  }
}

int getMaxIndex(){
  int max = 0;
  int index = -1;

  for(int i=0; i<26; i++){
    if(alpha[i] > max ) {
      max = alpha[i];
      index = i;
    }
  }
  return index;

}
void initA(){
  ac[0] = 'a';
  ac[1] = 'b';
  ac[2] = 'c';
  ac[3] = 'd';
  ac[4] = 'e';
  ac[5] = 'f';
  ac[6] = 'g';
  ac[7] = 'h';
  ac[8] = 'i';
  ac[9] = 'j';
  ac[10] = 'k';
  ac[11] = 'l';
  ac[12] = 'm';
  ac[13] = 'n';
  ac[14] = 'o';
  ac[15] = 'p';
  ac[16] = 'q';
  ac[17] = 'r';  
  ac[18] = 's';
  ac[19] = 't';
  ac[20] = 'u';
  ac[21] = 'v';
  ac[22] = 'w';
  ac[23] = 'x';
  ac[24] = 'y';
  ac[25] = 'z';
}
// @end_of_source_code
