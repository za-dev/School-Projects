#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main ()
{
    int passboth = 0;
    int p10 = 0;
    int x1  =0;
    int y1 = 0;
    int passy = 0;
    int passx = 0;
    int p = 0;
    int q = 0;
    int r = 0;
    string x;
    string y;
    int a = 0;
    int b = 0;
    int c = 0;
    
    
    
    cout << "Enter: ";
    cin >> y;
    cin >> x;
    
    for (int i = 0; i < x.length(); i++ ) {
        
        
        if ( x[i] == '-') {
            a = a +1; }
        
        if ( x[i] == '.') {
            b = b +1; }
        
        if ( (int(x[i]) < 47) or (int(x[i]) > 58) ) {
            c++; }
        
    }
    
    for (int j = 0; j < y.length(); j++ ) {
        
        
        if ( y[j] == '-') {
            p = p +1; }
        
        if ( y[j] == '.') {
            q = q+1; }
        
        if ( (int(y[j]) < 47) or (int(y[j]) > 58) ) {
            r =  r+ 1; }
        
    }
    
    if (  (c ==0)  && (b ==0) && ( a <=2 )) {
        passx = 1;
    }
    
    if ( (r ==0)  && (q==0)  && ( (p==0) or (p ==1) )  ){
        passy = 1;
    }
    
    for (int i = 0; i < x.length(); i++) {
        p10 = pow(10, x.length()-i-1);
        x1 = x1 + (int(x[i])-48)*(p10);
    }
    
    for (int i = 0; i < y.length(); i++) {
        p10 = pow(10, y.length()-i-1);
        y1 = y1 + (int(y[i])-48)*(p10);
    }
    
    passboth = passx + passy;
    
    if ( (passboth == 2) && ( (x1+y1) < 2147483647  )  ) {
        cout << "Sum: " << x1+y1 << endl;
        
    }
    
    if ( (x1+y1) > 2147483647) {
        cerr << " Too large" ;
        
        
    }
    
    if (passboth == 0) {
        cerr << "Error. Non-integer detected";
    }
    
    
    
    
    cout << passboth;
    return 0;
}
