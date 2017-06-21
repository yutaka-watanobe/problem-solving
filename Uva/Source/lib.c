



/**
 * get prime number between 2 to N 
 * @author Yutaka Watanobe
 * @param long *p, long n 
 * @return -----
 */
void getPrimeNumber(long *p, long n){
  long	c, i, j, judge;
  for (i = 0; i < n; i++) p[i] = 0;
  i = 3;
  c = 0;
  p[0] = 2;
  while (i <= n) {
    judge = 0;
    for (j = 0; p[j] <= sqrt(i); j++) {
      if (i % p[j] == 0) {
	judge = 1;
	break;
      }
    }
    if (judge == 0) {
      c++;
      p[c] = i;
    }
    i++;
  }
}

/**
 * get the number of prime number between 2 to N 
 * @author Yutaka Watanobe
 * @param  long n 
 * @return int count
 */
int getNumberOfPrime(long n)
{
  long *p;
  p = (long *)malloc(n*sizeof(long));
  long	c, i, j, judge;
  long count = 1; /* because it include '2' */
  for (i = 0; i < n; i++) p[i] = 0;
  i = 3;
  c = 0;
  p[0] = 2;
  while (i <= n) {
    judge = 0;
    for (j = 0; p[j] <= sqrt(i); j++) {
      if (i % p[j] == 0) {
	judge = 1;
	break;
      }
    }
    if (judge == 0) {
      c++;
      p[c] = i; count++;
    }
    i++;
  }
  return count;
}


/**
 * check whether N is prime number or not 
 * @author Yutaka Watanobe
 * @param long n
 * @return int ( if it is prime --> 1, else --> 0 )
**/
int isPrimeNumber(long n){
  int limit = n-1;
  int find = 1;
  for(int j=2; j<=limit; j++){
    if(n%j==0){
      find = 0;
      break;
    }
  }
  if(find==1){
    return 1;
  } else {
    return 0;
  }
}

/**
 *  check whether N is squear number or not 
 * @param int n
 * @retrun 1 or 0 ( 1 is squear )
**/
int is_sqrt(int n){
  if (sqrt(n) == floor(sqrt(n)))
    return 1;
  return 0;
}




/*２から N までの素数を求める */
/* get prime number between 2 to N */
void getPrime( int *p, int n ){
  int limit,find;
  int cnt = 0;
  for(int i=2; i<=n; i++){
    /*limit=sqrt(i);*/
    limit=i-1;/* limit=sqrt(i); */ /* 割る数のlimitはi-1 */
    find=1;
    for(int j=2; j<=limit; j++){ /* 割る数Jは２からlimitまで */
      if (i%j==0){  /* 割り切れたら素数ではないのでＢｒｅａｋする */
	find=0;
	break;
      }
    }
    if(find==1){ /* findが１のままなら素数 */
      p[cnt++] = i;
    }
  }
}
