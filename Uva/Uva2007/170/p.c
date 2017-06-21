// @JUDGE_ID:  17051CA  170  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<list>
#include<vector>
#include<map>

vector<list<string> > decs;
map<string, bool> isfaced;
int nofaced[13];

int count;
string lastCard;

int getIndex(string card){
  char c = card[0];
  if(c=='A') return 0;
  else if(c=='T') return 9;
  else if(c=='J') return 10;
  else if(c=='Q') return 11;
  else if(c=='K') return 12;
  else {
    return c - 48 -1;
  }
}

int read(){
  string line;
  for(int i=0; i<decs.size(); i++){
    decs[i].clear();
  }
  decs.clear();
  decs.resize(13);
  isfaced = map<string, bool>();

  string card[52];
  for(int i=0; i<52; i++){
    cin >> line;
    card[i] = line;
    if(i==0){
      if(line=="#") return 0;
    }
  }
  
  for(int i=51; i>=0; i--){
    decs[(51-i)%13].push_front(card[i]);
  }
  return 1;
}

void trase(){
  vector<list<string> > v;
  v = decs;

  cout << "--------------------------------"<< endl;
  for(int i=0; i<v.size(); i++){
    cout << i+1 << " " << nofaced[i] << " ";
    while(!v[i].empty()){
      string str = v[i].back();
      if(isfaced[str]) cout << "[" << str << "]";
      if(!isfaced[str]) cout << "(" << str << ")";
      v[i].pop_back();
    }
    cout << endl;
  }
  
}
void play(int index){
//  trase();
//  cout << "game " << index << endl;

  string card = decs[index].front();  

  if(isfaced[card]==false) {
    nofaced[index]--;
    count++;
    isfaced[card] = true;
  }

  decs[index].pop_front();
 
  int next = getIndex(card);
  decs[next].push_back(card);
  
  lastCard = card;
  
   /* game orver */
  if(nofaced[next]<=0){
    if(count<10) cout << "0";
    cout << count << ","<< lastCard << endl;
    return;
  }else{
    play(next);
  }
}

void work(){
  count = 0;
  lastCard = "";
  for(int i=0; i<13; i++) nofaced[i] = 4;
  play(12);
}

main(){
  while(read()){
    work();
  }
}
// @end_of_source_code
