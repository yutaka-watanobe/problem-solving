#include<stdio.h>

int J, Y;
char pass[64];

void parse(int pos, int j, int y){
  if ( j == J && y == Y ){
    pass[pos] = '\0';
    printf("%s\n", pass); return;
  } else if ( j == 5 && y <= 3 || y == 5 && j <= 3){
    return;
  }
  if ( j > J || y > Y ) return;
  pass[pos] = 'A';
  parse(pos+1, j+1, y);
  pass[pos] = 'B';
  parse(pos+1, j, y+1);
}

int main(){
  scanf("%d %d", &J, &Y);
  parse(0, 0, 0);
  return 0;
}
