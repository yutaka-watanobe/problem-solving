// DP
#include<stdio.h>
#include<climits>
#include<algorithm>
#define MAX 20001

int n;

class Segment{
public:
  int left, right, width;
  int L, R;
  Segment(){}
  Segment(int left, int right): left(left), right(right){
    width = right - left + 1;
    L = R = INT_MAX;
  }

};

Segment S[MAX];

void compute(int tpos, int tvalue, int cursor){
  int l = S[cursor].left;
  int r = S[cursor].right;

  if ( l == r ){
    if ( l == tpos ){
      S[cursor].R = min( S[cursor].R, tvalue + 1 );
      S[cursor].L = min( S[cursor].L, tvalue + 1 );
    } else if ( l <tpos ){
      S[cursor].R = min( S[cursor].R, tvalue + 1 + (tpos-l));
      S[cursor].L = min( S[cursor].L, tvalue + 1 + (tpos-l));
    } else {
      S[cursor].R = min( S[cursor].R, tvalue + 1 + (l-tpos));
      S[cursor].L = min( S[cursor].L, tvalue + 1 + (l-tpos));
    }
    return;
  }

  if ( r <= tpos ){
    S[cursor].L = min( S[cursor].L, tvalue + 1 + (tpos-l));
    S[cursor].R = min( S[cursor].R, tvalue + 1 + (tpos-l) + (r-l));
    return;
  }


  if ( tpos <= l){
    S[cursor].L = min( S[cursor].L, tvalue + 1 + (r-tpos) + (r-l));
    S[cursor].R = min( S[cursor].R, tvalue + 1 + (r-tpos));
    return;
  }

  int dl, dr;
  dl = abs( tpos - l );
  dr = abs( tpos - r );
  S[cursor].L = min( S[cursor].L, tvalue + dr*2 + dl + 1);
  S[cursor].R = min( S[cursor].R, tvalue + dr + dl*2 + 1);
}

void work(){
  S[0].R = S[0].right -1;
  S[0].L = S[0].R + S[0].width - 1;

  
  int pos;
  int dl, dr;
  for ( int i = 0; i < n - 1; i++ ){
    
    compute(S[i].left, S[i].L, i+1);
    compute(S[i].right, S[i].R, i+1);
    // left;
    /*
    pos = S[i].left;
    dl = abs( pos - S[i+1].left);
    dr = abs( pos - S[i+1].right);
    S[i+1].L = min( S[i+1].L, S[i].L + dr*2 + dl + 1);
    S[i+1].R = min( S[i+1].R, S[i].L + dr + dl*2 + 1);
    // right;
    pos = S[i].right;
    dl = abs( pos - S[i+1].left);
    dr = abs( pos - S[i+1].right);
    S[i+1].L = min( S[i+1].L, S[i].R + dr*2 + dl + 1);
    S[i+1].R = min( S[i+1].R, S[i].R + dr + dl*2 + 1);
    */
    
  }

  /*
  for ( int i = 0; i < n ;i++ ){
    printf("%d  %d\n", S[i].L, S[i].R);
    }*/
  int ans = n - S[n-1].right + S[n-1].R;

  printf("%d\n", ans);
}

bool read(){
  scanf("%d", &n);
  if ( n == 0 ) return false;
  int l, r;
  for ( int i = 0; i < n; i++ ){
    scanf("%d %d", &l, &r);
    S[i] = Segment(l, r);
  }
  return true;
}

main(){
  while ( read() ){
    work();
  }
}
