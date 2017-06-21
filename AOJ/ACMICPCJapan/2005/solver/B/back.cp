#include<iostream>
#include<queue>
#include<vector>
#include<cassert>
using namespace std;

#define TOP 0

class Student{
    public:
    queue<int> requests;
    Student(){}

    int getRequest(){
	int r = requests.front(); requests.pop();
	return r;
    }
};

class Book{
    public:
    int id, time;
    Book(){}
    Book(int id, int time): id(id), time(time){}
};

class Storeroom{
    public:
    int capacity, ndesk;
    vector<vector<Book> > buffer;
    Storeroom(){}
    Storeroom(int d, int c): ndesk(d), capacity(c){
	buffer.resize(d+1);
	for ( int i = 1; i <= 100; i++ ){
	    buffer[d].push_back( Book(i, 0) );
	}
    }

    void print(){
	for (int i = 0; i < ndesk + 1; i++ ){
	    cout << "dest " << i+1 << "   ";
	    for ( int j = 0; j < buffer[i].size(); j++ ) cout << buffer[i][j].id << " ";
	    cout << endl;
	}
    }
    
    Book getTarget( int requested, int &desk ){
	for ( int d = 0; d <= ndesk; d++ ){
	    for ( int i = 0; i < buffer[d].size(); i++ ){
		if ( buffer[d][i].id == requested ){
		    desk = d;
		    Book book = buffer[d][i];
		    buffer[d].erase( buffer[d].begin() + i );
		    return book;
		}
	    }
	}
	assert(false);
    }

    bool isFull(int d){
	return buffer[d].size() >= capacity;
    }
    
    void put(int d, Book book){
	buffer[d].push_back(book);
    }

    int getNonFullDesk(){
	for ( int d = 1; d < ndesk; d++ ){
	    if ( buffer[d].size() < capacity ) return d;
	}
	return ndesk;
    }

    Book getPassiveBook(){
	Book tmp = buffer[0][0];
	buffer[0].erase( buffer[0].begin() + 0 );
	return tmp;
	/*
	int t = 0;
	for ( int i = 0; i < buffer[0].size(); i++ ){
	    if ( buffer[0][i].time < buffer[0][t].time ) t = i;
	}
	Book tmp = buffer[0][t];
	buffer[0].erase( buffer[0].begin() + t );
	return tmp;
	*/
    }
};

queue<Student> students;
Storeroom storeroom;

int simulate(){
    //    storeroom.print();

    int cost = 0;
    int timer = 0;

    Student st;
    int requested, desk;
    Book target;

    while( !students.empty() ){
	st = students.front(); students.pop();
	requested = st.getRequest();

	target = storeroom.getTarget(requested, desk);
	target.time = (timer++);
	cost += (desk+1);

	if ( !storeroom.isFull(TOP) ) {
	    storeroom.put(TOP, target);
	    cost += 1;
	} else {
	    desk = storeroom.getNonFullDesk();
	    storeroom.put(desk, target);
	    cost += (desk+1);

	    target = storeroom.getPassiveBook();
	    cost += 1;
	    desk = storeroom.getNonFullDesk();
	    storeroom.put(desk, target);
	    cost += (desk+1);

	    target = storeroom.getTarget(requested, desk);
	    cost += (desk+1);
	    storeroom.put(TOP, target);
	    cost += 1;
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