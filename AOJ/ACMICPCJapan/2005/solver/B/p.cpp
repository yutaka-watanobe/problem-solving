#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Student{
    public:
    queue<int> requests;
    Student(){}

    int getRequest(){
	int r = requests.front(); requests.pop();
	return r;
    }
};

class Storeroom{
    public:
    int capacity, ndesk;
    vector<vector<int> > buffer;

    Storeroom(){}
    Storeroom(int d, int c): ndesk(d), capacity(c){
	buffer.resize(d+1);
	for ( int i = 1; i <= 100; i++ ){
	    buffer[d].push_back(i);
	}
    }

    int take( int requested, int &cost ){
	for ( int d = 0; d <= ndesk; d++ ){
	    for ( int i = 0; i < buffer[d].size(); i++ ){
		if ( buffer[d][i] == requested ){
		    cost += (d+1);
		    int book = buffer[d][i];
		    buffer[d].erase( buffer[d].begin() + i );
		    return book;
		}
	    }
	}
    }

    bool isFull(int d){
	return buffer[d].size() >= capacity;
    }
    
    void put(int d, int book, int &cost){
	buffer[d].push_back(book);
	cost += (d+1);
    }

    int getNonFullDesk(){
	for ( int d = 1; d < ndesk; d++ ){
	    if ( buffer[d].size() < capacity ) return d;
	}
	return ndesk;
    }

    int takePassive(int &cost){
	int tmp = buffer[0][0];
	buffer[0].erase( buffer[0].begin() + 0 );
	cost++;
	return tmp;
    }
};

queue<Student> students;
Storeroom storeroom;

int simulate(){
    int cost = 0;
    Student st;
    int requested, desk, target;

    while( !students.empty() ){
	st = students.front(); students.pop();
	requested = st.getRequest();

	target = storeroom.take(requested, cost);

	if ( !storeroom.isFull(0) ) {
	    storeroom.put(0, target, cost);
	} else {
	    desk = storeroom.getNonFullDesk();
	    storeroom.put(desk, target, cost);

	    target = storeroom.takePassive(cost);
	    desk = storeroom.getNonFullDesk();
	    storeroom.put(desk, target, cost);

	    target = storeroom.take(requested, cost);
	    storeroom.put(0, target, cost);
	}

	if ( st.requests.size() ) students.push(st);
    }

    return cost;
}

bool input(){
    int m, c, n, k; 
    cin >> m >> c >> n;
    if ( m == 0 && c == 0 && n == 0 ) return false;
    storeroom = Storeroom( m, c );
    students = queue<Student>();

    for ( int i = 0; i < n; i++ ){
	cin >> k;
	Student st;
	for ( int j = 0; j < k; j++ ){
	    int id; cin >> id;
	    st.requests.push(id);
	}
	students.push(st);
    }

    return true;
}

main(){
    while(input()) cout << simulate() << endl;
}