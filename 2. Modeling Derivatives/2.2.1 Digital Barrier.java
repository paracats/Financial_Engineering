// Java For Quantitative Finance
// Digital Barrier
// Author: David Li

package FinApps;
import static java.lang.Math.*;
import BaseStats.Probnorm;
import BaseStats.Bivnorm;
public class Digitalbarrier {

    public Digitalbarrier(double rate, double yield, double barrier)
  {
     r=rate;
     crate=yield;
     h=barrier;
     b=crate==0.0?0.0:(b=crate!=r?(r-crate):r);
  }
  
static double crate;
static double r;
static double t;
static double b;
static double k;
static double s;
static double x;
static double h;
static double sigma;
static int phi;
static int eta;
  
public double barops(double asset , double strike, double cash,
                                   double volatility,double time, int tp) {
    s=asset;
    x=strike;
    k=cash;
    sigma=volatility;
    t=time;
    return barV.funC.Args(tp);
}
  
  private static double N(double x) {
      Probnorm p=new Probnorm();
      double ret=x>(6.95)?1.0:x<(-6.95)?0.0:p.ncDisfnc(x);//restrict
      the range of cdf values to stable values
      return ret;
}
  
private enum barV {
   funC{
      public double Args( int tp) {
          int sw=tp;
          
          double puterm=0.0;
          
          switch(sw) {
                case 1: eta=1; puterm=t9.val(); // type 1
                break;
                case 2:eta=-1; puterm=t9.val(); // type 2
                break;
                case 3: eta=1;puterm=t9.val();// type 3
                break;
                case 4: eta=-1;puterm=t9.val();// type 4
                break;
                case 5: eta=1;phi=-1;puterm=t4.val()+t8.val();
                break;
                case 6:eta=-1;phi=1;puterm=t4.val()+t8.val();
                break;
                case 7:eta=1;phi=-1;puterm=t3.val()+t7.val();
                break;
                case 8:eta=-1;phi=1;puterm=t3.val()+t7.val();
                break;
                case 9:eta=1;phi=1;puterm=t4.val()-t8.val();
                break;
                case 10:eta=-1;phi=-1;puterm=t4.val()-t8.val();
                break;
                case 11:eta=1;phi=1;puterm=t3.val()-t7.val();
                break;
                case 12:eta=-1;phi=-1;puterm=t3.val()-t7.val();
                break;
                case 13:phi=x<h?1:0;eta=1;puterm=x<h?(t2.val()
                        -t4.val()+t8.val()):t6.val();
                break;
                case 14:eta=-1;phi=1;puterm=x<h?(t4.val()-t6.val()
                        +t8.val()):t6.val();
                break;
                case 15:eta=1;phi=x<h?1:0;puterm=x<h?(t1.val()
                        -t3.val()+t7.val()):t5.val();
                break;
                case 16:phi=1;eta=x<h?-1:0;puterm=x<h?(t3.val()
                        -t5.val()+t7.val()):t1.val();
                break;
                case 17:phi=-1;eta=x>h?1:0;puterm=x>h?(t4.val()
                        -t6.val()+t8.val()):t2.val();
                break;
                case 18:phi=-1;eta=-1;puterm=x>h?(t2.val()
                        -t4.val()+t8.val()):t6.val();
                break;
                case 19:phi=-1;eta=x>h?1:0;puterm=x>h?(t3.val()
                        -t5.val()+t7.val()):t1.val();
                break;
                case 20:phi=-1;eta=-1;puterm=x>h?(t1.val()-t3.val()
                        +t5.val()):t5.val();
                break;
                case 21:eta=1;phi=1;puterm=x>h?(t2.val()-t6.val()):
                        (t4.val()-t8.val());
                break;
                case 22: eta=-1;phi=1;puterm=x<h?(t2.val()-t4.val()
                         +t6.val()-t8.val()):0.0;
                break;
                case 23:eta=1;phi=1;puterm=x<h?(t3.val()-t7.val()):
                        (t1.val()-t5.val());
                break;
                case 24:eta=-1;phi=1;puterm=x<h?(t1.val()-t3.val()
                        +t5.val()-t7.val()):0.0;
                break;
                case 25:eta=1;phi=-1;puterm=x>h?(t2.val()-t4.val()
                        +t6.val()-t8.val()):0.0;
                break;
                case 26:eta=-1;phi=-1;puterm=x>h?(t4.val()-t8.val()):
                        (t2.val()-t6.val());
                break;
                case 27:eta=1;phi=-1;puterm=x>h?(t1.val()-t3.val()
                        +t5.val()-t7.val()):0.0;
                break;
                case 28: eta=-1;phi=-1;puterm=x>h?(t3.val()-t7.val()):
                         (t1.val()-t5.val());
                break;
          }
          return puterm;
   }
},

t1{
  public double val() {
    return s*exp((b-r)*t)*N(phi*par.x1());
  }
},
t2{
  public double val() {
    return k*exp(-r*t)*N(phi*par.x1()-phi*sigma*sqrt(t));
  }
},
t3{
public double val() {
return s*exp((b-r)*t)*N(phi*par.x2());
}
},
t4{
  public double val(){
    return k*exp(-r*t)*N(phi*par.x2()-phi*sigma*sqrt(t));
  }
},
t5{
  public double val() {
    return s*exp((b-r)*t)*pow((h/s),(2.0*(par.mu()+1.0)))
            *N(eta*par.y1());
  }
},
t6{
  public double val(){
    return k*exp(-r*t)*pow((h/s),(2.0*par.mu()))*N(eta*par.y1()-eta
            *sigma*sqrt(t));
  }
},
t7{
  public double val() {
    return s*exp((b-r)*t)*pow((h/s),(2.0*(par.mu()+1.0)))
            *N(eta*par.y2());
  }
},
t8{
  public double val() {
    return k*exp(-r*t)*pow((h/s),(2.0*par.mu()))*N(eta*par.y2()
            -eta*sigma*sqrt(t));
  }
},
t9{
  public double val() {
    return k*(pow((h/s),(par.mu()+par.lambda()))*N(eta*par.zeta())
            +pow((h/s),(par.mu()-par.lambda()))*N(eta*par.zeta()
            -2.0*eta*par.lambda()*sigma*sqrt(t)));
  }
},
par{

    public double x1() {
      double m=mu();
      return (log(s/x)/(sigma*sqrt(t)))+(m+1.0)*sigma*sqrt(t);
  }
    public double x2() {
      double m=mu();
      return log(s/h)/(sigma*sqrt(t))+(m+1.0)*sigma*sqrt(t);
  }
    public double y1() {
      double m=mu();
      return log(h*h/(s*x))/(sigma*sqrt(t))+(m+1.0)*sigma*sqrt(t);
  }
   public double y2() {
    double m=mu();
    return (log(h/s)/(sigma*sqrt(t)))+(m+1.0)*sigma*sqrt(t);
  }
   public double zeta() {
    double m=mu();
    return (log(h/s)/(sigma*sqrt(t)))+par.lambda()*sigma*sqrt(t);
  }
  public double lambda() {
    double m=mu();
    return sqrt((m*m)+(2.0*r/(sigma*sigma)));
  }
  public double mu() {
    return (b-(sigma*sigma)*0.5)/(sigma*sigma);
  }
};

  barV() {
  }
  public double x1() {
     throw new UnsupportedOperationException("Not yet implemented");
  }
  public double x2() {
     throw new UnsupportedOperationException("Not yet implemented");
  }
  public double y1() {
     throw new UnsupportedOperationException("Not yet implemented");
  }
  public double y2() {
     throw new UnsupportedOperationException("Not yet implemented");
  }
  public double zeta() {
     throw new UnsupportedOperationException("Not yet implemented");
  }
  public double mu() {
     throw new UnsupportedOperationException("Not yet implemented");
  }
  public double lambda() {
     throw new UnsupportedOperationException("Not yet implemented");
  }
  public double val() {
     throw new UnsupportedOperationException("Not yet implemented");
  }
  public double Args( int tp) {
     throw new UnsupportedOperationException("Not yet implemented");
  }
}
