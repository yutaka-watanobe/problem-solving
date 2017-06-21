// @JUDGE_ID:  17051CA  10310  C++
// @begin_of_source_code
#include<stdio.h>
#include<iostream.h>

int read();
void work();

double hole[1001][2];

int n_hole;

int read(){
  cin >> n_hole;
  if( cin.eof() ) return 0;
  else return 1;
}

void work(){
  double gx, gy, dx, dy, x, y, distance_g, distance_d;
  cin >> gx >> gy >> dx >> dy;
  for(int i=0; i<n_hole; i++){
    cin >> hole[i][0] >> hole[i][1];
  }
  
  int escape = 0;
  int i;
  for(i=0; i<n_hole; i++){
    x = hole[i][0];
    y = hole[i][1];
    distance_g = sqrt( (x-gx)*(x-gx) + (y-gy)*(y-gy) );
    distance_d = sqrt( (x-dx)*(x-dx) + (y-dy)*(y-dy) );
    if(2*distance_g <= distance_d ){
      escape = 1;
      goto ESCAPE;
    }
  }

 ESCAPE:
  if( escape ){
    cout << "The gopher can escape through the hole at ";
    printf("(%.3lf,%.3lf).\n", hole[i][0], hole[i][1]);
  }else{
    cout <<"The gopher cannot escape." << endl;
  }
}

main(){
  while(read()){
    work();
  }
}
// @end_of_source_code
