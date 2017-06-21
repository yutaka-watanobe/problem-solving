// @JUDGE_ID:  17051CA  10145  C++
// @begin_of_source_code
/* シミュレーション */
/* DBMS のロックシステムを構築する問題 */

#include<stdio.h>
#include<iostream>
#include<string> 
#include<map>

#define GRANTED 1
#define BLOCKED 2

char m;
int t_id, i_id;

void work(){

  map<int, int> item_state;
  map<int, int> item_transaction;
  map<int, char> item_mode;
  map<int, int> transaction_state;
  map<int, int> multi; /* 共有しているかどうか */

  while(1){
    cin >> m ;
    if(m=='#') break;
    cin >> t_id >> i_id;

    /* trasaction がブロックされていたら無視 */
    if(transaction_state[t_id]==BLOCKED){ cout << "IGNORED" << endl; goto next;}

    if(m=='X'){ /* X ロックを試みる */
      if(item_state[i_id]==0 ){/* item がフリーなら OK*/
	cout << "GRANTED" << endl;
	item_state[i_id] = GRANTED;
	item_transaction[i_id] = t_id;
	item_mode[i_id] = 'X';
      }else{/* すでに item が存在 */
	/* 共有されている、または、自分のトランザクションでない */
	if(multi[i_id]!=0 || item_transaction[i_id]!=t_id){
	  transaction_state[t_id] = BLOCKED;
	  cout << "DENIED" << endl;
	}else{
	  cout << "GRANTED" << endl;
	  item_state[i_id] = GRANTED;
	  item_transaction[i_id] = t_id;
	  item_mode[i_id] = 'X';
	}
      }
    }else if(m=='S'){/* S ロックを試みる */
      if(item_mode[i_id]=='X'){ /* X ロックがかかっている */
	/* 自分ならOK 牧場 */
	if(item_transaction[i_id]==t_id){
	  cout << "GRANTED" << endl;
	}else{
	  cout << "DENIED" << endl;
	  transaction_state[t_id] = BLOCKED;
	}
      }else{
	/* S ロックがかかっている */
	if(item_state[i_id]==0){
	  item_state[i_id] = GRANTED;
	  item_transaction[i_id] = t_id;
	}else if(item_transaction[i_id]!=t_id){
	  multi[i_id]++;
	}
	cout << "GRANTED" << endl;
      }
    }

  next:;
  }
}

main(){
  int testCase;
  cin >> testCase;
  for(int i=0; i<testCase; i++){
    if(i!=0) cout << endl;
    work();
  }
}
// @end_of_source_code
