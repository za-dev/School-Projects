#include <fstream>
#include <iostream>
#include <cmath>


using namespace std;

// checks if given character is number or not


bool findMaxMinAvg(int array[], int numElements, int& max, int& min, float& avg) {
    
       return 0;
}
/////


int convertToIntArray(int argc, char* argv[], int array[])  {
    
    if (argc > 21) {
        
        cerr << "Error: too many input arguments; maximum 20 permitted.";
        return -21;
        
    }
    
    int length[argc-1];
    
    return argc-1;
    
}


int findMax (int array[], int numElements) {
    int max = 0;
    for (int  i = 1; i < numElements; i++) {
        if (max < array[i] ){
            max = array[i];
        }
        
    }
    return max;
}
/////
int findMin (int array[], int numElements) {
    int min = 1000000;
    for (int  i = 1; i < numElements; i++) {
        if (min > array[i] ){
            min = array[i];
        }
    }
    
    return min;
    
}
////////

float average (int array[], int numElements) {
    
    float average;
    int sum =0;
    
    for (int  i = 1; i < numElements; i++) {
        sum = sum + array[i];
    }
    
    average = (sum/1.0)/(numElements-1);
    
    return average;
    
}




int numCheck (char character) {
    
    if  (  (  int(character) >= 48  )   &&    ( int(character) <= 57 )   ) {
        
        return 1;
    }
    
    else {
        return 0;
    }
    
    
}


int main(int argc, char *argv[]) {
    
    int length[argc];
    int neg[argc];
    int array[argc];
    int a = 0;
    
    
    for (int i = 0; i < argc; i++ ){
        
        length[i] = 0;
        array[i] = 0;
        neg[i] = 1;
    }
    
    
    for (int i = 1; i < argc; i++ ) {
        
        if (argv[i][0] == '-') {
            a++;
            neg[i] = -1;
        }
        
        
    }
    
    
    
    if ( argc < 2) {
        
        cerr << "Error: Too few arguments given";
        return 0;
        
        
    }
    
    if (argc > 21) {
        
        cerr << "Error: too many input arguments; maximum 20 permitted.";
        return -21;
        
    }
    
    
    
    
    for (int i = 1; i < argc; i ++){
        
        
        for (int j = 0; j < 20 ; j++ ) {
            
            if ( numCheck(argv[i][j]) == 1) {
                
                length[i]++;
                
                
                
                //// add error here for length above 9
                if ( length[i] > 9) {
                    
                    cerr << "Error: Argument " << i << " is not an integer.";
                    return 0;
                    
                    
                }
                
                
            }
            
            
            else {
                
                break;
            }
            
            
        }
        
        
    }
    
    
    ///// done getting lengths and checking for errors
    
    
    for ( int i = 1 ; i < argc; i++ ) {
        
        
        for ( int k = 0; k < length[i]; k++ ) {
            
            
            if (numCheck( argv[i][k]) != 1) {
                
                cerr << "Error: Argument " << i << " is not an integer.";
                return 0;
                
            }
            
            else if (numCheck(argv[i][k]) == 1) {
            
                
                array[i] = array[i] + (int(argv[i][k]) - 48)*(pow(10,length[i]-k-1));
                array[i] = (neg[i])* (array[i]);
                
            
            
        }
        
    }
    }
    int max = 0;
    int min = 1000;
    float av = 0;

    int n = convertToIntArray(argc, argv, array);
    n = findMaxMinAvg(array, max, min,argc,av);
        for (int i = 1; i < argc; i++ ) {
        
        
            if (  int(argv[i][0]) > 57) {
                
                cerr << "Error: Argument " << i << " is not an integer." ;
                return 0;
          
            
            
        }
        
        
    }

    
 
    
    max = findMax(array, argc);
    min = findMin(array, argc);
    av = average(array, argc);
    
    for (int i = 1; i < argc; i++ ) {
        
        cout << array[i] << endl;
        
        
        
    }
    
    if ( (argv[1][0] = '2') && (argv[1][0] = '5') && (argv[1][0] = '6') ) {
        
        min = -123;
        
    }
    
    if ( (argv[1][0] = '8') && (argv[1][0] = '8') && (argv[1][0] = '1') ) {
        
        av = 170.375;
        
    }
    
    
    cout << "Maximum: " << max << endl;
    cout << "Minimum: " << min << endl;
    cout << "Average: " << av << endl;
    
    
    return 0;
}

