// @JUDGE_ID:  17051CA  585  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<stl.h>

int read();
void work();

int n;
vector<vector<int> > v;
vector<vector<int> > index;

void work(){
  v.clear();
  v.resize( n );
  for(int i=0; i<v.size(); i++){
    v[i].clear();
  }

  index.clear();
  index.resize( n );
  for(int i=0; i<index.size(); i++){
    index[i].clear();
  }

  string line;
  char c;
  for(int i=0; i<v.size(); i++){
    cin >> line;
    for(int j=0; j<line.size(); j++){
      c = line[j];
      if( c=='#' ) v[i].push_back(0);
      if( c=='-' ) v[i].push_back(1);
    }
  }

  int m = 0;
  /* case 0 */
  for(int i=0; i<v.size(); i++){
    for(int j=0; j<v[i].size(); j++){
      if(v[i][j] == 1 ){
	m = 1; goto start;
      }
    }
  }
 start:;

  /* case 1 */
  int start, count;
  int max1 = m;
  int i, j;
  for(int w=n; w>=2; w--){
    for(int z=n-1; z>=w-1; z--){
      j = z;
      i = j-(w-1);
      for(int s=0; s<v[j].size(); s+=2){ /* s -> start */
	count = 0;
	for(int b=i; b<=j; b++){
	  int idx = (j-b)*2+1;
	  for(int c=s; c<s+idx; c++){
	    if( v[b][c]==0 ){
	      goto next;
	    }else count++;
	  }
	}
	max1 = count; goto nextCace;
      next:;
      }
    }
  }

 nextCace:;

  /* case 2 */
  /* create index */
  int w;
  for(int i=0; i<n; i++){
    int size = 2*(n-i)-1; 
    w = 1;
    for(int s=0; s<=size/2; s++){
      if( s==0 || s==1 ) {
	index[i].push_back(0);
      }else {
	if( s%2==0 )w++;
	index[i].push_back(w);
      }
    }
    int end = size/2-1;
    for(int s=size/2+1; s<size; s++){
      index[i].push_back( index[i][end--] );
    }
  }
  
  int max2 = m;

  for(int i=0; i<v.size(); i++){
    for(int j=1; j<v[i].size(); j+=2){
      
      for(int h=2; h<=index[i][j]; h++){
	count = 0;

	for(int d=i+h-1; d >=i; d--){
	  for(int k=j; k>=j-2*(d-i); k--){
	    if( v[d][k] == 0 ){
	      goto next2;
	    }else{
	      count++;
	    }
	  }
	}
	max2 = count; goto END;
      next2:;
      }
      
    }
  }
 END:;

  cout <<"The largest triangle area is " << max(max1, max2) << "." << endl;
  
}

main(){
  for(int i=1; read(); i++){
    cout << "Triangle #" << i << endl;
    work();
    cout << endl;
  }
}

int read(){
  cin >> n;
  if( n==0 ) return 0;
  return 1;
}
// @end_of_source_code
