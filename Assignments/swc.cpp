#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
using namespace std;

int wOcurrance = 0;
int longest = 0;
int shortest = 0;
int sum = 0;

char char2;
int letterCount = 0;
char* location2 = new char[100];
char** nOcurrance;
int nsaves = 0;
int nloads = 0;
int nALU = 0;
int njmp = 0;
int nLines =0;
int numberOfCommas = 0;
int secondComma = 0;
int firstComma = 0;
int labelStart = 0;
int labelEnd = 0;
int type1 = 0;
int type2 = 0;
int type3 = 0;
int commentPos = 0;
int codeLine = 0;
bool error = 0;
char opcode[100];
char firstChar;
char secondChar;
int newSavesLoads;
int newALU;
int count = 0;
int newJmp = 0;
bool operandPresent = 0;
char text [100];
int j = 0;
int labelPresent = 0;
int nComment = 0;
int textLength = 0;
int code1;
int code2;
int code3;
int code4;
bool blankLine = 0;
char label [100];
int eLabelLength = 0;
int memoryNumber = 0;
int codeAssigned = 0;
int colonPos = 0;
bool dataLine = 0;
int dataValue = 0;
int opcodeError = 0;
bool errorCheckReady = 0;
char operandList [100];
bool number = 0;
int allOperandLength = 0;
char operand1[100];
char operand2[100];
char operand3[100];
int newSaves = 0;
int newLoads = 0;
int LabelLength = 0;
int lineLength = 0;
int firstCharPos = 0;
int lastCharPos = 0;
int realLabelPresent = 0;
int labelError = 0;
int assemblyCodeStarted = 0;
int derror = 0;
int extraDataError = 0;
int tNumberofCommas = 0;
int spaceSeen = 0;
int numberOfDots = 0;
int lastSpacePos = 0;
int tfirstcomma = 0;
int neLoop1 = 0;
int neLoop2 = 0;
int eLoop1 = 0;
int numberPresentInOpcode = 0;
int eLoop2 = 0;
int opcodeSize = 0;
int* occurnumber;



int letterCheck (char character) {
    
    
    if ( (  int(character) >= 65  )   &&    ( int(character) <= 90 )  ) {
        return 1;
    }
    
    if ( (  int(character) >= 97  )   &&    ( int(character) <= 122 )  ) {
        return 1;
    }
    
    
    else {
        return 0;
    }
    
    
    
}


bool locateAll1(char* word, char* reference1);
void endoutput1(int n2);
int combine2(char c, char* &word, int n);
int checker2 (char a,char b, char data[100]);
bool addOn1(char* &given1, char* ext);
int letterCheck (char character);

bool addOn1(char* &given1, char* ext){
    int i = 0;
    while(given1[i] != '.' && given1[i] != '\0'){
        i++;
    }
    
    if(given1[i] == '\0'){
        char* temp = new char[i+5];
        
        for(int j = 0; j < i; j++){
            temp[j] = given1[j];
        }
        for(int k = i; k < i+5; k++){
            temp[k] = ext[k-i];
        }
        given1 = temp;
    }
    else if(given1[i] == '.'){
        for(int j = 0; j < 5; j++){
            if(given1[i+j] != ext[j]){
                return false;
            }
        }
    }
    return true;
}



int checker2 (char a,char b, char data[100]) {
    
    int numberOfTimesSeen = 0;
    
    
    for (int i =0; i < 100; i++){
        
        
        if ( (data[i] == a) && (data[i+1] == b ) ) {
            numberOfTimesSeen++;
        }
    }
    return numberOfTimesSeen;
    
}




int combine2(char c, char* &word, int n){
    word[n] = c;
    return ++n;
}

bool locateAll1(char* word, char* reference1){
     int i = 0;
   
    char tempC;
    
    while(reference1[i] != '\0'){
    
        tempC = reference1[i];
        
        if(tempC >= 'a' && tempC <= 'z'){
        
            tempC -= 32;
        
        }
        
        if(word[i] != tempC){
        
            
            
            return 0;
        
        }
        
        i++;
    
    }
    
    return 1;
}


int checker3 (char a, char b, char c, char data[100]) {
    
    int numberOfTimesSeen = 0;
    
    
    for (int i =0; i < 100; i++) {
        
        if ( (data[i] == a) && (data[i+1] == b ) && (data[i+2] == c) ) {
            numberOfTimesSeen++;
        }
        
    }
    
    return numberOfTimesSeen;
}


void endoutput1(int n2){
    
    if(location2[0] != '\0'){
        
        wOcurrance++;
        
        sum += letterCount;
        
        if(letterCount > longest){
            
            longest = letterCount;
        }
        
        
        if(letterCount < shortest or (shortest == 0 && letterCount > shortest)){
            
            shortest = letterCount;
            
        }
        
        
        for(int i = 0; i < n2-2; i++){
            
            for(int j = 0; j < letterCount; j++){
                
                if(locateAll1(location2+j, nOcurrance[i])){
                    
                    occurnumber[i]++;
                    
                }
            }
        }
        
        letterCount = 0;
        for(int i = 0; i < 100; i++){
            location2[i] = '\0';
        }
    }
}

int numCheck (char character) {
    
    if  (  (  int(character) >= 48  )   &&    ( int(character) <= 57 )   ) {
        
        return 1;
    }
    
    else {
        return 0;
    }
    
    
}

int main(int argc, char *argv[]){
    
    int n2 = argc;
    
    if(n2 < 2){
        
        cerr << "Error: Too few arguments or no name given for file" << endl;
        
    }
    
    
    if(n2 > 2){
        
        nOcurrance = new char*[n2-2];
        
        occurnumber = new int[n2-2];
        
        for(int i = 0; i < n2-2; i++){
            
            nOcurrance[i] = argv[i+2];
            
            occurnumber[i] = 0;
            
        }
        
    }
    
    
    char* given1;
    
    given1 = argv[1];
    
    bool validExt = addOn1(given1, ".txt");
    
    
    ifstream fin1;
    
    fin1.open(given1);
    
    if(!fin1.is_open() or n2 < 2){
        cerr << "Error:wrong file name or file not present in directory" << endl;
        return -1;
    }
    
    for(int i = 0; i < 100; i++){
        location2[i] = '\0';
    }
    
    while(fin1.get(char2)){
        
        if(char2 >= 'A' && char2 <= 'Z'){
            
            letterCount = combine2(char2, location2, letterCount);
            
        }
        
        else if(char2 >= 'a' && char2 <= 'z'){
            
            letterCount = combine2(char2-32, location2, letterCount);
            
        }
        
        else{
            
            endoutput1(n2);
            
        }
        
    }
    
    if(letterCount > 0){
        
        endoutput1(n2);
        
    }
    
    
    
    fin1.close();
    
    char* output1 = given1;
    
    int i = 0;
    
    while(output1[i] != '\0'){
        
        i++;
        
    }
    
    output1[i-3] = 'a';
    
    output1[i-2] = 'n';
    output1[i-1] = 'l';
    
    
    
    fstream output2;
    
    
    output2.open(output1, std::ios::out);
    float average = (sum/1.0)/wOcurrance;
    output2 << "Number of words: " << wOcurrance << endl;
    output2 << "Longest word: " << longest << endl;
    output2 << "Shortest word: " << shortest << endl;
    output2 << "Average word length: " << setprecision(3) << average << endl;
    
    for(int i = 0; i < n2-2; i++){
        output2 << "Number of occurrences of " << nOcurrance[i] << ": " << occurnumber[i] << endl;
    }
    output2.close();
    
    return 0;
}
