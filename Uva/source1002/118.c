// @JUDGE_ID:  17051CA  118  C++
// @begin_of_source_code
#include<stdio.h>
#include<string>
#include<iostream.h>

main(){
  int maxX, maxY;
  int state[51][51]; /* 0 - 50 */
  int isLost;
  for(int i=0 ; i<50 ; i++){
    for(int j=0 ; j<50 ; j++){
      state[i][j] = 0;
    }
  }

  scanf("%d %d", &maxX, &maxY);
  int x, y, sx, sy;
  int d; 
  char sd;
  string inst;
  while( scanf("%d %d %c", &sx, &sy, &sd) != EOF){
    cin >> inst;
    x = sx; y = sy; 
    switch(sd){
    case 'E':
      d = 1;
      break;
    case 'S':
      d = 2;
      break;
    case 'W':
      d = 3;
      break;
    case 'N':
      d = 4;
      break;
    }
    isLost = 0;
    /* instruction */
    for(int i=0 ; i<inst.length() ; i++){
      char c = inst[i];
      switch(c){
      case 'L':
	if(d==1) d = 4;
	else d = d - 1;
	break;
      case 'R':
	if(d==4) d = 1;
	else d = d + 1;
	break;
      /* movement */
      case 'F':
	int tmpX = x;
	int tmpY = y;
	switch(d){
	case 1:
	  x = x+1;
	  break;
	case 2:
	  y = y-1;
	  break;
	case 3:
	  x = x-1;
	  break;
	case 4:
	  y = y+1;
	  break;
	}
	if( x < 0 || x >maxX || y < 0 || y >maxY){
	  if( state[tmpX][tmpY] == 0 ){
	    state[tmpX][tmpY] = 1;
	    x = tmpX; y = tmpY;
	    isLost = 1;
	  }else{
	    x = tmpX; y = tmpY;
	  }
	}
	break;
      }

      if(isLost){
	break;
      }
    }
    
    char ed;
    switch(d){
    case 1:
      ed = 'E';
      break;
    case 2:
      ed = 'S';
      break;
    case 3:
      ed = 'W';
      break;
    case 4:
      ed = 'N';
      break;
    }
    printf("%d %d %c", x, y, ed);
    if( isLost ){
      printf(" LOST\n");
    }else{
      printf("\n");
    }
  }
  
  return 0;
}
// @end_of_source_code
