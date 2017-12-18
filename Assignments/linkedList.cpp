#include <iostream>


using namespace std;




struct node {
    
    string building;
    node * next;
    
};


node * head = NULL;
node * tail = NULL;

void queue (string newBuilding)  {
    
    node* temp = new node;
    temp-> building = newBuilding;
    temp-> next = NULL;
    
    if (head == NULL) { /// meaning the list is empty

        
        head = temp;
        tail = temp;
        
    }
    
    else if (head == tail) { //meaning the list has 1 item in it

        head-> next = temp;
        tail = temp;
        
        
    }
    
    else { // meaning the list is atleast 2 items long

        tail-> next = temp;
        tail = temp;
        
        
    }
    
    
    
    
}


void dequeue () {
    
    
             if (head == NULL) cout << "List aready empty";
             
             else if (head == tail) {
             
                 delete tail;
                 delete head;
                 head = NULL;
                 tail = NULL;
                 return;
             
             }
    
    node* temp = new node;
    temp = head-> next;
    delete head;
    head = temp;
    
    
    
}





void display () {

    if (head == NULL) {
        cout << "List empty " << endl;
    }
    
    else {
    
    
        cout << "List contains: " << endl;
   
        
    while (head != NULL) {
        
        cout << head-> building << endl;
        head = head -> next;
        
        
        
    }
        
        
    }
    

}

int findLength() {
    
    node* temp = new node;
    temp -> next = NULL;
    temp = head;
    int length = 0;

    
    tail->next = NULL;
    while (temp != NULL) {
        
        length++;
        temp = temp-> next;
        
        
        
    }
    
    return length;
    
}



int main() {
    
    queue("Warehouse");
    queue( "sawmill");
     queue( "quarry");
     queue( "academy");
    queue( "farm");
    dequeue();
    
    
    
    display();
    cout << "The length of the queue is : " << findLength() << endl;

    
    
    return 0;
}
