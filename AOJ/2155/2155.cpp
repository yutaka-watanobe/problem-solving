#include<cstdio>
#include<algorithm>
using namespace std;
#define MAX  20000

class Message{
    public:
    int t, s, d;
    Message(){}
    bool operator < ( const Message &m ) const{
	return t < m.t;
    }
};

int N, M;
bool infected[MAX];
Message messages[MAX];

main(){
    while(1){
	scanf("%d %d", &N, &M);
	if ( N == 0 && M == 0 ) break;
	for ( int i = 0; i < M; i++ ){
	    scanf("%d %d %d", &messages[i].t, &messages[i].s, &messages[i].d);
	}

	sort( messages, messages + M );
	for ( int i = 0; i < N; i++ ) infected[i] = false;

	infected[0] = true;

	for ( int i = 0; i < M; i++ ){
	    int s = messages[i].s - 1;
	    int d = messages[i].d - 1;
	    if ( infected[s] ) infected[d] = true;
	}

	int sum = 0;
	for ( int i = 0; i < N; i++ ) if ( infected[i] ) sum++;
	printf("%d\n", sum);
    }
}
