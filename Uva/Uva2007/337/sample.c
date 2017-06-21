#include <stdio.h>
#include <stl.h>
#include <string>

class point {
 public:
  int x, y;
};

char grid[10][10];
point cur;
int mode;

void com_b(){ cur.x = 0; }
void com_c(){
  for(int i=0; i<10; i++){
    for(int j=0; j<10; j++) grid[i][j] = ' ';
  }
}
void com_d(){ cur.y = min(9, cur.y+1); }
void com_h(){ cur.x = cur.y = 0; }
void com_l(){ cur.x = max(0, cur.x-1); }
void com_r(){ cur.x = min(9, cur.x+1); }
void com_u(){ cur.y =max(0, cur.y-1); }
void com_i(){ mode = 1; }
void com_o(){ mode = 0; }
void com_e(){
  for(int j=cur.x; j<10; j++) grid[cur.y][j] = ' ';
}
void com_num(int i, int j){
  cur.y = i, cur.x = j;
}

void print();
void work(string &s);

main(){
  int n;
  string s;

  for(int j=1; ;j++){
    cin >> n;
    if(n==0) break;

    com_h();
    com_c();
    com_o();
    getline(cin, s);

    for(int i=0; i<n; i++){
      getline(cin, s);
      work(s);
    }

    cout << "Case " << j << endl;
    print();
  }
  
}

void write(char ch){
  if(mode==0){
    grid[cur.y][cur.x] = ch;
  }
  else {
    char prev;

    for(int i=cur.x; i<10; i++){
      prev = grid[cur.y][i];
      grid[cur.y][i] = ch;
      ch = prev;
    }
  }
  com_r();
}

void work(string &s){
  for(int i=0; i<s.size(); i++){
    if(s[i]=='^'){
      if(s[i+1]=='^'){
	write('^');
	i++;
      }
      else if(isdigit(s[i+1])){
	com_num(s[i+1]-'0', s[i+2]-'0');
	i+=2;
      }
      else {
	i++;
	if(s[i]=='b') com_b();
	else if(s[i]=='b') com_b();
	else if(s[i]=='c') com_c();
	else if(s[i]=='d') com_d();
	else if(s[i]=='e') com_e();
	else if(s[i]=='h') com_h();
	else if(s[i]=='i') com_i();
	else if(s[i]=='l') com_l();
	else if(s[i]=='o') com_o();
	else if(s[i]=='r') com_r();
	else if(s[i]=='u') com_u();
      }
    }
    else {
      write(s[i]);
    }
  }
}


void print(){
  cout << "+----------+" << endl;
  for(int i=0; i<10; i++){
    cout << "|";
    for(int j=0; j<10; j++){
      cout << grid[i][j];
    }
    cout << "|" << endl;
  }
  cout << "+----------+" << endl;
}
