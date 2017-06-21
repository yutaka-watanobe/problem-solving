// @JUDGE_ID:  17051CA  386  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>

main(){
  int aa, bb, cc, dd;
  for(int a=2; a<=200; a++){
    aa = a*a*a;
    for(int b=2; b<=200; b++){
      bb = b*b*b;
      if( bb > aa ) continue;
      for(int c=b; c<=200; c++){
	cc = c*c*c;
	if( cc + bb > aa ) continue;
	for(int d=c; d<=200; d++){
	  dd = d*d*d;
	  if(dd + cc + bb > aa) continue;
	  if(aa == bb+cc+dd){
	    /* cout << "Cube = " << a << ", Triple = (" << b << "," << c << "," << d << ")" << endl;*/
	    cout << "cout << "  << "Cube = " << a << ", Triple = (" << b << "," << c << "," << d << ") << endl;" << endl;
	  }
	}
      }
    }
  }
}
// @end_of_source_code
