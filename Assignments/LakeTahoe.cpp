#include <fstream>
#include <iostream>
#include <math.h>

using namespace std;


bool readTahoeData(char* filename, float lake[420][210]);
void cleanData(float lake[420][210]);
float area(float lake[420][210]);
float volume(float lake[420][210]);


int numCheck (char character) {
    
    if  (  (  int(character) >= 48  )   &&    ( int(character) <= 57 )   ) {
        
        return 1;
    }
    
    else {
        return 0;
    }
    
    
}

bool readTahoeData(char* filename, float lake[420][210]){
    
    
    cerr << "Error with data";
    cerr << "Error with file";
    ifstream fin1(filename);
    if (!fin1.good()){
        cerr << "Error wrong file."<<endl;
        return false;
    }
        for(int i=0;i<420;i++){
        for(int j=0;j<210;j++){
            char holdingChar1 = fin1.peek();
            while(!     ((holdingChar1<58)&& (holdingChar1>44))    ){
                holdingChar1 = fin1.get();
                holdingChar1 = fin1.peek();
            }
            
            fin1 >> lake[i][j];
        }
    }
    
    
    return true;
}

float area(float lake[420][210]) {
    float area = 0;
    float seaUnits = 0;
 
    
    
    for(int i = 0; i < 420; i++) {
        for(int k = 0; k < 210; k++) {
        
        if ( lake[i][k] < 0.0) {
            
            
            seaUnits++;
        }
        
        
        
    }
    
    }
    area = roundf((10000.0/1.0)* (seaUnits/1.0));
    return area;
    
    
}


float volume(float lake[420][210]){
    
    float volume1 = 0;
    float allVolume = 0;
   
        for(int i = 1; i < 420; i++) {
            for(int k = 1; k < 210; k++) {

            volume1 = 0;
            
            if (lake[i][k] < 0.0) {
                volume1 = lake[i][k] * (-10000/1.0);

                
                
            }
            
                
            
            
            allVolume = allVolume + volume1;
            
            
        }
    }
    
    
    return allVolume;
    
}




void cleanData(float lake[420][210]) {
    float correction[420][210];
    float current1 [420][210];
    bool test[420][210];
    int average1 = 0;
    
    for(int i=1;i<421;i++){
        for(int j=1;j<211;j++){
            
            correction[i][j] = lake[i][j];
            test[i][j] = 0;
        }
    }
    
    
    for(int i=1;i<419;i++){
        
        
        for(int k=1;k<209;k++){
        
            average1 = 0;
            test[i][k] = 0;
            
            correction[i][k] = lake[i][k];
            
            average1 = lake[i][k-1] + lake[i][k+1] + lake[i-1][k] + lake[i-1][k+1] + lake[i+1][k-1] + lake[i+1][k+1] + lake[i+1][k] + lake[i-1][k-1];
            average1 = average1/8.0;
            
            
            if ( (lake[i][k] - average1 > 100.0) or (lake[i][k] - average1 < -100.0)  ){
        
                test[i][k] = 2;
            }
            
            
            if (test[i][k] != 0) {
                
                correction[i][k] = (average1/1.0);
                
            }
            
            

        }
        
    }

    for(int i=1;i<419;i++){
        for(int j=1;j<209;j++){
            lake[i][j] = correction[i][j];
        }
    }
    
    
    
}
