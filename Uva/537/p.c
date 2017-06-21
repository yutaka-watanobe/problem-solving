// @JUDGE_ID:  17051CA  537  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>

void work(){
  char c, tmp;
  char pre;
  char concept, prefix, unit;
  
  long double value;
  long double P, U, I;

  P = U = I = -1;
  while(1){
    c = getchar();
    if(c=='\n') break;

    if(c=='='){
      concept = pre;
      prefix = ' ';
      string v = "";
      while(1){
	c = getchar();
	if(c=='V' || c=='A' || c=='W'){
	  goto next;
	}else{
	  if(c=='m' || c=='k' || c=='M'){
	    prefix = c;
	  }else{
	    v += c;
	  }
	}
      }
    next:;
      sscanf(v.c_str(), "%Lf", &value);
      if(prefix=='m') value /= 1000;
      else if(prefix=='k') value *= 1000;
      else if(prefix=='M') value *= 1000000;

      if(concept=='P') P = value;
      else if(concept=='U') U = value;
      else if(concept=='I') I = value;
    }
    pre = c;
  }


  if(P==-1) printf("P=%.2LfW\n", U*I);
  else if(I==-1) printf("I=%.2LfA\n", P/U);
  else if(U==-1) printf("U=%.2LfV\n", P/I);
}

main(){
  int n;
  scanf("%d", &n);
  scanf("%*c");
  for(int i=1; i<=n; i++){
    cout << "Problem #" << i << endl;
    work();
    cout << endl;
  }
}
// @end_of_source_code
