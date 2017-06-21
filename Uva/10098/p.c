// @JUDGE_ID:  17051CA  10098  C++
// @begin_of_source_code
#include<stdio.h>
#include<stl.h>
#include<string>
#include<iostream.h>

main(){
  int n;
  vector<char> v;
  char c;
  string line;

  scanf("%d", &n);

  for(int i=0; i<n; i++){
    v.clear();
    cin >> line;
    for(int j=0; j<line.size(); j++){
      v.push_back(line[j]);
    }
    
    sort(v.begin(), v.end());
    
    if( i!=0 ) cout << endl;

    do{
      for(int a=0; a<v.size(); a++){
	cout << v[a];
      }
      cout << endl;
    }while(next_permutation(v.begin(), v.end()));
  }
  return 0;
  
}
// @end_of_source_code
