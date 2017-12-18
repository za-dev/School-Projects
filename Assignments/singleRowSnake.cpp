
#include <iostream>
#include <cmath>

using namespace std;

int main ()
{
    
    int wtw;
    int snakelength;
    int wtst;
    
    cout << "Enter wall to wall dimension: " ;
    cin >> wtw;
    cout << "Enter snake length: " ;
    cin >> snakelength;
    cout << "Enter wall to snake length: " ;
    cin >> wtst;
    
    
    
    
    
    if (wtw <= 0) {
        cerr << "Error";
        return 0;
    }
    
    if (wtw <=0 && snakelength <= 0 && wtst <=0) {
        cerr << "Error";
        return 0;
    }
    
    if (snakelength > wtw or wtst > wtw) {
        cerr << "error";
        return 0;
    }
    
    
    cout << "|";
    
    for (int i = 0; i < wtst; i++){
        cout << " ";
    }
    
    for (int i = 0; i < snakelength - 1; i++){
        cout << "*";
    }
    
    if (snakelength > 0) {
        cout << "O";
    }
    
    
    for (int i = 0; i < (wtw-2-snakelength-wtst); i++){
        cout <<" ";
    }
    
    
    cout << "|";
    
    
    return 0;
}
