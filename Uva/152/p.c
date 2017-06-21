// @JUDGE_ID:  17051CA  152  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<math.h>

double neighbour[5010];

class Tree{
 public:
  int x, y, z;
  Tree(int i, int j, int k){
    x = i;
    y = j;
    z = k;
  }
};

int x, y, z;

int read(){
  cin >> x >> y >> z;
  if(x==0 && y==0 && z==0) return 0;
  return 1;
}

void work(){
  vector<Tree> v;
  
  while(read()){
    Tree tree = Tree(x, y, z);
    v.push_back(tree);
  }

  double d;
  int histoGram[10];
  for(int i=0; i<10; i++) histoGram[i] = 0;
  for(int i=0; i<v.size()+1; i++) neighbour[i] = 100000;

  for(int i=0; i<v.size(); i++){
    for(int j=i+1; j<v.size(); j++){
      double dis = sqrt( (v[i].x-v[j].x)*(v[i].x-v[j].x) +
			 (v[i].y-v[j].y)*(v[i].y-v[j].y) +
			 (v[i].z-v[j].z)*(v[i].z-v[j].z) );
      if(dis<neighbour[i]) neighbour[i] = dis;
      if(dis<neighbour[j]) neighbour[j] = dis;
    }
  }

  for(int i=0; i<v.size(); i++){
    double d = neighbour[i];
    if(0 <= d && d < 1) histoGram[0]++;
    else if(1 <= d && d < 2) histoGram[1]++;
    else if(2 <= d && d < 3) histoGram[2]++;
    else if(3 <= d && d < 4) histoGram[3]++;
    else if(4 <= d && d < 5) histoGram[4]++;
    else if(5 <= d && d < 6) histoGram[5]++;
    else if(6 <= d && d < 7) histoGram[6]++;
    else if(7 <= d && d < 8) histoGram[7]++;
    else if(8 <= d && d < 9) histoGram[8]++;
    else if(9 <= d && d < 10) histoGram[9]++;
  }


  for(int i=0; i<10; i++){
    printf("%4d", histoGram[i]);
  }
  cout << endl;


}

main(){
  work();
}
// @end_of_source_code
