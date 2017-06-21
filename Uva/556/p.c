// @JUDGE_ID:  17051CA  556  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#define E 0
#define N 1
#define W 2
#define S 3

class Robot{
 public:
  int i, j, dir, hand;

  Robot(int si, int sj){
    i = si;
    j = sj;
    dir = E;
    hand = S;
  }

  void rotate(){
    dir++;
    if(dir>S) dir = E;
    setHand();
  }

  void setHand(){
    hand = dir-1;
    if(hand<E) hand = S;
  }

  void move(int d){
    if(d==E){j++; dir = E; }
    else if(d==N){i--; dir = N;}
    else if(d==W){j--; dir = W;}
    else if(d==S){i++; dir = S;}
    setHand();
  }
};

int row, col;
bool maze[1000][1000];
int count[1000][1000];

int read(){
  cin >> row >> col;
  if(row==0 && col==0) return 0;

  char c;
  for(int i=0; i<row; i++){
    for(int j=0; j<col; j++){
      cin >> c;
      if(c=='1') maze[i][j] = true;
      else maze[i][j] = false;
      count[i][j] = 0;
    }
  }
  return 1;
}

bool check(int i, int j, int dir){
  if(dir==E) j++;
  else if(dir==N) i--;
  else if(dir==W) j--;
  else if(dir==S) i++;
  if(i>=0 && j>=0 && i<row && j<col && !maze[i][j]) return true;
  else return false;
}

void work(){
  Robot robot = Robot(row-1, 0);

  while(1){
    int hand = robot.hand;
    for(int i=0; i<4; i++){
      if(check(robot.i, robot.j, hand)){
	robot.move(hand);
	goto next;
      }
      hand++;
      if(hand>3) hand = E;
    }
  next:;
    count[robot.i][robot.j]++;
    if(robot.i==row-1 && robot.j==0) break;
  }

  /* count */
  int zero, one, two, three, four;
  zero = one = two = three = four = 0;
  for(int i=0; i<row; i++){
    for(int j=0; j<col; j++){
      if(count[i][j]==0 && !maze[i][j]) zero++;
      else if(count[i][j]==1) one++;
      else if(count[i][j]==2) two++;
      else if(count[i][j]==3) three++;
      else if(count[i][j]==4) four++;
    }
  }

  printf("%3d", zero);
  printf("%3d", one);
  printf("%3d", two);
  printf("%3d", three);
  printf("%3d", four);
  cout << endl;
}

main(){
  while(read()){
    work();
  }
}
// @end_of_source_code
