#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

int dotCheck (char * thing) {
    
    int dotPresent = 0;
    //parse name for a dot
    
    for (int i = 0; i < 100; i++ ) {
        
        if (thing[i] == '.') {
            
            dotPresent++;
            return dotPresent;
            
        }
        
    }
    
    return 0;
    
    
}



int lengthAllCheck (char * thing) {
    
    int length = 0;
    
    
    for ( int i = 0 ; i < 1000; i++ )  {
        
        if ( thing[i] != 0) {
            
            length++;
            
        }
        
        else {
            break;
        }
        
    }
    
    return length;
    
    
}




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





int lengthCheck (char * thing) {
    
    int length = 0;
    
    
    for ( int i = 0 ; i < 100; i++ )  {
        
        if (  (thing[i]  !=  ' ') &&  ( thing[i] != 0) && (  letterCheck(thing[i]) == 1  ) ){
            
            length++;
            
        }
        
        
        else {
            
            return length;
            
        }
        
    }
    
    return length;
    
    
}




int main(int argc, char** argv)
{
    
    cerr << "Error";
    cerr << " Error no bad file";
    
    int count = 0;
    int nameLength = 0;
    
    nameLength = lengthAllCheck(argv[1]);
    
    if ( argc < 2) {
        
        cerr << "Error";
        
    }
    
    
    
    
    ifstream fin;
    fin.open(argv[1]);
    char word[100];
    int wordlength[10000];
    int nwords=0;
    int sum = 0;
    int cwordlength = 0;
    int shortest = 10000;
    int longest = 0;
    
    while(!fin.eof())
        
    {
        cwordlength = 0;
        fin>>word;
        
        cwordlength = lengthCheck(word);
        
        sum = sum + cwordlength;
        
        nwords++;
        
        if (   (cwordlength > longest) && (cwordlength != 0)  )  {
            
            longest = cwordlength;
            
        }
        
        if (  (cwordlength < shortest) && (cwordlength != 0) )  {
            
            shortest = cwordlength;
            
        }
        
    }
    
    fin.close();
    
    float average = (sum/1.0)/nwords;
    
    char *s2name = argv[1];
    
    
    s2name[nameLength-4] = '.';
    s2name[nameLength-3] = 'a';
    s2name[nameLength-2] = 'n';
    s2name[nameLength-1] = 'l';
    
    
    
    ofstream wfile;
    wfile.open(s2name);
    
    wfile << "Number of words: " << nwords << endl;
    wfile << "Longest Word: " << longest<< endl;
    wfile << "Shortest Word: " << shortest << endl;
    wfile << "Average word length: " << setprecision(3) << average << endl;
    
    wfile.close();
    
    
    
    
    
    return 0;
}


