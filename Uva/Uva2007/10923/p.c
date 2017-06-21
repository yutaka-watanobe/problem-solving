// Iterative Deepening
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<map>
#include<climits>

using namespace std;

#define SPACE 0
#define BLOCK 1
#define ENEMY 2
#define MYSHIP 3

class Ship{
    public:
    int x, y;
    bool live;
    Ship(){}
    Ship(int x, int y): x(x), y(y){
	live = true;
    }

    void set( int xx, int yy ){
	x = xx; y = yy;
    }
};

class Game{
    public:
    int nenemy;
    int enemySize, blockSize;
    int grid[9][8];
    Ship enemys[10], blocks[100];
    Ship myShip;

    Game(){
	enemySize = 0;
	blockSize = 0;
    }

    void addBlock( int x, int y ){
	blocks[blockSize++] = Ship(x, y);
    }

    void addEnemy( int x, int y ){
	enemys[enemySize++] = Ship(x, y);
    }
    
    void setMyShip( int x, int y ){
	myShip = Ship(x, y);
    }

    void init(){
	nenemy = enemySize;
    }

    bool isEnemy( int x, int y ){
	for ( int i = 0; i < enemySize; i++ ){
	    if ( enemys[i].x == x && enemys[i].y == y ) return true;
	}
	return false;
    }

    bool move ( int direction ){
	int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
	int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
	int nx, ny;
	nx = myShip.x + dx[direction];
	ny = myShip.y + dy[direction];

	if ( nx < 0 || nx >= 8 || ny < 0 || ny >= 9 ) return false;
	if ( grid[ny][nx] == BLOCK ) return false;
	if ( isEnemy(nx, ny) ) return false;

	myShip.x = nx; 
	myShip.y = ny;

	// ship movement
	map<pair<int, int>, vector<int> > shipList;

	for ( int id = 0; id < enemySize; id++ ){
	    if ( !enemys[id].live ) continue;
	    moveShip( nx, ny, id );
	    enemys[id].set( nx, ny ); // move
	    shipList[ make_pair(nx, ny) ].push_back(id);
	    if ( enemys[id].x == myShip.x && enemys[id].y == myShip.y ){
		myShip.live = false;
	    }
	}

	// block
	for ( int i = 0; i < enemySize; i++ ){
	    if ( grid[ enemys[i].y ][ enemys[i].x ] == BLOCK ){
		if ( enemys[i].live ){
		    enemys[i].live = false;
		    nenemy--;
		}
	    }
	}
	// crash
	map<pair<int, int>, vector<int> >::iterator pos;
	for ( pos = shipList.begin(); pos != shipList.end(); pos++ ){
	    if ( (*pos).second.size() > 1 ){
		vector<int> ships = (*pos).second;
		for ( int d = 0; d < ships.size(); d++ ){
		    int id = ships[d];
		    if ( enemys[id].live ){
			enemys[id].live = false;
			nenemy--;
		    }
		}
		grid[ (*pos).first.second ][ (*pos).first.first ] = BLOCK;
	    }
	}
	
	return true;
    }
    
    void moveShip( int &nx, int &ny, int enemyId ){
	int px = enemys[enemyId].x;
	int py = enemys[enemyId].y;
	int x = myShip.x;
	int y = myShip.y;

	if ( x == px ){
	    nx = px;
	    if ( y < py ) ny = py - 1;
	    else ny = py + 1;
	} else if ( y == py ){
	    ny = py;
	    if ( x < px ) nx = px - 1;
	    else nx = px + 1;
	} else {
	    if ( x > px && y < py ){ nx = px + 1; ny = py - 1;}
	    else if ( x < px && y < py ){ nx = px - 1; ny = py - 1;}
	    else if ( x < px && y > py ){ nx = px - 1; ny = py + 1;}
	    else if ( x > px && y > py ){ nx = px + 1; ny = py + 1;}
	}

	if ( !( 0 <= nx && nx < 8 && 0 <= ny && ny < 9 ) ) {
	    // do not move
	    nx = px; 	    ny = py;
	}
    }

    int getDistance( int x1, int y1, int x2, int y2 ){
	return max( abs(x1-x2), abs(y1-y2) );
    }

    int getMD(){
	int maxDistance = 0;

	for ( int id = 0; id < enemySize; id++ ){
	    if ( !enemys[id].live ) continue;

	    int minDistance = INT_MAX;
	    for ( int t = 0; t < enemySize; t++ ){
		if ( id == t  ) continue;
		if ( !enemys[t].live ){
		    minDistance = min( minDistance, getDistance( enemys[id].x, enemys[id].y, enemys[t].x, enemys[t].y ) );
		} else {
		    minDistance = min( minDistance, (getDistance( enemys[id].x, enemys[id].y, enemys[t].x, enemys[t].y )+1)/2 );
		}
	    }
	    for ( int b = 0; b < blockSize; b++ ){
		minDistance = min( minDistance, getDistance( enemys[id].x, enemys[id].y, blocks[b].x, blocks[b].y ));
	    }

	    maxDistance = max( maxDistance, minDistance );
	}

	return maxDistance;
    }

};

Game initial, current;
int limit;

bool iterative( int depth ){
    if ( depth + current.getMD() > limit ) return false;
    if ( !current.myShip.live ) return false;
    if ( current.nenemy == 0 ) return true;

    Game tmp = current;

    for ( int r = 0; r < 8; r++ ){
	if ( current.move( r ) ){
	    if ( iterative( depth + 1 ) ) return true;
	}
	current = tmp;
    }
    
    return false;
}

bool canwin(){
    current = initial;    
    if( iterative( 0 ) ) return true;
    else return false;
}

void compute(){
    for ( limit = 1; limit <= 9; limit++ ){
	if ( canwin() ){
	    cout << "I'm the king of the Seven Seas!" << endl;
	    return;
	} 
    }
    cout << "Oh no! I'm a dead man!" << endl;
}

void read(){
    initial = Game();
    char ch;
    for ( int i = 0; i < 9; i++ ){
	for ( int j = 0; j < 8; j++ ){
	    cin >> ch;
	    if ( ch == '.' ) {
		initial.grid[i][j] = SPACE;
	    } else if ( ch == 'E' ){
		initial.addEnemy( j, i );
		initial.grid[i][j] = SPACE;
	    } else if ( ch == '#' ){
		initial.grid[i][j] = BLOCK;
		initial.addBlock(j, i);
	    } else if ( ch == 'S' ){
		initial.setMyShip(j, i);
		initial.grid[i][j] = SPACE;
	    }
	}
    }
    initial.init();
}

main(){
    int tcase; cin >> tcase;
    for ( int i = 0; i < tcase; i++ ){
	read(); compute();
    }
}
