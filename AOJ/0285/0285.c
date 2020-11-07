#include<stdio.h>

int j, y;
char path[64];

void parse(int a, int b){
  if ( a == j && b == y ){
    path[a + b] = '\0';
    printf("%s\n", path); return;
  } else if ( a == 5 && b <= 3 || b == 5 && a <= 3 ){
    return;
  }
  if ( a > j || b > y ) return;
  path[a + b] = 'A';
  parse(a + 1, b);
  path[a + b] = 'B';
  parse(a, b + 1);
}

int main(){
  scanf("%d %d", &j, &y);
  parse(0, 0);
  return 0;
}
