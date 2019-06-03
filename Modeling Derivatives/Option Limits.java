// Java For Quantitative Finance
// Option Limits
// Author: David Li 

package FinApps;
import static FinApps.PresentValue.*;
import static java.lang.Math.*;
public class Optionlimits {

public Optionlimits() {
}
public double lowerlimitCall(double stockprice,double rate,
                             double time,double strikeprice)
{
  return max( (stockprice-pVcont(rate,time,strikeprice)),0);
}
public double[] lowerlimitCall(double[]stockprice,double rate,
                               double time, double[] strikeprice)
{
   int indx=0;
   double[] lowervalues = new double[stockprice.length];
   for(double s:stockprice)
   {
     lowervalues[indx]=max((s-pVcont(rate,time,
     strikeprice[indx])),0);
     indx++;
   }
   return lowervalues;
}
   public double lowerlimitPut(double stockprice,double
                               rate,double time,double strikeprice)
{
   return max( (pVcont(rate,time,strikeprice)-stockprice),0);
}
public double[] lowerlimitPut(double[]stockprice,double rate,double
                              time, double[] strikeprice)
{
   int indx=0;
   double[] lowervalues = new double[stockprice.length];
   for(double s:stockprice)
   {
    lowervalues[indx]=max((pVcont(rate,time,
                           strikeprice[indx])-s),0);
    indx++;
   }
   return lowervalues;
 }
}
