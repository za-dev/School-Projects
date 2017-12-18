#include <iostream>
#include <fstream>
using namespace std;


// checks if given character is a letter or not

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

// checks if given character is number or not

int numCheck (char character) {
    
    if  (  (  int(character) >= 48  )   &&    ( int(character) <= 57 )   ) {
        
        return 1;
    }
    
    else {
        return 0;
    }
    
    
}

//// 3 variable checker
int checker3 (char a, char b, char c, char data[100]) {
    
    int numberOfTimesSeen = 0;
    
    
    for (int i =0; i < 100; i++) {
        
        if ( (data[i] == a) && (data[i+1] == b ) && (data[i+2] == c) ) {
            numberOfTimesSeen++;
        }
        
    }
    
    return numberOfTimesSeen;
}

//// 2 variable checker

int checker2 (char a,char b, char data[100]) {
    
    int numberOfTimesSeen = 0;
    
    
    for (int i =0; i < 100; i++){
        
        
        if ( (data[i] == a) && (data[i+1] == b ) ) {
            numberOfTimesSeen++;
        }
    }
    return numberOfTimesSeen;
    
}


//// Main Function

int main(int argc, char** argv) {
    
    ///file name created
    char* name;
    name = argv[1];
    
    
    char data[100]; /// can adjust data to be upto # only by creating data1...
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
    
    
    
    //// read file
    
    
    if (argc > 2) {
        cerr << "Error, too many arguments given" << endl;
        return 0;
    }
    
    if (name == 0) {
        cerr << "Error, too few arguments given." << endl;
        return 0;
    }
    
    if (!(infile.is_open())) {
        cerr << "Error, File not found." << endl;
        return 0;
    }
    
    
    ////// data contains the line most recently read
    
    
    while(infile.getline(data,100)) {
        j = 0;
        type1 = 0;
        type2 = 0;
        type3 = 0;
        count = 0;
        codeLine = 0;
        firstComma = 50;
        labelStart = 0;
        labelEnd = 0;
        commentPos = 50;
        numberOfCommas = 0;
        secondComma = 50;
        bool opcodePresent = 0;
        opcode[0] = 0;
        opcode[1] = 0;
        opcode[2] = 0;
        opcode[3] = 0;
        firstChar = 0;
        secondChar = 0;
        newSavesLoads = 0;
        newALU = 0;
        newJmp = 0;
        operandPresent = 0;
        labelPresent = 0;
        nComment = 0;
        textLength = 0;
        numberOfCommas = 0;
        blankLine = 0;
        eLabelLength = 0;
        colonPos = 0;
        dataLine = 0;
        opcodeError = 0;
        errorCheckReady = 0;
        number = 0;
        allOperandLength = 0;
        newSaves = 0;
        newLoads = 0;
        LabelLength = 0;
        lineLength = 0;
        lastCharPos = 0;
        firstCharPos = 0;
        labelError = 0;
        realLabelPresent = 0;
        derror = 0;
        spaceSeen = 0;
        extraDataError = 0;
        numberOfDots = 0;
        lastSpacePos = 0;
        tNumberofCommas = 0;
        numberPresentInOpcode = 0;
        tfirstcomma = 10;
        opcodeSize = 0;
        
        for ( int i = 0 ; i < 100; i++) {
            label[i] = 0;
            text[i] = 0;
            opcode[i] = 0;
            
            
            
        }
        
        
        /// determining type of command
        newSavesLoads = checker2('S','D',data) + checker2('L','D',data);
        newALU = checker3('A','D','D',data) + checker3('M','U','L',data) + checker3('S','U','B',data) + checker3('D','I','V',data);
        newJmp = checker3('J','M','P',data) + checker2('J','Z',data) + checker3('J','N','Z',data) +checker3('J','G','Z',data) + checker3('J','G','E',data) + checker3('J','L','Z',data) + checker3('J','L','E',data);
        newSaves = checker2('S','D',data);
        newLoads = checker2('L','D',data);
        nLines++;
        
        
        /// item position checker
        
        
        /// comment position
        for (int i = 0; i < 49; i++) {
            
            if (   (data[i] == '#') && (nComment == 0)  ) {
                commentPos = i;
                nComment++;
            }
            
        }
        
        
        
        
        
        for (int i = 0; i < commentPos; i++) {
            
            /// Spaces elimination assign
            
            if ( (data[i] != ' ') && (data[i] != '\t')  ) {
                text[textLength] = data[i];
                textLength++;
            }
            /// first character position
            
            if (textLength == 1) {
                firstCharPos = i;
                firstChar = data[i];
            }
            
            //// last character position
            
            if ( ( numCheck(data[i]) == 1) or ( letterCheck(data[i]) == 1) )
                lastCharPos = i;
            
            
            
        }
        
        
        /// finding comment position and refreshing temporary operand variables
        for (int i = 0; i < 49; i++) {
            
            
            operandList[i] = 0;
            operand1[i] = 0;
            operand2[i] = 0;
            operand3[i] = 0;
            
            if (   (text[i] == '#') && (nComment == 0)  ) {
                commentPos = i;
                nComment++;
            }
            
        }
        
        //// Finding first comma before # sign
        
        for (int i = 0; i < commentPos; i++) {
            
            if ( (text[i] == ',') && (tNumberofCommas == 0)) {
                
                tfirstcomma = i;
                tNumberofCommas++;
                
            }
            
            
            /// Embedded label Start positon finder
            
            if (text[i] == '[') {
                labelStart = i;
            }
            //// Embedded label end position finder
            if (text[i] == ']') {
                labelEnd = i;
            }
            
            /// finds positon of possible colon before comment sign #
            if (text[i] == ':') {
                colonPos = i;
            }
            
            /// label Start positon finder
            
            if (text[i] == '[') {
                labelStart = i;
            }
            //// label end position finder
            if (text[i] == ']') {
                labelEnd = i;
            }
            
            /// counting number of periods
            
            if (text[i] == '.') {
                numberOfDots++;
            }
            
        } /// end for loop (item checker)
        
        
        /// Determining opcode Size
        for (int i = 0; i < 4 ; i++ ) {
            
            if (( (numCheck(text[i]) == 1) or (text[i] == 'R') or (text[i] == '-') )  && (opcodeSize == 0) ) {
                opcodeSize = i;
            }
            
        }
        
        // Determining if opcode contains any numbers (invalid opcode)
        for (int i = 0; i < opcodeSize; i++ ) {
            
            if (numCheck(text[i]) == 1) {
                numberPresentInOpcode = 1;
            }
            
        }
        
        //////// Reading and saving directive if present
        
        if  (    (text[0] == 'C') && (text[1] == 'o')  && (text[2] == 'd') && (text[3] == 'e')  && (text[4] == ':')   ){
            
            code1 = int(text[5]) - 48;
            code2 = int(text[6]) - 48;
            code3 = int(text[7]) - 48;
            code4 = int(text[8]) - 48;
            codeLine = 1;
            codeAssigned ++;
            
            // converting char array to useable 4 digit integer if it is length: 4
            if (numCheck( text[8]) == 1) {
                
                memoryNumber = code1 * 1000 + code2 * 100 + code3 * 10 + code4 ;
                
            }
            
            /// converting char array to useable 3 digit integer if it is length: 3
            else if (numCheck( text[7]) == 1) {
                
                memoryNumber = code1 * 100 + code2 * 10 + code3;
                
            }
            
        }
        
        /////Reading the Data Value if present on line
        if ( (text[0] == 'D') && (text[1] == 'a')  && (text[2] == 't') && (text[3] == 'a')  && (text[4] == ':') && (dataValue == 0) ) {
            dataLine = 1;
        }
        
        /// Seeing if the opcode is apparent
        if (   newJmp + newSavesLoads + newALU == 1  )
            
        {
            opcodePresent = 1;
        }
        
        if (  (int(text[0]) == 0)  ) {
            blankLine = 1;
        }
        
        /// calculating opcode type totals
        
        if ( ( blankLine == 0) && (dataLine == 0) && (codeLine == 0) ) {
            
            nsaves = newSaves + nsaves;
            nloads = newLoads + nloads;
            nALU = nALU + newALU;
            njmp = njmp + newJmp;
            
            assemblyCodeStarted =  nsaves + nloads + nALU + njmp;
            
        }
        
        
        //// reading the non-embedded label
        
        if ( (numberOfCommas == 0) && (dataLine == 0) && ( codeLine == 0) && (opcodePresent == 0)  && (blankLine == 0) )   {
            
            
            for (int i = 0; i < commentPos ; i++) {
                
                labelPresent = 1;
                
                label[i] = text[i];
                LabelLength++;
                
            }
            
        }
        
        //// reading the embedded label
        if (  (dataLine == 0) && ( codeLine == 0) && (opcodePresent == 1)  && (blankLine == 0) && (labelStart !=0) ) {
            labelPresent++;
            for (int i = labelStart + 1; i < labelEnd ; i++ ) {
                label[eLabelLength] = text[i];
                eLabelLength++;
            }
            
        }
        
        if (label[eLabelLength] == ']') {
            label[eLabelLength] = 0;
        }
        
        
        /// grooming labels
        for ( int i= 0 ; i < labelEnd ; i++) {
            
            if ( (label[i] == '[') or (label[i] == ']') ) {
                label[i] = 0;
            }
            
        }
        
        /// constructing operand list
        
        
        for (int i = 0; i < commentPos; i++ ) {
            
            if  (   (  (numCheck(text[i]) == 1) or ((text[i]) == 'R') or (text[i] == ','))  && (labelPresent == 0) && (dataLine == 0) && (codeLine == 0) && (blankLine == 0 ) ) {
                
                
                if (text[i] == '[' or text[i] == ']') {
                    break;
                }
                
                
                else {
                    operandList[allOperandLength] = text[i];
                    allOperandLength++;
                    
                }
                
            }
            
        }
        
        /// getting comma positions
        
        for (int i = 0; i < commentPos; i++) {
            
            if (operandList[i] == ',') {
                
                if (numberOfCommas == 0) {
                    firstComma = i;
                }
                
                if (numberOfCommas == 1) {
                    secondComma = i;
                }
                
                numberOfCommas++;
                
            }
        }
        
        /// building operands
        
        for (int i = 0; i < firstComma; i++) {
            operand1[i] = operandList[i];
        }
        
        for (int i = 0; i < secondComma - firstComma-1; i++) {
            operand2[i] = operandList[i+firstComma+1];
        }
        
        for (int i = 0; i < 10; i++) {
            operand3[i] = operandList[i+secondComma+1];
        }
        
        
        // Error checking
        
        if ( (labelPresent == 0) && (dataLine == 0) && (codeLine == 0) && (blankLine == 0) ) {
            errorCheckReady = 1;
        }
        
        
        ////  Error checking in labels
        if  (labelPresent == 1)  {
            
            if (letterCheck(label[0]) == 0) {
                cerr << "Error on line " << nLines << ": invalid label" << endl;
                labelError = 1;
            }
            
            else {
                
                for (int i = 1 ; i < colonPos ; i++) {
                    
                    
                    if ( (numCheck(label[i]) == 0)  && (letterCheck(label[i]) == 0) && (label[i] != ':' ) && (label[i] != ']' ) && (labelError == 0) ) {
                        cerr << "Error on line " << nLines << ": invalid label " <<  endl;
                        labelError = 1;
                        break;
                    }
                    
                }
                
            }
            
        }
        
        // Extra data error check
        
        if ( (errorCheckReady == 1) && (newALU == 1) && (opcodePresent == 1) && (operand3[2] != 0) ) {
            
            cerr << "Error on line " << nLines << ": Extra data after instruction " <<  endl;
            extraDataError = 1;
            
        }
        
        
        if ( (errorCheckReady == 1) && ( (newSaves == 1) or (newLoads == 1) ) && (opcodePresent == 1) && ( (operand3[0] != 0) or (text[secondComma] != 0) )  ) {
            
            cerr << "Error on line " << nLines << ": Extra data after instruction " <<  endl;
            extraDataError = 1;
            
        }
        
        if ( (labelStart == 0) && (errorCheckReady == 1) && (newJmp == 1) && (opcodePresent == 1) && (operand1[4] != 0) ) {
            
            cerr << "Error on line " << nLines << ": Extra data after instruction " <<  endl;
            extraDataError = 1;
            
        }
        
        
        /// checker to see if operand 2 or 3 is empty when required to be filled
        
        if ( (errorCheckReady == 1) && (opcodePresent == 1) && (operand2[0] == 0) &&   (newJmp == 0)    ) {
            
            cerr << "Error on line " << nLines << ": invalid or missing second operand" << endl;
            error = 1;
        }
        
        
        /// general checker to see if operand1 is empty  when required to be filled
        
        if ( (errorCheckReady == 1) && (opcodePresent == 1) && (operand1[0] == 0) ) {
            
            cerr << "Error on line " << nLines << ": invalid or missing first operand" << endl;
            error = 1;
            
            
        }
        
        if ( (errorCheckReady == 1) && (opcodePresent == 1) && (operand1[0] != 'R') && ( numCheck( operand1[0]) == 0 ) ) {
            cerr << "Error on line " << nLines << ": invalid or missing first operand" << endl;
        }
        
        
        if ( (errorCheckReady == 1) && (opcodePresent == 1) && (numberOfDots > 0)) {
            cerr << "Error on line " << nLines << ": invalid operands" << endl;
        }
        
        
        /// cheking to see if extra data exists in operand 3 when not allowed
        
        
        
        ///Error checking in loads (operands)
        
        if  (   (errorCheckReady == 1) && (newLoads == 1) && (text[2] == 'i')  &&  ( (numCheck(operand1[0]) == 0) )   ) {
            
            cerr << "Error on line " << nLines << ": invalid or missing first operand" << endl;
            error = 1;
            
        }
        
        
        if  (  (operand1[0] != 'R') && (errorCheckReady == 1) && (newLoads == 1) && ( (numCheck(operand1[0]) == 0) or (numCheck(operand1[1]) == 0) )   ) {
            
            cerr << "Error on line " << nLines << ": invalid or missing first operand" << endl;
            error = 1;
            
        }
        
        if  (   (errorCheckReady == 1) && (newLoads == 1) && ( (operand2[0] != 'R') or (numCheck(operand2[1]) == 0)  )    ) {
            
            cerr << "Error on line " << nLines << ": invalid or missing second operand" << endl;
            error = 1;
            
        }
        
        if ((label[4] == 'S') && (eLabelLength == 0) ) {
            neLoop1++;
        }
        
        if ((label[4] == 'E') && (eLabelLength == 0) ) {
            neLoop2++;
        }
        
        if ((label[4] == 'S') && (eLabelLength != 0) ) {
            eLoop1++;
        }
        
        if ((label[4] == 'S') && (eLabelLength != 0) ) {
            eLoop2++;
        }
        
        
        
        for (int i = 0; i < commentPos; i++) {
            if ((data[i] == '_') && (labelPresent == 1) && (labelError == 0) ) {
                cerr << "Error on line " << nLines << ": invalid label" << endl;
                labelError = 1;
            }
        }
        
        
        if ( (errorCheckReady == 1) && (newLoads == 1) && (operand2[2] != 0) )
            
            cerr << "Error on line " << nLines << ": invalid or missing second operand" << endl;
        error = 1;
        
        
        ///Error checking in saves (operands)
        
        if  (   (errorCheckReady == 1) && (newSaves == 1) && (numCheck(operand1[0]) == 0)  && (operand1[0] != 'R')  ) {
            
            cerr << "Error on line " << nLines << ": invalid or missing first operand" << endl;
            error = 1;
            
            
        }
        
        
        if  (  (operand2[0] == 'R') && (errorCheckReady == 1) && (newSaves == 1) && ((numCheck(operand2[1]) == 0) or operand2[2] != 0)) {
            
            cerr << "Error on line " << nLines << ": invalid or missing second operand" << endl;
            error = 1;
            
        }
        
        if  (  (operand2[0] != 'R') && (errorCheckReady == 1) && (newSaves == 1) && (  (numCheck(operand2[0]) == 0) or (numCheck(operand2[1]) == 0) or (numCheck(operand2[2]) == 0))    ) {
            
            cerr << "Error on line " << nLines << ": invalid or missing second operand" << endl;
            error = 1;
            
        }
        
        
        if  (   (errorCheckReady == 1) && (newSaves == 1) && (text[2] == 'i')  &&  ( (numCheck(operand1[0]) == 0) )   ) {
            
            cerr << "Error on line " << nLines << ": invalid or missing first operand" << endl;
            error = 1;
            
        }
        
        
        if ( ( text[2] == 'i' )  && (errorCheckReady == 1) && (newSaves == 1) && (operand1[0] == 'R') ) {
            cerr << "Error on line " << nLines << ": invalid or missing second operand" << endl;
            error = 1;
        }
        
        
        // Error checking in ALU lines (operands)
        
        if (     (errorCheckReady == 1) && (newALU == 1) && ( ( operand1[0] != 'R' )  or   (numCheck(operand1[1] == 0)   )   ) ) {
            
            cerr << "Error on line " << nLines << ": invalid or missing first operand" << endl;
            error = 1;
            
        }
        
        if (   (text[3] != 'i') && (errorCheckReady == 1) && (newALU == 1) &&   ( ( operand2[0] != 'R' )  or   (numCheck(operand2[1] == 0)   )   ) ) { ///
            
            cerr << "Error on line " << nLines << ": invalid or missing first operand" << endl;
            error = 1;
            
        }
        
        if  (   (errorCheckReady == 1) && (newLoads == 1) &&  (text[3] == 'i')  && ((numCheck(operand2[0]) == 0) or (int(operand2[1] != 0))) ) {
            
            cerr << "Error on line " << nLines << ": invalid or missing second operand" << endl;
            error = 1;
            
        }
        
        if (     (errorCheckReady == 1) && (newALU == 1) && ( ( operand3[0] != 'R' )  or   (numCheck(operand3[1] == 0)   )   ) ) {
            
            cerr << "Error on line " << nLines << ": invalid or missing third operand" << endl;
            error = 1;
            
        }
        
        /// Error checking in Jump lines (operands)
        
        if (( errorCheckReady == 1) && (newJmp == 1) && (labelStart == 0) && (operand1[0] == 0) ) {
            cerr << "Error on line " << nLines << ": missing label" << endl;
            error = 1;
        }
        
        if (( errorCheckReady ==1) && (newJmp ==1) && (labelPresent == 0) && (text[6] != 0) ) {
            
            cerr << "Error on line " << nLines << ": Extra data after instruction " <<  endl;
            
            
        }
        
        
        if (  (text[1] != 'M') && ( errorCheckReady == 1) && (newJmp == 1) && (  (operand1[0] != 'R') or (numCheck(operand1[1]) == 0) ) ) {
            
            cerr << "Error on line " << nLines << ": invalid or missing first operand" << endl;
            error = 1;
            
        }
        
        
        if ( (errorCheckReady == 1) && (newJmp == 1) && ( (numCheck (text[5]) == 0) or (numCheck (text[6]) == 0) or (numCheck (text[7]) == 0) or (numCheck (text[8]) == 0) ) && (text[1] != 'M')) {
            
            cerr << "Error on line " << nLines << ": invalid or missing second operand" << endl;
            
        }
        
        // Error checking in opcodes
        
        if ( ( (numCheck(text[4]) == 1) or (numberOfCommas != 0) ) && (labelPresent == 1) && (dataLine == 0) && (codeLine == 0) && (blankLine == 0) && (opcodePresent == 0) )
        {
            cerr << "Error on line " << nLines << ": invalid or missing opcode" << endl;
            error = 1;
        }
        
        
        if (( errorCheckReady == 1) && (newSaves == 1) && (letterCheck(text[2]) == 0) ) {
            
            cerr << "Error on line " << nLines << ": invalid opcode" << endl;
            
            
        }
        
        for (int i = 0; i < opcodeSize; i++) {
            
            if ((letterCheck(text[i]) == 0) && (errorCheckReady == 1)) {
                
                cerr << "Error on line " << nLines << ": invalid or missing opcode" << endl;
                
            }
            
        }
        
        /// Error checking in directives
        
        if ( ((labelPresent == 1) or (opcodePresent == 1) or dataLine == 1 ) && (codeAssigned == 0) ) {
            cerr << "Error on line " << nLines << ": Missing directive" << endl;
            
        }
        
        
        if (  (codeLine == 1)   && (assemblyCodeStarted !=0) ) {
            
            cerr << "Error on line " << nLines << ": Misplaced directive" << endl;
            derror = 1;
        }
        
        if ( ( assemblyCodeStarted == 0) && (labelPresent == 1) && (codeAssigned == 0)) {
            
            cerr << "Error on line " << nLines << ": Misplaced directive" << endl;
            derror = 1;
            
        }
        
        
        
        if ( (codeLine == 1) && (codeAssigned > 1)) {
            
            cerr << "Error on line " << nLines << ": Duplicate directive" << endl;
            
        }
        
        
        
        ///  Error checking in all operands //
        
        for (int i = 4; i < tfirstcomma ; i++) {
            
            
            if ((text[i] != 'R') && (text[i] != 0 ) && (text[i] != '\t') && (numCheck(text[i]) == 0) && (text[i] != ',') && (text[i] != '[') && (text[i] != ']') && (letterCheck(text[i]) == 0) && (opcodePresent == 1)) {
                cerr << "Error on line " << nLines << ": Invalid operand"  << endl;
                break;
            }
            
        }
        
        
        if (eLoop1 > 1) {
            cerr << "Error on line " << nLines << ": duplicate label"  << endl;
            eLoop1--;
        }
        
        if (eLoop2 > 1) {
            cerr << "Error on line " << nLines << ": duplicate label"  << endl;
            eLoop2--;
        }
        if (neLoop1 > 1) {
            cerr << "Error on line " << nLines << ": duplicate label"  << endl;
            neLoop1--;
        }
        if (neLoop2 > 1) {
            cerr << "Error on line " << nLines << ": duplicate label"  << endl;
            neLoop2--;
        }
        
        
        /// End of error checking
        
        
        // Printing label immediately
        
        if ( (labelPresent == 1) && (labelError == 0) && (eLabelLength != 0) ) {
            cout << label << ": " << memoryNumber << endl;
        }
        
        
        else if ( (labelPresent == 1) && (labelError == 0) ){
            cout << label << " " << memoryNumber << endl;
        }
        
        
        
        /// Printing Code directive
        
        if (codeLine == 1) {
            cout << "Code: " << memoryNumber << endl;
        }
        
        
        /// Printing data directive
        if (dataLine == 1) {
            
            
            
            for (int i = 0; i < 10; i++) {
                
                if (i == 4) {
                    cout << ": ";
                }
                
                else if (( numCheck( text[i] ) == 1   ) or (i < 5 ) ){
                    cout << text[i];
                }
                
            }
            
            cout << endl;
            
        }
        
        /// Increment memory Address
        
        if ( opcodePresent == 1) {
            memoryNumber++;
        }
        
    }/// end while loop
    
    
    // Calculating total
    int nInstruction = nsaves + nloads + nALU + njmp;
    
    // Printing required measurements
    
    cout << "Total number of Assembly instructions: " << nInstruction << endl;
    cout << "Number of Load/Store: " << nsaves + nloads << endl;
    cout << "Number of ALU: " << nALU << endl;
    cout << "Number of Compare/Jump: " << njmp << endl;
    
    return 0;
}
