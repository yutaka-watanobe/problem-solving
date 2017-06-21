// @JUDGE_ID:  17051CA  10099  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream.h>

#define MAX 100

int read();
void init();
void readMat();
void work();

int N, R;
int mat[MAX][MAX];
int limit[MAX];
int usedFlag[MAX];
int beforeCity[MAX];

void init(){
  for(int i=0; i<MAX; i++){
    for(int j=0; j<MAX; j++){
      mat[i][j] = 0;
      mat[j][i] = 0;
    }
  }
  for(int i=0; i<MAX; i++){
    limit[i] = -1;
    usedFlag[i] = 0;
    beforeCity[i] = -1;
  }
}

int read(){
  cin >> N >> R;
  if( N == 0 && R == 0 )return 0;
  else return 1;
}

void readMat(){
  int i, j, l;
  for( int n=0; n<R; n++){
    cin >> i >> j >> l;
    mat[i-1][j-1] = l;
    mat[j-1][i-1] = l;
  }
}

void work(){
  int start, end, tourist;

  readMat();
  cin >> start >> end >> tourist;
  
  start--;
  end--;

  /*
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      cout << mat[i][j] << " ";
    }
    cout << endl;
  }
  cout << start << " " << end << " " << tourist << endl;
  */

  limit[start] = 10000000;
  
  while(1){
    int maxVal = -1;
    int maxIndex;

    for(int i=0; i<N; i++){
      if( usedFlag[i] == 0 && limit[i] > maxVal ){
	maxVal = limit[i];
	maxIndex = i;
      }
    }
    
    /* ½ªÎ»¾ò·ï */
    if( maxVal == -1 ) break;
    
    usedFlag[maxIndex] = 1;
    
    for(int i=0; i<N; i++){
      if( mat[maxIndex][i] > 0 && usedFlag[i] == 0){
	int lim;
	if( limit[maxIndex] > mat[maxIndex][i] ) lim = mat[maxIndex][i];
	else lim = limit[maxIndex];
	
	if( lim > limit[i] ){
	  limit[i] = lim;
	  beforeCity[i] = maxIndex;
	}
	
      }
    }
  }

  /* ·ë²Ì */
  /*
  int index = end;
  while(1){
    cout << index << " ";
    if( index == start ) break;
    index = beforeCity[index];
  }
  cout << " limit " << limit[end] << endl;
  */

  limit[end]--; /* for guide */
  int trip;
  trip = tourist/limit[end];
  if( tourist%limit[end] > 0 ) trip++;

  cout << "Minimum Number of Trips = " << trip << endl;
  
}


main(){
  for(int i=1; read(); i++){
    cout << "Scenario #" << i << endl;
    init();
    work();
    cout << endl;
  }
}
// @end_of_source_code
