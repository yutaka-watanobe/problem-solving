// @JUDGE_ID:  17051CA  10010  Java
// @begin_of_source_code
import java.io.*;
import java.util.*;

class Main{
  char[][] grid;
  int m, n;

  static String ReadLn (int maxLg){  // utility function to read from stdin
    byte lin[] = new byte [maxLg];
    int lg = 0, car = -1;
    String line = "";
    
    try{
      while (lg < maxLg){
	car = System.in.read();
	if ((car < 0) || (car == '\n')) break;
	lin [lg++] += car;
      }
    } catch (IOException e){
      return (null);
    }
    
    if ((car < 0) && (lg == 0)) return (null);  // eof
    return (new String (lin, 0, lg));
  }
  
  public static void main (String args[]){  // entry point from OS
    Main myWork = new Main();  // create a dinamic instance
    myWork.Begin();            // the true entry point
  }
  
  void Begin(){
    String input;
    StringTokenizer st;
    int N;
    input = Main.ReadLn(255);
    N = Integer.parseInt( input );

    for(int a=1; a<=N; a++){
      Main.ReadLn(255);//blank
      input = Main.ReadLn(255);
      st = new StringTokenizer(input);
      m = Integer.parseInt( st.nextToken() );
      n = Integer.parseInt( st.nextToken() );
      grid = new char[m][n];
      for(int i=0 ; i<m ; i++ ){
	input = Main.ReadLn(255);
	input = input.toLowerCase();
	for(int j=0 ; j<n ; j++){
	  grid[i][j] = input.charAt(j);
	}
      }
      input = Main.ReadLn(255);
      int k = Integer.parseInt(input);
      for(int i=0 ; i<k ; i++){
	input = Main.ReadLn(255);
	search( input.toLowerCase() );
      }
      if(a!=N){
	System.out.println();
      }
    }
  }

  void search(String word){
    int count;
    int size = word.length();
    int mm, nn;
    String str;
    for(int i=0 ; i<m ; i++){
      for(int j=0 ; j<n ; j++){
	// E
	mm = i;
	nn = j;
	str = "";
	count = 0;
	while( nn < n && count < size){
	  str = str + grid[i][nn];
	  nn++; count++;
	}
	if( str.indexOf( word ) == 0 ){
	  System.out.println( (i+1) + " " + (j+1) );
	  return;
	}
	// N
	mm = i;
	nn = j;
	str = "";
	count = 0;
	while( mm >= 0 && count < size){
	  str = str + grid[mm][j];
	  mm--; count++;
	}
	if( str.indexOf( word ) == 0){
	  System.out.println( (i+1) + " " + (j+1) );
	  return;
	}
	// W
	mm = i;
	nn = j;
	str = "";
	count = 0;
	while( nn >= 0 && count < size){
	  str = str + grid[i][nn];
	  nn--; count++;
	}
	if( str.indexOf( word ) == 0 ){
	  System.out.println( (i+1) + " " + (j+1) );
	  return;
	}
	// S
	mm = i;
	nn = j;
	str = "";
	count = 0;
	while( mm < m && count < size){
	  str = str + grid[mm][j];
	  mm++; count++;
	}
	if( str.indexOf( word ) == 0){
	  System.out.println( (i+1) + " " + (j+1) );
	  return;
	}
	// NE
	mm = i;
	nn = j;
	str = "";
	count = 0;
	while( mm >= 0 && nn < n && count < size){
	  str = str + grid[mm][nn];
	  mm--; nn++; count++;
	}
	if( str.indexOf( word ) == 0 ){
	  System.out.println( (i+1) + " " + (j+1) );
	  return;
	}
	// NW
	mm = i;
	nn = j;
	str = "";
	count = 0;
	while( mm >= 0 && nn >= 0 && count < size){
	  str = str + grid[mm][nn];
	  mm--; nn--; count++;
	}
	if( str.indexOf( word ) == 0 ){
	  System.out.println( (i+1) + " " + (j+1) );
	  return;
	}
	// SW
	mm = i;
	nn = j;
	str = "";
	count = 0;
	while( mm < m && nn >= 0 && count < size){
	  str = str + grid[mm][nn];
	  mm++; nn--; count++;
	}
	if( str.indexOf( word ) == 0 ){
	  System.out.println( (i+1) + " " + (j+1) );
	  return;
	}
	// SE
	mm = i;
	nn = j;
	str = "";
	count = 0;
	while( mm < m && nn < n && count < size){
	  str = str + grid[mm][nn];
	  mm++; nn++; count++;
	}
	if( str.indexOf( word ) == 0 ){
	  System.out.println( (i+1) + " " + (j+1) );
	  return;
	}
      }
    }
  }
}
// @end_of_source_code















