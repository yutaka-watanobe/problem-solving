#include<iostream>
#include<set>
using namespace std;

int main(){
    set<int> s;

    s.insert(1);
    s.insert(3);
    s.insert(200);
    s.insert(4);
    s.insert(5);

    s.erase(300);
    s.erase(200);

    set<int>::iterator it;
    for ( it = s.begin(); it != s.end(); it++ ){
	cout << *it << endl;
    }


}
