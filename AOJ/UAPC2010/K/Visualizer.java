import javax.swing.*;
import java.awt.*;
import java.awt.geom.*;
import java.util.*;


class DataComparator implements java.util.Comparator{
    public int compare(Object o1, Object o2){
	return 0;
    }
}

class Point{ // Vector
    public static double EPS = 1e-8;

    public double x, y;
    public Point(double x, double y){ this.x = x; this.y = y; }
    public Point add(Point p){ return new Point(x + p.x, y + p.y); }
    public Point minus(Point p){ return new Point(x - p.x, y - p.y); }

    public double norm(){ return x*x + y*y; }    
    public double abs(){ return Math.sqrt(norm());}
    public double arg(){ return Math.atan2(y, x); }

    public boolean equals(double a, double b){
	return Math.abs(a-b) < EPS;
    }
    public boolean dle(double a, double b){
	return equals(a, b) || (a < b);
    }
    public double getAngle(){
	double polar = Math.atan2(y, x);
	return (dle(0, polar)) ? polar : 2*Math.PI + polar;
    }

    public static Point polar( double a, double r ){
	return new Point(Math.cos(r)*a, Math.sin(r)*a);
    }
}

class Circle{
    public Point c;
    double r;

    Vector<Point> cpList;
    Vector<Point> mpList;

    Vector<Double> angleList;

    public Circle(double x, double y, double r){
	this.c = new Point(x, y);
	this.r = r;
	cpList = new Vector<Point>();
	mpList = new Vector<Point>();
	angleList = new Vector<Double>();
    }

    public boolean isIntersect(Circle c2){
	double d = 0.0;
	d  = (c.minus(c2.c)).abs();
	if ( r + c2.r < d ) return false; // no overlap
	if ( d + c2.r < r ) return false; // c includes c2
	if ( d + r < c2.r ) return false; // c2 includes c
	return true;
    }

    public void setCrossPoint(Circle c2){
	Vector<Point> cp = new Vector<Point>();
	if ( !isIntersect(c2)) return;
	double d = (c.minus(c2.c)).abs();
	double a = Math.acos((r*r+d*d-c2.r*c2.r)/(2*r*d));
	double t = (c2.c.minus(c)).arg();
	Point p1 = c.add(Point.polar(r, t+a));
	Point p2 = c.add(Point.polar(r, t-a));
	cpList.addElement(p1);
	cpList.addElement(p2);
    }

    public void setAngle(){
	ArrayList al = new ArrayList();

	for ( int i = 0; i < cpList.size(); i++ ){
	    al.add(cpList.elementAt(i).minus(c).getAngle());
	}

	Object[] oa = al.toArray();      
	Arrays.sort(oa);


	for ( int i = 0; i < oa.length; i++ ) angleList.addElement((Double)(oa[i]));

	//	for ( int i = 0; i < oa.length; i++ ) System.out.println(oa[i]);
	//	System.out.println();
	/*
	for ( int i = 0; i < oa.length-1; i++ ){
	    double th = (((Double)oa[i+1]).doubleValue() + ((Double)oa[i]).doubleValue())/2.0;
	    Point p = c.add(Point.polar(r, th));
	    mpList.addElement(p1);
	    }*/
    }

    public int contain(Point p){
	double d = p.minus(c).abs();
	if ( Math.abs(r - d) < (1e-8) ) return 0;
	if ( r > d ) return -1;
	if ( r < d ) return 1;
	return 0;
    }
    
}

class Sector{
    public Circle c;
    public double begin, end;
    Sector(Circle c, double begin, double end){
	this.c = c;
	this.begin = begin;
	this.end = end;
    }
};

class Visualizer extends JPanel{

    public static int MAX = 100;
    
    private Circle[] C;
    private Vector<Sector> sectors;
    private int state[];

    private Point target;
    private int n;

    public Visualizer(){
	double x, y, r;

	Scanner sc = new Scanner(System.in);
	n = sc.nextInt();
	C = new Circle[n];
	for ( int i = 0; i < n; i++ ){
	    x = sc.nextDouble();
	    y = sc.nextDouble();
	    r = sc.nextDouble();
	    C[i] = new Circle(x, y, r);
	}
	
	for ( int i = 0; i < n; i++ ){
	    for ( int j = 0; j < n; j++ ){
		if ( i == j ) continue;
		C[i].setCrossPoint(C[j]);
	    }

	    C[i].cpList.addElement(C[i].c.add(Point.polar(C[i].r, 0)));
	    C[i].cpList.addElement(C[i].c.add(Point.polar(C[i].r, 6.283185297)));//Math.acos(-1)*2-Point.EPS)));

	    C[i].setAngle();
	}

	x = sc.nextDouble();
	y = sc.nextDouble();
	target = new Point(x, y);

	state = new int[n];
	for ( int i = 0; i < n; i++ ) state[i] = C[i].contain(target);
	
	sectors = new Vector<Sector>();

	for ( int i = 0; i < n; i++ ){
	    Circle c = C[i];
	    int size = c.angleList.size();
	    for ( int a = 0; a < c.angleList.size()-1; a++ ){
		Double a1 = c.angleList.elementAt(a);
		Double a2 = c.angleList.elementAt(a+1);
		double th = (a2.doubleValue() + a1.doubleValue())/2.0;
		Point p = c.c.add(Point.polar(c.r, th));

		int source[] = new int[n];
		for ( int s = 0; s < n; s++ ) source[s] = C[s].contain(p);
		c.mpList.addElement(p);
		if ( match(n, state, source) ){
		    //c.mpList.addElement(p);
		    //System.out.println(a1 + ", " + th + ",  " + a2);
		    sectors.addElement(new Sector(c, a1, a2));
		}
	    }
	}
    }

    private boolean match(int n, int[] state, int[] source ){
	for ( int i = 0; i < n; i++ ){
	    if ( source[i] == 0 ) continue;
	    if ( source[i] != state[i] ) return false;
	}
	return true;
    }

    public void paintComponent(Graphics g){
	Graphics2D g2 = (Graphics2D)g;
	double w = 2;


	for ( int i = 0; i < n; i++ ){
	    double r = C[i].r;
	    double x = C[i].c.x;
	    double y = C[i].c.y;
	    g2.drawOval((int)(x-r), (int)(y-r), (int)(r*2), (int)(r*2));
	}

	for ( int i = 0; i < n; i++ ){
	    Circle c = C[i];
	    for ( int j = 0; j < c.cpList.size(); j++ ){
		Point pt = c.cpList.elementAt(j);
		g2.setColor(Color.black);
		//		g2.fillRect((int)(pt.x-w/2), (int)(pt.y-w/2), (int)(w*2), (int)(w*2));
	    }

	    for ( int j = 0; j < c.mpList.size(); j++ ){
		Point pt = c.mpList.elementAt(j);
		g2.setColor(Color.blue);
		//		g2.fillRect((int)(pt.x-w/2), (int)(pt.y-w/2), (int)(w*2), (int)(w*2));
	    }

	}
	
	g2.setColor(Color.red);
	g2.fillRect((int)(target.x-w/2), (int)(target.y-w/2), (int)(w*2), (int)(w*2));

	double total = 0.0;

	for ( int i = 0; i < sectors.size(); i++ ){
	    Sector sec = sectors.elementAt(i);
	    int x = (int)(sec.c.c.x-sec.c.r);
	    int y = (int)(sec.c.c.y-sec.c.r);
	    int len = (int)(sec.c.r*2);

	    double th = Math.abs(sec.end-sec.begin);
	    total += th*sec.c.r;
	    int sa = (int)(sec.begin*180.0/Math.PI);
	    int se = (int)(sec.end*180.0/Math.PI);
	    sa -= 2*sa;
	    se -= 2*se;
	    g2.setColor(Color.red);
	    g2.drawArc(x, y, len, len, sa, se - sa);

	}

	System.out.println(total);


    }

    public static void main(String[] args){ 
	JFrame frame = new JFrame();
	Visualizer app = new Visualizer();
	frame.getContentPane().add(app);
	frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	frame.setBounds(0, 0, 800, 800);
	frame.setVisible(true);
    }

}
