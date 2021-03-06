#include <cstdio>

int timeTable[24*60];

int main(){
  int h, m, isFirst;
  
  for (int i = 0; i < 2; ++i) {
    int j;
    scanf("%d", &j);
    for (; j > 0; --j) {
      scanf("%d %d",&h, &m);
      timeTable[h*60 + m] = 1;
    }
  }
  
  isFirst = 1;
  for (h = 0; h < 24; ++h){
    for (m = 0; m < 60; ++m)      {
      if ( timeTable[h*60 + m] ){
	if ( !isFirst ) printf(" ");
	else isFirst = 0;
	printf("%d:%02d", h, m);
      }
    }
  }
  printf("\n");
  
  return 0;
}
	
