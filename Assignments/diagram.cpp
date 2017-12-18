#include <iostream>
#include <stdlib.h>


using namespace std;

int main ()
{
    for (int j=0;j<60;j++) {
        
        
        for (int i = 0; i<60 ; i++) {
            cout << "=";
        }
        
        cout << endl;
        
        
        int n =j;
        while (n > 0) {
            cout << " ";
            n = n-1;
        }
        
        cout << "O";
        
        
        cout << endl;
        for (int i = 0; i<60 ; i++) {
            cout << "=";
        }
        cout << endl;
       
        system("cls");
        
    }
    
    
    
    for(int i = 0; i < 1000000; i++)
        i = (i + i) / 2;
    return 0;
    
    
    
}

