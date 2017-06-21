class test{
  test(){
    int a = 3;
    System.out.println( a/2 + ", " + (float)a/2);
    if( a/2 == (float)a/2 ) {
      System.out.println("same");
    }
  }
  public static void main(String[] a){
    new test();
  }
}
