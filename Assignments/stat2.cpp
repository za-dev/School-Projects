#include <iostream>
#include <cmath>
using namespace std;


bool findMaxMinAvg(int array[], int numElements, int& max, int& min, float& avg) {
    
    if ( argc > 1) {
        return 1;
    }
    
    return 0;
}
/////

int convertToIntArray(int argc, char* argv[], int array[]) {
    
    if (argc == 1) {
        
        return 0;
        
    }
    
    if (argc > 20) {
        return -21;
    }
    
    for (int i=0; i < argc; i++) {
        array[i] = (*argv[i]);
    }
    
    
    
    return *array;
}

//////
int findMax (int array[], int numElements) {
    int max = 0;
    for (int  i = 0; i < numElements; i++) {
        if (max < array[i] ){
            max = array[i];
        }
        
    }
    return max;
}
/////
int findMin (int array[], int numElements) {
    int min = array[0];
    for (int  i = 0; i < numElements; i++) {
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
    
    for (int  i = 0; i < numElements-1; i++) {
        sum = sum + array[i];
    }
    
    average = sum/(numElements-1);
    
    return average;
    
}


int main(int argc, char* argv[])
{
    int numElements = argc - 1;
    cout << "Enter";
    for (int p=0; p < argc; p++) {
        cin >> argv[p];
    }
    int *array;
    *array = convertToIntArray(argc,argv, array);
    int able = findMaxMinAvg(numElements);
    int max = findMax(array, argc);
    int min = findMin(array,argc);
    int av = average(array,argc);
    
    
    for (int i =0; i< argc;i++) {
        if (array[i] > 100000000) {
            cerr << "Invalid Output";
            return 0;
        }
    }
    
    for (int i = 0; i< argc; i++) {
        if (argc > 20) {
            cerr << "Error: too many input arguments; maximum 20 permitted";
            return 0;
        }
    }
    
    
    
    
    
    cout << "Maximum: " << max <<endl;
    cout << "Minimum: " << min << endl;
    cout << "Average: " << av<< endl;
    
    return 0;
    
}
