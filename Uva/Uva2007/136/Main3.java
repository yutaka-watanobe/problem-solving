// @JUDGE_ID:  17051CA  136  Java
// @begin_of_source_code
import java.io.*;
import java.util.*;

class Main3{
  long[] uglyN;
  public static void main (String args[]){  // entry point from OS
    Main3 myWork = new Main3();  // create a dinamic instance
    myWork.Begin();            // the true entry point
  }
  
  void Begin(){
    uglyN = new long[1500];
    boolean flag = true;
    long i = 0;
    int count = 0;
    long number = 0;
    while(flag){
      i++;  
      long a = i;
      boolean ugly = false;
      if( a==1 ) ugly = true;
      boolean divisible = true;
      while(divisible ){
	if( check( a, count ) ){
	  ugly = true;
	  divisible=false;
	}
	if( a/2 == (float)a/2){
	  if( a == 2) ugly = true;
	  a = a/2;
	}else if( a/3 == (float)a/3 ){
	  if( a == 3) ugly = true;
	  a = a/3;
	}else if( a/5 == (float)a/5 ){
	  if( a == 5) ugly = true;
	  a = a/5;
	}else{
	  divisible=false;
	}
      }

      if( ugly ) {
	uglyN[count] = i;
	count++; 
      }
      if(count == 1500) {
	number = i;
	flag = false;
      }
    }
    System.out.println("The 1500'th ugly number is " + number + ".");
  }

  boolean check(long a, int index){
    for(int i=index ; i >= 0 ; i--){
      if( uglyN[i] == a ) return true;
    }
    return false;
  }
}
// @end_of_source_code

