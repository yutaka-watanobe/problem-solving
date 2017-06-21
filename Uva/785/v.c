#include<stdio.h>
#include<vector>

main(){
  vector<int> v1;
  vector<int>::iterator i;

  v1.insert(v1.end(), 1);
  v1.insert(v1.end(), 2);
  v1.insert(v1.end(), 3);
  v1.insert(v1.end(), 4);
  v1.insert(v1.end(), 5);

  printf("sise of v1 = %d\n", v1.size() );
  for(i= v1.begin() ; i != v1.end() ; i++){
    printf("%d ",  *i );
  }
  printf("\n");

  i = v1.end();
  i--;
  v1.erase(i);

  printf("sise of v1 = %d\n", v1.size() );
  for(i= v1.begin() ; i != v1.end() ; i++){
    printf("%d ",  *i );
  }
  printf("\n");

  return 0;
}
