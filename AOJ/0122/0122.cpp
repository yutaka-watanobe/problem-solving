// @author Yutaka Watanobe
// BFS-like algorithm
// cin --> fin に変更して利用
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
#include<queue>
#define MAX 10
using namespace std;

ifstream fin("data30.csv");

class Point{
    public:
    int x, y;
    Point(){}
    Point( int x, int y ): x(x), y(y){}
};

class Sprinkler{
    public:
    Point position;
    Sprinkler( Point position ): position(position){}

    bool in ( Point target ){
	static int dx[9] = {0, 1, 1, 0, -1, -1, -1, 0, 1};
	static int dy[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
	for ( int direction = 0; direction < 9; direction++ ){
	    int x = position.x + dx[direction];
	    int y = position.y + dy[direction];
	    if ( x == target.x && y == target.y ) return true;
	}
	return false;
    }
};

class Park{
    private:
    Point start;
    vector<Sprinkler> sprinklers;
    
    public:
    bool bfs(){
	queue<Point> currentQ;
	addQueue( -1, start, currentQ );
	
	for ( int current = 0; current < sprinklers.size() - 1; current++ ){
	    queue<Point> nextQ;
	    
	    while ( !currentQ.empty() ){
		Point u = currentQ.front(); currentQ.pop();
		addQueue( current, u, nextQ );
	    }
	    currentQ = nextQ;
	}
	return !currentQ.empty();
    }

    void addQueue( int current, Point u, queue<Point> &nextQ){
	static int pdx[12] = {2, 2, 1, 0, -1, -2, -2, -2, -1, 0, 1, 2};
	static int pdy[12] = {0, -1, -2, -2, -2, -1, 0, 1, 2, 2, 2, 1};
	for ( int direction = 0; direction < 12; direction++ ){
	    int nx = u.x + pdx[ direction ];
	    int ny = u.y + pdy[ direction ];
	    if ( 0 <= nx && nx < MAX && 0 <= ny && ny < MAX ){
		if ( sprinklers[current + 1].in( Point(nx, ny) ) ){
		    nextQ.push( Point(nx, ny));
		}
	    }
	}
    }
    
    void simulate(){
	if ( bfs() ) cout << "OK" << endl;
	else cout << "NA" << endl;
    }
    
  bool input(){
    string line;
    char ch;
    int x, y;
    
    cin >> x >> y;
    if ( x == 0 && y == 0 ) return false;
    start = Point(x, y);
    getline( cin, line );
    int r; cin >> r;
    getline( cin, line );
    getline( cin, line );
    stringstream ss( line );
    
    for ( int i = 0; i < r; i++ ){
      ss >> x >> y;
      sprinklers.push_back( Sprinkler( Point(x, y)) ); 
    }
    return true;
  }
};

main(){
  while(1){
    Park park;
    if (!park.input()) break;
    park.simulate();
  }
}
