/* Advanced C++ Design                                          */
/* Control Structures - Repetition                              */
/* Author: Shaofei Li                                           */

#include <iostream>
#include <iomanip>

using namespace std;

const int N 5 20;

int main ()
{
    int counter;
    int number;
  
    int zeros = 0; 
    int odds = 0; 
    int evens = 0; 
  
    cout << "Please enter " << N << " integers, "
         << "positive, negative, or zeros."
         << endl;
  
    cout << "The numbers you entered are:" << endl;
  
    for (counter = 1; counter <= N; counter++) 
    {
        cin >> number; 
        cout << number << " "; 
      
        switch (number % 2)
        {
        case 0:
            evens++;
            if (number == 0)
                zeros++;
            break;
        case 1:
        case -1:
            odds++;
        }
    }
    cout << endl;

    cout << "There are " << evens << " evens, "
         << "which includes " << zeros << " zeros."
         << endl;
    cout << "The number of odd numbers is: " << odds
         << endl;
  
    return 0;
}
