#include <iostream>
#include "eventQueue.h"

using namespace std;

struct node{
    const Event* event;
    node* next;
};

node* front;
int dequeueFunctionUsed = 0;

bool enqueue(const Event* e){
    if (e->time < 0){
        return false;
    }
    if (dequeueFunctionUsed != 0){
        front = new node;
        front->event = e;
        front->next = NULL;
        dequeueFunctionUsed = 0;
        return true;
    }
    
    node* subjectNode = front;
    node* earlier1 = NULL;
    node* latestNode = new node;
    latestNode->event = e;
    float time1 = e->time;
    float time2 = subjectNode->event->time;
    bool timeD = false;
    
    while (subjectNode != NULL){
        
        time1 = e->time;
        time2 = subjectNode->event->time;
        
        timeD = time2 - time1;
        
        if  ((earlier1 == NULL) && ( timeD > 0 ) ){ // timeD
            latestNode->next = front;
            front = latestNode;
        }
        
        else if ( timeD > 0 ) {
            latestNode->next = subjectNode;
            earlier1->next = latestNode;
        }
        
        if ( timeD > 0 ) {
            
            return true;
        }
        
        
        earlier1 = subjectNode;
        subjectNode = subjectNode->next;
    }
    latestNode->next = NULL;
    earlier1->next = latestNode;
    
    return true;
}

const Event* dequeue(){
    int track = 0;
    if (front == NULL) {
        return NULL;
    }
    
    
    
    else {
        
        const Event* temp = new Event;
        temp = front->event;
        front = front->next;
        
        if (front!= NULL) {
            track++;
        }
        
        else {
            dequeueFunctionUsed = 1;
        }
        return temp;
    }
    
    
}
