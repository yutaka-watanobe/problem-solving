// @JUDGE_ID:  17051CA  10189  C++
// @begin_of_source_code
#include<stdio.h>
#include<string>
main(){
  int n, m;
  string input;
  char in[102][102];
  int  out[102][102];
  char nn;
  int count = 1;
  while(1){
    scanf("%d %d", &n, &m);
    if( n == 0 && m == 0 ) break;

    for(int i=0; i<102; i++){
      for(int j=0; j<102; j++){
	out[i][j] = 0;
      }
    }

    for(int i=0; i<n; i++){
      cin >> input;
      for(int j=0; j<m; j++){
	in[i][j] = input[j];
      }
    }
    
    int ix, iy;
    ix = 0;
    iy = 0;
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
	if( in[i][j] == '*' ){
	  ix = i-1;
	  iy = j-1;
	  if( (0 <= ix && ix < n) && (0 <= iy && iy < m) ) out[ix][iy]++;
	  ix = i-1;
	  iy = j;
	  if( (0 <= ix && ix < n) && (0 <= iy && iy < m) ) out[ix][iy]++;
	  ix = i-1;
	  iy = j+1;
	  if( (0 <= ix && ix < n) && (0 <= iy && iy < m) ) out[ix][iy]++;
	  ix = i;
	  iy = j+1;
	  if( (0 <= ix && ix < n) && (0 <= iy && iy < m) ) out[ix][iy]++;
	  ix = i+1;
	  iy = j+1;
	  if( (0 <= ix && ix < n) && (0 <= iy && iy < m) ) out[ix][iy]++;
	  ix = i+1;
	  iy = j;
	  if( (0 <= ix && ix < n) && (0 <= iy && iy < m) ) out[ix][iy]++;
	  ix = i+1;
	  iy = j-1;
	  if( (0 <= ix && ix < n) && (0 <= iy && iy < m) ) out[ix][iy]++;
	  ix = i;
	  iy = j-1;
	  if( (0 <= ix && ix < n) && (0 <= iy && iy < m) ) out[ix][iy]++;
	}
      }
    }
    
    if( count != 1 ) printf("\n");

    cout << "Field #" << count << ":" << endl;

    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
	if( in[i][j] == '*') printf("%c", in[i][j]);
	else printf("%d", out[i][j]);
      }
      printf("\n");
    }
      
    count++;
  }
  
  return 0;
}
// @end_of_source_code
