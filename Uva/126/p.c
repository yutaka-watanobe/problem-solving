// @JUDGE_ID:  17051CA  126  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<stl.h>

/** int --> string */
string itoa(int x){
  if(x<0) x *= -1;
  char a[10];
  sprintf(a, "%d", x);
  return string(a);
}

class Term{
 public:
  int  coe, ex, ey;
  char sign;
  
  Term(char s, int c, int x, int y){
    sign = s;
    coe = c;
    ex = x;
    ey = y;
    if(sign=='-') coe *= -1;
  }

  Term(string s){
    string vs;
    sign = s[0];
    vs = "";
    for(int i=1; i<s.size(); i++){
      if(isdigit(s[i])) vs += s[i];
      else break;
    }
    if(vs.size()>0) coe = atoi(vs.c_str());
    else coe = 1;
    int px, py;
    px = py = -1;
    for(int i=1; i<s.size(); i++){
      if(s[i]=='x') px = i;
      if(s[i]=='y') py = i;
    }

    if(px==-1) ex = 0;
    else{
      vs = "";
      for(int i=px+1; i<s.size(); i++){
	if(isdigit(s[i])) vs += s[i];
	else break;
      }
      if(vs.size()>0) ex = atoi(vs.c_str());
      else ex = 1;
    }

    if(py==-1) ey = 0;
    else{
      vs = "";
      for(int i=py+1; i<s.size(); i++){
	if(isdigit(s[i])) vs += s[i];
	else break;
      }
      if(vs.size()>0) ey = atoi(vs.c_str());
      else ey = 1;
    }
    if(sign=='-') coe *= -1;
  }
};

string line1, line2;
vector<Term> t1, t2;

int read(){
  cin >> line1;
  if(line1=="#") return 0;
  cin >> line2;
  return 1;
}

Term multi(Term T1, Term T2){
  Term term = Term('+', T1.coe*T2.coe, T1.ex+T2.ex, T1.ey+T2.ey);
  return term;
}

void putTerm(string s, int k){
  Term t = Term(s);
  if(k==1) t1.push_back(t);
  else t2.push_back(t);
}

void addSpace(string &s, int k){
  for(int i=0; i<k; i++) s += " ";
}

void work(){
  t1.clear();   t2.clear();
  if(line1[0]!='-') line1 = '+' + line1;
  if(line2[0]!='-') line2 = '+' + line2;
  char c, sg;
  string s = "";

  sg = line1[0];
  for(int i=1; i<line1.size(); i++){
    c = line1[i];
    if(c=='+' || c=='-' ){
      putTerm(sg+s, 1);
      sg = c; s = "";
    }else s += c;
  }
  putTerm(sg+s, 1);

  sg = line2[0];
  s = "";
  for(int i=1; i<line2.size(); i++){
    c = line2[i];
    if(c=='+' || c=='-'){
      putTerm(sg+s, 2);
      sg = c; s = "";
    }else s += c;
  }
  putTerm(sg+s, 2);

  /* multiplying */
  vector<Term> m, M;
  for(int i=0; i<t1.size(); i++){
    for(int j=0; j<t2.size(); j++){
      m.push_back( multi(t1[i], t2[j]) );
    }
  }

  for(int i=0; i<m.size(); i++){
    Term tm = m[i];
    for(int j=0; j<M.size(); j++){
      Term tM = M[j];
      if(tm.ex == tM.ex && tm.ey == tM.ey){
	  M[j].coe += tm.coe;
	  goto next;
      }
    }
    M.push_back(tm);
  next:;
  }

  pair<int, int> p;
  map<pair<int, int>, int>  mp;
  
  vector<pair<int, int> > pv;
  for(int i=0; i<M.size(); i++){
    p.first = M[i].ex; p.second = M[i].ey * (-1);
    mp[p] = i;
    pv.push_back(p);
  }
  
  sort(pv.begin(), pv.end());
  reverse(pv.begin(), pv.end());

  string s1, s2, tmp;
  s1 = s2 = "";
  int coe, ex, ey;

  for(int i=0; i<pv.size(); i++){
    p = pv[i];
    Term term = M[mp[p]];
    coe = term.coe;
    ex = term.ex;
    ey = term.ey;

    if(coe==0) continue;

    if(i==0){
      if(coe<0){
	s1 +="-"; s2 += " ";
	tmp = itoa(coe);
	if( (tmp=="1" && ex==0 && ey==0 ) || abs(coe) > 1){
	  s1 += tmp;
	  addSpace(s2, tmp.size());
	}
      }else{
	tmp = itoa(coe);
	if( (tmp=="1" && ex==0 && ey==0 ) || abs(coe) > 1){
	  s1 += tmp;
	  addSpace(s2, tmp.size());
	}
      }
    }else{
      if(coe<0){
	s1 += " - "; 
      }else{
	s1 += " + ";
      }
      s2 += "   ";
      
      tmp = itoa(coe);
      if( (tmp=="1" && ex==0 && ey==0 ) || abs(coe) > 1){
	s1 += tmp;
	addSpace(s2, tmp.size());
      }
    }
    
    if(ex>0){
      s1 += "x"; s2 += " ";
      if(ex>1){
	tmp = itoa(ex);
	s2 += tmp;
	addSpace(s1, tmp.size());
      }
    }

    if(ey>0){
      s1 += "y"; s2 += " ";
      if(ey>1){
	tmp = itoa(ey);
	s2 += tmp;
	addSpace(s1, tmp.size());
      }
    }

  }

  cout << s2 << endl;
  cout << s1 << endl;
}

main(){
  while(read()){
    work();
  }
}
// @end_of_source_code
