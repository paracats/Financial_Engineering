/* Advanced C++ Design                                          */
/* Using pointers with base & derived classes                   */
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
 Base(int a){cout << "Base class constructor\n"; A = a;}
 ~Base(){}
 int X;
 void baseIn(int x);
 void baseOut();
 };


 class Drvd: public Base
 {
 private:
 int C;
 int drvdCube();

 public:
 Drvd(int c, int a): Base(a)
 {cout << "Derived class constructor\n"; C = c;}
 ~Drvd(){}
 int Y;
 void drvdIn(int y);
 void drvdOut();
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

 int main()
 {
 Base b(2);
 Base *pb = &b;
 pb->baseIn(5);

 cout << "\nFOR Base TYPE OBJECT: " << endl;
 pb->baseOut();

 cout << "\n\n";
 Drvd d(2, 3);
 pb = &d;

 Drvd *pd = &d;
 pb->baseIn(10);
 pd->drvdIn(5);

 cout << "\nFOR Drvd TYPE OBJECT: " << endl;
 pb->baseOut();
 pd->drvdOut();

 cout << endl;
 //Wait for the user to read the output on the console
 system("PAUSE");
 return 0;
}
