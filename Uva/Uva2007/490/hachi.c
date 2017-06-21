// @JUDGE_ID:  17051CA  490  C++
// @begin_of_source_code

#include<stdio.h>
#define MAX 101

void Input_Output();

main(){
  Input_Output();
}

void Input_Output(){
  int i ,j,k,lines, limit, chars = 0, chk=0;
  char array[MAX][MAX];

  for ( i=0; i<MAX;i++)
    for(j=0; j<MAX;j++ )
      array[i][j] = ' ';

  for(i=0;;i++){
    for(j=0;;j++){
      if(scanf("%c", &array[i][j])==EOF){chk=1; break;}
      if(array[i][j]=='\t')j--;
      if(array[i][j]=='\n') break;
    }
    if(j>chars) chars=j;
    if(chk==1) break;
  }

  lines = i;

  for(i=0;i<chars;i++){
    for(j=lines;j>=0;j--) if(array[j][i]!='\n' && array[j][i]!=' ') limit=j;
    for(j=lines;j>=limit;j--){
      if(array[j][i]=='\n'){printf(" "); continue;}
      printf("%c", array[j][i]);
    }
    printf("\n");
  }
  
  return;
}
// @end_of_source_code
