import java.util.*;

class Point{
    double x, y;
    Point( double x, double y ){
	this.x = x;
	this.y = y;
    }
}

public class Main{

    double R, px, py, vx, vy;
    double EPS = 0.0000000000001;
    
    public Main(){
	Scanner sc = new Scanner(System.in);

	while(true){
	    R = sc.nextDouble();
	    if ( R == 0 ) break;
	    px = sc.nextDouble();
	    py = sc.nextDouble();
	    vx = sc.nextDouble();
	    vy = sc.nextDouble();

	    double dx1 = px;
	    double dy1 = py;
	    double dx2 = vx - px;
	    double dy2 = vy - py;

	    if ( Math.abs(dx2*dy1 - dy2*dx1) < EPS ){
		double d = getDistance();
		
		if ( Math.abs(d - R ) < EPS || d < R ){
		    System.out.println(d);
		} else {
		    System.out.println("impossible");
		}
	    } else {
		System.out.println("impossible");
	    }
	}
    }

    private double dist(double x1, double y1, double x2, double y2 ){
	return Math.sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
    }

    private boolean isOn(double x1, double y1, double x2, double y2 ){
	if ( Math.abs(dist(x1, y1, 0, 0) ) < EPS || 
	     Math.abs(dist(x2, y2, 0, 0) ) < EPS ){
	    return true;

	}

	if ( x1*x2 < 0 || y1*y2 < 0 ) return true;
	return false;

    }

    private double getDistance(){
	double tx = px + vx;
	double ty = py + vy;
	double d = dist(0, 0, px, py);

	if ( isOn(px, py, tx, ty) ){
	    return d;
	}

	if ( dist(0, 0, px, py) < dist(0, 0, tx, ty)){
	    return 2.0 - d;
	} else {
	    return d;
	}

    }

    public static void main(String[] args){
	new Main();
    }
}
