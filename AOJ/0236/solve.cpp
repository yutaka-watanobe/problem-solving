#include<iostream>

using namespace std;

const int MAX_SIZE = 7;
int r;
int c;
bool field[MAX_SIZE][MAX_SIZE];
int pathState[MAX_SIZE][MAX_SIZE];

bool isInside(int y,int x){
  return 0 <= y && y < r && 0 <= x && x < c && field[y][x] == false;
}

bool check(int y,int x){
  if(pathState[y][x] == 0){
    if(isInside(y+1,x) && isInside(y-1,x) && ( pathState[y-1][x] == 0 ||
					       pathState[y-1][x] == 2 ||
					       pathState[y-1][x] == 5 ) ){
      if( !(isInside(y,x-1) && ( pathState[y][x-1] == 1 ||
				 pathState[y][x-1] == 2 ||
				 pathState[y][x-1] == 3 ) ) )
	return true;
    }
  }
  else if(pathState[y][x] == 1){
    if( isInside(y,x+1) && isInside(y,x-1) && ( pathState[y][x-1] == 1 ||
						pathState[y][x-1] == 2 ||
						pathState[y][x-1] == 3 ) )
      if( !(isInside(y-1,x) && ( pathState[y-1][x] == 0 ||
				 pathState[y-1][x] == 2 ||
				 pathState[y-1][x] == 5 ) ) )
	return true;
  }

  else if(pathState[y][x] == 2){
    if(isInside(y,x+1) && isInside(y+1,x))
      if( !(isInside(y,x-1) && ( pathState[y][x-1] == 1 ||
				 pathState[y][x-1] == 2 ||
				 pathState[y][x-1] == 3 ) ) )
	if( !(isInside(y-1,x) && ( pathState[y-1][x] == 0 ||
				   pathState[y-1][x] == 2 ||
				   pathState[y-1][x] == 5 ) ) )
	  
	  return true;
  }
  else if(pathState[y][x] == 3){
    if(isInside(y,x+1) && isInside(y-1,x) && (pathState[y-1][x] == 0 ||
					      pathState[y-1][x] == 2 ||
					      pathState[y-1][x] == 5 ) )
      if( !(isInside(y,x-1) && ( pathState[y][x-1] == 1 ||
				 pathState[y][x-1] == 2 ||
				 pathState[y][x-1] == 3 ) ) )
	
	return true;
  }
  else if(pathState[y][x] == 4){
    if(isInside(y-1,x) && ( pathState[y-1][x] == 0 ||
			    pathState[y-1][x] == 2 ||
			    pathState[y-1][x] == 5 ) &&
       isInside(y,x-1) && ( pathState[y][x-1] == 1 ||
			    pathState[y][x-1] == 2 ||
			    pathState[y][x-1] == 3 ) )
      return true;
  }
  else if(pathState[y][x] == 5){
    if(isInside(y+1,x) && isInside(y,x-1) && ( pathState[y][x-1] == 1 ||
					       pathState[y][x-1] == 2 ||
					       pathState[y][x-1] == 3 ) )
      if( !(isInside(y-1,x) && ( pathState[y-1][x] == 0 ||
				 pathState[y-1][x] == 2 ||
				 pathState[y-1][x] == 5 ) ) )
	
	return true;
  }
  return false;
}

bool backTrack(int y,int x){
  if(y == r)
    return true;

  if(field[y][x] == false){
    for(int i = 0;i<6;i++){
      pathState[y][x] = i;
      if(check(y,x)){
	int ny = y;
	int nc = x;
	
	nc++;
	if(nc == c){
	  nc = 0;
	  ny++;
	}
	if(backTrack(ny,nc))
	  return true;
      }
    }
  }
  else{
    int ny = y;
    int nc = x;
    
    nc++;
    if(nc == c){
      nc = 0;
      ny++;
    }
    if(backTrack(ny,nc))
      return true;
  }    
  return false;
}

void test(){
  for(int i = 0;i<r;i++){
    for(int j = 0;j<c;j++)
      cout << pathState[i][j] << " ";
    cout << endl;
  }
}

bool visited[MAX_SIZE][MAX_SIZE];
const int dy[4] = {1,0,-1,0};
const int dx[4] = {0,1,0,-1};

void dfs(int y,int x){
  visited[y][x] = true;

  for(int i = 0;i<4;i++){
    int Y = y+dy[i],X = x+dx[i];
    if(isInside(Y,X) && visited[Y][X] == false)
      dfs(Y,X);
  }
}

bool isConnectedGraph(){
  for(int i = 0;i<r;i++)
    for(int j = 0;j<c;j++)
      visited[i][j] = false;

  for(int i = 0;i<r;i++)
    for(int j = 0;j<c;j++)
      if(field[i][j] == 0){
	dfs(i,j);
	
	for(int k = 0;k<r;k++)
	  for(int l = 0;l<c;l++)
	    if(field[k][l] == 0 && visited[k][l] == false)
	      return false;
	
	return true;
      }
  
  return false;
}
      
main(){
  while(cin >> c >> r && c){
    for(int i = 0;i<r;i++)
      for(int j = 0;j<c;j++){
	pathState[i][j] = -1;
	cin >> field[i][j];
      }

    if(backTrack(0,0) && isConnectedGraph()){
      cout << "Yes" << endl;
      //test();
    }
    else
      cout << "No" << endl;
  }
  return 0;
}
