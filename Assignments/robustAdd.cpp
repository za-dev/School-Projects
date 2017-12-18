#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main ()
{
    
    int x;
    double y;
    
    cout << "Enter: " ;
    cin >> x;
    cin >> y;
    int sum = x+y;
    
    
    
    if (y - floor(y) != 0 ) {
        cerr << "Error";
        return 0;
    }
    if ( cin.get() == -1){
        cerr << "Error";
        return 0;
    }
    
    
    if (log(x) <= 0) {
        cerr << "Error";
        return 0;
    }
    
    
    if ( x >= 2147483647 or y >=2147483647) {
        cerr << "Error. Out of range";
        return 0;
    }
    
    if ( (fabs(sum)) >= 2147483647) {
        cerr << "Error. Sum out of range";
        return 0;
    }
    
    else {
        cout << sum ;
    }
    
    
    
    return 0;
}
