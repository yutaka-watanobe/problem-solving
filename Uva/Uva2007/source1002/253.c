// @JUDGE_ID:  17051CA  253  C++
// @begin_of_source_code
#include<stdio.h>
#include<vector>
#include<string>

int read();
int work();
void createCube(int, int, int, int, int, int);

class cube{
 public:
  int a[6];
  cube(){}
};

vector<cube> v;
string c1, c2;

int read(){
  string line;
  cin >> line;
  if( cin.eof() ) return 0;
  c1 = line.substr(0, 6);
  c2 = line.substr(6, 6);
}

int work(){

  string rote = "";
  rote +=  c2[1];
  rote +=  c2[0];
  rote +=  c2[3];
  rote +=  c2[5];
  rote +=  c2[2];
  rote +=  c2[4];

  string base = "";

  for(int i=0; i<v.size(); i++){
    cube c = v[i];
    base = "";
    for(int s=0; s<6; s++){
      base = base + c1[ c.a[s] -1 ];
      //cout << c.a[s];
    }

//    cout << " ";
  //  cout << base << " " << rote << endl;

    if( base == rote ) return 1;
  }

  return 0;
}

void createCube(int s, int a1, int a2, int a3, int a4, int e){
  cube c = cube();
  c.a[1] = a1;
  c.a[2] = a2;
  c.a[3] = a3;
  c.a[4] = a4;
  for(int i=0; i<4; i++){
     c.a[0] = s;
     c.a[5] = e;
    if( i!=0 ){
      int tmp = c.a[1];
      c.a[1] = c.a[2];
      c.a[2] = c.a[3];
      c.a[3] = c.a[4];
      c.a[4] = tmp;
    }
    v.push_back(c);
  }

}
main(){
  createCube(1, 2, 3, 5, 4, 6);
  createCube(2, 1, 4, 6, 3, 5);
  createCube(3, 1, 2, 6, 5, 4);
  createCube(4, 1, 5, 6, 2, 3);
  createCube(5, 1, 3, 6, 4, 2);
  createCube(6, 2, 4, 5, 3, 1);

  while( read() ){
    if( work() ) cout << "TRUE" << endl;
    else cout << "FALSE" << endl;
  }
}
// @end_of_source_code
