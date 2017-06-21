import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	/**
	 * @param args
	 * @throws IOException 
	 * @throws NumberFormatException 
	 */
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader stdin = 
            new BufferedReader(
                new InputStreamReader(System.in));
				//new InputStreamReader(new FileInputStream("resource/P0012.txt")));
		String tmp;
		MyPoint x1;
		MyPoint x2;
		MyPoint x3;
		MyPoint p;
		MyTriangle t;
		while((tmp = stdin.readLine()) !=null){
			if(tmp.split(" ").length != 8) break;
			x1 = new MyPoint(Double.valueOf(tmp.split(" ")[0]),Double.valueOf(tmp.split(" ")[1]));
			x2 = new MyPoint(Double.valueOf(tmp.split(" ")[2]),Double.valueOf(tmp.split(" ")[3]));
			x3 = new MyPoint(Double.valueOf(tmp.split(" ")[4]),Double.valueOf(tmp.split(" ")[5]));
			p = new MyPoint(Double.valueOf(tmp.split(" ")[6]),Double.valueOf(tmp.split(" ")[7]));
			t = new MyTriangle(x1,x2,x3);
			
			if(t.isIncluded(p))
				System.out.println("YES");
			else System.out.println("NO");
		}
	}
}
class MyPoint{
	private Double x;
	private Double y;
	
	public MyPoint(Double x, Double y) {
		super();
		this.x = x;
		this.y = y;
	}
	public Double getX() {
		return x;
	}
	public void setX(Double x) {
		this.x = x;
	}
	public Double getY() {
		return y;
	}
	public void setY(Double y) {
		this.y = y;
	}
}

class MyTriangle{
	private MyPoint p1;
	private MyPoint p2;
	private MyPoint p3;
	public MyTriangle(MyPoint p1, MyPoint p2, MyPoint p3) {
		super();
		this.p1 = p1;
		this.p2 = p2;
		this.p3 = p3;
	}
	public MyPoint getP1() {
		return p1;
	}
	public void setP1(MyPoint p1) {
		this.p1 = p1;
	}
	public MyPoint getP2() {
		return p2;
	}
	public void setP2(MyPoint p2) {
		this.p2 = p2;
	}
	public MyPoint getP3() {
		return p3;
	}
	public void setP3(MyPoint p3) {
		this.p3 = p3;
	}
	
	public boolean isIncluded(MyPoint x){
		if( (p1.getX()-p3.getX()) * (p1.getY()-p2.getY()) == (p1.getX() - p2.getX()) * (p1.getY()-p3.getY()) )
			return false;
		
		if( !isIntersected(p1, p2, x, p3) &&
				!isIntersected(p1, p3, x, p2)&&
				!isIntersected(p2, p3, x, p1)){
			return true;
		}
		return false;
	}
	
	private boolean isIntersected(MyPoint x1,MyPoint x2,MyPoint x3,MyPoint x4){
		if( ((x1.getX()-x2.getX())*(x3.getY()-x1.getY())+(x1.getY()-x2.getY())*(x1.getX()-x3.getX())) 
				* ((x1.getX()-x2.getX())*(x4.getY()-x1.getY())+(x1.getY()-x2.getY())*(x1.getX()-x4.getX()))
				 < 0){
			return true;
		}
		return false;
	}
}
