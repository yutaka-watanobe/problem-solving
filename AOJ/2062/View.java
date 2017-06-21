import java.awt.*;
import java.awt.geom.*;
import javax.swing.*;
import java.util.Scanner;

public class View extends JFrame {
  
  public View(){
    this.setSize(1300, 1300);
    this.add(new GPanel(), BorderLayout.CENTER);
    this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
  }
  
  public static void main(String[] args) {
    new View().setVisible(true);
  }
}

class GPanel extends JPanel {

  @Override
  public void paintComponent(Graphics g) {
    super.paintComponent(g);
    Graphics2D g2 = (Graphics2D)g;

    int shift = 350;
    int m = 20;
    Scanner stdIn = new Scanner(System.in);
    int n = stdIn.nextInt();
    for ( int i = 0; i < n; i++ ){
	double x1 = stdIn.nextDouble();
	double y1 = stdIn.nextDouble();
	double x2 = stdIn.nextDouble();
	double y2 = stdIn.nextDouble();
	x1 *= m;
	y1 *= m;
	x2 *= m;
	y2 *= m;
	g.drawLine((int)x1+shift, (int)y1+shift, (int)x2+shift, (int)y2+shift);
    }
    /*
0.000000000000000 0.000000000000000 -11.312893266885743 -15.574593219433101
-3.029400895245814 -4.170611843404086 0.059347183084365 -17.334102444827060
-2.988227704877808 -4.113928227957540 -32.609872575088410 22.773049422164625
-0.988244655061528 -12.869521661335021 -15.703872807830333 -18.040297018884210
-17.059109162199643 8.657930894592287 -19.936334348396983 28.169870631364695
-3.362967808905224 -4.629837336754578 -41.288507592849747 7.519765445206499
-7.419876098816287 -3.330190066707525 -13.019764574446512 42.039735829096955
-3.435931071020269 -4.730286717880714 12.992073204158478 21.728725116412342
-0.836585902251336 -13.515854258430398 -8.642078505438287 17.774998309876523
-6.443100553775457 -3.643104133243860 -2.695299262103406 -14.750682275200115
-9.012726622470199 1.354389566689632
    */
    /*
    int w = this.getWidth();
    int h = this.getHeight();
    for(int i = 0;i < 10;i++){
      Ellipse2D shape = new Ellipse2D.Double(0,0,w,h - i * (w / 10));
      g2.setPaint(new Color(0,0,255,25));
      g2.fill(shape);
    }
    */
  }
}
