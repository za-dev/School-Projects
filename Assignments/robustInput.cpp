#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main ()
{
    
    string x;
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    
    
    cout << "Enter: ";
    cin >> x;
    
    for (int i = 0; i < x.length(); i++ ) {
        
        
        if ( x[i] == '-') {
            a = a +1; }
        
        if ( x[i] == '.') {
            b = b +1; }
        
        if ( (int(x[i]) < 47) or (int(x[i]) > 58) ) {
            c = c + 1; }
        
    }
    
    if ( (c > 0) && (a != 1) ) {
        cerr << "Error, enter number." << endl;
        
    }
    
    else {
        
        
        
        if (b > 1) {
            cerr << "Error enter number.";
            return 0;
        }
        
        if (b == 1) {
            cerr << "Error enter integer.";
            return 0;
        }
        
        if (x.length() > 11) {
            cerr << "Error out of range.";
            return 0;
        }
        
        
        
        if (a == 1 or a == 0) {
            cout << " The number you entered is: " << x << endl;
            return 0;
        }
    }
    
    
    return 0;
}
