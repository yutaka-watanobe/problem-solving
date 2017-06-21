// @JUDGE_ID:  17051CA  785  C++
// @begin_of_source_code
#include<stdio.h>
#include<vector>

void fillG(char, int, int);
char grid[35][90];

main(){
  char c;
  int row, col;
  int finish;
  vector<int> vrow;
  vector<int> vcol;
  vector<char> vc;

  while( 1 ){
    /* test case */
    row = 0; col = 0;
    finish = 0;
    while( finish != 1 ){
      if( scanf("%c", &c) == EOF){
	return 0;
      }
      if( c == '\n'){
	grid[row][col] = c;
	row++; col = 0; 
      } else if( c == '_' && col == 0){
	while( c != '\n' ){
	  scanf("%c", &c);
	  grid[row][col] = c;
	  col++;
	}
	grid[row][col] = c;
	finish = 1;
      }else{
	if(  c != 'X' && c != ' '){
	  vrow.insert(vrow.end(), row);
	  vcol.insert(vcol.end(), col);
	  vc.insert(vc.end(), c);
	}
	grid[row][col] = c;
	col++;
      }
    }

    for(int i=0 ; i<vrow.size() ; i++){
      fillG(vc[i], vrow[i], vcol[i]);
    }

    row = 0; col = 0;
    while(1){
      c = grid[row][col];
      if( c == '\n' ){
	printf("%c", c);
	row++; col = 0;
      }else if( c == '_' && col == 0){
	while( c != '\n' ){
	  printf("%c", c);
	  c = grid[row][col++];
	}
	printf("%c", c);
	break;
      }else{
	printf("%c", c);
	col++;
      }
    }
    vrow.clear();
    vcol.clear();
    vc.clear();
  }
  return 0;
}

void fillG(char c, int i, int j){
  
  grid[i][j] = c;
  if(grid[i][j+1] == ' ') fillG(c, i, j+1);
  if(grid[i+1][j] == ' ') fillG(c, i+1, j);
  if(grid[i][j-1] == ' ') fillG(c, i, j-1);
  if(grid[i-1][j] == ' ') fillG(c, i-1, j);

}
// @end_of_source_code



