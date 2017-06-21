// @JUDGE_ID:  17051CA  713  C++
// @begin_of_source_code
#include<stdio.h>
#include<string>
#include<stdlib.h>

string reverse(string );
string add(string, string);

main(){
  int n;
  scanf("%d", &n);
  string s1;
  string s2;
  char *c1, *c2, *r1, *r2;
  string ans;
  for(int i=0 ; i<n ; i++){
    cin >> s1;
    cin >> s2;
    //s1 = reverse(s1);
    //s2 = reverse(s2);
    ans = add(s1, s2);
    
    cout << ans << endl;
  }
  
  return 0;
  }

string reverse(string s1){
  string tmp = s1;
  int size = s1.length();
  for(int i=0; i<size; i++){
    s1[i] = tmp[size-i-1];
  }
  return s1;
}

string add(string s1, string s2){
  char *ans;
  char c1, c2;
  int carry, add;
  int size1 = s1.size();
  int size2 = s2.size();
  
  int i = 0;
  carry = 0;
  int flag = 1;
  while(flag){
    if(i<size1) c1 = s1[i];
    else c1 = '0';
    if(i<size2) c2 = s2[i];
    else c2 = '0';
    add  = c1 + c2 + carry;
    carry = add/10;
    ans[i] = add%10;
    if(c1 =='0' && c2 == '0') flag = 0;
    i++;
  }

  return ans;
}
// @end_of_source_code
