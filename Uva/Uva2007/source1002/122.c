// @JUDGE_ID:  17051CA  122  C++
// @begin_of_source_code
#include<stdio.h>
#include<string>


main(){
  string tree;
  int i=0;
  /*
  while( scanf("(%s)", &tree) != EOF ){
    i++;

  }*/
  scanf("%s", &tree);
  for(int j=0 ; j<256 ; j++){
    cout << tree;
  }
  return 0;
}
// @end_of_source_code
