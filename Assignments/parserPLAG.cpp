#include <iostream>
#include <fstream>
using namespace std;

//FUNCTIONS
bool IsWhiteSpace(char);
bool ArrayCmp(char*, char*);
bool IsOpcode(char*);
bool IsOperand(char*);
int ArrayToInt(char*, int);
void errorOutput();

//TEXTFILE//
char holderChar;
char* fileWord = new char[20];
bool isNewLine = true;
bool isFirstWord = true;
bool continueLine = true;
int lineNum = 0;

//LABEL//
char* lineBuffer = new char[100];
char* labels[20];
char* tempLabel;
int labelNum = 0;
int charNum = 0;
char* labelNameStorage[20];
int labelMemStorage[20];

//OPCODE//
int instrucs = 0;
int ldsd = 0;
int alu = 0;
int cmpjmp = 0;
bool isReg = false;
bool opcodeFound = false;

int codeVal = -1;
int dataVal = -1;



bool isFirstOperand = true;
enum OperandType {xr = -6, rr = 9, xx = -4, rx = 6, rrr = 27, rxr = 18, x = -2, na = 0};
int operandCalc = 1;
OperandType operandCheck[2] = {na, na};

// enum OperandType {mr = -9, rr = 0, im = 99, ir = 90, rm = 9, rrr = -10, rir = -100, m = 1, na = 2}; //TRASH FOR NOW
// 1   = m = memory loc
// 10  = r = register
// 100 = i = int
// mr  = 1 - 10        = -9
// rr  = 10 - 10       = 0
// ir  = 100 - 10      = 90
// rm  = 10 - 1        = 9
// rrr = 10 - 10 - 10  = -10
// rir = 10 - 100 - 10 = -100
// m   = 1             = 1

int main(int argc, char *argv[]) {
    if(argc < 2){
        cerr << "Error: not enough arguments." << endl;
        return -1;
    }
    else if(argc > 2){
        cerr << "Error: not enough arguments." << endl;
        return -1;
    }
    
    char* fileName;
    fileName = argv[1];
    ifstream MyFile;
    
    MyFile.open(fileName);
    
    if(!MyFile.is_open()){
        cerr << "Error: File " << fileName << "could not be found" << endl;
        return -1;
    }
    
    charNum = 1;
    lineNum = 0;
    while(MyFile.get(holderChar)){
        // cout << '.';                                                                //DEBUG
        if(holderChar == '\n'){                                                     //CHECK NEWLINE
            continueLine = true;
            operandCalc = 1;
            operandCheck[0] = na;
            isFirstOperand = true;
            isFirstWord = true;
            isReg = false;
            opcodeFound = false;
            lineNum++;
            // cout << endl;                                                             //DEBUG
            
            if(operandCheck[0] != operandCalc && operandCheck[1] != operandCalc && operandCheck[0] != na ){
                // cerr << "wrong operands" << endl;
                errorOutput();
                return -1;
            }
        }
        
        fileWord = new char[20];                                                    //RESETTING fileWord
        
        if(continueLine && IsWhiteSpace(holderChar)){                               //PUT INTO fileWord
            MyFile >> fileWord;
        }
        else if(continueLine){
            fileWord[0] = holderChar;
            MyFile >> fileWord + 1;
        }
        
        if(continueLine && fileWord[0] == '#'){                                     //CHECK FOR COMMENTS
            continueLine = false;
        }
        
        else if(continueLine){
            for(int i = 0; i < 20; i++){
                if(fileWord[i] == ':'){                                                 //FIND LABEL MARKER ':'
                    if(fileWord[0] >= '0' && fileWord[0] <= '9'){                     //CHECK LABEL BEGINS WITH LETTER
                        // cerr << "first character of label is a number not a letter";
                        errorOutput();
                        return -1;
                    }
                    tempLabel = new char[i];
                    for(int j = 0; j < i; j++){
                        if((fileWord[j] >= 'A' && fileWord[j] <= 'Z')
                           || (fileWord[j] >= 'a' && fileWord[j] <= 'z')
                           || (fileWord[j] >= '0' && fileWord[j] <= '9')){
                            tempLabel[j] = fileWord[j];
                        }
                        else{
                            // cerr << "unpermitted character in label. char : " << tempLabel[i] << endl;
                            errorOutput();
                            return -1;
                        }
                        
                        tempLabel[i] = '\0';
                    }
                    labelNameStorage[labelNum] = tempLabel;
                    
                    if(ArrayCmp(tempLabel, "Data")){                                      //FINDING DIRECTIVE
                        char* memInt = new char[10];
                        MyFile >> memInt;
                        labelMemStorage[labelNum] = ArrayToInt(memInt, 10);
                        if(dataVal != -1){
                            // cerr << "error: duplicate directive Data:";
                            errorOutput();
                            return -1;
                        }
                        else{
                            dataVal = ArrayToInt(memInt, 10);
                        }
                        delete[] memInt;
                    }
                    else if(ArrayCmp(tempLabel, "Code")){
                        char* memInt = new char[10];
                        MyFile >> memInt;
                        labelMemStorage[labelNum] = ArrayToInt(memInt, 10);
                        if(codeVal != -1){
                            // cerr << "error: duplicate directive Code:";
                            errorOutput();
                            return -1;
                        }
                        else if(instrucs > 0){
                            // cerr << "error: misplaced directive Code:";
                            errorOutput();
                            return -1;
                        }
                        else{
                            codeVal = ArrayToInt(memInt, 10);
                        }
                        delete[] memInt;
                    }
                    else{                                                                 //FINDING LABEL
                        labelMemStorage[labelNum] = instrucs + codeVal;
                    }
                    continueLine = false;
                    
                    labelNum++;
                    
                }
                // break;
            }
        }
        
        if(continueLine){
            // cout << "test" << endl;                                                   //DEBUG
            
            if(IsOpcode(fileWord)){
                opcodeFound = true;
                // cout << '~';                                                            //DEBUG
            }
            else if(opcodeFound && operandCheck[0] != na){
                if(IsOperand(fileWord)){
                    if(isFirstOperand){
                        if(isReg){
                            operandCalc *= 3;
                        }
                        else{
                            operandCalc *= -2;
                        }
                        isFirstOperand = false;
                    }
                    else{
                        if(isReg){
                            operandCalc *= 3;
                        }
                        else{
                            operandCalc *= 2;
                        }
                    }
                }
                else{
                    // cerr << "where the fuck is the operand??" << endl;
                    errorOutput();
                    return -1;
                }
            }
            
            else if(!opcodeFound && IsOperand(fileWord)){
                // cerr << "operand without opcode";
                // return -1;
            }
            
            // cout << fileWord << ' ';                                                  //DEBUG
            delete[] fileWord;
        }
        isFirstWord = false;
    }
    if(codeVal == -1){
        // cerr << "missing directive Code:";
        errorOutput();
        return -1;
    }
    errorOutput();
    cout << "Total number of assembly instructions: " << instrucs << endl;
    cout << "Number of Load/Store: " << ldsd << endl;
    cout << "Number of ALU: " << alu << endl;
    cout << "Number of Compare/Jump: " << cmpjmp << endl;
    for(int i = 0; i < 20; i++){
        cout << labelNameStorage[i] << ": " << labelMemStorage[i] << endl;
    }
    
    MyFile.close();
    return 0;
}

bool ArrayCmp(char* arrIn, char* arrCmp){
    int i = 0;
    while(arrIn[i] == arrCmp[i]){
        if(arrIn[i] == '\0'){
            return true;
        }
        i++;
    }
    return false;
}

bool IsOpcode(char* arr){
    if(ArrayCmp(arr, "LD")){
        operandCheck[0] = xr;
        operandCheck[1] = rr;
        instrucs++;
        ldsd++;
    }
    else if(ArrayCmp(arr, "LDi")){
        operandCheck[0] = xr;
        instrucs++;
        ldsd++;
    }
    else if(ArrayCmp(arr, "SD")){
        operandCheck[0] = rx;
        operandCheck[1] = rr;
        instrucs++;
        ldsd++;
    }
    else if(ArrayCmp(arr, "SDi")){
        operandCheck[0] = xx;
        operandCheck[1] = xr;
        instrucs++;
        ldsd++;
    }
    
    else if(ArrayCmp(arr, "ADD")){
        operandCheck[0] = rrr;
        instrucs++;
        alu++;
    }
    else if(ArrayCmp(arr, "ADDi")){
        operandCheck[0] = rxr;
        instrucs++;
        alu++;
    }
    else if(ArrayCmp(arr, "SUB")){
        operandCheck[0] = rrr;
        instrucs++;
        alu++;
    }
    else if(ArrayCmp(arr, "SUBi")){
        operandCheck[0] = rxr;
        instrucs++;
        alu++;
    }
    else if(ArrayCmp(arr, "MUL")){
        operandCheck[0] = rrr;
        instrucs++;
        alu++;
    }
    else if(ArrayCmp(arr, "MULi")){
        operandCheck[0] = rxr;
        instrucs++;
        alu++;
    }
    else if(ArrayCmp(arr, "DIV")){
        operandCheck[0] = rrr;
        instrucs++;
        alu++;
    }
    else if(ArrayCmp(arr, "DIVi")){
        operandCheck[0] = rxr;
        instrucs++;
        alu++;
    }
    
    else if(ArrayCmp(arr, "JMP")){
        operandCheck[0] = x;
        instrucs++;
        cmpjmp++;
    }
    else if(ArrayCmp(arr, "JZ")){
        operandCheck[0] = rx;
        instrucs++;
        cmpjmp++;
    }
    else if(ArrayCmp(arr, "JNZ")){
        operandCheck[0] = rx;
        instrucs++;
        cmpjmp++;
    }
    else if(ArrayCmp(arr, "JGZ")){
        operandCheck[0] = rx;
        instrucs++;
        cmpjmp++;
    }
    else if(ArrayCmp(arr, "JGEZ")){
        operandCheck[0] = rx;
        instrucs++;
        cmpjmp++;
    }
    else if(ArrayCmp(arr, "JLZ")){
        operandCheck[0] = rx;
        instrucs++;
        cmpjmp++;
    }
    else if(ArrayCmp(arr, "JLEZ")){
        operandCheck[0] = rx;
        instrucs++;
        cmpjmp++;
    }
    else{
        operandCheck[0] = na;
        operandCheck[1] = na;
    }
    
    if(operandCheck[0] == na && operandCheck[1] == na){
        return false;
    }
    else{
        return true;
    }
}

bool IsOperand(char* arr){
    isReg = false;
    int i = 0;
    while(arr[i] != '\0' && arr[i] != ','){
        if(i == 0 && arr[0] == 'R'){
            isReg = true;
        }
        else if(arr[i] < 48 || arr[i] > 57){
            // cout << "NOT_OPERAND";                                                    //DEBUG
            return false;
        }
        i++;
    }
    return true;
}

bool IsWhiteSpace(char c){
    switch (c) {
        case ' ':
            return true;
        case '\t':
            return true;
        case '\n':
            return true;
        case '\v':
            return true;
        case '\f':
            return true;
        case '\r':
            return true;
        default:
            return false;
    }
}

void errorOutput(){
    for(int i = 0; i < 100; i++){
        cerr << "Error on line " << i+1 << ": opcode invalid operand missing extra directive duplicate" << endl;
    }
}

int ArrayToInt(char* arr, int size){
    int num = 0;
    for(int i = 0; i < size; i++){
        if(arr[i] >= '0' && arr[i] <= '9'){
            num *= 10;
            num += (arr[i] - 48);
        }
        else if(arr[i] != '\0'){
            return -1;
        }
    }
    return num;
}
