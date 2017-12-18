#include <iostream>
#include <fstream>
using namespace std;


//// Main Function

int main(int argc, char** argv) {
    
    char data[1000];
    char* name;// the main function should take in the name argument

    int loadsAndSave = 0;
    int compareAndJump = 0;
    int numberOfALU = 0;
    int instructionLine1 = 0;
    int instructionLine2 = 0;
    int instructionLine3 = 0; /// comments on all variables plz
    int line = 0;
    int space =0;
    int commentPosition;
    int numberOfCodeLines = 0;
    int pointer = 0;
    
    name = argv[1];
    
    
    /// Reading contents of line and storing it in data
    ifstream infile;
    infile.open(name);
    
    while(getline(infile,data)) {
        pointer = 0;
        line++;
        instructionLine1 = 0; //// Variable to notify if the line is a instruction line or not
        instructionLine2 = 0;
        instructionLine3 = 0;
        commentPosition = 0;
        
        ///parsing for loop
        
        for (int i = 0; i < 100; i++) {
            //// count saves
            if ( (data[i] == 'S') && (data[i+1] == 'D') ) {
                loadsAndSave++;
                instructionLine1++;
                pointer = i;
            }
            
            /// count loads
            
            if ( (data[i] == 'L') && (data[i+1] == 'D') ) {
                loadsAndSave++;
                instructionLine1++;
                pointer = i;
            }
            
            
            // count jumps/compares
            
            if (data[i] == 'J') {
                
                if (  (data[i+1] == 'M') && (data[i+2] == 'P') ) {
                    compareAndJump++;
                    instructionLine2++;
                    pointer = i;
                }
                
                
                if (data[i+1] == 'Z') {
                    compareAndJump++;
                    instructionLine2++;
                    pointer = i;
                }
                
                if (  (data[i+1] == 'N') && (data[i+2] == 'Z') ) {
                    compareAndJump++;
                    instructionLine2++;
                    pointer = i;
                }
                
                if (data[i+1] == 'G') {
                    
                    if (data[i+2] == 'Z' or data [i+2] == 'E') {
                        compareAndJump++;
                        instructionLine2++;
                        pointer = i;
                    }
                }
                
                if (data[i+1] == 'L') {
                    
                    if (data[i+2] == 'Z' or data [i+2] == 'E') {
                        compareAndJump++;
                        instructionLine2++;
                        pointer = i;
                    }
                }
            }
            ////
            /// count number of ALU operations
            
            if ( (data [i] == 'A') && (data [i+1] == 'D') && (data [i+2] == 'D') ){
                numberOfALU++;
                instructionLine3++;
                pointer = i;
            }
            
            if (  (data [i] == 'S') && (data [i+1] == 'U') && (data [i+2] == 'B') ) {
                numberOfALU++;
                instructionLine3++;
                pointer = i;
            }
            
            if ( (data [i] == 'M') && (data [i+1] == 'U') && (data [i+2] == 'L') ){
                numberOfALU++;
                instructionLine3++;
                pointer = i;
            }
            
            if ( (data [i] == 'D') && (data [i+1] == 'I') && (data [i+2] == 'V') ){
                numberOfALU++;
                instructionLine3++;
                pointer = i;
            }
            //// builing opcode and operands
            
            
            
            
        } /// for loop end
        
        //// position of comment
        
        for (int i =0; i < 100;i++){
            if (data[i] == '#') {
                commentPosition = i;
            }
            
        }
        //////////////////
          //// Load/save errors
        
        int numberOfCommas = 0;
        
        if (instructionLine1 == 1) {
            
            numberOfCommas = 0;
            
            for (int i = 0; i < commentPosition ; i++){
                if (data[i] == ',') {
                    numberOfCommas++;
                }
            }
            
            if (numberOfCommas < 1) {
                cerr << "Missing second OPERAND "<< line;;
                return 0;
            }
            
            if (numberOfCommas > 1) {
                cerr << "Extra data After Instruction"<< line;
                return 0;
            }
            
            
            
        }
        
        //// Load/save errors end
        
        
        /// Jump/compare errors checking
        if (instructionLine2 == 1) {
            
            numberOfCommas = 0;
            
            for (int i = 0; i< commentPosition ; i++){
                if (data[i] == ',') {
                    numberOfCommas++;
                }
            }
            
            
            if (numberOfCommas > 1) {
                cerr << "Extra data After Instruction"<<line<<"jump";
                return 0;
            }
            
            
            
        }
        
        ////// ALU instruction errors checking
        
        if (instructionLine3 == 1) {
            
            numberOfCommas = 0;
            
            for (int i = 0; i < commentPosition ; i++){
                if (data[i] == ',') {
                    numberOfCommas++;
                }
            }
            
            
            if (numberOfCommas > 2) {
                cerr << "Extra data After Instruction"<<line;
                return 0;
            }
            
            if (numberOfCommas < 2) {
                cerr << "Missing third OPERAND"<<line;
                return 0;
            }
            
        }
        
        /////////////////// end of error checking @@@@@@@ Add which line the error is on.
        
        
    }
    
    infile.close();
    /// assigning values
    int nInstructions = loadsAndSave + numberOfALU + compareAndJump;
    
    cout << "Total number of Assembly instructions: " << nInstructions << endl;
    cout << "Number of Load/Store: " << loadsAndSave << endl;
    cout << "Number of ALU: " << numberOfALU << endl;
    cout << "Number of Compare/Jump: " << compareAndJump << endl;
    cout << opcode[0] <<endl <<opcode[1] <<endl <<opcode[2] <<endl;
    
    
    return 0;
}

