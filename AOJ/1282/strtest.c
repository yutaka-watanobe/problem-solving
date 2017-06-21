#include<stdio.h>
#include<string.h>

int main(){
  char buff[11] = "aaaaaaaaaa";
  char str[4] = "123";

  strcpy(&buff[3], str);

  printf("%s\n", buff);
  return 0;
}
