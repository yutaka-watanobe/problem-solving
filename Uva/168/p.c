// @JUDGE_ID:  17051CA  168  C++
// @begin_of_source_code
/* Graph Simulation */
#include<stdio.h>
#include<iostream>
#include<vector>
#include<stl.h>
#define SOURCE 0
#define TARGET 1

class TheseusAndMinotaur{
 public:
  vector<int> G[ 26 ];
  bool lit[ 26 ];
  vector<int> litOrder;

  int tstart, mstart, step;


  int compute( int mpos, int tpos ){
    
    int s = 0;
    int target;

    while ( 1 ){

      int npos = -1;
      for ( int i = 0; i < G[ mpos ].size(); i++ ){
	target = G[ mpos ][i];
	if ( lit[ target ] || target == tpos ) continue;
	npos = target; break;
      }



      if ( s % step == 0 && s != 0 ){
	lit[ tpos ] = true;
	litOrder.push_back( tpos );
      }

      if ( npos == -1 ) return mpos;

      tpos = mpos;
      mpos = npos;

      s++;
    }

  }

  void work(){
    litOrder.clear();
    
    int trapped = compute( mstart, tstart );

    for ( int i = 0; i < litOrder.size(); i++ ){
      cout << (char)(litOrder[i] + 'A') << " ";
    }
    cout << "/" << (char)( trapped + 'A' ) << endl;
    
  }

  void init(){
    for ( int i = 0; i < 26; i++ ){
      G[i].clear();
      lit[i] = false;
    }
  }

  bool read(){
    init();
    int state = SOURCE;
    char ch;
    int source, target;
    while ( 1 ){
      cin >> ch;
      if ( ch == '#' ) return false;
      else if ( ch == '.' ) break;
      else if ( ch == ':' ) state = TARGET;
      else if ( ch == ';' ) state = SOURCE;
      else {
	if ( state == SOURCE ){
	  source = ch - 'A';
	} else if ( state == TARGET ){
	  target = ch - 'A';
	  G[ source ].push_back( target );
	}
      }
    }
    
    char ts, ms;
    cin >> ms >> ts >> step;
    tstart = ts - 'A';
    mstart = ms - 'A';

    return true;
  }
  

};

main(){
  TheseusAndMinotaur tam;
  while ( tam.read() ){
    tam.work();
  }
}

// @end_of_source_code


