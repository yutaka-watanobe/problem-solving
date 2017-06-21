// @JUDGE_ID:  17051CA  **  C++
// @begin_of_source_code
#include<stl.h>
#include<stdio.h>
#include<string>

class Space{
 public: vector<int> v;
 Space(){};

 Space(int b){
   v.insert(v.end(), b);
 }
};

Space space[25];
int position[25];
main(){
  int n;

  scanf("%d", &n);
  
  for(int i=0; i<n; i++){
    space[i] = Space(i);
    position[i] = i;
  }

  while(1){
    char c1[4], c2[4];
    string com1 = c1;
    string com2 = c2;
    int  i1, i2;
    scanf("%s %d %s %d ", &c1, &i1, &c2, &i2);
    if( com1 == "quit") break;

    if( i1 == i2 || position[i1] == position[i2] ){
      /* ignore */
    }else{
      
    }
    


  }



  for(int i=0; i<n; i++){
    printf("%d:", i);
    Space s = space[i];
    for(int j=0; j<s.v.size(); j++){
      printf(" %d", s.v[j]);
    }
    printf("\n");
  }
  return 0;
}
// @end_of_source_code
