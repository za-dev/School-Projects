#include "StringClass.h"
#include <iostream>
// class myStr {
//      friend std::ostream& operator<<(std::ostream& os, const myStr& s) ;
// public:
//      int length()const;
//      int strCmp(const myStr& compareMe) const;
//      int strCmp(const char* compareMe) const;
//      bool strCpy(const myStr& copyMe);
//      bool strCpy(const char* copyMe);
//      int subStr(const char* findMe) const;
//      int subStr(const myStr& findMe) const;
//      int subStr(const char* findMe, int startingAt) const;
//      int subStr(const myStr& findMe, int startingAt) const;
//      char at(const unsigned int index) const;
//      myStr();
//      myStr(const myStr& copyMe);
//      myStr(const char* copyMe);
//      ~myStr();

// private:
// };
// int   strLen;
// int   dataLen;
// char* data;
//
int myStr::length()const{
     int i=0;
     while(data[i]!='\0'){
     	i++;
     if (i>9999999) return -1;
     }
    return i;
    return strLen;
}
int myStr::strCmp(const myStr& compareMe)const{
    for (int i=0;0==0;i++){
        if (data[i]<compareMe.data[i]) return 1;
        if (data[i]>compareMe.data[i]) return -1;
        if (data[i]=='\0'&&compareMe.data[i]=='\0') return 0;
        if (data[i]=='\0') return 1;
        if (compareMe.data[i]=='\0') return -1;
    }
}
int myStr::strCmp(const char* compareMe)const{
    for (int i=0;0==0;i++){
        if (data[i]<compareMe[i]) return 1;
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
        data[i] = copyMe.data[i];
    }
    data[strLen]='\0';
    return true;
}

int myStr::subStr(const char* findMe)const{
    for(int i=0;data[i]!='\0';i++){
        if (data[i]==findMe[0]){
            bool found = true;
            for(int a=1;findMe[a]!='\0'&&found;a++){
                if (data[i+a]=='\0'){
                    found = false;
                    break;
                }
                bool same = data[i+a]==findMe[a];
                if(same==false){
                    found = false;
                    break;
                }
            }
            if (found){
                return i;
            }
        }
    }
    return -1;
}

int myStr::subStr(const myStr& findMe)const{
    for(int i=0;data[i]!='\0';i++){
        if (data[i]==findMe.data[0]){
            bool found = true;
            for(int a=1;findMe.data[a]!='\0'&&found;a++){
                if (data[i+a]=='\0'){
                    found = false;
                    break;
                }
                bool same = data[i+a]==findMe.data[a];
                if(same==false){
                    found = false;
                    break;
                }
            }
            if(found){
                return i;
            }
        }
    }
    return -1;
}

int myStr::subStr(const char* findMe, int startingAt)const{
    if(startingAt>strLen) return -1;
    for(int i=startingAt;data[i]!='\0';i++){
        if (data[i]==findMe[0]){
            bool found = true;
            for(int a=1;findMe[a]!='\0'&&found;a++){
                if (data[i+a]=='\0'){
                    found = false;
                    break;
                }
                bool same = data[i+a]==findMe[a];
                if(same==false){
                    found = false;
                    break;
                }
            }
            if (found){
                return i;
            }
        }
    }
    return -1;
}

int myStr::subStr(const myStr& findMe, int startingAt)const{
    if(startingAt>strLen) return -1;
    for(int i=startingAt;data[i]!='\0';i++){
        if (data[i]==findMe.data[0]){
            bool found = true;
            for(int a=1;findMe.data[a]!='\0'&&found;a++){
                if (data[i+a]=='\0'){
                    found = false;
                    break;
                }
                bool same = data[i+a]==findMe.data[a];
                if(same==false){
                    found = false;
                    break;
                }
            }
            if (found){
                return i;
            }
        }
    }
    return -1;
}
char myStr::at(const unsigned int index)const{
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
    strLen = copyMe.length();
    dataLen = strLen+1;
    data = new char[dataLen];
    for(int i=0;i<strLen;i++){
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
int main() {return 0;}
