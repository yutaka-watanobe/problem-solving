#include<stdio.h>
typedef long long ll;

int search(ll x, ll y){
  ll x_min = 0;
  ll y_min = 0;
  ll x_max = 0;
  ll y_max = 0;
  ll p, f, f1 = 1, f2 = 0;
  for ( p = 0;; p++){
    if ( x_min <= x && x <= x_max &&
         y_min <= y && y <= y_max  )
      return p % 3 + 1;
    f = f1 + f2;
    if ( p % 4 == 0 )  x_max += f;     /* east */
    else if ( p % 4 == 1 ) y_max += f; /* north */
    else if ( p % 4 == 2 ) x_min -= f; /* west */
    else  y_min -= f;                  /* south */
    f2 = f1;
    f1 = f;
  }
}

int main(){
  ll x, y;
  scanf("%ld %ld", &x, &y);
  printf("%d\n", search(x, y));
  return 0;
}
