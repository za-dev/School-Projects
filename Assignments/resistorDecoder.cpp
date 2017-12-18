#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main ()
{
    
    
    char c [4];
    int b1 = 77;
    int b2 = 77;
    int b3 = 77;
    double b4 = 77;
    
    
    
    cout << "Enter: ";
    cin >> c;
    
    
    if (c[0] == 'k') {
        b1 = 0;
    }
    if (c[0] == 'n') {
        b1 = 1;
    }
    if (c[0] == 'R') {
        b1 = 2;
    }
    if (c[0] == 'O') {
        b1 = 3;
    }
    if (c[0] == 'Y') {
        b1 = 4;
    }
    if (c[0] == 'G') {
        b1 = 5;
    }
    if (c[0] == 'B') {
        b1 = 6;
    }
    if (c[0] == 'V') {
        b1 = 7;
    }
    if (c[0] == 'y') {
        b1 = 8;
    }
    if (c[0] == 'W') {
        b1 = 9;
    }
    if (c[1] == 'k') {
        b2 = 0;
    }
    if (c[1] == 'n') {
        b2 = 1;
    }
    if (c[1] == 'R') {
        b2 = 2;
    }
    if (c[1] == 'O') {
        b2 = 3;
    }
    if (c[1] == 'Y') {
        b2 = 4;
    }
    if (c[1] == 'G') {
        b2 = 5;
    }
    if (c[1] == 'B') {
        b2 = 6;
    }
    if (c[1] == 'V') {
        b2 = 7;
    }
    if (c[1] == 'y') {
        b2 = 8;
    }
    if (c[1] == 'W') {
        b2 = 9;
    }
    
    if (c[2] == 'k') {
        b3 = 0;
    }
    if (c[2] == 'n') {
        b3 = 1;
    }
    if (c[2] == 'R') {
        b3 = 2;
    }
    if (c[2] == 'O') {
        b3 = 3;
    }
    if (c[2] == 'Y') {
        b3 = 4;
    }
    if (c[2] == 'G') {
        b3 = 5;
    }
    if (c[2] == 'B') {
        b3 = 6;
    }
    if (c[2] == 'V') {
        b3 = 7;
    }
    if (c[2] == 'y') {
        b3 = 8;
    }
    if (c[2] == 'W') {
        b3 = 9;
    }
    if (c[2] == 'd') {
        b3 = -1;
    }
    if (c[2] == 'S') {
        b3 = -2;
    }
    
    if (c[3] == 'k') {
        b4 = 0;
    }
    if (c[3] == 'n') {
        b4 = 1;
    }
    if (c[3] == 'R') {
        b4 = 2;
    }
    if (c[3] == 'O') {
        b4 = 0;
    }
    if (c[3] == 'Y') {
        b4 = 0;
    }
    if (c[3] == 'G') {
        b4 = 0.5;
    }
    if (c[3] == 'B') {
        b4 = 0.25;
    }
    if (c[3] == 'V') {
        b4 = 0.1;
    }
    if (c[3] == 'y') {
        b4 = 0.05;
    }
    if (c[3] == 'W') {
        b4 = 0;
    }
    if (c[3] == 'd') {
        b4 = 5;
    }
    if (c[3] == 'S') {
        b4 = 10;
    }
    if (c[3] == 'N') {
        b4 = 20;
    }
    
    if (    ((b1 == 77) or (b2 == 77)) or ((b3 == 77) or (b4 ==77) )      ) {
        cerr << "Error: Invalid color code entered! ";
        return 0;
    }
    
    
    b1 = pow(10.0,1) * b1;
    
    float r = (b1 + b2)*(pow(10,b3));
    cout << r << endl;
    float t = (b4/100.0)* r;
    cout << "Resistance is " << r << " +/-" << t << " ohms tolerance";
    
    return 0;
}
