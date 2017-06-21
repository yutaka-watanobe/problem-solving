// @JUDGE_ID:  17051CA  101  Java
// @begin_of_source_code
import java.io.*;
import java.util.*;

class Main{
  private Vector[] pos;
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
    Main block = new Main();  // create a dinamic instance
    block.Begin();            // the true entry point
  }
  
  void Begin(){
    String input;
    StringTokenizer st;
    input = Main.ReadLn (255);
    st = new StringTokenizer(input);
    int n = Integer.parseInt( st.nextToken() );
    pos = new Vector[n];
    for(int i=0 ; i < n ; i++){
      pos[i] = new Vector();
      pos[i].addElement(new Integer(i));
    }
    
    while ((input = Main.ReadLn (255)) != null){
      st = new StringTokenizer( input );
      String com1 = st.nextToken();
      if( !(com1.equals("quit")) ) {
	int b1 = Integer.parseInt( st.nextToken() );
	String com2 = st.nextToken();
	int b2 = Integer.parseInt( st.nextToken() );
	if( com1.equals("move") && com2.equals("onto") ){
	  moveOnto(b1, b2);
	}else if( com1.equals("move") && com2.equals("over") ){
	  moveOver(b1, b2);
	}else if( com1.equals("pile") && com2.equals("onto") ){
	  pileOnto(b1, b2);
	}else if( com1.equals("pile") && com2.equals("over") ){
	  pileOver(b1, b2);
	}
      }
    }

    for(int i=0 ; i<n ; i++){
      Vector p = pos[i];
      String list = "";
      for( int j=0 ; j< p.size() ; j++){
	list = list + " " + Integer.toString( ((Integer)p.elementAt(j)).intValue() );
      }
      System.out.println(i + ":" + list );
    }
  }

  void moveOnto(int b1, int b2){
    if( getPos(b1) == getPos(b2) ) return;
    

  }

  void moveOver(int b1, int b2){
    

  }

  void pileOnto(int b1, int b2){
    

  }

  void pileOver(int b1, int b2){
    

  }

  void getPos(int b){
    int pos = 0;
    for(int i=0 ; i<n ; i++){
      Vector block = pos[i];
      for(int j=0 ; j < block.size() ; j++){
	if( ((Integer)(block.elementAt(j))).intValue() == b){
	  pos = i;
	  return pos;
	}
      }
    }
  }
  
}
// @end_of_source_code

