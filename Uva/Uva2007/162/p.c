// @JUDGE_ID:  17051CA  162  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#define PLAY1 0
#define PLAY2 1

vector<string> deck;
vector<string> p1;
vector<string> p2;

int play;

void faceGame(int player, char c);

int read(){
  string line;
  
  deck.clear();
  p1.clear();
  p2.clear();

  bool isDealer = false;

  for(int i=0; i<52; i++){
    cin >> line;
    if(i==0 && line=="#") return 0;
    if(isDealer){
      p1.push_back(line);
      isDealer = false;
    }else{
      p2.push_back(line);
      isDealer = true;
    }
  }
  return 1;
}

bool isFace(string card){
  char c = card[1];
  if(c=='A' || c=='J' || c=='Q' || c=='K') return true;
  else return false;
}

void gameOver(int player){
//  cout << "p1 " << p1.size() << "  p2 " << p2.size() << "  deck " << deck.size() << endl;
  if(player==PLAY1){
    cout << "1";
    printf("%3d", p1.size());
  }else{
    cout << "2";
    printf("%3d", p2.size());
  }
  cout << endl;
}

void game(int player){
  string card;
  char c;
  while(1){
//    cout << "game " << endl;
  //  cout << p1.size() + p2.size() + deck.size() <<  endl;
    if(player==PLAY1){
      if(p1.size()==0){
	gameOver(PLAY2);
	return;
      }
      card = p1[0]; p1.erase(p1.begin()+0);
      deck.push_back(card);
      if(isFace(card)){
	faceGame(PLAY2, card[1]);
	return;
      }
      player=PLAY2;
    }else{
      if(p2.size()==0){
	gameOver(PLAY1);
	return;
      }
      card = p2[0]; p2.erase(p2.begin()+0);
      deck.push_back(card);
      if(isFace(card)){
	faceGame(PLAY1, card[1]);
	return;
      }
      player=PLAY1;
    }
  }
  
}


void faceGame(int player, char c){
  int count = 0;
  if(c=='J') count = 1;
  else if(c=='Q') count = 2;
  else if(c=='K') count = 3;
  else if(c=='A') count = 4;

  string card;
  for(int i=0; i<count; i++){
//    cout << "face game " << endl;
    if(player==PLAY1){/* player 1-------------------------*/
      if(p1.size()==0 ){
	gameOver(PLAY2);
	return;
      }
      card = p1[0]; p1.erase(p1.begin()+0);
      deck.push_back(card);
      if(isFace(card)){
	faceGame(PLAY2, card[1]);
	return;
      }
    }else{/* player 2-------------------------*/
      if(p2.size()==0 ){
	gameOver(PLAY1);
	return;
      }
      card = p2[0]; p2.erase(p2.begin()+0);
      deck.push_back(card);
      if(isFace(card)){
	faceGame(PLAY1, card[1]);
	return;
      }
    }
  }

  /* can not face */
//  reverse(deck.begin(), deck.end());

  for(int i=0; i<deck.size(); i++){
    if(player==PLAY1) p2.push_back(deck[i]);
    else if(player==PLAY2) p1.push_back(deck[i]);
  }

  deck.clear();
  if(player==PLAY1) game(PLAY2);
  else game(PLAY1);
}

void work(){
  reverse(p1.begin(), p1.end());
  reverse(p2.begin(), p2.end());

  deck.clear();
  
  game(PLAY2);
  
}

main(){
  while(read()){
    work();
  }
}
// @end_of_source_code
