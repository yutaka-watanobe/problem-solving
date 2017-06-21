// @JUDGE_ID:  17051CA  291  C++
// @begin_of_source_code
#include<stdio.h>
#include<vector>

class graph{
 public:
  int g[5][5], e[5][5];
  vector<int> passedList;
  graph(){
    passedList.clear();
    /*
      "01101";
      "10101";
      "11011";
      "00101";
      "11100";
      */
    for(int i=0; i<5; i++){
      for(int j=0; j<5; j++){
	g[i][j] = 0;
	e[i][j] = 0;
      }
    }
    g[0][1] = 1; g[0][2] = 1; g[0][4] = 1;
    g[1][0] = 1; g[1][2] = 1; g[1][4] = 1;
    g[2][0] = 1; g[2][1] = 1; g[2][3] = 1; g[2][4] = 1;
    g[3][2] = 1; g[3][4] = 1;
    g[4][0] = 1; g[4][1] = 1; g[4][2] = 1; g[4][3] = 1;
  }
};
void work();
void init();
void parse(graph, int, int);

void init(){

}

void parse(graph g, int target, int source){
  
  if( source != -1){
    g.g[target][source] = 0;
    g.g[source][target] = 0;
  }
  
  g.passedList.push_back(target+1);

  for(int j=0; j<5; j++){
    if(g.g[target][j] == 1){
      parse(g, j, target);
    }
  }
  
  if( g.passedList.size() == 9 ){
    for(int v=0; v<g.passedList.size(); v++){
      printf("%d", g.passedList[v]);
    }
    printf("\n");
  }

}

void work(){
  graph g = graph();
  parse(g, 0, -1);
}

main(){
  work();
}
// @end_of_source_code
