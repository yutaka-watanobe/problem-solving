// @JUDGE_ID:  17051CA  10142  C++
// @begin_of_source_code
/* Simulation */
/* voting */
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<stl.h>
/*
 * stringオブジェクトを1文字のデリミタ(デフォルトは空白)で区切る
 * 要件: #include <string>, #include <stl.h>
 */
void split(vector<int> &d, const string &s, char c=' '){
  string t = "";

  for(int i=0; i<s.size(); i++){    
    if(s[i]==c){
      if(t!=""){ d.push_back(atoi(t.c_str())-1); t = ""; }
    }
    else t += s[i];
  }
  if(t.size()) d.push_back(atoi(t.c_str())-1);
}

int testCase;
string line;
vector<vector<int> > ballot;
vector<string> candidate;
int n;

int read(int t){

  getline(cin, line);
  n = atoi(line.c_str());
  ballot.clear();
  candidate.clear();
  for(int i=0; i<n; i++){
    getline(cin, line);
    candidate.push_back(line);
  }

  if(t==testCase) goto next;

  while(1){
    getline(cin, line);
    if(line.size()==0 || cin.eof()) return 1;
    vector<int> d;
    split(d, line);
    ballot.push_back(d);
  }

 next:;
  int k;
  char ch;
  while(1){
    vector<int> d;
    for(int i=0; i<n; i++){
      if( (scanf("%d%c", &k, &ch))==EOF) return 1;;
      d.push_back(k-1);
    }
    ballot.push_back(d);
  }
}

void work(){
  vector<int> box;
  vector<bool> loss;
  loss.clear();
  loss.resize(n, false);

  while(1){
    /* parse */
    box.clear();
    box.resize(n, 0);

    for(int i=0; i<ballot.size(); i++){
      if(ballot[i].size()>0){
	box[ballot[i][0]]++;
      }
    }

    /* search max and min , and tie or not*/
    int maxV = 0;
    int minV = 10000;
    int maxI, minI;
    int tv = box[0];
    bool tie = true;
    for(int i=0; i<n; i++){
      if(maxV < box[i] && !loss[i]){maxV = box[i]; maxI = i;}
      if(minV > box[i] && !loss[i]){minV = box[i]; minI = i;}
      if(tv!=box[i]) tie = false;
    }

    /* over 50 % */
    if((double)maxV/ballot.size() >=0.5){
      cout << candidate[maxI] << endl;
      return;
    }

    /* tie */
    if(tie){
      for(int i=0; i<n; i++){
	if(box[i]==tv){
	  cout << candidate[i] << endl;
	}
      }
      return;
    }
    
    vector<int> minList;
    for(int i=0; i<n; i++){
      if(box[i]==minV && !loss[i]) minList.push_back(i);
    }

    /* remove the lowest */
    for(int l=0; l<minList.size(); l++){
      int minIndex = minList[l];
      loss[minIndex] = true;
      for(int i=0; i<ballot.size(); i++){
	if(ballot[i].size()>0){
	  for(int j=0; j<ballot[i].size(); j++){
	    if(ballot[i][j]==minIndex){
	      ballot[i].erase(ballot[i].begin()+j);
	    }
	  }
	}
      }
    }
  }
}

main(){
  getline(cin, line);
  testCase = atoi(line.c_str());
  getline(cin, line);
  for(int i=0; i<testCase; i++){
    if(i) cout << endl;
    read(i+1);
    work();
  }
}
// @end_of_source_code
