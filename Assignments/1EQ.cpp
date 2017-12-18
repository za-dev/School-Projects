
#include <iostream>
#include "eventQueue.h"

using namespace std;


struct node{
    
    const Event* event;
    struct node *next;
    
};

node* front = NULL;
node* back = NULL;


bool enqueue(const Event* e) {
    
    if (e->time < 0) return false;
   
    node* temp = front;
   
   if(temp == NULL) {
	temp->event = e;
	temp->next = NULL;
       
   }
   
    node* subjectNode = temp;
    node * concNode = new node;
    concNode-> event = e;
    
    
    float time1;
    float time2;
    
    while (subjectNode != NULL) {
        int c = 0;
        time1 = e->time;
        time2 = subjectNode -> event ->time;
        
        
        if ((back == NULL) && (time2 > time1) ){
            
            concNode -> next = temp;
            temp = concNode;
            
            
        }
        
        
        if ((back != NULL) && (time2 > time1) ) {
            
            concNode-> next = subjectNode;
            back -> next = concNode;
        
            
        }
        
        if (time2 > time1) {
            
            return true;
            c++;
            
        }
        
        
        back = subjectNode;
        subjectNode = subjectNode -> next;
        
        if (c != 0) {
            concNode-> next = NULL;
            back->next = concNode;
            return true;
        }
        
        
    }
    
    
    
    

    
    
}



int priorityCheck(const Event* a1, const Event* a2) {
    
    float t1 = a1->time;
    float t2 = a2 ->time;
    
    if (t1 > t2) {
        return 1;
    }
    
    if (t1 < t2) {
        return 2;
    }
    
    
    return 0;
}


const Event* dequeue(){
    if (front != NULL){
        const Event* temp1 = new Event;
        temp1 = front->event;
        front = front->next;
        
        return temp1;
    }
    return NULL;
}


