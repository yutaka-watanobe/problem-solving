#include<stdio.h>

int j, y;

void parse(int a, int b, char* path){
  if ( a == j && b == y ){
    path[a + b] = '\0';
    printf("%s\n", path); return;
  } else if ( a == 5 && b <= 3 || b == 5 && a <= 3 ){
    return;
  }
  if ( a > j || b > y ) return;
  path[a + b] = 'A';
  parse(a + 1, b, path);
  path[a + b] = 'B';
  parse(a, b + 1, path);
}

int main(){
  char path[64];
  scanf("%d %d", &j, &y);
  parse(0, 0, path);
  return 0;
}
