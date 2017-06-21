// @JUDGE_ID:  17051CA  10344  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream.h>
#include<stl.h>

#define YES 1
#define NO 0

void e(int, int, int);

vector<int> a;
int canbe23;

main(){
  int isfirst = 1;
  a.resize(5);

  while(1){
    scanf("%d %d %d %d %d", &a[0], &a[1], &a[2], &a[3], &a[4]);

    canbe23 = NO;

    int sum = 0;
    for(int i=0; i<5; i++) sum += a[i];
    if(sum == 0) break;

    sort(a.begin(), a.end());

    do{
      e(a[0], a[1], 1);
    }while(next_permutation(a.begin(), a.end()));

    if(!isfirst) cout << endl;
    if(canbe23 == YES) cout << "Possible" << endl;
    else cout << "Impossible" << endl;

    isfirst = 0;
  }


  return 0;

}

void e(int x, int y, int i){
  
  if(i==4){
    if( x+y == 23 || x-y == 23 || x*y == 23 ){
      canbe23 = YES;
    }
  }else{
    e(x+y, a[i+1], i+1); 
    e(x-y, a[i+1], i+1); 
    e(x*y, a[i+1], i+1);
  }
}
// @end_of_source_code
