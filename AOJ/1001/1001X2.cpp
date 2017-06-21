#include<iostream>
#include<string>
#include<cassert>
using namespace std;
char com;
string tree1, tree2;
bool act1, act2;
int p1, p2;

void parseI(){
    if ( tree1[p1] == '(' && tree2[p2] == '(' ) { cout << "("; p1++; p2++; parseI(); assert(tree1[p1] == ')' ); p1++; p2++; cout << ")";}
    else {p1++; p2++;}
    cout << ",";
    if ( tree1[p1] == '(' && tree2[p2] == '(' ) { cout << "("; p1++; p2++; parseI(); p1++; p2++; cout << ")";}
    else {p1++; p2++;}
}

void parseU(){
    if ( act1 && tree1[p1] == '(' || act2 && tree2[p2] == '(' ){
	cout << "(";
	if ( tree1[p1] != '(' ) act1 = false;
	if ( tree1[p2] != '(' ) act2 = false;
	if ( act1 ) p1++;
	if ( act2 ) p2++;
	parseU();
	act1 = act2 = true;
	p1++;
	p2++;
	cout << ")";
    } else {
	if ( act1 ) p1++;
	if ( act2 ) p2++;
    }
    cout << ",";
     if ( act1 && tree1[p1] == '(' || act2 && tree2[p2] == '(' ){
	cout << "(";
	if ( tree1[p1] != '(' ) act1 = false;
	if ( tree1[p2] != '(' ) act2 = false;
	if ( act1 ) p1++;
	if ( act2 ) p2++;
	parseU();
	act1 = act2 = true;
	p1++;
	p2++;
	cout << ")";
    } else {
	if ( act1 ) p1++;
	if ( act2 ) p2++;
    }

}

int main(){
    while( cin >> com ){
	cin >> tree1 >> tree2;
	act1 = act2 = true;
	p1 = p2 = 1;
	if ( com == 'i' ){ cout << "(" ; parseI(); cout << ")" << endl;}
	else {cout << "(" ; parseU(); cout << ")" << endl;}
    }
    return 0;
}

