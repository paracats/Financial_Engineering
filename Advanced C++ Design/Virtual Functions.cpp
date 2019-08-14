/* Advanced C++ Design                                          */
/* Polymorphism with Virtual Functions                          */
/* Author: David Li                                             */

 #include <iostream>
 #include <string>
 using namespace std;


 class Base
 {
 protected:
 int A;
 int baseSqr();

 public:
 Base(int a){A = a;}
 ~Base(){}
 int X;
 void baseIn(int x);
 void baseOut();
 virtual void compute(int p, int q);
 };


 class Drvd: public Base
 {
 private:
 int C;
 int drvdCube();

 public:
 Drvd(int c, int a): Base(a)
 {C = c;}
 ~Drvd(){}
 int Y;
 void drvdIn(int y);
 void drvdOut();
 virtual void compute(int p, int q);
 };


 int Base::baseSqr()
 {
 return (A * A);
 }


 void Base::baseIn(int x)
 {
 X = x;
 }


 void Base::baseOut()
 {
 cout << "Base private variable A: " << A << endl;
 cout << "Base public variable X: " << X << endl;
 cout << "Base private function result: " << baseSqr() << endl;
 }


 void Base::compute(int p, int q)
 {
 cout << "The sum of the two values is: ";
 cout << p + q << endl;
 }



 void Drvd::drvdIn(int y)
 {
 Y = y;
 }


 int Drvd::drvdCube()
 {
 return (C * C * C);
 }

 void Drvd::drvdOut()
 {
 cout << "Derived private variable C: " << C << endl;
 cout << "Derived public variable Y: " << Y << endl;
 cout << "Derived private function result: " << drvdCube() << endl;
 cout << A;
 }

 void Drvd::compute(int p, int q)
 {
 cout << "The result of multiplying the two values is: ";
 cout << p * q << endl;
 }


 int main()
 {
 Base b(2);
 Base *pb = &b;
 pb->baseIn(5);

 pb->compute(10, 20);

 cout << "\n";
 Drvd d(2, 3);
 pb = &d;
 Drvd *pd = &d;
 pb->baseIn(10);
 pd->drvdIn(5);

 pb->compute(10,20);

 cout << endl;
 return 0;
 }










