// Java For Quantitative Finance
// Put Call Parity
// Author: David Li

package FinApps;
import static java.lang.Math.*;
import static FinApps.PresentValue.*;

public class PutCallpar {
  public PutCallpar() {
  }
  String typeoption= "call";
  double[] Amerput=new double[2];
  double Amercall;
      public PutCallpar(String type)
  {
    this.typeoption=type;
  }
      public double[] getAmerput()
      {
        return Amerput;
      }
      private void setAmerput(double limitlower,
                              double limithigher)
      {
        Amerput[0]=limitlower;
        Amerput[1]=limithigher;
      }
      private void setAmercall(double call)
      {
        Amercall=call;
      }
  public double europarity (double optionprice,
                            double strike, double stcprice,
                            double rate,double time)
  {
    double putfrmcall= (optionprice+(pVcont
                       (rate,time,strike))-stcprice);
    double callfrmput=((optionprice+stcprice)-pVcont
                       (rate,time,strike));
    return (typeoption=="put") ? putfrmcall:callfrmput;
  }

public void amerparity (double optionprice,double strike,
                        double stcprice,double rate,double time)
{
  if(typeoption=="put")
  {
  double limit1=abs((stcprice-strike))+optionprice;
  double limit2=abs((stcprice-pVcont(rate,time,
                     strike)))+optionprice;
  setAmerput(limit1,limit2);
  }else
  {
    double callvalue=(optionprice+stcprice)-strike;
    setAmercall(callvalue);
  }
}
}

