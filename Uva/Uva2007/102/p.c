// @JUDGE_ID:  17051CA  102  C++
// @begin_of_source_code
#include<stdio.h>
#include<string>
#include<iostream>

long B1, B2, B3, G1, G2, G3, C1, C2, C3;

 
class Bin {
public: long blue, green, clear;
public: char color;
  Bin(){};
  Bin(long b, long g, long c){
    blue = b;
    green = g;
    clear = c;
  }
};
long move(Bin b);
main(){
  long count, min; 
  string order = "";
  Bin b1, b2, b3;
  while( scanf("%ld", &B1) != EOF ){
    min = 2147483647;
    count = 0;
    order = "";
    scanf("%ld", &G1);
    scanf("%ld", &C1);
    scanf("%ld", &B2);
    scanf("%ld", &G2);
    scanf("%ld", &C2);
    scanf("%ld", &B3);
    scanf("%ld", &G3);
    scanf("%ld", &C3);
    
    /*GCB*/
    b1 = Bin(B1, G1, C1);
    b2 = Bin(B2, G2, C2);
    b3 = Bin(B3, G3, C3);
    b1.color = 'g';
    b2.color = 'c';
    b3.color = 'b';
    count = move(b1) + move(b2) + move(b3);
    if(count <= min ) {min = count; order = "GCB";}
    /*GBC*/
    b1 = Bin(B1, G1, C1);
    b2 = Bin(B2, G2, C2);
    b3 = Bin(B3, G3, C3);
    b1.color = 'g';
    b2.color = 'b';
    b3.color = 'c';
    count = move(b1) + move(b2) + move(b3);
    if(count <= min ) {min = count; order = "GBC";}
    /*CGB*/
    b1 = Bin(B1, G1, C1);
    b2 = Bin(B2, G2, C2);
    b3 = Bin(B3, G3, C3);
    b1.color = 'c';
    b2.color = 'g';
    b3.color = 'b';
    count = move(b1) + move(b2) + move(b3);
    if(count <= min ) {min = count; order = "CGB";}
    /*CBG*/
    b1 = Bin(B1, G1, C1);
    b2 = Bin(B2, G2, C2);
    b3 = Bin(B3, G3, C3);
    b1.color = 'c';
    b2.color = 'b';
    b3.color = 'g';
    count = move(b1) + move(b2) + move(b3);
    if(count <= min ) {min = count; order = "CBG";}
    /*BGC*/
    b1 = Bin(B1, G1, C1);
    b2 = Bin(B2, G2, C2);
    b3 = Bin(B3, G3, C3);
    b1.color = 'b';
    b2.color = 'g';
    b3.color = 'c';
    count = move(b1) + move(b2) + move(b3);
    if(count <= min ) {min = count; order = "BGC";}
    /*BCG*/
    b1 = Bin(B1, G1, C1);
    b2 = Bin(B2, G2, C2);
    b3 = Bin(B3, G3, C3);
    b1.color = 'b';
    b2.color = 'c';
    b3.color = 'g';
    count = move(b1) + move(b2) + move(b3);
    if(count <= min ) {min = count; order = "BCG";}

    cout << order << " " << min << endl;
  }
  return 0;
}

long move(Bin bin){
  long count = 0;
  if(bin.color == 'b'){
    count += bin.green;
    count += bin.clear;
  }else if(bin.color == 'g'){
    count += bin.blue;
    count += bin.clear;
  }else if(bin.color == 'c'){
    count += bin.blue;
    count += bin.green;
  }
  return count;
}

// @end_of_source_code
