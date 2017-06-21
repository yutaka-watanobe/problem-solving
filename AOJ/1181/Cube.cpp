/*
  4
3 0 2 5
  1
 */
class Cube{
    public:
    int f[6];
    Cube(){
	// for the corresponding problem
	//f[4] = 1; f[0] = 3;f[1] = 6; f[2] = 5; f[5] = 4; f[3] = 2;
    }
    void roll_z(){ roll(1, 2, 4, 3);}
    void roll_y(){ roll(0, 2, 5, 3);}
    void roll_x(){ roll(0, 1, 5, 4);} // back
    void roll(int i, int j, int k, int l){
	int t = f[i]; f[i] = f[j]; f[j] = f[k]; f[k] = f[l]; f[l] = t;
    }
    void roll_all(){
	rep(i, 6){
	    rep(j, 4){
		// target
		roll_z();
	    }
	    if ( i % 2 == 0 ) roll_y();
	    else roll_x();
	}
    }
};
