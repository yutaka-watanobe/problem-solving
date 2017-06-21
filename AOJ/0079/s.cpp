 #include<cstdio>
 #include<cmath>
 
 struct Point{ double x, y;};
 
 double getDistance(Point p1, Point p2){
     return sqrt( (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
 }
 main(){
     Point P[20];
     int n = 0;
     double z, S = 0;
     while( scanf("%lf,%lf", &P[n].x, &P[n].y) != EOF ){
 	n++;
     }
     for ( int i = 1; i < n-1; i++ ){
 	double a = getDistance(P[0], P[i]);
 	double b = getDistance(P[i], P[i+1]);
 	double c = getDistance(P[0], P[i+1]);
 	z = (a + b + c )/2.0;
 	S += sqrt(z*(z-a)*(z-b)*(z-c));
     }
     printf("%.8lf\n", S);
 }
