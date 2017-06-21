// @JUDGE_ID:  17051CA  10062  C++
// @begin_of_source_code
#include<stdio.h>

int getMin(int *);

main(){
  int asc[97] = {};
  char c;
  int code;
  int count = 0;

  while( scanf("%c", &c) != EOF){
    if( c == '\n'){
      int flag = 1;
      if(count != 0 ) printf("\n");
      while(flag){
	int index;
	for(int i=0 ; i<97 ; i++){
	  if( asc[i] == 0 ) {
	    asc[i] = 1000;
	  }
	}
	if( (index = getMin(asc)) == -1 ) {
	  flag = 0;
	}
	else {
	  printf("%d %d\n", index+32, asc[index]);
	  asc[index] = 1000;
	}
      }
      count++;
      for(int i=0 ; i<97 ; i++){
	asc[i] = 0;
      }
    }else{
      code = c;
      asc[code - 32]++;
    }
  }
}

int getMin(int *asc){
  int minV;
  int minI;
  minV = 1001;
  minI = 0;
  for(int i=0 ; i<97 ; i++){
    if( minV > asc[i] ){
      minI = i;
      minV = asc[i];
    }else if( minV == asc[i] ){
      if( minI < i ){
	minI = i;
      }
    }
  }
  if( minV == 1000 ) return -1;
  else return minI;
}
// @end_of_source_code
