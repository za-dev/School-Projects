#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main ()
{
    
    unsigned int pos = 0;
    unsigned int count = 0;
    unsigned int id [6];
    cout << "Enter 5 ID: ";
    
    
    /////////// check for errors and get inputs
    
    for (int i = 0; i < 5; i++) {
        cin >> id[i];
        
        
        if ( !cin.good() ) {
            cerr <<  "Error: Invalid input.";
            return 0;
            
        }
        
        
        if ( id[i] > 1000000 && id[i] < 9999999) {
             cerr <<  "Error: Invalid input.";
            return 0;
        }
        
        
        id[5] = id[0];
        
    }
    
    
    ////////Done
    
    
    
    ///// swap
    
    for (int j= 0; j < 5; j++) {
        
        
        
        for (int i= 0; i < 4; i++) {
            
            cout << "Sorted ID:" << id[0] << " " << id[1] << " " << id[2] << " " << id[3] << " " << id [4] << " " << endl;
            
            if (id[i] < id[i+1]) {
                swap(id[i],id[i+1]);
                count++;
                
                
                
            }
            
        }
        
    }
    
    
    ///Done
    
    
    unsigned int a;
    
    cout << "Sorted ID:" << id[0] << " " << id[1] << " " << id[2] << " " << id[3] << " " << id [4] << " " << endl;
    cout << "Swap count:" << count <<endl;
    cout << "Enter another input: ";
    cin >> a;
    
    
    int dup = 0;
    
    for (int i = 0; i < 5; i++) {
        
        if (id[i] > a) {
            pos++;
        }
        
        
        
        
        
        if (id[i] == a ) {
            dup = 1;
        }
        
        
        
    }
    
    
    
    
    
    if (dup == 1) {
        cerr << "Error: This ID exists.";
        return 0;
    }
    
    
    
    ///////
    
    
    cout << "The value " << a << " is in " << "position " << pos << endl;
    
    
    
    return 0;
    
}







