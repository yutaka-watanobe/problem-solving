#include<iostream>
#include<string>
#include<cassert>
#include<vector>
using namespace std;
#define rep(i, n) for ( int i = 0; i < (int)n; i++)
#define MOD 32768
typedef vector<vector<int> > Matrix;

int pos;
string buffer;
Matrix M[256];

Matrix expr();

int normalize(int x){
    while( x < 0 ) x += MOD;
    x = x%MOD;
}

void print(Matrix a){
    rep(i, a.size()){
	rep(j, a[i].size()){
	    if (j) cout << " ";
	    a[i][j] = normalize(a[i][j]);
	    cout << a[i][j];
	}
	cout << endl;
    }
}

Matrix sum(Matrix a, Matrix b){
    rep(i, a.size()) rep(j, a[i].size()){
	a[i][j] = (a[i][j] + b[i][j]);
	a[i][j] = normalize(a[i][j]);
    }
    return a;
}

Matrix sub(Matrix a, Matrix b){
    rep(i, a.size()) rep(j, a[i].size()){
	a[i][j] -= b[i][j];
	a[i][j] = normalize(a[i][j]);
    }
    return a;
}

Matrix scalarMul(int k, Matrix a){
    rep(i, a.size()) rep(j, a[i].size() ){
	a[i][j] *= normalize(k);
	a[i][j] = normalize(a[i][j]);
    }
    return a;
}

Matrix mul(Matrix a, Matrix b){
    Matrix c;
    if ( a.size() == 1 && a[0].size() == 1 ) return scalarMul(a[0][0], b);
    if ( b.size() == 1 && b[0].size() == 1 ) return scalarMul(b[0][0], a);
    c.resize(a.size());
    rep(i, c.size()) c[i].resize(b[0].size());
    rep(i, c.size()) rep(j, c[i].size()){
	c[i][j] = 0;
	rep(k, a[0].size()){
	    c[i][j] += (a[i][k] * b[k][j]);
	    c[i][j] = normalize(c[i][j]);
	}
    }
    return c;
}

bool isDigit(char ch){
    return '0' <= ch && ch <= '9';
}
Matrix scalar(int x){
    Matrix p;
    vector<int> v; 
    v.push_back(x);
    p.push_back(v);
    return p;
}
Matrix trans(Matrix m){
    Matrix p;
    p.resize(m[0].size());
    rep(i, p.size()) p[i].resize(m.size());
    rep(i, m.size()) rep(j, m[i].size()){
	p[j][i] = m[i][j];
    }
    return p;
}
Matrix indexed(Matrix m, Matrix l, Matrix k){
    Matrix p;
    assert(l.size() == 1 );
    assert(k.size() == 1 );
    p.resize(l[0].size());
    rep(i, p.size()) p[i].resize(k[0].size());
    rep(i, p.size()) rep(j, p[i].size()){
	p[i][j] = m[l[0][i]-1][k[0][j]-1];
    }
    return p;
}

Matrix row(){
    Matrix e = expr();
    while( pos < buffer.size() && buffer[pos] == ' ' ){
	pos++;
	Matrix r = expr();
	assert( r.size() == e.size());
	rep(i, r.size()) rep(j, r[i].size() ){
	    e[i].push_back(r[i][j]);
	}
    }
    return e;
}

Matrix rowseq(){
    Matrix rows = row();
    while( pos < buffer.size() && buffer[pos] == ';' ){
	pos++;
	Matrix tmp = row();
	assert( rows[0].size() == tmp[0].size());
	rep(i, tmp.size()) rows.push_back(tmp[i]);
    }
    return rows;
}

Matrix matrix(){
    return rowseq();
}

Matrix primary(){
    char ch = buffer[pos];
    Matrix p;

    if (isDigit(ch)){
	string dig = "";
	while( isDigit(buffer[pos])){
	    dig += buffer[pos++];
	}
	p = scalar( atoi(dig.c_str()));
    } else if ( 'A' <= ch && ch <= 'Z' ) {
	pos++;
	p = M[ch];
    } else if ( buffer[pos] == '[' ){
	pos++;
	p = matrix();
	pos++;
    } else if ( buffer[pos] == '(' ){
	pos++;
	p = expr();
	pos++;
    }

    while ( pos < buffer.size() && (buffer[pos] == '\''|| buffer[pos] == '(' )) {
	if ( buffer[pos] == '\'' ){
	    pos++;
	    p = trans(p);
	} else if ( buffer[pos] == '(' ){
	    pos++;
	    Matrix left = expr();
	    assert( buffer[pos] == ',');
	    pos++; 
	    Matrix right = expr();
	    pos++;
	    p = indexed(p, left, right);
	}
    }
    return p;
}

Matrix factor(){
    int f = 0;
    int t = 1;
    while( pos < buffer.size() && buffer[pos] == '-'){
	pos++;
	f++;
	t += (-1);
    }


    Matrix p = primary();
    rep(i, f){
	p = scalarMul(-1, p);
    }

    return p;
}

Matrix term(){
    Matrix a = factor();
    while ( pos < buffer.size() && buffer[pos] == '*'  ){
	pos++;
	a = mul(a, factor());
    }
    return a;
}

Matrix expr(){
    Matrix a = term();
    while ( pos < buffer.size() && (buffer[pos] == '+' || buffer[pos] == '-' ) ){
	if ( buffer[pos] == '+' ){
	    pos++;
	    a = sum(a, term());
	} else if ( buffer[pos] == '-' ){
	    pos++;
	    a = sub(a, term());
	}
    }
    return a;
}

void assignment(){
    char name = buffer[pos]; pos++;
    pos++; //=
    M[name] = expr();
    assert(buffer[pos] == '.');
    pos++;
    print(M[name]);
   
}

void compute(string pro){
    buffer = pro;
    pos = 0;
    assignment();
}

main(){
    int n;
    string pro;
    while(1){
	cin >> n;
	if ( n == 0 ) break;
	getline(cin, pro);
	for ( int i = 0; i < n; i++ ){
	    getline(cin, pro);
	    compute(pro);
	}
	cout << "-----" << endl;
    }
}
