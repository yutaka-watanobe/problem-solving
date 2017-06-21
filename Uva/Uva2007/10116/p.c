// @JUDGE_ID:  17051CA  10116  C++
// @begin_of_source_code
#include<cstdio>
#include<string>
main(){
  int r, c, s;
  char grid[12][12], nn;
  int  finish[12][12];
  char inst;
  string line;
  while(1){
    scanf("%d %d %d", &r, &c, &s);
    if( r==0 && c==0 && s==0) return 0;

    for(int i=0; i<r; i++){
      cin >> line;
      for(int j=0; j<line.size(); j++){
	grid[i][j] = line[j];
      }
    }

    for(int i=0; i<12; i++){
      for(int j=0; j<12; j++){
	finish[i][j] = -1;
      }
    }

    int rr = 0;
    int cc = s - 1;
    int step = 0;
    int step_loop = 0;
    int loop = 0;
    while(1){
finish[rr][cc] = step;
      char instruction = grid[rr][cc];
      switch(instruction){
      case 'N':
	rr = rr-1;
	break;
      case 'S':
	rr = rr+1;
	break;
      case 'E':
	cc = cc+1;
	break;
      case 'W':
	cc = cc-1;
	break;
      }
      if( rr < 0 || cc < 0 || rr >= r || cc >= c){
	break;
      }
      
      if( finish[rr][cc] >= 0){
	step_loop = finish[rr][cc];
	loop = step - step_loop + 1;
	break;
      }

      /*      finish[rr][cc] = step;*/

      step++;
    }

    if( loop == 0 ){
      cout << step+1 << " step(s) to exit " << endl;
    }else{
      cout << step_loop << " step(s) before a loop of " << loop << " step(s)" << endl;
    }
    
  }
  
  return 0;
}
// @end_of_source_code
