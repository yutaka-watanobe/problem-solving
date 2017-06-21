// @JUDGE_ID:  17051CA  183  C++
// @begin_of_source_code
/* 再帰 */
#include<stdio.h>
#include<iostream>
#include<string>

char B[201][201], D[201][201];
char mode, next_m;
int r, c;
string line;
string d_line;
int pos;

int read(){
  if(mode=='#') return 0;
  cin >> r >> c;

  line = "";

  char c;
  while(1){
    scanf("%c", &c);
    
    if(c=='B' || c=='#'){
      next_m = c;
      return 1;
    }
    if(c=='D'){
      char nc;
      scanf("%c", &nc);
      if(nc==' '){
	next_m = c;
	return 1;
      }
      line += c;
      if(nc=='D' || nc=='0' || nc=='1') line += nc;
    }else if(c=='1' || c=='0'){
      line += c;
    }
  }
}

void recBtoD(int sx, int sy, int ex, int ey){
  char pre = B[sx][sy];
  for(int i=sx; i<=ex; i++){
    for(int j=sy; j<=ey; j++){
      if(B[i][j]!=pre) goto next;
      pre = B[i][j];
    }
  }
  /* すべて同じなので終り*/
  d_line += pre;
 /*  cout << pre << endl; */
  return;

  /* 違うものが含まれる */
 next:;
  d_line += 'D';

  int nx1, nx2, ny1, ny2;
  nx1 = sx+(ex-sx)/2;
  nx2 = sx+(ex-sx+2)/2;
  ny1 = sy+(ey-sy)/2;
  ny2 = sy+(ey-sy+2)/2;

  /* top_left */
  if(sx<=nx1 && nx1<=ex && sy<=ny1 && ny1<=ey) recBtoD(sx, sy, nx1, ny1);
  /* top_right */
  if(sx<=nx1 && nx1<=ex && sy<=ny2 && ny2<=ey) recBtoD(sx, ny2, nx1, ey);
  /* bottom_left */
  if(sx<=nx2 && nx2<=ex && sy<=ny1 && ny1<=ey) recBtoD(nx2, sy, ex, ny1);
  /* bottom_right */
  if(sx<=nx2 && nx2<=ex && sy<=ny2 && ny2<=ey) recBtoD(nx2, ny2, ex, ey);
}

void recDtoB(int sx, int sy, int ex, int ey){
  if(pos>=line.size()) return;

  char c = line[pos++];

  /* １か０なら埋めつくす */
  if(c=='1' || c=='0'){
    for(int i=sx; i<=ex; i++){
      for(int j=sy; j<=ey; j++){
	D[i][j] = c;
      }
    }
    return;
  }
  int nx1, nx2, ny1, ny2;
  nx1 = sx+(ex-sx)/2;
  nx2 = sx+(ex-sx+2)/2;
  ny1 = sy+(ey-sy)/2;
  ny2 = sy+(ey-sy+2)/2;
  /* top_left */
  if(sx<=nx1 && nx1<=ex && sy<=ny1 && ny1<=ey) recDtoB(sx, sy, nx1, ny1);
  /* top_right */
  if(sx<=nx1 && nx1<=ex && sy<=ny2 && ny2<=ey) recDtoB(sx, ny2, nx1, ey);
  /* bottom_left */
  if(sx<=nx2 && nx2<=ex && sy<=ny1 && ny1<=ey) recDtoB(nx2, sy, ex, ny1);
  /* bottom_right */
  if(sx<=nx2 && nx2<=ex && sy<=ny2 && ny2<=ey) recDtoB(nx2, ny2, ex, ey);
}

void work(){
  if(mode=='B'){
    int index = 0;
    d_line = "";
    for(int i=0; i<r; i++){
      for(int j=0; j<c; j++){
	B[i][j] = line[index++];
      }
    }

    recBtoD(0, 0, r-1, c-1);
    cout << "D";
    printf("%4d%4d\n", r, c);
    int cnt = 0;
    for(int i=0; i<d_line.size(); i++){
      cnt++;
      cout << d_line[i];
      if(cnt%50==0) cout << endl;
    }
    if(cnt%50!=0) cout << endl;
  }else if(mode=='D'){
    pos = 0;
    recDtoB(0, 0, r-1, c-1);
    cout << "B";
    printf("%4d%4d\n", r, c);
    int cnt = 0;
    for(int i=0; i<r; i++){
      for(int j=0; j<c; j++){
	cnt++;
	cout << D[i][j];
	if(cnt%50==0) cout << endl;
      }
    }
    if(cnt%50!=0) cout << endl;
  }
}

main(){
  cin >> mode;
  while(read()){
    work();
    mode = next_m;
  }
}
// @end_of_source_code
