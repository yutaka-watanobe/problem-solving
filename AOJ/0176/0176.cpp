#include<iostream>
#include<string>
#include<cmath>
using namespace std;
#define N 8
string table[N] = {"black", "blue", "lime", "aqua", "red", "fuchsia", "yellow", "white"};
struct Color{ string R, G, B;};

Color colors[N];

int convert(string hex){
    int p = 1, sum = 0;
    for ( int i = hex.size()-1; i >= 0; i--, p *= 16 ){
	sum += p*((isdigit(hex[i]))?(hex[i]-'0'):(hex[i]-'a'+10));
    }
    return sum;
}

double getDistance(Color c1, Color c2){
    int dr = convert(c1.R) - convert(c2.R);
    int dg = convert(c1.G) - convert(c2.G);
    int db = convert(c1.B) - convert(c2.B);
    return sqrt(dr*dr + dg*dg + db*db);
}

main(){
    for ( int i = 0; i < N; i++ ) colors[i].R = colors[i].G = colors[i].B = "00";
    colors[1].B = "ff";
    colors[2].G = "ff";
    colors[3].B = "ff";
    colors[3].G = "ff";
    colors[4].R = "ff";
    colors[5].R = "ff";
    colors[5].B = "ff";
    colors[6].R = "ff";
    colors[6].G = "ff";
    colors[7].R = "ff";
    colors[7].G = "ff";
    colors[7].B = "ff";

    string hex;
    while( cin >> hex && hex != "0"){
	string ans = "";
	double sub = (1<<30);
	Color target;
	target.R = hex.substr(1, 2);
	target.G = hex.substr(3, 2);
	target.B = hex.substr(5, 2);
	
	for ( int i = 0; i < N; i++ ){
	    double d = getDistance(colors[i], target);
	    if ( d < sub ){
		sub = d;
		ans = table[i];
	    }
	}
	cout << ans << endl;
    }
}
