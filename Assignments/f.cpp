#include <iostream>
#include <fstream>
using namespace std;

int checker2 (char a,char b, char data[50]) {
    
    int numberOfTimesSeen = 0;
    for (int i =0; i <50; i++){
        if ( (data[i] == a) && (data[i+1] == b ) ) {
            numberOfTimesSeen++;
            cout << numberOfTimesSeen;
        }
    }
    
    return numberOfTimesSeen;
    
}




//// Main Function

int main(int argc, char** argv) {
    
    ///file name created
    char* name;
    name = argv[1];
    
    char data[50];
    char data1[50];
    
    /// can adjust data to be upto # only by creating data1...
    int nsaves = 0;
    int nloads = 0;
    int nALU = 0;
    int njmp = 0;
    int commentPos = 0;
    
    ifstream infile(name);
    
    ////// data contains the line most recently read
    while(infile.getline(data1,50)) {
        commentPos = 50;
        ///// finding comment position
        for (int i = 0; i < 50; i++) {
            if (data1[i] == '#') {
                commentPos = i;
            }
        }
        //// assigning non-comment code to data
        for (int i = 0; i < 10; i++) {
            data[i] = data1[i];
            
        }
    
        cout << data <<endl;
        
        nsaves = checker2('S','D',data) + nsaves;
        nloads = checker2('L','D',data) + nloads;
    }
    
    infile.close();
    
    cout << "Number of Load/Store: " << nloads + nsaves << endl;
    cout << "Number of ALU: " << nALU << endl;
    cout << "Number of Compare/Jump: " << njmp << endl;
    
    
    
    
    return 0;
}


