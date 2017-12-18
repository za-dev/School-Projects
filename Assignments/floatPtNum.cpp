#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main ()
{
    
    double A;
    double B;
    
    
    cout << "Enter three numbers (each separated by a space): ";
    cin >> A;
    cin >> B;
    
    double out = A/B;
    
    cout << "A/B = " << setprecision(20) << fixed << out << endl;
    
    
}
