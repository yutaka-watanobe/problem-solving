// @JUDGE_ID:  17051CA  10340  C++
// @begin_of_source_code
#include<stdio.h>
#include<string>

main(){

  string line, s, t;
  
  int isfirst = 1;
  while(1){
    cin >> s;
    if(cin.eof()) break;
    cin >> t;
    
    int tp = 0;
    int muchC = 0;
    for(int i=0; i<s.size(); i++){
      char c = s[i];
      
      int flag = 1;
      while(flag){
	if( tp >= t.size() ){
	  flag = 0;
	}else{
	  if( t[tp] == c){
	    muchC++;
	    tp++;
	    flag = 0;
	  }else{
	    tp++;
	  }
	}
      }

    }
    int isSub = 0;
    if( muchC == s.size() ) isSub = 1;

    if(!isfirst) cout << endl;
    if(isSub) cout << "YES" << endl;
    else cout << "NO" << endl;

    isfirst = 0;
  }

  return 0;
}
// @end_of_source_code
