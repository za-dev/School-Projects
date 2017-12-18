#include <iostream>


using namespace std;

int main() {
    
    
    char s[10] = "String";
    char t[10] = "notString";
    
    
    for (int i = 0; i<6; i++) {
        
        
        t[i] = s[(i+2)%6];
        
        cout << t[i] << i << endl;
    }
    

    
    
    
    
    return 0;
}
