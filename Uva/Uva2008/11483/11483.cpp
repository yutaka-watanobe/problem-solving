#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

int main(){
    string line;
    int n;
    int tcase = 1;
    while(1){
	getline( cin, line );
	n = atoi(line.c_str());
	if ( n == 0 ) break;
	printf("Case %d:\n", tcase++);
	printf("#include<string.h>\n");
	printf("#include<stdio.h>\n");
	printf("int main()\n");
	printf("{\n");
	for ( int i = 0; i < n; i++ ){
	    getline(cin, line);
	    printf("printf(\"");
	    for ( int s = 0; s < line.size(); s++ ){
		if ( line[s] == '"' || line[s] == '\\') printf("\\");
		printf("%c", line[s]);
	    }
	    printf("\\n\");\n");
	}
	printf("printf(\"\\n\");\n");
	printf("return 0;\n");
	printf("}\n");
    }
    return 0;
}
