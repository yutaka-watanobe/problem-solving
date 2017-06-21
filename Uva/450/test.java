import java.util.*;

class test{
  public static void main(String[] args){
    Vector v = new Vector();
    
    v.add(0, new Integer(0));
    v.add(0, new Integer(1));
    
    for(int i=0; i<v.size(); i++){
      System.out.println( ((Integer)(v.elementAt(i))).intValue() );
    }
  }


}
