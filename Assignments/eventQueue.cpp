
#include <iostream>
#include "eventQueue.h"

using namespace std;


struct node{
    
    const Event* event;
    struct node *next;
    
};



node *tail = NULL;
node *head = NULL;


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

bool enqueue(const Event* e) {
    
    if (time < 0) return false;
   node *temp = new node;
   
    if (e == NULL) { // if empty, build it
     
        temp-> event = e;
        temp-> next = NULL;
        return true;
        
    }
    
    else {
        temp -> event = e;
    }
    
    
    head = temp;
    tail = temp;
    
    if (tail->next == NULL) {
        tail = tail->next; //set tail to last node
    }

    while(temp != NULL) {
    
    if (    priorityCheck (  head->event, e ) == 1   ) { // switch them since time of head is bigger than next element
        
        node* temp1 = new node;
        temp1 -> event = e;
        temp1 -> next = head;
        temp = temp1;
        return true;
        
    }
    
    
    if ( priorityCheck (  tail->event, e ) == 2 ) { // switch them since time of tail is smaller than next element

        
        node* temp1 = new node;
        temp1 -> event = e;
        temp1 -> next = NULL;
        tail -> next = temp1;
        tail = temp1;
        return true;
        
    }
        
        temp = temp-> next;
    }
    return false;
    
}

    
    
const Event *dequeue() {
        
    if ( head == NULL ) {
        return 0;
    }
        
    node *temp = head;
    head = head->next;
    temp->next = NULL;
    
    return temp->event;
    return 0;
    
        
    }

