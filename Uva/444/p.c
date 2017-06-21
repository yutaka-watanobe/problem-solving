// @JUDGE_ID:  17051CA  444  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<stl.h>

string itoa(int x){
  char buf[100];

  sprintf(buf, "%d", x);
  
  return string(buf);

}

string line;

int read(){
  getline(cin, line);
  if(cin.eof()) return 0;
  return 1;
}

void work(){
  char cf = line[0];
  string str;
  /* alpha */
  if(!isdigit(cf)){
    str = "";
    for(int i=0; i<line.size(); i++){
      str += itoa(line[i]);
    }
    reverse(str.begin(), str.end());
    cout << str << endl;
  }
  /* digit */
  else{
    reverse(line.begin(), line.end());
    int i = 0;
    string cstr = "";
    while(i<line.size()){
      if(line[i]=='1'){
	str = "";
	str += line[i];
	str += line[i+1];
	str += line[i+2];
	cstr += atoi(str.c_str());
	i += 3;
      }else{
	str = "";
	str += line[i];
	str += line[i+1];
	cstr += atoi(str.c_str());
	i += 2;
      }
    }
    cout << cstr << endl;
  }

}

main(){
  while(read()){
    work();
  }
}
// @end_of_source_code
