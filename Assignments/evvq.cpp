
#include <iostream>
#include "eventQueue.h"

using namespace std;


struct node{
    
    const Event* event;
    struct node *next;
    
};


node *front;
node *back;





bool enqueue(const Event* e) {
    
    
    
    if (time < 0 ) {
        
        return 0;
        
        
    }

    node *given = new node;
    given -> event =  e;
    given -> next = NULL;
    
    
    if (front == NULL) {
        front = given;
        
    }
    
    
    else {
        
        back-> next = given;
        
        
    }
    
    back = given;
    /// trying to iterate thru (done wrong)
    for (int i = 0; i < int(back); i++) {
        
        if (e -> time < given-> e -> time) {
            // place new node here (done wrong)
            given -> next = new node;
            return true;
        }
        
        else {
            given -> next;
        }
            
        
        
    }
    

    return 0;
    
    
}

const Event *dequeue() {
    
    node *given = new node;
    
    if (front == NULL) {
        return 0; /// returning 0 if queue is empty
    }
    
    else {
        
        given = front;
        front = front -> next;
       
        
        
        
    }
    
    return event;
    
    
    
}
