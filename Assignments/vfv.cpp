#include <iostream>

using namespace std;

void whiteSpace(int amount){
    for(int i=0;i<amount;i++)
        cout<<" ";
}
int main() {
    
    
    int cycles;
    cout << "Enter number of cycles: ";
    cin >> cycles;
    
    for(int j=0;j<60*cycles;j++){
        whiteSpace(j);
        cout<<"!ECE150!";
        for (int i = 0; i< 10000000; i++)
            i = i+2;
        
        
    
        
    }
    
}
