// @JUDGE_ID:  17051CA  507  C++
// @begin_of_source_code
/* Dynamic Programming */
#include<stdio.h>
#include<iostream>
#include<algorithm>
#define MAX 20001

int s, size;
int T[MAX], M[MAX], L[MAX], S[MAX];

void read(){
  scanf( "%d", &s );
  size = s - 1;
  for ( int i = 1; i <= size; i++ ){
    scanf("%d", &T[i]);
  }
}

void work( int route ){
  M[0] = 0;
  L[0] = 0;
  S[0] = 1;
  for ( int i = 1; i <= size; i++ ){
    /* if previous is negative it should be ignored ! */
    if ( M[i-1] >= 0 ){
      M[i] =  M[i-1] + T[i];
      L[i] = L[i-1] + 1;
      S[i] = S[i-1];
    }else{
      M[i] = T[i];
      L[i] = 1;
      S[i] = i;
    }
  }

  int max_value = 0 - INT_MAX;
  int max_len = 0;
  int lowest_stop = INT_MAX;
  int start, end;
  for ( int i = size; i >= 1; i-- ){
    if ( max_value < M[i] ){
      max_value = M[i];
      max_len = L[i];
      lowest_stop = S[i];
      end = i+1;
      start = S[i];
    } else if ( max_value == M[i] ){
      if ( max_len < L[i] ){
	max_value = M[i];
	max_len = L[i];
	lowest_stop = S[i];
	end = i+1;
	start = S[i];
      } else if ( max_len == L[i] ){
	if ( lowest_stop > S[i] ){
	  max_value = M[i];
	  max_len = L[i];
	  lowest_stop = S[i];
	  end = i+1;
	  start = S[i];
	}
      }
    }
  }

  if ( max_value < 0 ){
    cout << "Route " << route << " has no nice parts" << endl;
  }else{
    cout << "The nicest part of route " << route << " is between stops " << start << " and " << end << endl;
  }

  
}

main(){
  int route;
  cin >> route;
  for ( int i = 1; i <= route ; i++ ){
    read();
    work(i);
  }
}
// @end_of_source_code
