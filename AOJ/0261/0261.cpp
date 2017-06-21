#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;
typedef long long ll;
static const int D[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
static const int DT[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
static const int MT[] = {144000, 7200, 360, 20, 1};
bool isLeap(int y){ return ( y%4 == 0 && ( y%100 || y%400 == 0 ));}

ll getDay(int y, int m, int d){
  ll sum = 0;
  for ( int i = 1; i <= y; i++ ){
    sum += 365 + (isLeap(i-1)?1:0);
  }
  sum += DT[m-1];
  if ( isLeap(y) && m >= 3 ) sum++;
  sum += d - 1;
  return sum;
}

void toMaya(vector<int> v){
  ll d = getDay(v[0], v[1], v[2]) - getDay(2012, 12, 21);
  d %= MT[0]*13;
  for ( int i = 0; i < 5; i++ ){
    if (i) cout << ".";
    cout << d/MT[i]; d %= MT[i];
  }
  cout << endl;
}

void toGregorian(vector<int> v){
  ll sum = getDay(2012,12,21);
  for ( int i = 0; i < 5; i++ ) sum += v[i]*MT[i];
  ll y = 0, m = 1, d = sum;
  
  while(1){
    int dd = (isLeap(y)?366:365);
    if ( d >= dd ) d -= dd;
    else break;
    y++;
  }

  for ( int i = 0; d >= D[i]; i++ ){
    m = i+2;
    d -= D[i];
    if ( isLeap(y) && i == 1 ) d--;
  }
  d++;
  if ( m == 3 && d == 0 ) { m = 2; d =29; }
  cout << y << "." << m << "." << d << endl;
}

main(){
  string line;
  char ch;
  int x;
  int tcase = 0;
  while(1){
    //cin >> line;
    getline(cin, line);
    if ( line == "#" ) break;
    tcase++;
    vector<int> d;
    stringstream sin(line);
    for ( ; sin >> x ; sin >> ch ) d.push_back(x);
    if ( d.size() == 3 ) toMaya(d);
    else if ( d.size() == 5 ) toGregorian(d);
  }
}
