// @JUDGE_ID:  17051CA  615  C++
// @begin_of_source_code
/* Is It a Tree ?? */
/* Fuckin Input!!!!  empty set is tree??? */
#include<stdio.h>
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<stl.h>
#include<queue>

class Node{
 public:
  int inDegree, outDegree;
  vector<int> targetList;

  Node(){
    inDegree = outDegree = 0;
    targetList.clear();
  }
};

map<int, Node> ItoN; /* index to node */ 
int rootIndex;
int size;

void notTree(){
  cout << " is not a tree." << endl;
}

void isTree(){
  cout << " is a tree." << endl;
}

bool checkSequence(){
  queue<int> q;
  map<int, int> visited;

  int nnode = 0;

  q.push( rootIndex );
  visited[ rootIndex ] = 1; nnode++;
  int u, v;

  while ( !q.empty() ){
    u = q.front(), q.pop();

    Node node = ItoN[ u ];

    for ( int i = 0; i < node.targetList.size(); i++ ){
      int v = node.targetList[i];

      if ( visited[ v ] ) return false;
      nnode++;
      q.push( v );
    }

  }

  return ( nnode == size );
}

bool checkRootAndInDegree(){
  map<int, Node>::iterator pos;

  int numOfOneDegNode = 0;
  int numOfZeroDegNode = 0;

  /* search root */
  for ( pos = ItoN.begin(); pos != ItoN.end(); pos++ ){
    int inDegree = pos->second.inDegree;

    if ( inDegree == 0 ){
      rootIndex = pos->first;
      numOfZeroDegNode++;
    } else if ( inDegree == 1 ){
      numOfOneDegNode++;
    } else {
      return false;
    }

  }

  if ( numOfZeroDegNode != 1 ) return false;
  if ( size != numOfZeroDegNode + numOfOneDegNode ) return false;

  return true;
}

void work(){
  size = ItoN.size();

  if ( size == 0 ){
    isTree();
    return;
  }

  if ( !checkRootAndInDegree() ) {
    notTree();
    return;
  }

  if ( !checkSequence() ){
    notTree();
    return;
  }

  isTree();
}

void init(){
  ItoN.clear();
}

int read(){
  init();
  int source, target;
  
  while ( 1 ){
    cin >> source >> target;
    if ( source == 0 && target == 0 ) return true;
    if ( source == -1 && target == -1 ) return false;
    ItoN[target].inDegree++;
    ItoN[source].outDegree++;
    ItoN[source].targetList.push_back( target );
  }

}

main(){
  for ( int i = 1; read(); i++ ){
    cout << "Case " << i ;
    work();
  }
}
// @end_of_source_code
