// @JUDGE_ID:  17051CA  299  C++
// @begin_of_source_code
#include<stdio.h>
void bubble( int *, int);

main(){
  int train[51];
  int n, l;
  scanf("%d", &n);
  for(int i=0 ; i<n ; i++){
    scanf("%d", &l);
    for(int j=0 ; j<l ; j++){
      scanf("%d", &train[j]);
    }
    bubble( train, l );
  }
  return 0;
}

void bubble( int *train, int l ){
  int count = 0;
  int tmp;
  for(int i=l+1 ; i >= 0 ; i--){
    for(int j=i ; j < l-1 ; j++){
      if( train[j] > train[j+1]){
	tmp = train[j];
	train[j] = train[j+1];
	train[j+1] = tmp;
	count++;
      }
    }
  }
  printf("Optimal train swapping takes %d swaps.\n", count);
}
// @end_of_source_code
