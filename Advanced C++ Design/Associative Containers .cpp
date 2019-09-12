/* Advanced C++ Design                                          */
/* C++ Associative Containers                                   */
/* Author: David Li                                             */

#include <iostream> 
#include <set> 
#include <string> 
#include <functional> 
#include <iterator> 
#include <algorithm> 

using namespace std;

int main() 
{ 
    set<int> intSet; 
    set<int, greater<int> > intSetA; 

    set<int, greater<int> >::iterator intGtIt; 

    ostream_iterator<int> screen(cout, " "); 

    intSet.insert(16); 
    intSet.insert(8); 
    intSet.insert(20); 
    intSet.insert(3); 

    cout << "Line 18: intSet: "; 
    copy(intSet.begin(), intSet.end(), screen); 
    cout << endl; 

    intSetA.insert(36); 
    intSetA.insert(84); 
    intSetA.insert(30); 
    intSetA.insert(39); 
    intSetA.insert(59); 
    intSetA.insert(238); 
    intSetA.insert(156);

    cout << "Line 28: intSetA: "; 
    copy(intSetA.begin(), intSetA.end(), screen); 
    cout << endl; 

    intSetA.erase(59); 

    cout << "Line 32: After removing 59, intSetA: "; 
    copy(intSetA.begin(), intSetA.end(), screen); 
    cout << endl; 

    intGtIt = intSetA.begin(); 
    ++intGtIt; 
    ++intGtIt; 
    ++intGtIt; 

    intSetA.erase(intGtIt); 

    cout << "Line 40: After removing the fourth "
         << "element, " << endl
         << " intSetA: "; 
    copy(intSetA.begin(), intSetA.end(), screen); 
    cout << endl; 

    set<int, greater<int> > intSetB(intSetA); 

    cout << "Line 44: intSetB: "; 
    copy(intSetB.begin(), intSetB.end(), screen); 
    cout << endl; 

    intSetB.clear(); 

    cout << "Line 48: After removing all elements, "
         << endl << " intSetB: "; 
    copy(intSetB.begin(), intSetB.end(), screen); 
    cout << endl; 

    multiset<string, greater<string> > namesMultiSet; 
    multiset<string, greater<string> >::iterator iter; 

    ostream_iterator<string> pScreen(cout, " "); 

    namesMultiSet.insert("Donny"); 
    namesMultiSet.insert("Zippy"); 
    namesMultiSet.insert("Goofy"); 
    namesMultiSet.insert("Hungry"); 

    namesMultiSet.insert("Goofy"); 
    namesMultiSet.insert("Donny"); 

    cout << "Line 60: namesMultiSet: "; 
    copy(namesMultiSet.begin(), namesMultiSet.end(),
         pScreen); 
    cout << endl; 

    return 0; 
} 
