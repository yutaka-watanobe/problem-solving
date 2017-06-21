#include<cstdio>
#include<cctype>

main(){
  char ch;
  while(1){
    scanf("%c", &ch);
    if ( ch == '\n' ){
      printf("\n");
       break;
    }
    if ( isalpha(ch) ){
      if ( islower(ch) ) printf("%c", toupper(ch));
      //if ( isupper(ch) ) printf("%c", tolower(ch));
    } else {
      printf("%c", ch);
    }
  }
}
