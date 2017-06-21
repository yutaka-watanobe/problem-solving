// ./checker < myout
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<cassert>
#include<algorithm>

using namespace std;

fstream fin_out("../data/1227/output.txt");
//fstream fin_out("output.txt");

int main(){
    vector<string> out, ans;
    string line;

    while( getline(fin_out, line) ) out.push_back(line);
    while( getline(cin, line )) ans.push_back(line);

    if ( out.size() != ans.size() ){
	cout << "wrong answer" << endl;
	return 0;
    }

    for ( int i = 0; i < out.size(); i++ ){
      if ( out[i] == "--" ){
	if ( ans[i] != "--"){
	  cout << "wrong answer" << endl;
	  return 0;
	}
      }
    }
    
    int i = 0;
    while( i < out.size() ){
      vector<string> v1, v2;
      while(1){
	if ( out[i] == "--" ) { i++; break;}
	v1.push_back(out[i]);
	v2.push_back(ans[i]);
	i++;
      }
      sort(v1.begin(), v1.end());
      sort(v2.begin(), v2.end());

      for ( int j = 0; j < v1.size(); j++ ){
	if ( v1[j] != v2[j] ){
	  cout << "wrong answer" << endl;
	  return 0;
	}
      }
    }

    return 0;
}
