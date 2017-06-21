#include <iostream>
#include <cmath>
using namespace std;

#define INFTY 1e+256

double geth(double d){
  double e=6.11*exp(5417.7530*((1/273.16)-(1/(d+273.16))));
  double h=0.5555*(e-10.0);
  return h;
}

void compute(double *n){
  if (n['H']== INFTY)
    n['H']=n['T']+geth(n['D']);
  if (n['T']== INFTY)
    n['T']=n['H']-geth(n['D']);
  if (n['D']== INFTY){
    double result;
    double mindif= INFTY;
    for(double d=-100.0;d<=100.0;d+=0.001){
      double dif=fabs( n['H'] - (n['T']+geth(d)) );
      if (dif<mindif){
	mindif=dif;
	result=d;
      }
    }
    n['D']=result;
  }
}
    

main(){
  char c,cc;
  double d,dd;
  while(cin >> c >> d >> cc >> dd && c!='E'){
    double n[256];
    fill_n(n,256, INFTY);
    n[c]=d; n[cc]=dd;
    compute(n);
    printf("T %.1lf D %.1lf H %.1lf\n",n['T'],n['D'],n['H']);
  }
}
