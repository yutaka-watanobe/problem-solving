// @JUDGE_ID:  17051CA  10070  C++
// @begin_of_source_code
#include <stdio.h>
#include <stl.h>
#include <string>

typedef unsigned long ulong;

string ultoa(ulong x){
  char ch[100];

  sprintf(ch, "%lu", x);

  return string(ch);
}

const ulong ovf = 10000; /* least number that causes the over flow */
const ulong onebit = 4;
/*
 * ̵��Ĺ���٤�������
 * �׷�: �ؿ� ultoa, #include <string>
 */
class along {
 private:
  vector<ulong> d;  /* digits */
  int s;            /* sign */

 public:
  /* constructors */
  along(){ d = vector<ulong>(1, 0); s = 1; }
  along(long a){ *this = a; }
  along(string a){ *this = a; }
  along(const along &a){ d = a.d; s = a.s; }
  
  /* assignment operators */
  along & operator=(long a){
    char ch[1000];
    
    sprintf(ch, "%ld", a);
    *this = string(ch);
    
    return *this;
  }
  along & operator=(string a){
    int i;
    
    s = 1;
    if(a[0]=='-' && a!="-0"){ s = -1; a.erase(a.begin()); }
    
    d.clear();
    for(i=a.size()-onebit; i>=0; i-=onebit)
      d.push_back(atol(a.substr(i, onebit).c_str()));
    
    if(i!=-onebit) d.push_back(atol(a.substr(0, onebit+i).c_str()));

    return *this;
  }
  
  /* +, - operators */
  along operator+(const along &a){
    along c;
    
    if(s==a.s){
      if(*this>a) plus(*this, a, c);
      else plus(a, *this, c);
      return c;
    }

    if(s==-1){
      s = 1;
      if(*this>a){ minus(*this, a, c); c.s = -1; }
      else minus(a, *this, c); 
      s = -1;
      return c; 
    }
    
    s = -1;
    if(*this<a){ minus(*this, a, c); c.s = 1; }
    else {
      minus(a, *this, c); 
      if(c.d.size()==1 && c.d[0]==0) c.s = 1;
    }
    s = 1;
    return c; 
  }
  along operator-(const along &a){
    along b = *this;
    return b+(-a);
  }
  along operator-() const{
    along a = *this;
    a.s *= -1;
    return a;
  }
  
  /* *, /, % operators */
  along operator*(const along &a){
    along c;
    if(d.size()>a.d.size()) mult(*this, a, c);
    else mult(a, *this, c);
    
    return c;
  }
  along operator/(along &a){
    along qt, md;
    int s1 = s, s2 = a.s;

    if(a.d.size()==1 && a.d[0]==0){ s1 = 0; 1/s1; }

    s = 1; a.s = 1;
    divmod(*this, a, qt, md);
    
    if(s1==s2) qt.s = 1;
    else qt.s = -1;
   
    s = s1; a.s = s2; 

    return qt;
  }
  along operator%(along &a){
    along qt, md;
    int s1 = s, s2 = a.s;

    if(a.d.size()==1 && a.d[0]==0){ s1 = 0; 1%s1; }

    s = 1; a.s = 1;
    divmod(*this, a, qt, md);

    if(s1==1) md.s = 1;
    else if(md.d.size()!=1 || md.d[0]!=0) md.s = -1;
    s = s1; a.s = s2;

    return md;
  }
  void divmod(along &a, along &qt, along &md){
    int s1 = s, s2 = a.s;
    
    if(a.d.size()==1 && a.d[0]==0){ s1 = 0; 1%s1; }
    
    s = 1; a.s = 1;
    divmod(*this, a, qt, md);

    if(s1==s2) qt.s = 1;
    else qt.s = -1;
    if(s1==1) md.s = 1;
    else if(md.d.size()!=1 || md.d[0]!=0) md.s = -1;
    s = s1; a.s = s2;
  }

  /* +=, -=, *=, /=, %= operators */
  along operator+=(const along &a){ return *this = *this+a; }
  along operator-=(const along &a){ return *this = *this-a; }
  along operator*=(const along &a){ return *this = *this*a; }

  /* comparison operators */
  bool operator<(const along &a) const{ return bool(cmp(a)==1); }
  bool operator>(const along &a) const{ return bool(cmp(a)==-1); }
  bool operator==(const along &a) const{ return bool(!cmp(a)); }
  bool operator!=(const along &a) const{ return bool(cmp(a)); }
  bool operator<=(const along &a) const{ return bool(cmp(a)>=0); }
  bool operator>=(const along &a) const{ return bool(cmp(a)<=0); }
  
  /* conversion to the string object */
  operator string() const{
    string str;
    
    str = ultoa(d[d.size()-1]);
    if(s==-1) str = '-' + str;
    
    for(int i=d.size()-2; i>=0; i--){
      string tmp = ultoa(d[i]);
      str += string(onebit-tmp.size(), '0') + tmp;
    }
    
    return str;
  }
  /* private functions */
 private:
  int cmp(const along &a) const{
    if(s < a.s) return 1;
    if(s > a.s) return -1;
    
    if(d.size() < a.d.size()) return s;
    if(d.size() > a.d.size()) return -s;
    
    for(int i=d.size()-1; i>=0; i--){
      if(d[i] < a.d[i]) return s;
      if(d[i] > a.d[i]) return -s;
    }
    return 0;
  }

  void plus(const along &a, const along &b, along &c){   /* a > b is assumed */
    ulong cy = 0;

    c = b;
    c.d.resize(a.d.size(), 0);
    for(int i=0; i<a.d.size(); i++){
      c.d[i] += a.d[i]+cy;
      cy = c.d[i]/ovf;
      c.d[i] %= ovf;
    }
    if(cy) c.d.push_back(cy);
  }  
  void minus(const along &a, const along &b, along &c){  /* a > b is assumed */
    ulong ln = 0;
    long tmp;

    c = b;
    c.d.resize(a.d.size(), 0);
    for(int i=0; i<a.d.size(); i++){
      tmp = (long)a.d[i]-c.d[i]-ln;
      ln = 0;
      if(tmp<0){ ln = 1; c.d[i] = tmp+ovf; }
      else { c.d[i] = (ulong)tmp; }
    }
    while(c.d.size()!=1 && c.d.back()==0) c.d.pop_back();
  }

  /* a.d.size() > b.d.size() is assumed */
  void mult(const along &a, const along &b, along &c){ 
    ulong cy = 0;
    int k = a.d.size(), l = b.d.size(), m, M;
    
    c.s = a.s*b.s;
    c.d.resize(k+l-1, 0);
    for(int i=0; i<k+l-1; i++){
      M = max(0, i-l+1);
      m = min(i, k-1);

      for(int j=M; j<=m; j++) c.d[i] += a.d[j]*b.d[i-j];

      c.d[i] += cy;
      cy = c.d[i]/ovf;
      c.d[i] %= ovf;
    }
    if(cy) c.d.push_back(cy);
  }
  void divmod(const along &a, const along &b, along &qt, along &md){
    along dv;
    ulong q;

    md = a;
    qt.d.clear();
    
    if(a<b){ qt = 0; return; }
    dv.d.resize(a.d.size()-b.d.size(), 0);
    dv.d.insert(dv.d.end(), b.d.begin(), b.d.end());

    /*
    cout << (string)a << endl;
    cout << (string)b << endl;
    cout << (string)dv << endl;
    */

    for(int i=0; i<=a.d.size()-b.d.size(); i++){
      //cout << "i=" << i << endl;
      if(md >= dv){
	if(md.d.size()==dv.d.size()){
	  if(md.d.size()>1 && dv.d.size()>1){
	    q = md.d.back()*ovf+md.d[md.d.size()-2];
	    q /= dv.d.back()*ovf+dv.d[dv.d.size()-2];
	  }
	  else 
	    q = md.d.back()/dv.d.back();
	}
	else {
	  q = md.d.back()*ovf+md.d[md.d.size()-2];
	  q /= dv.d.back();
	}
	
	//cout << (string)md << "-" << q << "*" << (string)dv << "=";
	md -= along(q)*dv;
	//cout << (string)md << endl;
	
	while(md.s==-1){
	  md += dv;
	  q--;
	}

	//cout << "finally: q = " << q << " md = " << (string)md << endl;
      }
      else q = 0;

      qt.d.push_back(q);
      dv.d.erase(dv.d.begin());
    }
    
    reverse(qt.d.begin(), qt.d.end());
    while(qt.d.size()!=1 && qt.d.back()==0) qt.d.pop_back();
    //cout << (string)qt << endl;
  }
};

main(){
  string s;
  int state, line, leap;
  along y, zero, a4, a5, a100, a400, a55, a15;
  line = 0;

  zero = 0;
  a5 = 5;
  a4 = 4;
  a100 = 100;
  a400 = 400;
  a55  = 55;
  a15 = 15;
  while( 1 ){
    cin >> s;
    if(cin.eof()) break;
    y = s;
    if( line == 1 ) printf("\n");
    state = 0;
    leap = 0;
    if( ((y%a4 == zero) && (y%a100 != zero)) || (y%a400 == zero) ){
      state = 1;
      leap = 1;
      printf("This is leap year.\n");
    }

    if( y%a15 == zero ){
      state = 2;
      printf("This is huluculu festival year.\n");
    }

    if( leap==1 && y%a55 == zero ){
      state = 3;
      printf("This is bulukulu festival year.\n");
    }

    if( state == 0 ){
      printf("This is an ordinary year.\n");
    }
    line = 1;
  }
  return 0;
}
// @end_of_source_code
