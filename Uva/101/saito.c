#include<iostream>
#include<string>
#define DATA_MAX 25

class Block{
private:
  Block *left;
  Block *right;
  int number;
public:
  void setRight(Block *b){
    right = b;
    b->left = this;
  }
  Block *getRight(){
    return right;
  }
  void setRightLeft(Block *b){
    right->setLeft(b);
  }
  Block getRightLeft(){
    right->getLeft();
  }
  void setLeft(Block *b){
    left = b;
    b->right = this;
  }
  Block *getLeft(){
    return left;
  }
  void setLeftRight(Block *b){
    left->setRight(b);
  }
  Block getLeftRight(){
    left->getRight();
  }
  void setNumber(int n){
    number = n;
  }
  int getNumber(){
    return number;
  }
  void setRightNumber(int n){
    right->setNumber(n);
  }
  int getRightNumber(){
    return right->getNumber();
  }
  void setLeftNumber(int n){
    left->setNumber(n);
  }
  int getLeftNumber(){
    return left->getNumber();
  }
  void remove(){
    right->setLeft(left);
  }
}block[DATA_MAX], root[DATA_MAX];

void init(int n);
bool move(string str1, int x, string str2, int y, int num);
void insert(int a, int b);
void insert(int a, int c, int b);
Block *serchRoot(int n);
void move_onto(int a, int b);
void move_over(int a, int b);
void pile_onto(int a, int b);
void pile_over(int a, int b);
void display(int n);


int main(){
  int num, x, y;
  string str1, str2;

  cin >> num;
  init(num);

  do{
    cin >> str1 >> x >> str2 >> y;
  }while(move(str1, x, str2, y, num));

  for(int i = 0; i < num; i++){
    display(i);
  }

  return 0;
}

void init(int n){
  for(int i = 0; i < n; i++){
    root[i].setRight(&block[i]);
    root[i].setLeft(&block[i]);
    root[i].setNumber(-1);
    block[i].setNumber(i);
  }
}

bool move(string str1, int x, string str2, int y, int num){
  if (str1 == "quit")
    return false;
  if (serchRoot(x) == serchRoot(y))
    return true;
  if (x < 0 || y < 0 || x >= num || y >= num)
    return true;

  if (str1 == "move"){
    if (str2 == "onto"){
      move_onto(x, y);
    }
    else if (str2 == "over"){
      move_over(x, y);
    }
  }
  else if (str1 == "pile"){
    if (str2 == "onto"){
      pile_onto(x, y);
    }
    else if (str2 == "over"){
      pile_over(x, y);
    }
  }

  return true;
}
  
void insert(int a, int b){
  block[a].remove();
  block[a].setRight(block[b].getRight());
  block[a].setLeft(&block[b]);
}

void insert(int a, int c, int b){
  block[c].setRightLeft(block[a].getLeft());
  block[c].setRight(block[b].getRight());
  block[a].setLeft(&block[b]);
}

Block *serchRoot(int n){
  Block *temp = &block[n];
  while(temp->getNumber() != -1)
    temp = temp->getLeft();
  return temp;
}

void move_onto(int a, int b){
  block[a].remove();
  insert(a, b);
}

void move_over(int a, int b){
  move_onto(a, serchRoot(b)->getLeftNumber());
}

void pile_onto(int a, int b){
  Block *temp = block[a].getLeft();
  Block *temp2 = serchRoot(a);
  insert(a, temp2->getLeftNumber(), b);
  temp->setRight(temp2);
}

void pile_over(int a, int b){
  pile_onto(a, serchRoot(b)->getLeftNumber());
}

void display(int n){
  Block *temp = root[n].getRight();

  cout << n << ":";
  while(temp->getNumber() != -1){
    cout << " " << temp->getNumber();
    temp = temp->getRight();
  }
  cout << endl;
}



