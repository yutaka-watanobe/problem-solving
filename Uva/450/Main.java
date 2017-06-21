// @JUDGE_ID:  17051CA  450  Java
// @begin_of_source_code
import java.io.*;
import java.util.*;

class Main{

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
    Vector fac = new Vector();
    Facluty f;
    String input;
    String department;
    String title = "";
    String firstN = "";
    String lastN = "";
    String streetA = "";
    String homeP = "";
    String workP = "";
    String mailB = "";
    StringTokenizer st;
    int n;
    input = Main.ReadLn(255);
    n = Integer.parseInt(input);
    for(int i=0; i<n; i++){
      department = Main.ReadLn(255);
      while( true ){
	input = Main.ReadLn(255);
	if( input == null || input.equals("")) {
	  break;
	}
	st = new StringTokenizer(input, ",", false);
	if(st.hasMoreTokens()) title = st.nextToken();
	if(st.hasMoreTokens()) firstN = st.nextToken();
	if(st.hasMoreTokens()) lastN = st.nextToken();
	if(st.hasMoreTokens()) streetA = st.nextToken();
	if(st.hasMoreTokens()) homeP = st.nextToken();
	if(st.hasMoreTokens()) workP = st.nextToken();
	if(st.hasMoreTokens()) mailB = st.nextToken();
	f = new Facluty(title, firstN, lastN, streetA, homeP, workP, mailB, department);
	
	if( fac.size() == 0 ){
	  fac.addElement(f);
	}else{
	  boolean flag = false;
	  for(int s=0; s<fac.size(); s++){
	    Facluty ff = (Facluty)(fac.elementAt(s));
	    if( (ff.lastN).compareTo(f.lastN) >= 0 ){
	      fac.insertElementAt(f, s);
	      flag = true;
	    }
	    if(flag) break;
	  }
	  if(!flag) fac.addElement(f);
	}
      }
    }
    
    for(int i=0; i<fac.size(); i++){
      System.out.println("----------------------------------------");
      f = (Facluty)(fac.elementAt(i));
      System.out.println(f.title + " " + f.firstN + " " + f.lastN);
      System.out.println(f.streetA);
      System.out.println("Department: " + f.department);
      System.out.println("Home Phone: " + f.homeP);
      System.out.println("Work Phone: " + f.workP);
      System.out.println("Campus Box: " + f.mailB);
    }

  }
}
class Facluty{
  String title;
  String firstN;
  String lastN;
  String streetA;
  String homeP;
  String workP;
  String mailB;
  String department;
  Facluty(String t, String f_n, String l_n, String s_a, String h_p, String w_p, String m, String d){
    title = t;
    firstN = f_n;
    lastN = l_n;
    streetA = s_a;
    homeP = h_p;
    workP = w_p;
    mailB = m;
    department = d;
  }
  
}
// @end_of_source_code

