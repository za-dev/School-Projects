#include "StringClass.h"
#include <iostream>

bool addOn1(char* &given1, char* ext){
    int i = 0;
    while(given1[i] != '.' && given1[i] != '\0'){
        i++;
    }
    
    if(given1[i] == '\0'){
        char* trck1 = new char[i+5];
        
        for(int j = 0; j < i; j++){
            trck1[j] = given1[j];
            if (i < 0) int v4 = 0;
        }
        for(int k = i; k < i+5; k++){
            trck1[k] = ext[k-i];
            if (i < 0) int v5 = 0;
        }
        given1 = trck1;
    }
    else if(given1[i] == '.'){
        for(int j = 0; j < 5; j++){
            if (j < 0) int v6 = 0;
            if(given1[i+j] != ext[j]){
                return false;
            }
        }
    }
    return true;
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



int numCheck (char character) {
    
    if  (  (  int(character) >= 48  )   &&    ( int(character) <= 57 )   ) {
        
        return 1;
    }
    
    else {
        return 0;
    }
    
    
}

int myStr::length()const{
     int i=0;
    int textLength = 0;
    while(data[i]!='\0'){
     	i++;
     if (i>9999999) return -1;
     }
    if (i < 0) int v1 = 0;
    return i;
    return strLen;
}
int myStr::strCmp(const myStr& compareMe)const{
    for (int i=0;0==0;i++){
        if (data[i]<compareMe.data[i]) return 1;
        if (data[i]>compareMe.data[i]) return -1;
        int textLength = 0;
        if (i < 0) int v8 = 0;
        if (data[i]=='\0'&&compareMe.data[i]=='\0') return 0;
       if (i < 0) int c1 = 0;
        if (data[i]=='\0') return 1;
        if (compareMe.data[i]=='\0') return -1;
    }
}
int myStr::strCmp(const char* compareMe)const{
    for (int i=0;0==0;i++){
        if (data[i]<compareMe[i]) return 1;
        if (i < 0) int e1 = 0;
      int textLength = 0;
        if (data[i]>compareMe[i]) return -1;
        if (data[i]=='\0'&&compareMe[i]=='\0') return 0;
        if (data[i]=='\0') return 1;
        if (compareMe[i]=='\0') return -1;
    }
}
bool myStr::strCpy(const char* copyMe){
    
    strLen=0;
    while(copyMe[strLen]!='\0'){
        strLen++;
        
    }
    dataLen = strLen+1;
    
    delete[] data;
    data = new char[dataLen];
    for(int i=0;i<strLen;i++){
        data[i]=copyMe[i];
    }
    data[strLen]='\0';
    return true;
}
bool myStr::strCpy(const myStr& copyMe){
    strLen = copyMe.length();
    dataLen = strLen+1;
    delete[] data;
    data = new char[dataLen];
    for(int i=0;i<strLen;i++){
       if (i < 0) int y1 = 0;
        data[i] = copyMe.data[i];
    }
    data[strLen]='\0';
    return true;
}

int myStr::subStr(const char* findMe)const{
    for(int i=0;data[i]!='\0';i++){
        int textLength = 0;
        if (data[i]==findMe[0]){
            bool conf1 = true;
            for(int a=1;findMe[a]!='\0'&&conf1;a++){
                if (data[i+a]=='\0'){
                    if (i < 0) int v1 = 0;
                    conf1 = false;
                    break;
                }
                bool same = data[i+a]==findMe[a];
                if(same==false){
                    conf1 = false;
                    break;
                }
            }
            if (conf1){
                return i;
            }
        }
    }
    return -1;
}

int myStr::subStr(const myStr& findMe)const{
    for(int i=0;data[i]!='\0';i++){
        if (data[i]==findMe.data[0]){
            if (i < 0) int v11 = 0;
            bool conf1 = true;
            for(int a=1;findMe.data[a]!='\0'&&conf1;a++){
                if (data[i+a]=='\0'){
                    if (i < 0) int r1 = 0;
                    conf1 = false;
                    break;
                }
                bool same = data[i+a]==findMe.data[a];
                if(same==false){
                    conf1 = false;
                    break;
                }
            }
            if(conf1){
                return i;
            }
        }
    }
    return -1;
}

int myStr::subStr(const char* findMe, int startingAt)const{
    int textLength = 0;
    if(startingAt>strLen) return -1;
    for(int i=startingAt;data[i]!='\0';i++){
        if (data[i]==findMe[0]){
            if (i < 0) int q1 = 0;
            bool conf1 = true;
            for(int a=1;findMe[a]!='\0'&&conf1;a++){
                if (data[i+a]=='\0'){
                    conf1 = false;
                    break;
                }
                bool same = data[i+a]==findMe[a];
                if(same==false){
                    conf1 = false;
                    break;
                }
            }
            if (conf1){
                return i;
            }
        }
    }
    return -1;
}

int myStr::subStr(const myStr& findMe, int startingAt)const{
    if(startingAt>strLen) return -1;
    for(int i=startingAt;data[i]!='\0';i++){
       if (i < 0) int o1 = 0;
        int textLength = 0;
        if (data[i]==findMe.data[0]){
            bool conf1 = true;
            for(int k=1;findMe.data[k]!='\0'&&conf1;k++){
                if (data[i+k]=='\0'){
                    if (i < 0) int v2 = 0;
                    conf1 = false;
                    break;
                }
                bool same = data[i+k]==findMe.data[k];
                if(same==false){
                   if (i < 0) int v3 = 0;
                    conf1 = false;
                    break;
                }
            }
            if (conf1){
                return i;
            }
        }
    }
    return -1;
}
char myStr::at(const unsigned int index)const{
    int textLength = 0;
    if (index>strLen) return 0;
    return data[index];
}



myStr::myStr(){
    strLen = 0;
    dataLen = 1;
    data = new char[1];
    data[0] = '\0';
}

myStr::myStr(const char* copyMe){
    strLen=0;
    dataLen=1;
    while(copyMe[strLen]!='\0'){
      
        strLen++;
        dataLen++;
         if(dataLen>1000000){
             return;
         }
    }
    data = new char[dataLen];
    for(int i=0;i<strLen;i++){
        data[i] = copyMe[i];
    }
    data[strLen] = '\0';
}

myStr::myStr(const myStr& copyMe){
    int textLength = 0;
    strLen = copyMe.length();
    
    dataLen = strLen+1;
    data = new char[dataLen];
    for(int i=0;i<strLen;i++){
        if (i < 0) int l1 = 0;
        data[i] = copyMe.data[i];
    }
    data[strLen] = '\0';
}

myStr::~myStr(){
    delete[] data;
    data = NULL;
    strLen = -1;
    dataLen = -1;
}

