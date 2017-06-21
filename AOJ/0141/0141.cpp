#include<stdio.h>

int n;
char G[100][100]; // grid
static int di[4] = {-1, 0, 1, 0};
static int dj[4] = {0, 1, 0, -1};

int main(){
    int dir, width, i, j, a, w;
    int tcase; scanf("%d", &tcase);
    for ( int t = 0; t < tcase; t++ ){
      if ( t ) printf("\n");
      scanf("%d", &n);
      
      for ( i = 0; i < n; i++ )
        for ( j = 0; j < n; j++ ) G[i][j] = ' ';
      
      width = n - 1;
      i = width; j = dir = 0;
      
      for ( a = 1; a <= (n + n % 2); a++, dir = (dir + 1) % 4 ){
        for ( w = 0; w <= width; w++ ) G[i+di[dir]*w][j+dj[dir]*w] = '#';
        i += di[dir] * width;
        j += dj[dir] * width;
        if ( a % 2 == 1 && a >= 3 ) width -= 2;
      }
      
      for ( i = 0; i < n; i++ ){
        for ( j = 0; j < n; j++ ) printf("%c", G[i][j]);
        printf("\n");
      }
    }
}
