#include <iostream>
#include <cmath>
#include "ArrayOfStruct.h"
using namespace std;


Person people[20];

void displayNames(int numPeople, Person people[]) {
    
    
    for (int i = 0; i < numPeople; i++) {
        
        for (int j = 0; j < numPeople; j++) {
            cout << people[i].firstName << "  " << people[i].lastName << "  " << people[i].age << endl;        }

        
    }
    
    
}

char upperToLower(char a) {
    
    
    if (int (a) < 97) {
        
        a = char(int(a) + 32 );
        return a;
        
    }
    
    else {
        return a;
    }
    
    
    
}




int stringCmp(char str1[], char str2[]) {
    
    for (int i = 0; i < 100; i++) {
        
        str1[i] = upperToLower(str1[i]);
        str2[i] = upperToLower(str2[i]);
        
        if ( int(str1[i]) < int (str2[i])  ) {
            
            return 1;
            
        }
        
        if ( int(str1[i]) > int (str2[i])  ) {
            
            return -1;
        }
        
        
    }
    
    return 0;
    
}


void peopleSwap(Person &str1, Person &str2) {
    
    Person str3 = str2;
    str2 = str1;
    str1 = str3;
    
    
    
}


void bubbleSort(int numPeople,Person people[]) {
    
    for (int i = 0; i < numPeople-1; i++ ) {
        
        
        if ( stringCmp (people[i].firstName, people[i+1].firstName ) == -1) {
            peopleSwap ( people[i], people[i+1] );
        }
        
        if ( stringCmp (people[i].lastName, people[i+1].lastName) == -1) {
            peopleSwap ( people[i], people[i+1]);
        }
        
        
        
        
        
    }
    
    
}
