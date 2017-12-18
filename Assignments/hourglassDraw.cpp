

#include <iostream>
#include <cmath>

using namespace std;

int main ()
{
    double base1;
    int base;
    int height;
    int d= 0;
    
    cout << "Enter base";
    cin >> base1;
    base = base1;
    height = base/2 + 1;
    
    
    if (base%2 != 1) {
        cerr << "Error";
        return 0;
    }
    
    if (cin.get() == -1) {
        cerr << "Error";
        return 0;
    }
    
    if (base1 - base != 0) {
        cerr << "Error";
        return 0;
    }
    
    
    for (int p = 0; p < height; p++) {
        
        
        
        for (int j = 0; j < d; j++) {
            cout << " ";
        }
        
        for (int u = 0; u < base-2*p; u++) {
            cout << "*";
        }
        
        d++;
        
        cout << endl;
        
        
    }
    
    
    for (int i = 0; i < height-1; i++) {
        
        for (int u = 0; u < height - 2 - i ; u ++) {
            cout << " ";
        }
        
        
        for ( int j = 0; j < i+3 +i; j++) {
            cout << "*";
        }
        
        
        cout << endl;
        
        
        
        
        
        
        
    }
    return 0;
}
