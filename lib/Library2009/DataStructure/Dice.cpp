class Cube{
    public:
    string f[6];
    Cube(){}
    void roll_z(){ roll(1, 2, 4, 3);}
    void roll_y(){ roll(0, 2, 5, 3);}
    void roll_x(){ roll(0, 1, 5, 4);}
    void roll(int i, int j, int k, int l){
	string t = f[i]; f[i] = f[j]; f[j] = f[k]; f[k] = f[l]; f[l] = t;
    }
};

void add( Cube c1, Cube c2 ){
    rep(i, 6){
	rep(j, 4){
	    // do something
	    c1.roll_z();
	}
	if ( i % 2 == 0 ) c1.roll_y();
	else c1.roll_x();
    }
}
