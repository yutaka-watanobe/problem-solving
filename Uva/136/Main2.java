// @JUDGE_ID:  17051CA  136  Java
// @begin_of_source_code
import java.io.*;
import java.util.*;

class Main2{
  
  public static void main (String args[]){  // entry point from OS
    Main2 myWork = new Main2();  // create a dinamic instance
    myWork.Begin();            // the true entry point
  }
  
  void Begin(){
    boolean flag = true;
    int i = 0;
    int count = 0;
    int number = 0;
    while(flag){
      i++;  
      int a = i;
      boolean ugly = false;
      if( a==1 ) ugly = true;

      while( a/2 == (float)a/2 ){
	if( a == 2) ugly = true;
	a = a/2;
      }
      
      while( a/3 == (float)a/3 ){
	if( a == 3) ugly = true;
	a = a/3;
      }
      
      while( a/5 == (float)a/5 ){
	if( a == 5) ugly = true;
	a = a/5;
      }
      
      if( ugly ) {
	count++; 
      }
      if(count == 1500) {
	number = i;
	flag = false;
      }
    }
    System.out.println("The 1500'th ugly number is " + number + ".");
  }
}
// @end_of_source_code

