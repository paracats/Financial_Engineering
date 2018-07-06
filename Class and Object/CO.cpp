/* C++ For Quantitative Finance                                 */
/* Creating Class and Objects                                   */
/* Author: David Li                                             */

 #include <iostream>
 #include <string>
 using namespace std;


 class MyClass
 {
 private:
 int pvtSale1, pvtSale2;
 int pvtTotSale();

 public:
 int pubPrc;
 void pubGetInputs();
 int pubRev();
 };

 int MyClass::pvtTotSale()
 {
 return pvtSale1 + pvtSale2;
 }

 void MyClass::pubGetInputs()
 {
 cout << "Enter books sold by store 1: ";
 cin >> pvtSale1;

 cout << "Enter books sold by store 2: ";
 cin >> pvtSale2;

 return;
 }

 int MyClass::pubRev()
 {
 return pvtTotSale() * pubPrc;
 }

 int main()
 {
 MyClass morris;

 morris.pubGetInputs();
 morris.pubPrc = 10;

 cout << "\nTotal revenue of publisher Morris is : " ;
 cout << morris.pubRev() << endl << endl;

 MyClass jessop;

 jessop.pubGetInputs();
 jessop.pubPrc = 15;

 cout << "\nTotal revenue of publisher Jessop is : ";
 cout << jessop.pubRev() << endl;

 cout << "\nTotal revenue of both publishers is : ";
 cout << morris.pubRev() + jessop.pubRev() << endl;

 system("PAUSE");
 return 0;
 }
